#include <stdio.h>
#include <math.h>
#include <XYstage.h>
#include "App.h"

// 構造体宣言
XY	xy;

// グローバル座標におけるハンド位置
static HomoMat xy_base_homo ={{1.0, 0.0, 0.0},
		                        {0.0, 1.0, 0.0},
		                        {0.0, 0.0, 1.0},
								{0.0, 0.0, 0.0}};
// 制御ゲイン
/*
HANDCtrlCoef hand_ctrl_coef = {{7.0, 10.0, 7.0, 10.0, 7.0, 10.0, 7.0, 7.0, 12.0, 12.0},	// Kp
								{0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0},				// Ti
								{30.0, 30.0, 30.0, 30.0, 30.0, 30.0, 30.0, 30.0, 30.0, 30.0},	// Td
								{0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0},				// Cf
								1.0};															// Kg
*/
XYCtrlCoef xy_ctrl_coef = {{80.0, 80.0},	// Kp
							{0.0, 0.0},	// Ti
							{340.0, 340.0},	// Td
							{0.0, 0.0},	// Cf
							1.2};	// Kg

//周波数の定義
#define OMEGA	1.0

//スライダの初期位置
#define XY_INIT02	-0.0
#define XY_INIT03	-0.0

// 初期姿勢
static XYJnt	prepare_jnt_ang = {XY_INIT02, XY_INIT03};
//////////////////////////////////////////////////////
int xyTrajApp(XYJnt ref_jnt_ang, XYJnt data, double time, double *sensor, double *camera)
{
	//関節角度の定義
	#define DIS1_M1		-0.05//スライダが後ろに動く距離，ハンド02搭載
	#define DIS1_M2		-0.05//スライダが後ろに動く距離，ハンド03搭載
	//スライダの配置から
	//ロゴシールが貼ってある方向がプラス
	//XY_M1とXY_M2は逆向きにすること

	//制御ゲイン
	//I(x, y)を1として計算
	#define KP_XY2	0.0005
	#define KD_XY2	0.00
	//I(x, y)を255として計算
	#define KP_XY1	KP_XY2/255
	#define KD_XY1	KD_XY2/255

	//時間の定義
	#define TIME1	5.0//布をセットする時間
	#define TIME11	15.0//画像処理の設定時間
	#define TIME2	16.0//手首を下にセットする時間
	#define TIME3	17.0//布のゆれを無くすための時間
	#define TIME4	17.1//布を変形させる時間（手首を上に曲げる）
	#define TIME45	17.2//布を変形させる時間（手首を上に曲げる）
	#define TIME5	17.3//ロボットを止める時間
	#define TIME6	17.4//布を把持する時間

	//スライダ移動距離の調整ゲイン
	#define DIS_GAIN	4.0
	#define DIS_GAIN2	2.0

	int jnt, crd;

	//カメラの値の保存
	static double c0;//camera[0]，ハンド03用の指（x座標か面積）
	static double c1;//camera[1]，ハンド03用の指（y座標）
	static double c2;//camera[2]，ハンド02用の指（x座標か面積）
	static double c3;//camera[3]，ハンド02用の指（y座標）
	static double c4;//camera[4]，ハンド03用の布（x座標か面積）
	static double c5;//camera[5]，ハンド03用の布（y座標）
	static double c6;//camera[6]，ハンド02用の布（x座標か面積）
	static double c7;//camera[7]，ハンド02用の布（y座標）

	//スライダの位置の値の保存
	static double xy_m1;
	static double xy_m2;

	//布と指がほぼ一致したかのフラグ
	static int flag_xy;

	//PD出力
	double xy_pd;

	//布と指がほぼ一致したかの判定の閾値
	//define GAMMA	100/255//*255は0次モーメントを計算するときに，I(x, y)を255として計算しているため
	#define GAMMA	100

	//M1はハンド03搭載
	//M2はハンド02搭載

	for(jnt=0;jnt<XY_JNT;jnt++)   ref_jnt_ang[jnt] = prepare_jnt_ang[jnt];
	if(time <= TIME1){
		ref_jnt_ang[XY_M1] = XY_INIT02;
		ref_jnt_ang[XY_M2] = XY_INIT03;
	}else if(time <= TIME11){
		ref_jnt_ang[XY_M1] = XY_INIT02;
		ref_jnt_ang[XY_M2] = XY_INIT03;
	}else if(time <= TIME2){
		ref_jnt_ang[XY_M1] = XY_INIT02;
		ref_jnt_ang[XY_M2] = XY_INIT03;
	}else if(time <= TIME3){
		ref_jnt_ang[XY_M1] = XY_INIT02;
		ref_jnt_ang[XY_M2] = XY_INIT03;
/*
	}else if(time <= TIME4){//できればビジュアルフィードバックの部分（形状指定）
		ref_jnt_ang[XY_M1] = XY_INIT02 + DIS1_M1*(time-TIME3)/(TIME4-TIME3);
		ref_jnt_ang[XY_M2] = XY_INIT03 + DIS1_M2*(time-TIME3)/(TIME4-TIME3);
*/
	}else if(time <= TIME45){//できればビジュアルフィードバックの部分（形状指定）
		ref_jnt_ang[XY_M1] = XY_INIT02 + (DIS_GAIN+1)*DIS1_M1*(time-TIME3)/(TIME45-TIME3);
		ref_jnt_ang[XY_M2] = XY_INIT03 + (DIS_GAIN+1)*DIS1_M2*(time-TIME3)/(TIME45-TIME3);
	}else if(time <= TIME5){
		ref_jnt_ang[XY_M1] = XY_INIT02 + DIS1_M1+DIS_GAIN*DIS1_M1;
		ref_jnt_ang[XY_M2] = XY_INIT03 + DIS1_M2+DIS_GAIN*DIS1_M2;
		xy_m1 = ref_jnt_ang[XY_M1];
		xy_m2 = ref_jnt_ang[XY_M2];
		flag_xy = 0;
	}else if(time <= TIME6){//ビジュアルフィードバックの部分（把持するための制御）
		if(flag_xy ==1){//布との面積が一致した後
			ref_jnt_ang[XY_M1] = xy_m1;
			ref_jnt_ang[XY_M2] = xy_m2;
		}else if(camera[0]!=0){//トラッキングできているとき
			//カメラの値の保存
			//static double c0;//camera[0]，ハンド03用の指（x座標か面積）
			//static double c1;//camera[1]，ハンド03用の指（y座標）
			//static double c2;//camera[2]，ハンド02用の指（x座標か面積）
			//static double c3;//camera[3]，ハンド02用の指（y座標）
			//static double c4;//camera[4]，ハンド03用の布（x座標か面積）
			//static double c5;//camera[5]，ハンド03用の布（y座標）
			//static double c6;//camera[6]，ハンド02用の布（x座標か面積）
			//static double c7;//camera[7]，ハンド02用の布（y座標）

			//奥行きがほぼ同じとき
			if( ((camera[4]+camera[6])/2/255 - (camera[0]+camera[2])/2/255) <= GAMMA || flag_xy==1){
				flag_xy = 1;
				ref_jnt_ang[XY_M1] = xy_m1;
				ref_jnt_ang[XY_M2] = xy_m2;
				xy_m1 = ref_jnt_ang[XY_M1];
				xy_m2 = ref_jnt_ang[XY_M2];
			}else{
			//布につけたマーカーの面積に一致するようにスライダの前後位置を制御
			//xy_pd = KP_XY1*( (camera[4]+camera[6])/2 - (camera[0]+camera[2])/2) + KD_XY1*( ((camera[4]-c4)+(camera[6]-c6))/2 - ((camera[0]-c0)+(camera[2]-c2))/2);//PD出力
				xy_pd = KP_XY2*( (camera[4]+camera[6])/2/255 - (camera[0]+camera[2])/2/255) + KD_XY2*( ((camera[4]-c4)+(camera[6]-c6))/2/255 - ((camera[0]-c0)+(camera[2]-c2))/2/255);//PD出力
				ref_jnt_ang[XY_M1] = xy_m1 + xy_pd;
				ref_jnt_ang[XY_M2] = xy_m2 + xy_pd;
				//目標値制限
				if (ref_jnt_ang[XY_M1] > -0.1){
					ref_jnt_ang[XY_M1] = -0.1;
				}
				if (ref_jnt_ang[XY_M2] > -0.1){
					ref_jnt_ang[XY_M2] = -0.1;
				}
				xy_m1 = ref_jnt_ang[XY_M1];
				xy_m2 = ref_jnt_ang[XY_M2];
			}
		}else{//トラッキングできていないとき
			ref_jnt_ang[XY_M1] = XY_INIT02 + DIS1_M1+DIS_GAIN*DIS1_M1 - DIS1_M1*DIS_GAIN2*(time-TIME5)/(TIME6-TIME5);
			ref_jnt_ang[XY_M2] = XY_INIT03 + DIS1_M2+DIS_GAIN*DIS1_M2 - DIS1_M2*DIS_GAIN2*(time-TIME5)/(TIME6-TIME5);
			xy_m1 = ref_jnt_ang[XY_M1];
			xy_m2 = ref_jnt_ang[XY_M2];
		}
	}else{
		ref_jnt_ang[XY_M1] = xy_m1;
		ref_jnt_ang[XY_M2] = xy_m2;
//		ref_jnt_ang[XY_M1] = camera[1];
//		ref_jnt_ang[XY_M2] = camera[2];
    }

	//カメラの値の代入
	c0=camera[0];
	c1=camera[1];
	c2=camera[2];
	c3=camera[3];
	c4=camera[4];
	c5=camera[5];
	c6=camera[6];
	c7=camera[7];

	return 0;
}


//////////////////////////////////////
// ハンド初期設定
//////////////////////////////////////
int xyAppSet(XY *xy)
{
	int jnt;
	xy->base_homo = &xy_base_homo;
	xy->ctrl_coef = &xy_ctrl_coef;
	xy->prepare_jnt_ang = prepare_jnt_ang;
	return 0;
}
