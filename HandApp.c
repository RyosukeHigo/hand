#include <stdio.h>
#include <math.h>
#include <Hand.h>
#include "App.h"

// 構造体宣言
HAND	hand;

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
HANDCtrlCoef hand_ctrl_coef = {{15.0, 20.0, 15.0, 20.0, 15.0, 20.0, 15.0, 15.0, 25.0, 25.0},	// Kp
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



//////////////////////////////////////////////////////
static HANDJnt	prepare_jnt_ang1 = {-PI/2.0, 0.0, -PI/2.0, 0.0, -PI/2.0, 0.0, -PI/3.0*2.0 + PI/36.0, PI/3.0*2.0 - PI/36.0, 0.0, 0.0};
int handTrajDemo1(HANDJnt ref_jnt_ang, double time)
{
#define TRAJ_RAD PI/4.0
#define TRAJ_RATE1 0.1
#define TRAJ_RATE2 1.0
#define TRAJ_RATE3 10.0

#define DEMO1_TIME1 5.0
#define DEMO1_TIME2 8.0
#define DEMO1_TIME3 9.0
	int jnt;
    double rate = 0.0;
	for(jnt=0;jnt<HAND_JNT;jnt++)   ref_jnt_ang[jnt] = prepare_jnt_ang1[jnt];
    /*if(time < DEMO1_TIME1){
    	ref_jnt_ang[HAND_M1] = TRAJ_RAD*(1.0-cos(2.0*PI*time*TRAJ_RATE1)) + prepare_jnt_ang1[HAND_M1];
        ref_jnt_ang[HAND_M3] = TRAJ_RAD*(1.0-cos(2.0*PI*time*TRAJ_RATE1)) + prepare_jnt_ang1[HAND_M3];
        ref_jnt_ang[HAND_M5] = TRAJ_RAD*(1.0-cos(2.0*PI*time*TRAJ_RATE1)) + prepare_jnt_ang1[HAND_M5];
        ref_jnt_ang[HAND_M2] = TRAJ_RAD*(1.0-cos(2.0*PI*time*TRAJ_RATE1)) + prepare_jnt_ang1[HAND_M2];
        ref_jnt_ang[HAND_M4] = TRAJ_RAD*(1.0-cos(2.0*PI*time*TRAJ_RATE1)) + prepare_jnt_ang1[HAND_M4];
        ref_jnt_ang[HAND_M6] = TRAJ_RAD*(1.0-cos(2.0*PI*time*TRAJ_RATE1)) + prepare_jnt_ang1[HAND_M6];
    }else if(time < DEMO1_TIME2){
        rate = 2.0*PI*DEMO1_TIME1*TRAJ_RATE1;
        ref_jnt_ang[HAND_M1] = TRAJ_RAD*(1.0-cos(2.0*PI*time*TRAJ_RATE2-rate)) + prepare_jnt_ang1[HAND_M1];
        ref_jnt_ang[HAND_M3] = TRAJ_RAD*(1.0-cos(2.0*PI*time*TRAJ_RATE2-rate)) + prepare_jnt_ang1[HAND_M3];
        ref_jnt_ang[HAND_M5] = TRAJ_RAD*(1.0-cos(2.0*PI*time*TRAJ_RATE2-rate)) + prepare_jnt_ang1[HAND_M5];
        ref_jnt_ang[HAND_M2] = TRAJ_RAD*(1.0-cos(2.0*PI*time*TRAJ_RATE2-rate)) + prepare_jnt_ang1[HAND_M2];
        ref_jnt_ang[HAND_M4] = TRAJ_RAD*(1.0-cos(2.0*PI*time*TRAJ_RATE2-rate)) + prepare_jnt_ang1[HAND_M4];
        ref_jnt_ang[HAND_M6] = TRAJ_RAD*(1.0-cos(2.0*PI*time*TRAJ_RATE2-rate)) + prepare_jnt_ang1[HAND_M6];
    }else if(time <DEMO1_TIME3){
        rate = 2.0*PI*DEMO1_TIME2*TRAJ_RATE2;
        ref_jnt_ang[HAND_M1] = TRAJ_RAD*(1.0-cos(2.0*PI*time*TRAJ_RATE3-rate)) + prepare_jnt_ang1[HAND_M1];
        ref_jnt_ang[HAND_M3] = TRAJ_RAD*(1.0-cos(2.0*PI*time*TRAJ_RATE3-rate)) + prepare_jnt_ang1[HAND_M3];
        ref_jnt_ang[HAND_M5] = TRAJ_RAD*(1.0-cos(2.0*PI*time*TRAJ_RATE3-rate)) + prepare_jnt_ang1[HAND_M5];
        ref_jnt_ang[HAND_M2] = TRAJ_RAD*(1.0-cos(2.0*PI*time*TRAJ_RATE3-rate)) + prepare_jnt_ang1[HAND_M2];
        ref_jnt_ang[HAND_M4] = TRAJ_RAD*(1.0-cos(2.0*PI*time*TRAJ_RATE3-rate)) + prepare_jnt_ang1[HAND_M4];
        ref_jnt_ang[HAND_M6] = TRAJ_RAD*(1.0-cos(2.0*PI*time*TRAJ_RATE3-rate)) + prepare_jnt_ang1[HAND_M6];
    }else{
        ref_jnt_ang[HAND_M2] =  0.0;
        ref_jnt_ang[HAND_M4] =  0.0;
        ref_jnt_ang[HAND_M6] =  0.0;
        ref_jnt_ang[HAND_M1] =  0.0;
        ref_jnt_ang[HAND_M3] =  0.0;
        ref_jnt_ang[HAND_M5] =  0.0;
    }*/
	return 0;
}

static HANDJnt	prepare_jnt_ang2 = {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0};
int handTrajDemo2(HANDJnt ref_jnt_ang, double time)
{
	int jnt;
    double rate = 0.0;
	for(jnt=0;jnt<HAND_JNT;jnt++)   ref_jnt_ang[jnt] = prepare_jnt_ang2[jnt];
    if(time < 1.0){
    	ref_jnt_ang[HAND_M1] = -PI/2.0;	
        ref_jnt_ang[HAND_M3] = -PI/2.0;
        ref_jnt_ang[HAND_M5] = -PI/2.0;
        ref_jnt_ang[HAND_M7] = -PI/3.0*2.0 + PI/36.0;
        ref_jnt_ang[HAND_M8] =  PI/3.0*2.0 - PI/36.0;
    }else if(time < 2.0){
        ref_jnt_ang[HAND_M1] = -PI/2.0;
        ref_jnt_ang[HAND_M3] =  0.0;	
        ref_jnt_ang[HAND_M5] = -PI/2.0;
        ref_jnt_ang[HAND_M2] =  0.0;
        ref_jnt_ang[HAND_M4] = PI/2.0;	
        ref_jnt_ang[HAND_M6] =  0.0;	
        ref_jnt_ang[HAND_M7] = -PI/3.0*2.0 + PI/36.0;
        ref_jnt_ang[HAND_M8] =  PI/3.0*2.0 - PI/36.0;
    }else if(time <3.0){
        ref_jnt_ang[HAND_M1] = -PI/8.0;
        ref_jnt_ang[HAND_M3] =  0.0;	
        ref_jnt_ang[HAND_M5] = -PI/2.0;
        ref_jnt_ang[HAND_M2] = PI/2.0;
        ref_jnt_ang[HAND_M4] = PI/2.0;	
        ref_jnt_ang[HAND_M6] =  0.0;	
        ref_jnt_ang[HAND_M7] = -PI/3.0*2.0 + PI/36.0;
        ref_jnt_ang[HAND_M8] =  PI/3.0*2.0 - PI/36.0;
    }else if(time <4.0){
        ref_jnt_ang[HAND_M1] = -PI/8.0;
        ref_jnt_ang[HAND_M3] =  0.0;	
        ref_jnt_ang[HAND_M5] =  0.0;
        ref_jnt_ang[HAND_M2] = PI/2.0;
        ref_jnt_ang[HAND_M4] = PI/2.0;	
        ref_jnt_ang[HAND_M6] = PI/2.0;	
        ref_jnt_ang[HAND_M7] = -PI/3.0*2.0 + PI/36.0;
        ref_jnt_ang[HAND_M8] =  PI/3.0*2.0 - PI/36.0;
    }else if(time <5.0){
        ref_jnt_ang[HAND_M1] = -PI/2.0;	
        ref_jnt_ang[HAND_M3] = -PI/2.0;		
        ref_jnt_ang[HAND_M5] = -PI/2.0;		
        ref_jnt_ang[HAND_M2] = 0.0;
        ref_jnt_ang[HAND_M4] = 0.0;	
        ref_jnt_ang[HAND_M6] = 0.0;	
        ref_jnt_ang[HAND_M7] = -PI/3.0*2.0 + PI/36.0;
        ref_jnt_ang[HAND_M8] =  PI/3.0*2.0 - PI/36.0;
    }else if(time <6.0){
        ref_jnt_ang[HAND_M1] =  -PI/8.0;
        ref_jnt_ang[HAND_M3] =  0.0;	
        ref_jnt_ang[HAND_M5] =  0.0;
        ref_jnt_ang[HAND_M2] = PI/2.0;
        ref_jnt_ang[HAND_M4] = PI/2.0;	
        ref_jnt_ang[HAND_M6] = PI/2.0;	
        ref_jnt_ang[HAND_M7] = -PI/3.0*2.0 + PI/36.0;
        ref_jnt_ang[HAND_M8] =  PI/3.0*2.0 - PI/36.0;
    }else{
        ref_jnt_ang[HAND_M1] = -PI/2.0;	
        ref_jnt_ang[HAND_M3] = -PI/2.0;		
        ref_jnt_ang[HAND_M5] = -PI/2.0;		
        ref_jnt_ang[HAND_M2] = 0.0;
        ref_jnt_ang[HAND_M4] = 0.0;	
        ref_jnt_ang[HAND_M6] = 0.0;	
        ref_jnt_ang[HAND_M7] = -PI/3.0*2.0 + PI/36.0;
        ref_jnt_ang[HAND_M8] =  PI/3.0*2.0 - PI/36.0;
    }
    return 0;
}

static HANDJnt	prepare_jnt_ang3 = {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0};
int handTrajDemo3(HANDJnt ref_jnt_ang, double time)
{
#define DEMO3_TIME1  0.5
#define DEMO3_TIME2  0.55
#define DEMO3_TIME3  0.6
#define DEMO3_TIME4  0.65
#define DEMO3_TIME5  0.7
#define DEMO3_TIME6  0.75
#define DEMO3_TIME7  0.8
#define DEMO3_TIME8  (DEMO3_TIME7+0.1)
#define DEMO3_TIME9  (DEMO3_TIME8+0.05)
#define DEMO3_TIME10 (DEMO3_TIME9+0.05)
#define DEMO3_TIME11 (DEMO3_TIME10+0.05)
#define DEMO3_TIME12 (DEMO3_TIME11+0.05)
#define DEMO3_TIME13 (DEMO3_TIME12+0.05)
#define DEMO3_TIME14 (DEMO3_TIME13+0.05)
#define DEMO3_TIME15 (DEMO3_TIME14+0.1)
#define DEMO3_TIME16 (DEMO3_TIME15+0.05)
#define DEMO3_TIME17 (DEMO3_TIME16+0.2)
#define DEMO3_TIME18 (DEMO3_TIME17+0.5)
#define DEMO3_TIME19 (DEMO3_TIME18+0.5)
	int jnt;
    double rate = 0.0;
	for(jnt=0;jnt<HAND_JNT;jnt++)   ref_jnt_ang[jnt] = prepare_jnt_ang3[jnt];
    if(time < DEMO3_TIME1){
        ref_jnt_ang[HAND_M1] = -PI/2.0;
        ref_jnt_ang[HAND_M3] = -PI/2.0;
        ref_jnt_ang[HAND_M5] = -PI/2.0;
        ref_jnt_ang[HAND_M2] =  0.0;
        ref_jnt_ang[HAND_M4] =  0.0;
        ref_jnt_ang[HAND_M6] =  0.0;
    }else if(time < DEMO3_TIME2){
        ref_jnt_ang[HAND_M1] = -PI/2.0;
        ref_jnt_ang[HAND_M3] = -PI/2.0;
        ref_jnt_ang[HAND_M5] = -PI/2.0 + PI/4.0*3.0*sin(PI/2.0*(time -DEMO3_TIME1)/(DEMO3_TIME2-DEMO3_TIME1));
        ref_jnt_ang[HAND_M2] =  0.0;
        ref_jnt_ang[HAND_M4] =  0.0;
        ref_jnt_ang[HAND_M6] =  0.0;
    }else if(time < DEMO3_TIME3){
        ref_jnt_ang[HAND_M1] = -PI/2.0;
        ref_jnt_ang[HAND_M3] = -PI/2.0;
        ref_jnt_ang[HAND_M5] =  PI/4.0;
        ref_jnt_ang[HAND_M2] =  0.0;
        ref_jnt_ang[HAND_M4] =  0.0;
        ref_jnt_ang[HAND_M6] =  0.0 + PI/2.0*sin(PI/2.0*(time -DEMO3_TIME2)/(DEMO3_TIME3-DEMO3_TIME2));
    }else if(time < DEMO3_TIME4){
        ref_jnt_ang[HAND_M1] = -PI/2.0 + PI/4.0*3.0*sin(PI/2.0*(time -DEMO3_TIME3)/(DEMO3_TIME4-DEMO3_TIME3));
        ref_jnt_ang[HAND_M3] = -PI/2.0;
        ref_jnt_ang[HAND_M5] =  PI/4.0;
        ref_jnt_ang[HAND_M2] =  0.0;
        ref_jnt_ang[HAND_M4] =  0.0;
        ref_jnt_ang[HAND_M6] =  PI/2.0;
    }else if(time < DEMO3_TIME5){
        ref_jnt_ang[HAND_M1] =  PI/4.0;
        ref_jnt_ang[HAND_M3] = -PI/2.0;
        ref_jnt_ang[HAND_M5] =  PI/4.0;
        ref_jnt_ang[HAND_M2] =  0.0  + PI/2.0*sin(PI/2.0*(time -DEMO3_TIME4)/(DEMO3_TIME5-DEMO3_TIME4));
        ref_jnt_ang[HAND_M4] =  0.0;
        ref_jnt_ang[HAND_M6] =  PI/2.0;
    }else if(time < DEMO3_TIME6){
        ref_jnt_ang[HAND_M1] =  PI/4.0;
        ref_jnt_ang[HAND_M3] =  -PI/2.0 + PI/4.0*3.0*sin(PI/2.0*(time -DEMO3_TIME5)/(DEMO3_TIME6-DEMO3_TIME5));
        ref_jnt_ang[HAND_M5] =  PI/4.0;
        ref_jnt_ang[HAND_M2] =  PI/2.0;
        ref_jnt_ang[HAND_M4] =  0.0;
        ref_jnt_ang[HAND_M6] =  PI/2.0;
    }else if(time < DEMO3_TIME7){
        ref_jnt_ang[HAND_M1] =  PI/4.0;
        ref_jnt_ang[HAND_M3] =  PI/4.0;
        ref_jnt_ang[HAND_M5] =  PI/4.0;
        ref_jnt_ang[HAND_M2] =  PI/2.0;
        ref_jnt_ang[HAND_M4] =  0.0  + PI/2.0*sin(PI/2.0*(time -DEMO3_TIME6)/(DEMO3_TIME7-DEMO3_TIME6));
        ref_jnt_ang[HAND_M6] =  PI/2.0;
    }else if(time < DEMO3_TIME8){
        ref_jnt_ang[HAND_M1] =  PI/4.0;
        ref_jnt_ang[HAND_M3] =  PI/4.0;
        ref_jnt_ang[HAND_M5] =  PI/4.0;
        ref_jnt_ang[HAND_M2] =  PI/2.0;
        ref_jnt_ang[HAND_M4] =  PI/2.0;
        ref_jnt_ang[HAND_M6] =  PI/2.0;
    }else if(time < DEMO3_TIME9){
        ref_jnt_ang[HAND_M1] =  PI/4.0;
        ref_jnt_ang[HAND_M3] =  PI/4.0;
        ref_jnt_ang[HAND_M5] =  PI/4.0;
        ref_jnt_ang[HAND_M2] =  PI/2.0;
        ref_jnt_ang[HAND_M4] =  PI/2.0 - PI/2.0*sin(PI/2.0*(time -DEMO3_TIME8)/(DEMO3_TIME9-DEMO3_TIME8));
        ref_jnt_ang[HAND_M6] =  PI/2.0;
    }else if(time < DEMO3_TIME10){
        ref_jnt_ang[HAND_M1] =  PI/4.0;
        ref_jnt_ang[HAND_M3] =  PI/4.0 -  PI/4.0*3.0*sin(PI/2.0*(time -DEMO3_TIME9)/(DEMO3_TIME10-DEMO3_TIME9));
        ref_jnt_ang[HAND_M5] =  PI/4.0;
        ref_jnt_ang[HAND_M2] =  PI/2.0;
        ref_jnt_ang[HAND_M4] =  0.0;
        ref_jnt_ang[HAND_M6] =  PI/2.0;
    }else if(time < DEMO3_TIME11){
        ref_jnt_ang[HAND_M1] =  PI/4.0;
        ref_jnt_ang[HAND_M3] = -PI/2.0;
        ref_jnt_ang[HAND_M5] =  PI/4.0;
        ref_jnt_ang[HAND_M2] =  PI/2.0  - PI/2.0*sin(PI/2.0*(time -DEMO3_TIME10)/(DEMO3_TIME11-DEMO3_TIME10));
        ref_jnt_ang[HAND_M4] =  0.0;
        ref_jnt_ang[HAND_M6] =  PI/2.0;
    }else if(time < DEMO3_TIME12){
        ref_jnt_ang[HAND_M1] =  PI/4.0 - PI/4.0*3.0*sin(PI/2.0*(time -DEMO3_TIME11)/(DEMO3_TIME12-DEMO3_TIME11));
        ref_jnt_ang[HAND_M3] = -PI/2.0;
        ref_jnt_ang[HAND_M5] =  PI/4.0;
        ref_jnt_ang[HAND_M2] =  0.0;
        ref_jnt_ang[HAND_M4] =  0.0;
        ref_jnt_ang[HAND_M6] =  PI/2.0;
    }else if(time < DEMO3_TIME13){
        ref_jnt_ang[HAND_M1] = -PI/2.0;
        ref_jnt_ang[HAND_M3] = -PI/2.0;
        ref_jnt_ang[HAND_M5] =  PI/4.0;
        ref_jnt_ang[HAND_M2] =  0.0;
        ref_jnt_ang[HAND_M4] =  0.0;
        ref_jnt_ang[HAND_M6] =  PI/2.0 - PI/2.0*sin(PI/2.0*(time -DEMO3_TIME12)/(DEMO3_TIME13-DEMO3_TIME12));
    }else if(time < DEMO3_TIME14){
        ref_jnt_ang[HAND_M1] = -PI/2.0;
        ref_jnt_ang[HAND_M3] = -PI/2.0;
        ref_jnt_ang[HAND_M5] =  PI/4.0 - PI/4.0*3.0*sin(PI/2.0*(time -DEMO3_TIME13)/(DEMO3_TIME14-DEMO3_TIME13));
        ref_jnt_ang[HAND_M2] =  0.0;
        ref_jnt_ang[HAND_M4] =  0.0;
        ref_jnt_ang[HAND_M6] =  0.0;
    }else if(time < DEMO3_TIME15){
        ref_jnt_ang[HAND_M1] = -PI/2.0;
        ref_jnt_ang[HAND_M3] = -PI/2.0;
        ref_jnt_ang[HAND_M5] = -PI/2.0;
        ref_jnt_ang[HAND_M2] =  0.0;
        ref_jnt_ang[HAND_M4] =  0.0;
        ref_jnt_ang[HAND_M6] =  0.0;
    }else if(time < DEMO3_TIME16){
        ref_jnt_ang[HAND_M1] = -PI/2.0;
        ref_jnt_ang[HAND_M3] = -PI/2.0;
        ref_jnt_ang[HAND_M5] = -PI/2.0;
        ref_jnt_ang[HAND_M2] =  0.0;
        ref_jnt_ang[HAND_M4] =  0.0;
        ref_jnt_ang[HAND_M6] =  0.0;
        ref_jnt_ang[HAND_M7] =  0.0;
        ref_jnt_ang[HAND_M8] =  PI/3.0*2.0;
    }else if(time < DEMO3_TIME17){
        ref_jnt_ang[HAND_M1] = -PI/2.0;
        ref_jnt_ang[HAND_M3] = -PI/2.0;
        ref_jnt_ang[HAND_M5] = -PI/2.0;
        ref_jnt_ang[HAND_M2] =  0.0;
        ref_jnt_ang[HAND_M4] =  0.0;
        ref_jnt_ang[HAND_M6] =  0.0;
        ref_jnt_ang[HAND_M7] =  0.0        - PI/3.0*2.0*sin(PI*(time -DEMO3_TIME16)/(DEMO3_TIME17-DEMO3_TIME16));
        ref_jnt_ang[HAND_M8] =  PI/3.0*2.0 - PI/3.0*2.0*sin(PI*(time -DEMO3_TIME16)/(DEMO3_TIME17-DEMO3_TIME16));
    }else if(time < DEMO3_TIME18){
        ref_jnt_ang[HAND_M1] = -PI/2.0;
        ref_jnt_ang[HAND_M3] = -PI/2.0;
        ref_jnt_ang[HAND_M5] = -PI/2.0;
        ref_jnt_ang[HAND_M2] =  0.0;
        ref_jnt_ang[HAND_M4] =  0.0;
        ref_jnt_ang[HAND_M6] =  0.0;
        ref_jnt_ang[HAND_M7] =  -PI/2.0;
        ref_jnt_ang[HAND_M8] =   PI/2.0;
        ref_jnt_ang[HAND_M9]  = 0.0;
        ref_jnt_ang[HAND_M10] = PI/3.0*sin(2.0*PI*(time -DEMO3_TIME17)/(DEMO3_TIME18-DEMO3_TIME17));
    }else if(time < DEMO3_TIME19){
        ref_jnt_ang[HAND_M1] = -PI/2.0;
        ref_jnt_ang[HAND_M3] = -PI/2.0;
        ref_jnt_ang[HAND_M5] = -PI/2.0;
        ref_jnt_ang[HAND_M2] =  0.0;
        ref_jnt_ang[HAND_M4] =  0.0;
        ref_jnt_ang[HAND_M6] =  0.0;
        ref_jnt_ang[HAND_M7] =  -PI/2.0;
        ref_jnt_ang[HAND_M8] =   PI/2.0;
//        ref_jnt_ang[HAND_M9]  = -PI/3.0*sin(2.0*PI*(time -DEMO3_TIME18)/(DEMO3_TIME19-DEMO3_TIME18));
        ref_jnt_ang[HAND_M9]  = -PI/5.0*sin(2.0*PI*(time -DEMO3_TIME18)/(DEMO3_TIME19-DEMO3_TIME18));
        ref_jnt_ang[HAND_M10] = 0.0;
    }
    return 0;
}


//////////////////////////////////////
// ハンド初期設定
//////////////////////////////////////
int handAppSet(HAND *hand)
{
	int jnt;
	hand->base_homo = &hand_base_homo;
	hand->ctrl_coef = &hand_ctrl_coef;
	if(app_num==1)	hand->prepare_jnt_ang = prepare_jnt_ang1;
	else if(app_num==2)	hand->prepare_jnt_ang = prepare_jnt_ang2;
	else if(app_num==3)	hand->prepare_jnt_ang = prepare_jnt_ang3;
//	hand->prepare_jnt_ang = prepare_jnt_ang;
	return 0;
}
