#include <stdio.h>
#include <math.h>
#include <Hand.h>
#include "App.h"

// �\���̐錾
HAND	hand02;

// �O���[�o�����W�ɂ�����n���h�ʒu
static HomoMat hand_base_homo ={{1.0, 0.0, 0.0},
		                        {0.0, 1.0, 0.0},
		                        {0.0, 0.0, 1.0},
								{0.0, 0.0, 0.0}};
// ����Q�C��
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

// �f���ԍ�
#ifndef MATLAB_MEX_FILE
extern unsigned int     app_num;
#else
extern unsigned int     app_num = 0;
#endif

//static HANDJnt	prepare_jnt_ang = {-PI/2.0, 0.0, -PI/2.0, 0.0, -PI/2.0, 0.0, -PI/3.0*2.0 + PI/36.0, -PI/3.0*2.0 + PI/36.0, 0.0, 0.0};
//static HANDJnt	prepare_jnt_ang;



//�w�ԍ�02�p
// ref_jnt_ang[HAND_M1]�F���w���������N
// ref_jnt_ang[HAND_M2]�F���w��[�����N
// ref_jnt_ang[HAND_M3]�F�E�w���������N
// ref_jnt_ang[HAND_M4]�F�E�w��[�����N
// ref_jnt_ang[HAND_M5]�F���w���������N
// ref_jnt_ang[HAND_M6]�F���w��[�����N
// ref_jnt_ang[HAND_M7]�F���w���񎲁i�}�C�i�X�����̂݁j
// ref_jnt_ang[HAND_M8]�F�E�w���񎲁i�v���X�����̂݁j
// ref_jnt_ang[HAND_M9]�F�����Ȏ�
// ref_jnt_ang[HAND_M10]�F������




