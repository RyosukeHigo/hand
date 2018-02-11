#include <stdio.h>
#include <math.h>
#include <AVS.h>
#include "App.h"

// 構造体宣言
AVSALL	avs;

// グローバル座標におけるAVS位置
static HomoMat avs_base_homo[AVS_NUM] ={{{0.0, -1.0, 0.0},
										{1.0, 0.0, 0.0},
		                                {0.0, 0.0, 1.0},
										{0.45, 0.36, 0.14}},
										{{0.0, -1.0, 0.0},
										{1.0, 0.0, 0.0},
										{0.0, 0.0, 1.0},
										{0.45, -0.36, 0.14}}};
// 制御ゲイン
static AVSCtrlCoefAll	avs_ctrl_coef = {{6000.0, 6000.0, 6000.0, 6000.0},    // Kp
									   {0.0, 0.0, 0.0, 0.0},    // Ti
									   {200000.0, 200000.0, 200000.0, 200000.0},      // Td
									   {40.0, 40.0, 40.0, 40.0},     // IcKp
//									   1.8};                 // Kg
									   10.0};                 // Kg
/*
static AVSCtrlCoefAll	avs_ctrl_coef = {{6000.0, 6000.0, 6000.0, 6000.0},    // Kp
									   {0.0, 0.0, 0.0, 0.0},    // Ti
									   {200000.0, 200000.0, 200000.0, 200000.0},      // Td
									   {40.0, 40.0, 40.0, 40.0},     // IcKp
//									   1.8};                 // Kg
									   20.0};                 // Kg
									   */
// 初期姿勢
//static AVSJntAll	avs_prepare_jnt_ang = {PI/4, -PI/4, -PI/4, PI/4};		// スローイングアーム方向
//static AVSJntAll	avs_prepare_jnt_ang = {-PI/4, -PI/4, PI/4, PI/4};		// バッティングアーム方向
//static AVSJntAll	avs_prepare_jnt_ang = {-PI/4, PI/4, PI/4, -PI/4};		// バッティングアーム方向
static AVSJntAll	avs_prepare_jnt_ang = {-PI/4, PI/6, -PI/4, -PI/6};


//////////////////////////////////////////////////////
int avsTrajApp(AVSJntAll ref_jnt_ang, double time)
{
	int jnt;

////////////////////////
// 時系列軌道
////////////////////////
#if	0
#define AVS_TRAJ_RAD PI/4.0
#define AVS_TRAJ_RAD2 PI/6.0
#define AVS_TRAJ_RATE 1.0
    ref_jnt_ang[AVS1_PAN] = -AVS_TRAJ_RAD*(1.0-cos(2.0*PI*time*AVS_TRAJ_RATE)) + avs_prepare_jnt_ang[AVS_M1];
    ref_jnt_ang[AVS1_TILT] = AVS_TRAJ_RAD2*(1.0-cos(2.0*PI*time*AVS_TRAJ_RATE)) + avs_prepare_jnt_ang[AVS_M2];
    ref_jnt_ang[AVS2_PAN] = AVS_TRAJ_RAD*(1.0-cos(2.0*PI*time*AVS_TRAJ_RATE)) + avs_prepare_jnt_ang[AVS_M3];
    ref_jnt_ang[AVS2_TILT] = -AVS_TRAJ_RAD2*(1.0-cos(2.0*PI*time*AVS_TRAJ_RATE)) + avs_prepare_jnt_ang[AVS_M4];
#endif

/////////////////////////////
// 対象を見失ったときの軌道
/////////////////////////////
	for(jnt=0;jnt<AVS_JNT_ALL;jnt++)	ref_jnt_ang[jnt] = avs_prepare_jnt_ang[jnt];

	return 0;
}

////////////////////////
// ビジュアルサーボ
////////////////////////
int avsVisualTrajApp(AVSImgCenAll ref_img_center, double time)
{
	// 対象が画像中心にくるように制御
	ref_img_center[AVS1_PAN] = 0.0;
	ref_img_center[AVS1_TILT] = 0.0;
	ref_img_center[AVS2_PAN] = 0.0;
	ref_img_center[AVS2_TILT] = 0.0;
	return 0;
}


//////////////////////////////////////
// アクティブビジョン初期設定
//////////////////////////////////////
int avsAppSet(AVSALL *avs)
{
	int jnt, num;
	avs->base_homo = avs_base_homo;
	avs->ctrl_coef = &avs_ctrl_coef;
	avs->prepare_jnt_ang = avs_prepare_jnt_ang;
	return 0;
}
