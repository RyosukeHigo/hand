#include <stdio.h>
#include <math.h>
#include <Hand.h>
#include "App.h"

// �\���̐錾
HAND	hand03;

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
static HANDCtrlCoef hand_ctrl_coef = {{15.0, 20.0, 15.0, 20.0, 15.0, 20.0, 15.0, 15.0, 25.0, 25.0},	// Kp
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


//�w�ԍ�03�p
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

// �����p���ɂ��ā@03�p
// static HANDJnt	prepare_jnt_ang1 = {-PI/2.0, 0.0, -PI/2.0, 0.0, -PI/2.0, 0.0, -PI/3.0*2.0 + PI/36.0, PI/3.0*2.0 - PI/36.0, 0.0, 0.0};
// static HANDJnt	prepare_jnt_ang1 = {���w���������N, ���w��[�����N, ���w���������N, ���w��[�����N, 
//										�E�w���������N, �E�w��[�����N, ���w����, �E�w����, ������, ������};



//////////////////////////////////////////////////////
//���{�b�g������񂯂�ŏ���
//���w�C���w�C�E�w�C���w����C�E�w����C�����ȁC������
static HANDJnt	prepare_jnt_ang1 = {PI/4.0, PI/2.0, 0.0, PI/2.0, PI/4.0, PI/2.0, 0.0, PI/4.0, -PI/2.0, 0.0};
int hand03TrajDemo1(HANDJnt ref_jnt_ang, HANDJnt data, Object obj, double time, double *sensor, double *camera)
{
	int jnt;
    double rate = 0.0;

	for(jnt=0;jnt<HAND_JNT;jnt++)   ref_jnt_ang[jnt] = prepare_jnt_ang1[jnt];

	return 0;
}


//���{�b�g������񂯂�ŕ�����
//���w�C���w�C�E�w�C���w����C�E�w����C�����ȁC������
static HANDJnt	prepare_jnt_ang2 = {PI/4.0, PI/2.0, PI/4.0, PI/2.0, PI/4.0, PI/2.0, 0.0, 0.0, PI/2.0, 0.0};
int hand03TrajDemo2(HANDJnt ref_jnt_ang, HANDJnt data, Object obj, double time, double *sensor, double *camera)
//int hand03TrajDemo2(HANDJnt ref_jnt_ang, double time, double *sensor, double *camera)
{
	int jnt;
    double rate = 0.0;

	for(jnt=0;jnt<HAND_JNT;jnt++)   ref_jnt_ang[jnt] = prepare_jnt_ang2[jnt];

	return 0;
}


//���{�b�g�Ɛl�Ԃ�����񂯂�ł������ɂȂ�
//���w�C���w�C�E�w�C���w����C�E�w����C�����ȁC������
static HANDJnt	prepare_jnt_ang3 = {PI/4.0, PI/2.0, PI/4.0, PI/2.0, PI/4.0, PI/2.0, 0.0, 0.0, PI/2.0, 0.0};
int hand03TrajDemo3(HANDJnt ref_jnt_ang, HANDJnt data, Object obj, double time, double *sensor, double *camera)
{
	int jnt;
    double rate = 0.0;

	for(jnt=0;jnt<HAND_JNT;jnt++)   ref_jnt_ang[jnt] = prepare_jnt_ang3[jnt];

	return 0;
}


//////////////////////////////////////
// �n���h�����ݒ�
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