//////////////////////////////////////////////////////
static HANDJnt	prepare_jnt_ang1 = {-PI/2.0, 0.0, -PI/2.0, 0.0, -PI/2.0, 0.0, -PI/3.0*2.0 + PI/36.0, PI/3.0*2.0 - PI/36.0, 0.0, 0.0};
int hand02TrajDemo1(HANDJnt ref_jnt_ang, double time, double *sensor, double *camera)
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
    if(time < DEMO1_TIME1){
    	ref_jnt_ang[HAND02_M1] = TRAJ_RAD*(1.0-cos(2.0*PI*time*TRAJ_RATE1)) + prepare_jnt_ang1[HAND02_M1];
        ref_jnt_ang[HAND02_M3] = TRAJ_RAD*(1.0-cos(2.0*PI*time*TRAJ_RATE1)) + prepare_jnt_ang1[HAND02_M3];
        ref_jnt_ang[HAND02_M5] = TRAJ_RAD*(1.0-cos(2.0*PI*time*TRAJ_RATE1)) + prepare_jnt_ang1[HAND02_M5];
        ref_jnt_ang[HAND02_M2] = TRAJ_RAD*(1.0-cos(2.0*PI*time*TRAJ_RATE1)) + prepare_jnt_ang1[HAND02_M2];
        ref_jnt_ang[HAND02_M4] = TRAJ_RAD*(1.0-cos(2.0*PI*time*TRAJ_RATE1)) + prepare_jnt_ang1[HAND02_M4];
        ref_jnt_ang[HAND02_M6] = TRAJ_RAD*(1.0-cos(2.0*PI*time*TRAJ_RATE1)) + prepare_jnt_ang1[HAND02_M6];
    }else if(time < DEMO1_TIME2){
        rate = 2.0*PI*DEMO1_TIME1*TRAJ_RATE1;
        ref_jnt_ang[HAND02_M1] = TRAJ_RAD*(1.0-cos(2.0*PI*time*TRAJ_RATE2-rate)) + prepare_jnt_ang1[HAND02_M1];
        ref_jnt_ang[HAND02_M3] = TRAJ_RAD*(1.0-cos(2.0*PI*time*TRAJ_RATE2-rate)) + prepare_jnt_ang1[HAND02_M3];
        ref_jnt_ang[HAND02_M5] = TRAJ_RAD*(1.0-cos(2.0*PI*time*TRAJ_RATE2-rate)) + prepare_jnt_ang1[HAND02_M5];
        ref_jnt_ang[HAND02_M2] = TRAJ_RAD*(1.0-cos(2.0*PI*time*TRAJ_RATE2-rate)) + prepare_jnt_ang1[HAND02_M2];
        ref_jnt_ang[HAND02_M4] = TRAJ_RAD*(1.0-cos(2.0*PI*time*TRAJ_RATE2-rate)) + prepare_jnt_ang1[HAND02_M4];
        ref_jnt_ang[HAND02_M6] = TRAJ_RAD*(1.0-cos(2.0*PI*time*TRAJ_RATE2-rate)) + prepare_jnt_ang1[HAND02_M6];
    }else if(time <DEMO1_TIME3){
        rate = 2.0*PI*DEMO1_TIME2*TRAJ_RATE2;
        ref_jnt_ang[HAND02_M1] = TRAJ_RAD*(1.0-cos(2.0*PI*time*TRAJ_RATE3-rate)) + prepare_jnt_ang1[HAND02_M1];
        ref_jnt_ang[HAND02_M3] = TRAJ_RAD*(1.0-cos(2.0*PI*time*TRAJ_RATE3-rate)) + prepare_jnt_ang1[HAND02_M3];
        ref_jnt_ang[HAND02_M5] = TRAJ_RAD*(1.0-cos(2.0*PI*time*TRAJ_RATE3-rate)) + prepare_jnt_ang1[HAND02_M5];
        ref_jnt_ang[HAND02_M2] = TRAJ_RAD*(1.0-cos(2.0*PI*time*TRAJ_RATE3-rate)) + prepare_jnt_ang1[HAND02_M2];
        ref_jnt_ang[HAND02_M4] = TRAJ_RAD*(1.0-cos(2.0*PI*time*TRAJ_RATE3-rate)) + prepare_jnt_ang1[HAND02_M4];
        ref_jnt_ang[HAND02_M6] = TRAJ_RAD*(1.0-cos(2.0*PI*time*TRAJ_RATE3-rate)) + prepare_jnt_ang1[HAND02_M6];
    }else{
        ref_jnt_ang[HAND02_M2] =  0.0;
        ref_jnt_ang[HAND02_M4] =  0.0;
        ref_jnt_ang[HAND02_M6] =  0.0;
        ref_jnt_ang[HAND02_M1] =  0.0;
        ref_jnt_ang[HAND02_M3] =  0.0;
        ref_jnt_ang[HAND02_M5] =  0.0;
    }
	return 0;
}

