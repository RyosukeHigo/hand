#include <stdio.h>
#include <math.h>
#include <Hand.h>
#include <Kine.h>
#include "App.h"

// 構造体宣言
HAND hand02;

// グローバル座標におけるハンド位置
static HomoMat hand_base_homo = {{1.0, 0.0, 0.0},
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

//手首旋回制御あり

HANDCtrlCoef hand_ctrl_coef = {{15.0, 20.0, 15.0, 20.0, 15.0, 20.0, 15.0, 15.0, 10.0, 25.0}, // Kp
							   {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0},			 // Ti
							   {60.0, 75.0, 60.0, 75.0, 60.0, 75.0, 30.0, 30.0, 30.0, 75.0}, // Td
							   {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0},			 // Cf
							   1.0};														 // Kg

//手首旋回制御なし

/*static HANDCtrlCoef hand_ctrl_coef = {{15.0, 20.0, 15.0, 20.0, 15.0, 20.0, 15.0, 15.0, 0.0, 25.0}, // Kp
									  {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0},		   // Ti
									  {60.0, 75.0, 60.0, 75.0, 60.0, 75.0, 60.0, 60.0, 0.0, 75.0}, // Td
									  {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0},		   // Cf
									  1.0};														   // Kg
*/
//手首旋回制御なし，展示用（指先のゲイン小さく）
/*
HANDCtrlCoef hand_ctrl_coef = {{15.0, 10.0, 15.0, 10.0, 15.0, 10.0, 15.0, 15.0, 0.0, 25.0},	// Kp
								{0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0},				// Ti
								{60.0, 40.0, 60.0, 40.0, 60.0, 40.0, 60.0, 60.0, 0.0, 75.0},	// Td
								{0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0},				// Cf
								1.0};															// Kg
								*/

// デモ番号
#ifndef MATLAB_MEX_FILE
extern unsigned int app_num;
#else
extern unsigned int app_num = 0;
#endif

//static HANDJnt	prepare_jnt_ang = {-PI/2.0, 0.0, -PI/2.0, 0.0, -PI/2.0, 0.0, -PI/3.0*2.0 + PI/36.0, -PI/3.0*2.0 + PI/36.0, 0.0, 0.0};
//static HANDJnt	prepare_jnt_ang;

//指番号02用
// ref_jnt_ang[HAND_M1]：左指根元リンク
// ref_jnt_ang[HAND_M2]：左指先端リンク
// ref_jnt_ang[HAND_M3]：中指根元リンク
// ref_jnt_ang[HAND_M4]：中指先端リンク
// ref_jnt_ang[HAND_M5]：右指根元リンク
// ref_jnt_ang[HAND_M6]：右指先端リンク
// ref_jnt_ang[HAND_M7]：左指旋回軸（マイナス方向のみ）
// ref_jnt_ang[HAND_M8]：右指旋回軸（プラス方向のみ）
// ref_jnt_ang[HAND_M9]：手首旋回軸
// ref_jnt_ang[HAND_M10]：手首屈曲軸
#define LEFT_FINGER 0
#define MIDDLE_FINGER 1
#define RIGHT_FINGER 2

//ハンドのリンクの長さ2018-01-19
const double Lr = 0.030;
const double L1 = 0.0639; //指付け根リンク長
//const double L2 = 0.0365;//指先リンク長　半球の中心を指先とする場合は0.0365m　指先の場合0.045m
//const double L2 = 0.049; //指サックつけたとき
const double r = 0.045 - 0.0365; //指先半球の半径
const double Lpr = 0.03;
const double Lpm = 0.0;
const double Lpl = -0.03;
//const double Lw0 = 0.105;
const double Lw1 = 0.0515; //設計図の0.045という値は正しくない　実際に測ると0.0515となった　2018/02/10
//重心位置をグローバルで保存cog_writeで書き込み制限
double cog_x = 0.0;
double cog_y = 0.0;
int cog_write = 1;

//前のハンド関節の値を保存
double prev_jnt_ang[10];

double prev_mfinger_x;
double prev_mfinger_y;
//運動学で関節角から右指、左指の指先座標を求める
/*
 *  同次変換行列
 *     T={{nx, ox, ax, px},
 *        {ny, oy, ay, py},
 *        {nz, oz, az, pz},
 *        { 0,  0,  0,  1}};
 */
/*void forKine(HANDJnt ref_jnt_ang, HANDJnt prepare_jnt_ang1, char finger_type)
{
	double qw1 = ref_jnt_ang[HAND02_M10];//手首屈曲関節
	double qw2 = ref_jnt_ang[HAND02_M9];//手首旋回関節
	double q1 = 0;
	double q2 = 0;
	double q3 = 0;
	double Lp = 0;
	//左指
	if(finger_type == 'r')
	{
		q1 = ref_jnt_ang[HAND02_M7];
		q2 = ref_jnt_ang[HAND02_M1];
		q3 = ref_jnt_ang[HAND02_M2];
		Lp = Lpr;
	}
	//中指
	else if(finger_type == 'm')
	{
		q1 = 0;
		Lp = Lpm;
	}
	//右指
	else if(finger_type == 'l')
	{
		q1 = ref_jnt_ang[HAND02_M8];
		q2 = ref_jnt_ang[HAND02_M3];
		q3 = ref_jnt_ang[HAND02_M4];
		Lp = Lpl;
	}
	HomoMat T;
	T.nvec[0] = sin(qw1); T.ovec[0] = cos(qw1)*sin(qw2);  T.avec[0] = cos(qw1)*cos(qw2);  T.pvec[0] = 0;
	T.nvec[1] = 0; 		  T.ovec[1] = -cos(qw2);          T.avec[1] = sin(qw2);           T.pvec[1] = 0;
	T.nvec[2] = cos(qw1); T.ovec[2] = -sin(qw1)*sin(qw2); T.avec[2] = -sin(qw1)*cos(qw2); T.pvec[2] = 0;
	HomoMat A0;
	A0.nvec[0] = 1; A0.ovec[0] = 0; A0.avec[0] = 0; A0.pvec[0] = Lw0;
	A0.nvec[1] = 0; A0.ovec[1] = 1; A0.avec[1] = 0; A0.pvec[1] = Lp;
	A0.nvec[2] = 0; A0.ovec[2] = 0; A0.avec[2] = 1; A0.pvec[2] = Lw1;
	HomoMat A1;
	A1.nvec[0] = cos(q1); A1.ovec[0] = 0; A1.avec[0] = sin(q1);  A1.pvec[0] = Lr*cos(q1);
	A1.nvec[1] = sin(q1); A1.ovec[1] = 0; A1.avec[1] = -cos(q1); A1.pvec[1] = Lr*sin(q1);
	A1.nvec[2] = 0;       A1.ovec[2] = 1; A1.avec[2] = 0;        A1.pvec[2] = 0;
	HomoMat A2;
	A2.nvec[0] = -sin(q2);  A2.ovec[0] = -cos(q2); A2.avec[0] = 0; A2.pvec[0] = -L1*sin(q2);
	A2.nvec[1] = cos(q2);   A2.ovec[1] = -sin(q2); A2.avec[1] = 0; A2.pvec[1] = L1*cos(q2);
	A2.nvec[2] = 0;         A2.ovec[2] = 0;        A2.avec[2] = 1; A2.pvec[2] = 0;
	HomoMat A3;
	A3.nvec[0] = cos(q3); A3.ovec[0] = -sin(q3); A3.avec[0] = 0; A3.pvec[0] = L2*cos(q3);
	A3.nvec[1] = sin(q3); A3.ovec[1] = cos(q3);  A3.avec[1] = 0; A3.pvec[1] = L2*sin(q3);
	A3.nvec[2] = 0;       A3.ovec[2] = 0;       A3.avec[2] = 1; A3.pvec[2] = 0;

	HomoMat *hand0,*hand1,*hand2,*hand3,*hand4;
	homoMatProduct(hand0, &T,  &A0);
	homoMatProduct(hand1, hand0, &A1);
	homoMatProduct(hand2, hand1, &A2);
	homoMatProduct(hand3, hand2, &A3);
	ref_jnt_ang[HAND02_M8] = hand3->pvec[2];
	ref_jnt_ang[HAND02_M3] = hand3->pvec[0];
	ref_jnt_ang[HAND02_M4] = hand3->pvec[1];
}
*/

//逆運動学で右指、左指の角度を求める
//並木先生のキネマティクスのドキュメントとはハンド屈曲関節の回転方向の定義が逆だったのでqw1の符号を反転させた
void invKine(HANDJnt ref_jnt_ang, HANDJnt prepare_jnt_ang1, double time, double stime, double angle, double xm, double ym, double zm, int finger_type)
{
	//
	//手首屈曲関節
	double L2 = 0.0365;
	if (finger_type == MIDDLE_FINGER)
	{
		L2 = 0.0525 - 0.0085; //指先の半球の半径0.0085mを引いた長さ
	}
	double Lw0 = 0.105;
	if (finger_type == MIDDLE_FINGER)
	{
		Lw0 += 0.03;
	}
	double Lpr = 0.03;
	double Lpl = -0.03;
	double Lp = 0.03;
	if (finger_type == RIGHT_FINGER)
	{
		Lp = Lpr;
	}
	else if (finger_type == LEFT_FINGER)
	{
		Lp = Lpl;
	}
	else if (finger_type == MIDDLE_FINGER)
	{
		Lp = Lpl;
	}
	double qw1 = (atan2(xm, zm) - atan2(sqrt(xm * xm + zm * zm - Lw0 * Lw0), Lw0)); //xm * xm + zm * zm - Lw0 * Lw0>=0
	if (xm * xm + zm * zm - Lw0 * Lw0 < 0.0)
	{
		return;
	}
	//指先関節
	double ta = xm * cos(qw1) - zm * sin(qw1) - Lw1;
	double tb = ym - Lr + Lp;
	if (finger_type == RIGHT_FINGER)
	{
		tb = ym + Lr + Lp;
	}
	/*else if(finger_type == MIDDLE_FINGER)
	{
		tb = ym + Lr + Lp;
	}*/
	double C3 = (ta * ta + tb * tb - L1 * L1 - L2 * L2) / (2 * L1 * L2);
	if (C3 > 1.0 || C3 < -1.0)
	{
		return;
	}
	double S3 = sqrt(1 - C3 * C3);
	double q3 = atan2(S3, C3); //|C3|<=1
	//指付根関節
	double A = L2 * C3 + L1;
	double B = L2 * S3;
	double C = -ym + Lr - Lp;
	if (finger_type == RIGHT_FINGER)
	{
		C = ym + Lr + Lp;
	}
	/*else if(finger_type == MIDDLE_FINGER)
	{
		C = ym + Lr + Lp;
	}*/

	if (A * A + B * B - C * C < 0.0)
	{
		return;
	}
	double q2 = atan2(A, B) - atan2(sqrt(A * A + B * B - C * C), C); //A * A + B * B - C * C>=0
	if (finger_type == LEFT_FINGER)
	{
		//ref_jnt_ang[HAND02_M9] = zm;
		ref_jnt_ang[HAND02_M10] = -qw1;
		ref_jnt_ang[HAND02_M1] = q2;
		ref_jnt_ang[HAND02_M2] = q3;
	}
	else if (finger_type == RIGHT_FINGER)
	{
		//ref_jnt_ang[HAND02_M9] = zm;
		ref_jnt_ang[HAND02_M10] = -qw1;
		ref_jnt_ang[HAND02_M5] = q2;
		ref_jnt_ang[HAND02_M6] = q3;
	}
	else if (finger_type == MIDDLE_FINGER)
	{
		ref_jnt_ang[HAND02_M10] = -qw1;
		ref_jnt_ang[HAND02_M3] = prepare_jnt_ang1[HAND02_M3] + q2;
		ref_jnt_ang[HAND02_M4] = q3;
	}
}

//平方根の中身が負になるのでX,Yの値の調節が必要
void UturnKine(HANDJnt ref_jnt_ang, HANDJnt prepare_jnt_ang1, double TRAJ_RATE3, double time, double stime, double angle, double *camera)
{
	//逆運動学で指先に円軌道生成し指先でキューブを回す
	double X = cog_x;
	double Y = cog_y;
	double theta_s = PI / 12;
	double FP = 0.0085; //人差し指半径　人差し指指先関節リンク長は0.0525
	double cube_d = 0.0555;
	double QO = cube_d / 2;
	double PO = QO / cos(theta_s);
	double FO = FP + PO;
	double target_cog_x = 0.145; //Uturnのときの把持指のX座標
	double offset = 0.006;
	double ys = cube_d / 2 + r - offset;
	double z = 0.105;
	double step1 = 0.1;
	double step2 = 0.3;
	double step3 = 0.5;
	double step4 = 0.6;

	int jnt;
	//step1 準備　重心位置を奥にずらして　U回転ができるようにする
	if (time - stime < step1)
	{
		if (cog_write)
		{
			cog_x = camera[1];
			cog_y = camera[2];
			cog_write = 0;
		}
		//target_m_finger_x =  prev_mfinger_x + (0.145 + cube_d / 6 - prev_mfinger_x) * 10 * (time - stime);
		if (time - stime < step1 - 0.05)
		{
			target_cog_x = cog_x - cube_d / 3 + (target_cog_x - (cog_x - cube_d / 3)) * sin(PI * 10 * (time - stime));

			invKine(ref_jnt_ang, prepare_jnt_ang1, time, 0.0, 0.0, target_cog_x, ys, z, LEFT_FINGER);
			invKine(ref_jnt_ang, prepare_jnt_ang1, time, 0.0, 0.0, target_cog_x, -ys, z, RIGHT_FINGER);
			invKine(ref_jnt_ang, prepare_jnt_ang1, time, 0.0, 0.0, target_cog_x, ys, 0.135, MIDDLE_FINGER);
		}
		else
		{
			for (jnt = 0; jnt < HAND_JNT; jnt++)
				ref_jnt_ang[jnt] = prev_jnt_ang[jnt];
		}

		//ref_jnt_ang[HAND02_M3] = prev_jnt_ang[HAND02_M3];
		//ref_jnt_ang[HAND02_M4] = prev_jnt_ang[HAND02_M4];
		if (time - stime > step1 - 0.001)
		{
			cog_write = 1;
		}
	}
	//step2　回転動作
	else if (time - stime < step2)
	{
		if (cog_write)
		{
			cog_x = camera[1];
			cog_y = camera[2];
			cog_write = 0;
		}
		double theta = PI / 2.0 + theta_s + 5 * (time - stime - step1) * PI / 2.0;
		double x = X + FO * cos(theta);
		double y = Y + FO * sin(theta);
		invKine(ref_jnt_ang, prepare_jnt_ang1, time, 0.0, 0.0, x, y, 0.135, MIDDLE_FINGER);
		invKine(ref_jnt_ang, prepare_jnt_ang1, time, 0.0, 0.0, target_cog_x, ys, z, LEFT_FINGER);
		invKine(ref_jnt_ang, prepare_jnt_ang1, time, 0.0, 0.0, target_cog_x, -ys, z, RIGHT_FINGER);
		if (time - stime > step2 - 0.001)
		{
			cog_write = 1;
		}
	}
	//step3 指先を元に戻す
	else if (time - stime < step3)
	{
		double target_y = cube_d / 2 + r + 0.005;
		double theta = PI / 2.0 + theta_s + PI / 2.0;
		double x = X + FO * cos(theta) - 0.002;
		double y = Y + FO * sin(theta) + (target_y - (Y + FO * sin(theta))) * 5 * (time - stime - step2);
		invKine(ref_jnt_ang, prepare_jnt_ang1, time, 0.0, 0.0, x, y, 0.135, MIDDLE_FINGER);
		invKine(ref_jnt_ang, prepare_jnt_ang1, time, 0.0, 0.0, target_cog_x, ys, z, LEFT_FINGER);
		invKine(ref_jnt_ang, prepare_jnt_ang1, time, 0.0, 0.0, target_cog_x, -ys, z, RIGHT_FINGER);
	}
	//step4 step1でずらした重心を元に戻す
	else if (time - stime < step4)
	{
		if (cog_write)
		{
			cog_x = camera[1];
			cog_y = camera[2];
			cog_write = 0;
		}
		double target_y = cube_d / 2 + r + 0.005;
		double theta = PI / 2.0 + theta_s + PI / 2.0;
		double x = X + FO * cos(theta) - 0.002;
		double target_x;
		//double x = X + FO * cos(theta) - 0.002 + 0.01 * 10 * (time - stime - step3);
		if (time - stime < step4 - 0.05)
		{
			target_x = x + (0.130 - x) * sin(PI * 10 * (time - stime - step3));
			target_cog_x = target_cog_x + (0.130 - target_cog_x) * 10 * (time - stime - step3);
			invKine(ref_jnt_ang, prepare_jnt_ang1, time, 0.0, 0.0, target_cog_x, target_y, 0.135, MIDDLE_FINGER);
			invKine(ref_jnt_ang, prepare_jnt_ang1, time, 0.0, 0.0, target_cog_x, ys, z, LEFT_FINGER);
			invKine(ref_jnt_ang, prepare_jnt_ang1, time, 0.0, 0.0, target_cog_x, -ys, z, RIGHT_FINGER);
		}
		else
		{
			for (jnt = 0; jnt < HAND_JNT; jnt++)
				ref_jnt_ang[jnt] = prev_jnt_ang[jnt];
		}
		//ref_jnt_ang[HAND02_M3] = prev_jnt_ang[HAND02_M3];
		//ref_jnt_ang[HAND02_M4] = prev_jnt_ang[HAND02_M4];
		if (time - stime > step4 - 0.001)
		{
			cog_write = 1;
		}
	}
}
//Xturnでは重心位置の制限が強すぎたので重心位置から下へ1ブロック,手前に0.5ブロックの位置を把持して持ち上げる戦略
void Xturn2(HANDJnt ref_jnt_ang, HANDJnt prepare_jnt_ang1, double TRAJ_RATE3, double time, double stime, double angle, double *camera)
{
	double cube_d = 0.0555;			//キューブの直径WeiLong GTS2　　白いやつは　0.0565m
	double offset = 0.003;			//把持力に関係している　大きくすると強く把持してキューブが回転しないかもしれない。小さくてもキューブが把持できない。
	double xs = cog_x - cube_d / 6; //キューブの1列目と2列目の中間を持つ
	double ys = cube_d / 2 + r - offset;
	double zs = 0.105;

	double xe = 0.130; //目標位置
	double ze;
	double base_h = 0.28;  //土台の高さ
	double base_r = 0.195; //土台からロボット座標の原点までの高さ
	double z = 0.105;
	double z_top = base_h - base_r + (2 * cube_d) / 3 + 0.004; //キューブの上層と中層の間のZ座標　0.005は少し持ち上げたほうが回転ミスが減るから
	double z_bottom = base_h - base_r + cube_d / 6;			   //一番下の把持位置 キューブの底面ブロックの真ん中のZ座標

	///step1 キューブを把持
	double step1 = 0.1;
	double step2 = 0.3;
	double step3 = 0.4;
	if (time - stime < step1)
	{
		if (cog_write)
		{
			cog_x = camera[1];
			cog_y = camera[2];
			//cog_write = 0;
		}
		if (time - stime < step1 - 0.05)
		{
			ys = ys - 0.002 + 10 * 2 * offset * (time - stime);
			xs = xe + (xs - xe) * 10 * (time - stime);
			z = zs - (zs - z_bottom) * 10 * (time - stime);
			invKine(ref_jnt_ang, prepare_jnt_ang1, time, 0.0, 0.0, xs, -ys, z, RIGHT_FINGER);
			invKine(ref_jnt_ang, prepare_jnt_ang1, time, 0.0, 0.0, xs, ys, z, LEFT_FINGER);
		}
		else
		{
			xs = xe + (xs - xe) * 10 * (time - stime);
			ys = ys + 2 * offset - 10 * offset * (time - stime);
			z = zs - (zs - z_bottom) * 10 * (time - stime);
			invKine(ref_jnt_ang, prepare_jnt_ang1, time, 0.0, 0.0, xs, -ys, z, RIGHT_FINGER);
			invKine(ref_jnt_ang, prepare_jnt_ang1, time, 0.0, 0.0, xs, ys, z, LEFT_FINGER);
		}
		//ys = ys + 2 * offset * cos(5 * PI * (time - stime));//この時点でキューブに触れると動くので
		//z = zs - (zs - z_bottom) * sin(5 * PI * (time - stime));//sinが0.0→1.0と動く

		if (time - stime > step1 - 0.001)
		{
			cog_x = camera[1];
			cog_y = camera[2];
			cog_write = 0;
		}
	} //step2 キューブを持ち上げる
	else if (time - stime < step2)
	{
		//z = z_bottom + (z_top - z_bottom) * sin(2.5 * PI * (time - stime - step1));//sinが0.0→1.0
		//xs = xs + (xe - xs) * sin(2.5 * PI * (time - stime - step1));
		z = z_bottom + (z_top - z_bottom) * 5 * (time - stime - step1);
		xs = xs + (xe - xs) * 5 * (time - stime - step1);
		invKine(ref_jnt_ang, prepare_jnt_ang1, time, 0.0, 0.0, xs, -ys, z, RIGHT_FINGER);
		invKine(ref_jnt_ang, prepare_jnt_ang1, time, 0.0, 0.0, xs, ys, z, LEFT_FINGER);
	} //step3　指先を元の位置に戻す
	else if (time - stime < step3)
	{
		//z = z_top - (z_top - z) * sin(5 * PI * (time - stime - step2));
		z = z_top - (z_top - z) * 10 * (time - stime - step2);
		//ys = ys + 2 * offset;
		//xs = xe + (xs - xe) * 2 * (time - stime - step2);
		invKine(ref_jnt_ang, prepare_jnt_ang1, time, 0.0, 0.0, xe, -ys, z, RIGHT_FINGER);
		invKine(ref_jnt_ang, prepare_jnt_ang1, time, 0.0, 0.0, xe, ys, z, LEFT_FINGER);
		if (time - stime > step3 - 0.001)
		{
			cog_write = 1;
		}
	}
	ref_jnt_ang[HAND02_M3] = prepare_jnt_ang1[HAND02_M3] + prev_jnt_ang[HAND02_M3];
	ref_jnt_ang[HAND02_M4] = prev_jnt_ang[HAND02_M4];
}

//手首回転を利用したx軸回転 x = 0.13では逆運動学がおかしくなる　x = 0.12なら大丈夫だった
void Xturn(HANDJnt ref_jnt_ang, HANDJnt prepare_jnt_ang1, double TRAJ_RATE3, double time, double stime, double angle, double cog_x, double cog_y)
{
	/*
	double TRAJ_RAD = 2 * PI * 30 / 360;
	double rate = 0;
	double DEMO1_TIME1 = 0.1;
	double TRAJ_RATE2 = 5;

	ref_jnt_ang[HAND02_M1] -= 2 * PI * 0.5 / 360;
	ref_jnt_ang[HAND02_M5] -= 2 * PI * 0.5 / 360;
	if (time - stime < 0.2)
	{
		ref_jnt_ang[HAND02_M10] = -2 * PI * 10 / 360 * (1 - cos(2.0 * PI * (time - stime)));
	}
	else if (time - stime - 0.2 < DEMO1_TIME1)
	{
		ref_jnt_ang[HAND02_M10] = TRAJ_RAD / 4 * (1.0 - cos(2.0 * PI * (time - stime) * TRAJ_RATE2)) + prepare_jnt_ang1[HAND02_M10];
	}
	else if (time - stime - 0.2 < 2 * DEMO1_TIME1)
	{
		rate = 2.0 * PI * DEMO1_TIME1 * TRAJ_RATE2;
		ref_jnt_ang[HAND02_M10] = TRAJ_RAD / 4 * (1.0 - cos(2.0 * PI * (2 * DEMO1_TIME1 - (time - stime)) * TRAJ_RATE2)) + prepare_jnt_ang1[HAND02_M10];
	}*/
	double cube_d = 0.0555; //キューブの直径WeiLong GTS2　　白いやつは　0.0565m
	double offset = 0.002;  //把持力に関係している　大きくすると強く把持してキューブが回転しないかもしれない。小さくてもキューブが把持できない。
	int use_right = 1;
	int use_left = 0;
	double xs = cog_x - cube_d / 3; //キューブ手前列の真ん中を持つ
	double ys = cube_d / 2 + r - offset;
	double zs = 0.105;

	double xe = 0.120; //0.135;//目標位置
	double ze;

	double z = 0.105;
	double z_top = 0.1306;
	double z_bottom = 0.0929; //一番下の把持位置
	///step1 キューブを把持
	double step1 = 0.1;
	double step2 = 0.3;
	double step3 = 0.4;
	if (time - stime < step1)
	{
		//ys = ys + 2 * offset * cos(5 * PI * (time - stime));//この時点でキューブに触れると動くので
		//z = zs - (zs - z_bottom) * sin(5 * PI * (time - stime));//sinが0.0→1.0と動く
		ys = ys + 2 * offset * 10 * (time - stime);
		z = zs - (zs - z_bottom) * 10 * (time - stime);
		invKine(ref_jnt_ang, prepare_jnt_ang1, time, 0.0, 0.0, xs, -ys, z, use_right);
		invKine(ref_jnt_ang, prepare_jnt_ang1, time, 0.0, 0.0, xs, ys, z, use_left);
	} //step2 キューブを持ち上げる
	else if (time - stime < step2)
	{
		//x=0.1340,z = 0.1145あたりでおかしい挙動
		//z = z_bottom + (z_top - z_bottom) * sin(2.5 * PI * (time - stime - step1));//sinが0.0→1.0
		//xs = xs + (xe - xs) * sin(2.5 * PI * (time - stime - step1));
		z = z_bottom + (z_top - z_bottom) * 5 * (time - stime - step1);
		xs = xs + (xe - xs) * 5 * (time - stime - step1);
		invKine(ref_jnt_ang, prepare_jnt_ang1, time, 0.0, 0.0, xs, -ys, z, use_right);
		invKine(ref_jnt_ang, prepare_jnt_ang1, time, 0.0, 0.0, xs, ys, z, use_left);
	} //step3　指先を元の位置に戻す
	else if (time - stime < step3)
	{
		//z = z_top - (z_top - z) * sin(5 * PI * (time - stime - step2));
		z = z_top - (z_top - z) * 10 * (time - stime - step2);
		ys = ys + 2 * offset * 10 * (time - stime - step2);
		invKine(ref_jnt_ang, prepare_jnt_ang1, time, 0.0, 0.0, xe, -ys, z, use_right);
		invKine(ref_jnt_ang, prepare_jnt_ang1, time, 0.0, 0.0, xe, ys, z, use_left);
	}
	//ref_jnt_ang[HAND02_M9] = z;
	//ref_jnt_ang[HAND02_M3] = xs;
	//ref_jnt_ang[HAND02_M8] = ys;
}
void Yturn2(HANDJnt ref_jnt_ang, HANDJnt prepare_jnt_ang1, double TRAJ_RATE3, double time, double stime, double angle, double cog_x, double cog_y)
{
	double theta = PI / 6;
	double tan_vec_x_r = cos(-theta);
	double tan_vec_y_r = sin(-theta);
	double tan_vec_x_l = cos(PI + theta);
	double tan_vec_y_l = sin(PI + theta);
	double cube_d = 0.0555; //キューブの直径WeiLong GTS2　　白いやつは　0.0565m
	double offset = 0.005;  //把持力に関係している　大きくすると強く把持してキューブが回転しないかもしれない。小さくてもキューブが把持できない。
	double xs = 0.140;		//cog_x - cube_d / 6;//キューブ手前列の真ん中を持つ
	double ys = cube_d / 2 + r - offset;
	double z = 0.105;
	double step1 = 0.01;
	double step2 = 0.035;
	double step3 = 0.06;
	//ready
	if (time - stime < step1)
	{
		invKine(ref_jnt_ang, prepare_jnt_ang1, time, 0.0, 0.0, xs + tan_vec_x_r, -ys + tan_vec_y_r, z, RIGHT_FINGER);
		invKine(ref_jnt_ang, prepare_jnt_ang1, time, 0.0, 0.0, xs + tan_vec_x_l, ys + tan_vec_y_l, z, LEFT_FINGER);
	}
	//throw
	else if (time - stime < step2)
	{
		tan_vec_x_r = 0.015 / 0.025 * (time - stime - step1) * tan_vec_x_r;
		tan_vec_y_r = 0.015 / 0.025 * (time - stime - step1) * tan_vec_y_r;
		tan_vec_x_l = 0.015 / 0.025 * (time - stime - step1) * tan_vec_x_l;
		tan_vec_y_l = 0.015 / 0.025 * (time - stime - step1) * tan_vec_y_l;
		invKine(ref_jnt_ang, prepare_jnt_ang1, time, 0.0, 0.0, xs + tan_vec_x_r, -ys + tan_vec_y_r, z, RIGHT_FINGER);
		invKine(ref_jnt_ang, prepare_jnt_ang1, time, 0.0, 0.0, xs + tan_vec_x_l, ys + tan_vec_y_l, z, LEFT_FINGER);
	}
	else if (time - stime < step3)
	{
		tan_vec_x_r = 0.015 * tan_vec_x_r;
		tan_vec_y_r = 0.015 * tan_vec_y_r;
		tan_vec_x_l = 0.015 * tan_vec_x_l;
		tan_vec_y_l = 0.015 * tan_vec_y_l;
		invKine(ref_jnt_ang, prepare_jnt_ang1, time, 0.0, 0.0, xs + tan_vec_x_r, -ys + tan_vec_y_r, z, RIGHT_FINGER);
		invKine(ref_jnt_ang, prepare_jnt_ang1, time, 0.0, 0.0, xs + tan_vec_x_l, ys + tan_vec_y_l, z, LEFT_FINGER);
		ref_jnt_ang[HAND02_M1] = -PI / 6;
		ref_jnt_ang[HAND02_M5] = 0;
	}
	//Catch
	else if (angle > 70.0 || angle < 20.0)
	{
		tan_vec_x_r = 0 * tan_vec_x_r;
		tan_vec_y_r = 0 * tan_vec_y_r;
		tan_vec_x_l = 0 * tan_vec_x_l;
		tan_vec_y_l = 0 * tan_vec_y_l;
		invKine(ref_jnt_ang, prepare_jnt_ang1, time, 0.0, 0.0, xs + tan_vec_x_r, -ys + tan_vec_y_r, z, RIGHT_FINGER);
		invKine(ref_jnt_ang, prepare_jnt_ang1, time, 0.0, 0.0, xs + tan_vec_x_l, ys + tan_vec_y_l, z, LEFT_FINGER);
	}
}

//指先を利用したy軸回転
void Yturn(HANDJnt ref_jnt_ang, HANDJnt prepare_jnt_ang1, double TRAJ_RATE3, double time, double stime, double angle)
{

	//throw
	if (time - stime < 0.025)
	{
		ref_jnt_ang[HAND02_M6] = PI / 90 * 10 * (1.0 - cos(2.0 * PI * (time - stime) * TRAJ_RATE3)) + prepare_jnt_ang1[HAND02_M2];
		ref_jnt_ang[HAND02_M2] = -PI / 4 * (1.0 - cos(2.0 * PI * (time - stime) * TRAJ_RATE3)) + prepare_jnt_ang1[HAND02_M6];
	}
	else if (time - stime < 0.05)
	{
		ref_jnt_ang[HAND02_M1] = -PI / 25 * (1.0 - cos(2.0 * PI * (time - stime) * TRAJ_RATE3)) + prepare_jnt_ang1[HAND02_M1];
		ref_jnt_ang[HAND02_M5] = -PI / 25 * (1.0 - cos(2.0 * PI * (time - stime) * TRAJ_RATE3)) + prepare_jnt_ang1[HAND02_M5];
	}
	//Catch
	else if (angle > 70.0 || angle < 20.0)
	{
		ref_jnt_ang[HAND02_M1] = prepare_jnt_ang1[HAND02_M1];
		ref_jnt_ang[HAND02_M5] = prepare_jnt_ang1[HAND02_M5];
	}
	else
	{
		ref_jnt_ang[HAND02_M1] = -PI / 25 * (1.0 - cos(2.0 * PI * 0.05 * TRAJ_RATE3)) + prepare_jnt_ang1[HAND02_M1];
		ref_jnt_ang[HAND02_M5] = -PI / 25 * (1.0 - cos(2.0 * PI * 0.05 * TRAJ_RATE3)) + prepare_jnt_ang1[HAND02_M5];
	}
}
//////////////////////////////////////////////////////
//準備体操
//左指，中指，右指，左指旋回，右指旋回，手首旋回，手首屈曲
//static HANDJnt prepare_jnt_ang1 = {-PI / 2.0, 0.0, -PI / 2.0, 0.0, -PI / 2.0, 0.0, -PI / 3.0 * 2.0 + PI / 36.0, PI / 3.0 * 2.0 - PI / 36.0, 0.0, 0.0};
//連続動作用の初期値static HANDJnt prepare_jnt_ang1 = {2 * PI * 2 / 360, 0.0, 0.0, -5 * PI / 90, 2 * PI * 2 / 360, 0.0, 0.0, 0, 0.0, 0.0};
static HANDJnt prepare_jnt_ang1 = {0.0, 0.0,	   //左指
								   PI / 2, 0.0,	//中指
								   0.0, 0.0,	   //右指
								   -1.006147, 0.0, //左指旋回　右指旋回
								   0.0, 0.0};	  //手首旋回　手首屈曲

int hand02TrajDemo1(HANDJnt ref_jnt_ang, HANDJnt data, Object obj, double time, double *sensor, double *camera)
{
#define TRAJ_RAD PI / 4.0
#define TRAJ_RATE1 0.1
#define TRAJ_RATE2 1.0
#define TRAJ_RATE3 10.0

#define DEMO1_TIME1 0.5
#define DEMO1_TIME2 8.0
#define DEMO1_TIME3 9.0
	int jnt;
	double rate = 0.0;
	for (jnt = 0; jnt < HAND_JNT; jnt++)
		ref_jnt_ang[jnt] = prepare_jnt_ang1[jnt];

	//デバック用
	/*
double cube_d = 0.0555;
double x = camera[1];
double y = cube_d / 2 + r + 0.005;
double z = 0.105;
invKine(ref_jnt_ang, prepare_jnt_ang1, time, 0.0, 0.0, x, -y, z, 1);
invKine(ref_jnt_ang, prepare_jnt_ang1, time, 0.0, 0.0, x, y, z, 0);
*/

	//初期位置へ移動
	if (time < 2.0)
	{
		if (time < 0.5)
		{
			cog_x = camera[1];
			cog_y = camera[2];
		}
		double cube_d = 0.0555;			//キューブの直径WeiLong GTS2　　白いやつは　0.0565m
		double offset = 0.005;			//把持力に関係している　大きくすると強く把持してキューブが回転しないかもしれない。小さくてもキューブが把持できない。
		double xs = cog_x - cube_d / 3; //キューブ手前列の真ん中を持つ
		double ys = cube_d / 2 + r;		//- offset;// - 0.004; //+ 2 * offset;
		double zs = 0.105;
		prev_mfinger_x = cog_x - cube_d / 3;
		prev_mfinger_y = cube_d / 2 + r + 0.002;
		invKine(ref_jnt_ang, prepare_jnt_ang1, time, 0.0, 0.0, xs, -ys, zs, RIGHT_FINGER);
		invKine(ref_jnt_ang, prepare_jnt_ang1, time, 0.0, 0.0, xs, ys, zs, LEFT_FINGER);
		invKine(ref_jnt_ang, prepare_jnt_ang1, time, 0.0, 0.0, xs, prev_mfinger_y, 0.135, MIDDLE_FINGER);

		ref_jnt_ang[HAND02_M1] *= (0.5 * time);
		ref_jnt_ang[HAND02_M2] *= (0.5 * time);
		ref_jnt_ang[HAND02_M3] =  PI / 2 + (ref_jnt_ang[HAND02_M3] - PI / 2) * (0.5 * time);
		ref_jnt_ang[HAND02_M4] *= (0.5 * time);
		ref_jnt_ang[HAND02_M5] *= (0.5 * time);
		ref_jnt_ang[HAND02_M6] *= (0.5 * time);
		ref_jnt_ang[HAND02_M10] *= (0.5 * time);
	}

	//手首を利用した回転　逆運動学利用ver
	/*
	for(int i = 1; i <= 10 ; i++){
		double interval = 0.6;
		if(time < 2.0) break;
		if(time > 2.0 + interval * (i - 1) && time < 2.0 + interval * i - 0.2)
		{
			if(cog_write)
			{
				cog_x = camera[1];
				cog_y = camera[2];
				cog_write = 0;
			}
			Xturn2(ref_jnt_ang, prepare_jnt_ang1, TRAJ_RATE3, time, 2.0 + interval * (i - 1), camera[3], cog_x , cog_y);
			if(time > 2.0 + interval * i - 0.002 - 0.2)
			{
				cog_write = 1;
			}
			break;
		}
		else if(time < 2.0 + interval * i)
		{
			Yturn2(ref_jnt_ang, prepare_jnt_ang1, TRAJ_RATE3, time, 2.0 + interval * (i - 1) + 0.4 , camera[3], cog_x , cog_y);
			break;
		}
		//ref_jnt_ang[HAND02_M9] = cog_x;
	}
	*/
	// U面回転　連続動作
	for (int i = 1; i <= 10; i++)
	{
		double interval = 1.0;
		if (time < 2.0)
			break;
		if (time < 2.0 + interval * i - 0.4)
		{
			UturnKine(ref_jnt_ang, prepare_jnt_ang1, TRAJ_RATE3, time, 2.0 + interval * (i - 1), camera[3], camera);
			break;
		}
		else if (time < 2.0 + interval * i)
		{
			Xturn2(ref_jnt_ang, prepare_jnt_ang1, TRAJ_RATE3, time, 2.0 + interval * (i - 1) + 0.6, camera[3], camera);
			break;
		}
	}

	//Y回転
	/*
	if (time > 2.0 && time < 10.0)
	{
		Yturn2(ref_jnt_ang, prepare_jnt_ang1, TRAJ_RATE3, time, 2.0, camera[3], cog_x, cog_y);
	}
	*/
	//関数版
	/*if(time < 2.0)
	{
		return 0;
	}
	else if (time < 2.2)
	{
		Yturn(ref_jnt_ang, prepare_jnt_ang1, TRAJ_RATE3, time, 2.0, camera[3]);
	}
	else if (time < 2.7)
	{
		Xturn(ref_jnt_ang, prepare_jnt_ang1, TRAJ_RATE3, time, 2.2, camera[3]);
	}
	else if (time < 4.0)
	{
		Uturn(ref_jnt_ang, prepare_jnt_ang1, TRAJ_RATE3, time, 2.7, camera[3]);
	}*/

	//Uturn(ref_jnt_ang, prepare_jnt_ang1, TRAJ_RATE3, time, camera[3]);
	//関節角を保存
	for (jnt = 0; jnt < HAND_JNT; jnt++)
		prev_jnt_ang[jnt] = ref_jnt_ang[jnt];
	return 0;
}

//ロボットがじゃんけんで勝つ
//左指，中指，右指，左指旋回，右指旋回，手首旋回，手首屈曲
static HANDJnt prepare_jnt_ang2 = {PI / 4.0, PI / 2.0, PI / 4.0, PI / 2.0, PI / 4.0, PI / 2.0, 0.0, 0.0, 0.0, PI / 2.5 - PI / 8.0};
int hand02TrajDemo2(HANDJnt ref_jnt_ang, HANDJnt data, Object obj, double time, double *sensor, double *camera)
{
#define TIME 60

	int jnt;
	double rate = 0.0;

	//カメラの値の保存
	double c0;		   //camera[0]，x座標
	static double c0_; //camera[0]，x座標
	double c1;		   //camera[1]，y座標
	static double c1_; //camera[1]，y座標
	double c2;		   //camera[2]，面積
	static double c2_; //camera[2]，面積
	double c3;		   //camera[3]，手
	static double c3_; //camera[3]，手
	double dt = 0.001;
	double T = 0.1;
	double T1 = 0.01;
	static int flag;
	static int flag_j;
	static int local_time;

	for (jnt = 0; jnt < HAND_JNT; jnt++)
		ref_jnt_ang[jnt] = prepare_jnt_ang2[jnt];

	if (time < 0.005)
	{
		c0 = 0.0;
		c0_ = 0.0;
		c1 = 0.0;
		c1_ = 0.0;
		c2 = 0.0;
		c2_ = 0.0;
		c3 = 0.0;
		c3_ = 0.0;
		flag = 0;
		flag_j = 0;
		local_time = 0;
	}
	c0 = c0_ + 1 / T * (camera[0] - c0_) * dt;
	//	c1 = c1_ + 1/T*(camera[1]-c1_)*dt;
	c1 = c1_ + 1 / T1 * (camera[1] - c1_) * dt;
	c2 = c2_ + 1 / T * (camera[2] - c2_) * dt;
	c3 = c3_ + 1 / T1 * (camera[3] - c3_) * dt;
	//camera[4] = c3;//c0;
	//camera[5] = c1;
	//camera[6] = c2;
	c0_ = c0;
	c1_ = c1;
	c2_ = c2;
	c3_ = c3;

	if (time <= TIME)
	{
		if (time >= 0.1)
		{

			//手が見えているときに実行
			if (camera[2] > 10)
			{ //面積で判定

				//手首の運動：y座標を元に動く
				//				if(c0 > 500){
				ref_jnt_ang[HAND02_M10] = PI / 2.5;
				//				}else if(c0 < 10){
				//					ref_jnt_ang[HAND02_M10]=PI/2.5-PI/8.0;
				//				}else{
				//					ref_jnt_ang[HAND02_M10]=PI/2.5-PI/8.0*cos(PI/2*(c0-10.0)/490.0);
				//				}

				//じゃんけんをする指の運動：指の数を元に動く
				//camera[3]=1→グー
				//camera[3]=2→チョキ
				//camera[3]=3→パー
				//				if(c0>200){//y座標がある程度大きいとき（中心に近い）に，指を動かす
				//				if(ref_jnt_ang[HAND02_M10]>PI/2.5-PI/16.0){//y座標がある程度大きいとき（中心に近い）に，指を動かす
				if (camera[3] == 3)
				{ //パーのとき，チョキを出す
					ref_jnt_ang[HAND02_M1] = 0.0;
					ref_jnt_ang[HAND02_M2] = 0.0;
					ref_jnt_ang[HAND02_M3] = 0.0;
					ref_jnt_ang[HAND02_M4] = 0.0;
					flag_j = 4;
				}
				else if (camera[3] == 1)
				{ //グーのとき，パーを出す
					ref_jnt_ang[HAND02_M1] = 0.0;
					ref_jnt_ang[HAND02_M2] = 0.0;
					ref_jnt_ang[HAND02_M3] = 0.0;
					ref_jnt_ang[HAND02_M4] = 0.0;
					ref_jnt_ang[HAND02_M5] = 0.0;
					ref_jnt_ang[HAND02_M6] = 0.0;
					flag_j = 2;
				}
				else if (camera[3] == 2)
				{ //チョキのとき，グーを出す
					flag_j = 3;
				}
				else if (camera[3] == 0)
				{ //処理しないとき
					ref_jnt_ang[HAND02_M10] = PI / 2.5 - PI / 8.0;
				}
				//				}

				//手が見えていないときに実行
			}
			else
			{
				flag_j = 0;
			}
		}
	}

	//camera[4]=flag_j;
	return 0;
}

//ロボットと人間がじゃんけんであいこになる
//左指，中指，右指，左指旋回，右指旋回，手首旋回，手首屈曲
static HANDJnt prepare_jnt_ang3 = {PI / 4.0, PI / 2.0, PI / 4.0, PI / 2.0, PI / 4.0, PI / 2.0, 0.0, 0.0, PI / 2.0, 0.0};
int hand02TrajDemo3(HANDJnt ref_jnt_ang, HANDJnt data, Object obj, double time, double *sensor, double *camera)
{
	//	#define TIME	50

	int jnt;
	double rate = 0.0;

	//カメラの値の保存
	double c0;		   //camera[0]，x座標
	static double c0_; //camera[0]，x座標
	double c1;		   //camera[1]，y座標
	static double c1_; //camera[1]，y座標
	double c2;		   //camera[2]，面積
	static double c2_; //camera[2]，面積
	double c3;		   //camera[3]，変化数
	static double c3_; //camera[3]，変化数
	double dt = 0.001;
	double T = 0.1;
	double T1 = 0.01;
	static int flag;
	static int flag_j;
	static int local_time;

	for (jnt = 0; jnt < HAND_JNT; jnt++)
		ref_jnt_ang[jnt] = prepare_jnt_ang3[jnt];

	if (time < 0.005)
	{
		c0 = 0.0;
		c0_ = 0.0;
		c1 = 0.0;
		c1_ = 0.0;
		c2 = 0.0;
		c2_ = 0.0;
		c3 = 0.0;
		c3_ = 0.0;
		flag = 0;
		flag_j = 0;
		local_time = 0;
	}
	c0 = c0_ + 1 / T * (camera[0] - c0_) * dt;
	//	c1 = c1_ + 1/T*(camera[1]-c1_)*dt;
	c1 = c1_ + 1 / T1 * (camera[1] - c1_) * dt;
	c2 = c2_ + 1 / T * (camera[2] - c2_) * dt;
	c3 = c3_ + 1 / T1 * (camera[3] - c3_) * dt;
	camera[4] = c3; //c0;
	camera[5] = c1;
	camera[6] = c2;
	c0_ = c0;
	c1_ = c1;
	c2_ = c2;
	c3_ = c3;

	if (time <= TIME)
	{
		if (time >= 0.2)
		{
			//手が見えているときに実行
			if (camera[2] > 0)
			{
				//手首の運動：y座標を元に動く
				if (c1 > 400)
				{
					ref_jnt_ang[HAND02_M9] = -PI / 2.0;
				}
				else if (c1 < 300)
				{
					ref_jnt_ang[HAND02_M9] = -PI / 2.0 + PI / 10.0;
				}
				else
				{
					ref_jnt_ang[HAND02_M9] = -PI / 2.0 + PI / 10.0 * cos(PI / 2 * (c1 - 300.0) / 100.0);
				}

				//じゃんけんをする指の運動：指の数を元に動く
				if (camera[3] > 10)
				{ //パーのとき，パーを出す
					ref_jnt_ang[HAND02_M2] = 0.0;
					ref_jnt_ang[HAND02_M4] = 0.0;
					ref_jnt_ang[HAND02_M6] = 0.0;
					ref_jnt_ang[HAND02_M8] = 0.0;
					ref_jnt_ang[HAND02_M3] = 0.0;
					ref_jnt_ang[HAND02_M5] = 0.0;
					flag_j = 1;
				}
				else if (camera[3] <= 0)
				{ //グーのとき，グーを出す
					flag_j = 3;
				}
				else
				{ //チョキのとき，チョキを出す
					ref_jnt_ang[HAND02_M2] = 0.0;
					ref_jnt_ang[HAND02_M6] = 0.0;
					ref_jnt_ang[HAND02_M8] = 0.0;
					ref_jnt_ang[HAND02_M5] = 0.0;
					flag_j = 2;
				}
				//手が見えていないときに実行
			}
			else
			{
				flag = 0;
			}
		}
	}
	camera[0] = flag_j;
	return 0;
}

//////////////////////////////////////
// ハンド初期設定
//////////////////////////////////////
int handAppSet02(HAND *hand02)
{
	int jnt;
	hand02->base_homo = &hand_base_homo;
	hand02->ctrl_coef = &hand_ctrl_coef;
	if (app_num == 1)
		hand02->prepare_jnt_ang = prepare_jnt_ang1;
	else if (app_num == 2)
		hand02->prepare_jnt_ang = prepare_jnt_ang2;
	else if (app_num == 3)
		hand02->prepare_jnt_ang = prepare_jnt_ang3;
	//	hand->prepare_jnt_ang = prepare_jnt_ang;
	return 0;
}
