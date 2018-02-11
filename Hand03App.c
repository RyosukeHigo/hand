#include <stdio.h>
#include <math.h>
#include <Hand.h>
#include "App.h"

// 構造体宣言
HAND	hand03;

// グローバル座標におけるハンド位置
static HomoMat hand_base_homo ={{1.0, 0.0, 0.0},
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
static HANDCtrlCoef hand_ctrl_coef = {{15.0, 20.0, 15.0, 20.0, 15.0, 20.0, 15.0, 15.0, 25.0, 25.0},	// Kp
								{0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0},				// Ti
								{60.0, 75.0, 60.0, 75.0, 60.0, 75.0, 60.0, 60.0, 75.0, 75.0},	// Td
								{0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0},				// Cf
								1.0};															// Kg

// デモ番号
#ifndef MATLAB_MEX_FILE
extern unsigned int     app_num;
#else
extern unsigned int     app_num = 0;
#endif

//static HANDJnt	prepare_jnt_ang = {-PI/2.0, 0.0, -PI/2.0, 0.0, -PI/2.0, 0.0, -PI/3.0*2.0 + PI/36.0, -PI/3.0*2.0 + PI/36.0, 0.0, 0.0};
//static HANDJnt	prepare_jnt_ang;


//指番号03用
// ref_jnt_ang[HAND_M1]：中指根元リンク
// ref_jnt_ang[HAND_M2]：中指先端リンク
// ref_jnt_ang[HAND_M3]：右指根元リンク
// ref_jnt_ang[HAND_M4]：右指先端リンク
// ref_jnt_ang[HAND_M5]：左指根元リンク
// ref_jnt_ang[HAND_M6]：左指先端リンク
// ref_jnt_ang[HAND_M7]：左指旋回軸（マイナス方向のみ）
// ref_jnt_ang[HAND_M8]：右指旋回軸（プラス方向のみ）
// ref_jnt_ang[HAND_M9]：手首屈曲軸
// ref_jnt_ang[HAND_M10]：手首旋回軸

// 初期姿勢について　03用
// static HANDJnt	prepare_jnt_ang1 = {-PI/2.0, 0.0, -PI/2.0, 0.0, -PI/2.0, 0.0, -PI/3.0*2.0 + PI/36.0, PI/3.0*2.0 - PI/36.0, 0.0, 0.0};
// static HANDJnt	prepare_jnt_ang1 = {左指根元リンク, 左指先端リンク, 中指根元リンク, 中指先端リンク, 
//										右指根元リンク, 右指先端リンク, 左指旋回, 右指旋回, 手首屈曲, 手首旋回};



//////////////////////////////////////////////////////
//ロボットがじゃんけんで勝つ
//左指，中指，右指，左指旋回，右指旋回，手首屈曲，手首旋回
static HANDJnt	prepare_jnt_ang1 = {PI/4.0, PI/2.0, 0.0, PI/2.0, PI/4.0, PI/2.0, 0.0, PI/4.0, -PI/2.0, 0.0};
int hand03TrajDemo1(HANDJnt ref_jnt_ang, HANDJnt data, Object obj, double time, double *sensor, double *camera)
{
	int jnt;
    double rate = 0.0;

	for(jnt=0;jnt<HAND_JNT;jnt++)   ref_jnt_ang[jnt] = prepare_jnt_ang1[jnt];

	return 0;
}


//ロボットがじゃんけんで負ける
//左指，中指，右指，左指旋回，右指旋回，手首屈曲，手首旋回
static HANDJnt	prepare_jnt_ang2 = {PI/4.0, PI/2.0, PI/4.0, PI/2.0, PI/4.0, PI/2.0, 0.0, 0.0, PI/2.0, 0.0};
int hand03TrajDemo2(HANDJnt ref_jnt_ang, HANDJnt data, Object obj, double time, double *sensor, double *camera)
//int hand03TrajDemo2(HANDJnt ref_jnt_ang, double time, double *sensor, double *camera)
{
	int jnt;
    double rate = 0.0;

	for(jnt=0;jnt<HAND_JNT;jnt++)   ref_jnt_ang[jnt] = prepare_jnt_ang2[jnt];

	return 0;
}


//ロボットと人間がじゃんけんであいこになる
//左指，中指，右指，左指旋回，右指旋回，手首屈曲，手首旋回
static HANDJnt	prepare_jnt_ang3 = {PI/4.0, PI/2.0, PI/4.0, PI/2.0, PI/4.0, PI/2.0, 0.0, 0.0, PI/2.0, 0.0};
int hand03TrajDemo3(HANDJnt ref_jnt_ang, HANDJnt data, Object obj, double time, double *sensor, double *camera)
{
	int jnt;
    double rate = 0.0;

	for(jnt=0;jnt<HAND_JNT;jnt++)   ref_jnt_ang[jnt] = prepare_jnt_ang3[jnt];

	return 0;
}


//////////////////////////////////////
// ハンド初期設定
//////////////////////////////////////
int handAppSet03(HAND *hand03)
{
	int jnt;
	hand03->base_homo = &hand_base_homo;
	hand03->ctrl_coef = &hand_ctrl_coef;
	if(app_num==1)	hand03->prepare_jnt_ang = prepare_jnt_ang1;
	else if(app_num==2)	hand03->prepare_jnt_ang = prepare_jnt_ang2;
	else if(app_num==3)	hand03->prepare_jnt_ang = prepare_jnt_ang3;
//	hand->prepare_jnt_ang = prepare_jnt_ang;
	return 0;
}