//���w�C�E�w�C���w�C���w����C�E�w����C�����ȁC������
static HANDJnt	prepare_jnt_ang2 = {-PI/2.5, PI/2.0-PI/6, -PI/2.5, PI/2.0-PI/6, -PI/2.5, PI/2.0-PI/6, -PI, PI, -PI/2.0, 0.0};
int hand02TrajDemo2(HANDJnt ref_jnt_ang, HANDJnt data, Object obj, double time, double *sensor, double *camera)
//int hand02TrajDemo2(HANDJnt ref_jnt_ang, double time, double *sensor, double *camera)
{
	//���Ԃ̒�`
	#define TIME1	20.0//�c���҂����

	int jnt;
    double rate = 0.0;

	//�J�����̒l�̕ۑ�
	static double c0;//camera[0]�C���đ́ix���W�j
	static double c1;//camera[1]�C���đ́iy���W�j
	static double c2;//camera[2]�C���đ́i�ʐρj

	//�c�������Ƃ��̃t���O
	static int flag_hand02;

	//�c������
	static int time_grasp;
	//�c�����Ȃ�����
	static int time_grasp2;

	//�c������^�C�~���O�̖ڕW�l
	#define REF_X		400
	#define REF_Y		550
	#define REF_AREA	2000
	//#define REF_X		400
	//#define REF_Y		600
	//#define REF_AREA	1500

	//�f�o�b�N�p�C�v�Z�̏��ԏ�CHand02App.c�ŗ^����̂��ǂ��D
	if(0){
		if(time>5.0){
			camera[0]=1.0;
			camera[1]=0.1;
			camera[2]=0.2;
			camera[3]=0.3;
			camera[4]=1.0;
			camera[5]=1.0;
			camera[6]=1.0;
			camera[7]=1.0;
			camera[8]=1.0;
		}
	}

	for(jnt=0;jnt<HAND_JNT;jnt++)   ref_jnt_ang[jnt] = prepare_jnt_ang2[jnt];

	if(time <= TIME1){
		//�c�����Ԃ̏�����
		if(time == 0.0){
			time_grasp=0;
			time_grasp2=0;
		}
		
		//���đ̃L���b�`�v���O����
		if(flag_hand02 == 1){//�c��������
			ref_jnt_ang[HAND02_M1] = -PI/15.0;
			ref_jnt_ang[HAND02_M3] = -PI/15.0;
			ref_jnt_ang[HAND02_M5] = -PI/15.0;
			//�c�����Ԃ̍X�V
			time_grasp++;
		}else if(camera[0]!=0){//�g���b�L���O�ł��Ă���Ƃ�
			//�J�����̒l�̕ۑ�
			//static double c0;//camera[0]�C�n���h03�p�̎w�ix���W�j
			//static double c1;//camera[1]�C�n���h03�p�̎w�iy���W�j
			//static double c2;//camera[2]�C�n���h02�p�̎w�i�ʐρj

			//�c������Ƃ�
			if( fabs(REF_X-camera[0]) < 20 && fabs(REF_Y-camera[1]) < 50 && fabs(REF_AREA-camera[2]) < 300 ){
				ref_jnt_ang[HAND02_M1] = -PI/15.0;
				ref_jnt_ang[HAND02_M3] = -PI/15.0;
				ref_jnt_ang[HAND02_M5] = -PI/15.0;
				flag_hand02 = 1;
			}
		}

		//�c�����Ȃ��Ƃ�
		if(flag_hand02 == 1 && time_grasp >= 1000 && time_grasp <= 1999){//�c�����~�߂�
			ref_jnt_ang[HAND02_M1] = -PI/2.5;
			ref_jnt_ang[HAND02_M3] = -PI/2.5;
			ref_jnt_ang[HAND02_M5] = -PI/2.5;
		}else if(flag_hand02 == 1 && time_grasp == 2000){//�c�����~�߂�
			ref_jnt_ang[HAND02_M1] = -PI/2.5;
			ref_jnt_ang[HAND02_M3] = -PI/2.5;
			ref_jnt_ang[HAND02_M5] = -PI/2.5;
			time_grasp=0;
			flag_hand02 = 0;
		}

	}

	//�J�����̒l�̑��
	c0=camera[0];
	c1=camera[1];
	c2=camera[2];

	return 0;
}

static HANDJnt	prepare_jnt_ang3 = {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0};
int hand02TrajDemo3(HANDJnt ref_jnt_ang, double time, double *sensor, double *camera)
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
        ref_jnt_ang[HAND02_M1] = -PI/2.0;
        ref_jnt_ang[HAND02_M3] = -PI/2.0;
        ref_jnt_ang[HAND02_M5] = -PI/2.0;
        ref_jnt_ang[HAND02_M2] =  0.0;
        ref_jnt_ang[HAND02_M4] =  0.0;
        ref_jnt_ang[HAND02_M6] =  0.0;
    }else if(time < DEMO3_TIME2){
        ref_jnt_ang[HAND02_M1] = -PI/2.0;
        ref_jnt_ang[HAND02_M3] = -PI/2.0;
        ref_jnt_ang[HAND02_M5] = -PI/2.0 + PI/4.0*3.0*sin(PI/2.0*(time -DEMO3_TIME1)/(DEMO3_TIME2-DEMO3_TIME1));
        ref_jnt_ang[HAND02_M2] =  0.0;
        ref_jnt_ang[HAND02_M4] =  0.0;
        ref_jnt_ang[HAND02_M6] =  0.0;
    }else if(time < DEMO3_TIME3){
        ref_jnt_ang[HAND02_M1] = -PI/2.0;
        ref_jnt_ang[HAND02_M3] = -PI/2.0;
        ref_jnt_ang[HAND02_M5] =  PI/4.0;
        ref_jnt_ang[HAND02_M2] =  0.0;
        ref_jnt_ang[HAND02_M4] =  0.0;
        ref_jnt_ang[HAND02_M6] =  0.0 + PI/2.0*sin(PI/2.0*(time -DEMO3_TIME2)/(DEMO3_TIME3-DEMO3_TIME2));
    }else if(time < DEMO3_TIME4){
        ref_jnt_ang[HAND02_M1] = -PI/2.0 + PI/4.0*3.0*sin(PI/2.0*(time -DEMO3_TIME3)/(DEMO3_TIME4-DEMO3_TIME3));
        ref_jnt_ang[HAND02_M3] = -PI/2.0;
        ref_jnt_ang[HAND02_M5] =  PI/4.0;
        ref_jnt_ang[HAND02_M2] =  0.0;
        ref_jnt_ang[HAND02_M4] =  0.0;
        ref_jnt_ang[HAND02_M6] =  PI/2.0;
    }else if(time < DEMO3_TIME5){
        ref_jnt_ang[HAND02_M1] =  PI/4.0;
        ref_jnt_ang[HAND02_M3] = -PI/2.0;
        ref_jnt_ang[HAND02_M5] =  PI/4.0;
        ref_jnt_ang[HAND02_M2] =  0.0  + PI/2.0*sin(PI/2.0*(time -DEMO3_TIME4)/(DEMO3_TIME5-DEMO3_TIME4));
        ref_jnt_ang[HAND02_M4] =  0.0;
        ref_jnt_ang[HAND02_M6] =  PI/2.0;
    }else if(time < DEMO3_TIME6){
        ref_jnt_ang[HAND02_M1] =  PI/4.0;
        ref_jnt_ang[HAND02_M3] =  -PI/2.0 + PI/4.0*3.0*sin(PI/2.0*(time -DEMO3_TIME5)/(DEMO3_TIME6-DEMO3_TIME5));
        ref_jnt_ang[HAND02_M5] =  PI/4.0;
        ref_jnt_ang[HAND02_M2] =  PI/2.0;
        ref_jnt_ang[HAND02_M4] =  0.0;
        ref_jnt_ang[HAND02_M6] =  PI/2.0;
    }else if(time < DEMO3_TIME7){
        ref_jnt_ang[HAND02_M1] =  PI/4.0;
        ref_jnt_ang[HAND02_M3] =  PI/4.0;
        ref_jnt_ang[HAND02_M5] =  PI/4.0;
        ref_jnt_ang[HAND02_M2] =  PI/2.0;
        ref_jnt_ang[HAND02_M4] =  0.0  + PI/2.0*sin(PI/2.0*(time -DEMO3_TIME6)/(DEMO3_TIME7-DEMO3_TIME6));
        ref_jnt_ang[HAND02_M6] =  PI/2.0;
    }else if(time < DEMO3_TIME8){
        ref_jnt_ang[HAND02_M1] =  PI/4.0;
        ref_jnt_ang[HAND02_M3] =  PI/4.0;
        ref_jnt_ang[HAND02_M5] =  PI/4.0;
        ref_jnt_ang[HAND02_M2] =  PI/2.0;
        ref_jnt_ang[HAND02_M4] =  PI/2.0;
        ref_jnt_ang[HAND02_M6] =  PI/2.0;
    }else if(time < DEMO3_TIME9){
        ref_jnt_ang[HAND02_M1] =  PI/4.0;
        ref_jnt_ang[HAND02_M3] =  PI/4.0;
        ref_jnt_ang[HAND02_M5] =  PI/4.0;
        ref_jnt_ang[HAND02_M2] =  PI/2.0;
        ref_jnt_ang[HAND02_M4] =  PI/2.0 - PI/2.0*sin(PI/2.0*(time -DEMO3_TIME8)/(DEMO3_TIME9-DEMO3_TIME8));
        ref_jnt_ang[HAND02_M6] =  PI/2.0;
    }else if(time < DEMO3_TIME10){
        ref_jnt_ang[HAND02_M1] =  PI/4.0;
        ref_jnt_ang[HAND02_M3] =  PI/4.0 -  PI/4.0*3.0*sin(PI/2.0*(time -DEMO3_TIME9)/(DEMO3_TIME10-DEMO3_TIME9));
        ref_jnt_ang[HAND02_M5] =  PI/4.0;
        ref_jnt_ang[HAND02_M2] =  PI/2.0;
        ref_jnt_ang[HAND02_M4] =  0.0;
        ref_jnt_ang[HAND02_M6] =  PI/2.0;
    }else if(time < DEMO3_TIME11){
        ref_jnt_ang[HAND02_M1] =  PI/4.0;
        ref_jnt_ang[HAND02_M3] = -PI/2.0;
        ref_jnt_ang[HAND02_M5] =  PI/4.0;
        ref_jnt_ang[HAND02_M2] =  PI/2.0  - PI/2.0*sin(PI/2.0*(time -DEMO3_TIME10)/(DEMO3_TIME11-DEMO3_TIME10));
        ref_jnt_ang[HAND02_M4] =  0.0;
        ref_jnt_ang[HAND02_M6] =  PI/2.0;
    }else if(time < DEMO3_TIME12){
        ref_jnt_ang[HAND02_M1] =  PI/4.0 - PI/4.0*3.0*sin(PI/2.0*(time -DEMO3_TIME11)/(DEMO3_TIME12-DEMO3_TIME11));
        ref_jnt_ang[HAND02_M3] = -PI/2.0;
        ref_jnt_ang[HAND02_M5] =  PI/4.0;
        ref_jnt_ang[HAND02_M2] =  0.0;
        ref_jnt_ang[HAND02_M4] =  0.0;
        ref_jnt_ang[HAND02_M6] =  PI/2.0;
    }else if(time < DEMO3_TIME13){
        ref_jnt_ang[HAND02_M1] = -PI/2.0;
        ref_jnt_ang[HAND02_M3] = -PI/2.0;
        ref_jnt_ang[HAND02_M5] =  PI/4.0;
        ref_jnt_ang[HAND02_M2] =  0.0;
        ref_jnt_ang[HAND02_M4] =  0.0;
        ref_jnt_ang[HAND02_M6] =  PI/2.0 - PI/2.0*sin(PI/2.0*(time -DEMO3_TIME12)/(DEMO3_TIME13-DEMO3_TIME12));
    }else if(time < DEMO3_TIME14){
        ref_jnt_ang[HAND02_M1] = -PI/2.0;
        ref_jnt_ang[HAND02_M3] = -PI/2.0;
        ref_jnt_ang[HAND02_M5] =  PI/4.0 - PI/4.0*3.0*sin(PI/2.0*(time -DEMO3_TIME13)/(DEMO3_TIME14-DEMO3_TIME13));
        ref_jnt_ang[HAND02_M2] =  0.0;
        ref_jnt_ang[HAND02_M4] =  0.0;
        ref_jnt_ang[HAND02_M6] =  0.0;
    }else if(time < DEMO3_TIME15){
        ref_jnt_ang[HAND02_M1] = -PI/2.0;
        ref_jnt_ang[HAND02_M3] = -PI/2.0;
        ref_jnt_ang[HAND02_M5] = -PI/2.0;
        ref_jnt_ang[HAND02_M2] =  0.0;
        ref_jnt_ang[HAND02_M4] =  0.0;
        ref_jnt_ang[HAND02_M6] =  0.0;
    }else if(time < DEMO3_TIME16){
        ref_jnt_ang[HAND02_M1] = -PI/2.0;
        ref_jnt_ang[HAND02_M3] = -PI/2.0;
        ref_jnt_ang[HAND02_M5] = -PI/2.0;
        ref_jnt_ang[HAND02_M2] =  0.0;
        ref_jnt_ang[HAND02_M4] =  0.0;
        ref_jnt_ang[HAND02_M6] =  0.0;
        ref_jnt_ang[HAND02_M7] =  0.0;
        ref_jnt_ang[HAND02_M8] =  PI/3.0*2.0;
    }else if(time < DEMO3_TIME17){
        ref_jnt_ang[HAND02_M1] = -PI/2.0;
        ref_jnt_ang[HAND02_M3] = -PI/2.0;
        ref_jnt_ang[HAND02_M5] = -PI/2.0;
        ref_jnt_ang[HAND02_M2] =  0.0;
        ref_jnt_ang[HAND02_M4] =  0.0;
        ref_jnt_ang[HAND02_M6] =  0.0;
        ref_jnt_ang[HAND02_M7] =  0.0        - PI/3.0*2.0*sin(PI*(time -DEMO3_TIME16)/(DEMO3_TIME17-DEMO3_TIME16));
        ref_jnt_ang[HAND02_M8] =  PI/3.0*2.0 - PI/3.0*2.0*sin(PI*(time -DEMO3_TIME16)/(DEMO3_TIME17-DEMO3_TIME16));
    }else if(time < DEMO3_TIME18){
        ref_jnt_ang[HAND02_M1] = -PI/2.0;
        ref_jnt_ang[HAND02_M3] = -PI/2.0;
        ref_jnt_ang[HAND02_M5] = -PI/2.0;
        ref_jnt_ang[HAND02_M2] =  0.0;
        ref_jnt_ang[HAND02_M4] =  0.0;
        ref_jnt_ang[HAND02_M6] =  0.0;
        ref_jnt_ang[HAND02_M7] =  -PI/2.0;
        ref_jnt_ang[HAND02_M8] =   PI/2.0;
        ref_jnt_ang[HAND02_M9]  = 0.0;
        ref_jnt_ang[HAND02_M10] = PI/3.0*sin(2.0*PI*(time -DEMO3_TIME17)/(DEMO3_TIME18-DEMO3_TIME17));
    }else if(time < DEMO3_TIME19){
        ref_jnt_ang[HAND02_M1] = -PI/2.0;
        ref_jnt_ang[HAND02_M3] = -PI/2.0;
        ref_jnt_ang[HAND02_M5] = -PI/2.0;
        ref_jnt_ang[HAND02_M2] =  0.0;
        ref_jnt_ang[HAND02_M4] =  0.0;
        ref_jnt_ang[HAND02_M6] =  0.0;
        ref_jnt_ang[HAND02_M7] =  -PI/2.0;
        ref_jnt_ang[HAND02_M8] =   PI/2.0;
//        ref_jnt_ang[HAND02_M9]  = -PI/3.0*sin(2.0*PI*(time -DEMO3_TIME18)/(DEMO3_TIME19-DEMO3_TIME18));
        ref_jnt_ang[HAND02_M9]  = -PI/5.0*sin(2.0*PI*(time -DEMO3_TIME18)/(DEMO3_TIME19-DEMO3_TIME18));
        ref_jnt_ang[HAND02_M10] = 0.0;
    }
    return 0;
}


//////////////////////////////////////
// �n���h�����ݒ�
//////////////////////////////////////
int handAppSet02(HAND *hand02)
{
	int jnt;
	hand02->base_homo = &hand_base_homo;
	hand02->ctrl_coef = &hand_ctrl_coef;
	if(app_num==1)	hand02->prepare_jnt_ang = prepare_jnt_ang1;
	else if(app_num==2)	hand02->prepare_jnt_ang = prepare_jnt_ang2;
	else if(app_num==3)	hand02->prepare_jnt_ang = prepare_jnt_ang3;
//	hand->prepare_jnt_ang = prepare_jnt_ang;
	return 0;
}
