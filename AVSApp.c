#include <stdio.h>
#include <math.h>
#include <AVS.h>
#include "App.h"

// �\���̐錾
AVSALL	avs;

// �O���[�o�����W�ɂ�����AVS�ʒu
static HomoMat avs_base_homo[AVS_NUM] ={{{0.0, -1.0, 0.0},
										{1.0, 0.0, 0.0},
		                                {0.0, 0.0, 1.0},
										{0.45, 0.36, 0.14}},
										{{0.0, -1.0, 0.0},
										{1.0, 0.0, 0.0},
										{0.0, 0.0, 1.0},
										{0.45, -0.36, 0.14}}};
// ����Q�C��
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
// �����p��
//static AVSJntAll	avs_prepare_jnt_ang = {PI/4, -PI/4, -PI/4, PI/4};		// �X���[�C���O�A�[������
//static AVSJntAll	avs_prepare_jnt_ang = {-PI/4, -PI/4, PI/4, PI/4};		// �o�b�e�B���O�A�[������
//static AVSJntAll	avs_prepare_jnt_ang = {-PI/4, PI/4, PI/4, -PI/4};		// �o�b�e�B���O�A�[������
static AVSJntAll	avs_prepare_jnt_ang = {-PI/4, PI/6, -PI/4, -PI/6};


//////////////////////////////////////////////////////
int avsTrajApp(AVSJntAll ref_jnt_ang, double time)
{
	int jnt;

////////////////////////
// ���n��O��
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
// �Ώۂ����������Ƃ��̋O��
/////////////////////////////
	for(jnt=0;jnt<AVS_JNT_ALL;jnt++)	ref_jnt_ang[jnt] = avs_prepare_jnt_ang[jnt];

	return 0;
}

////////////////////////
// �r�W���A���T�[�{
////////////////////////
int avsVisualTrajApp(AVSImgCenAll ref_img_center, double time)
{
	// �Ώۂ��摜���S�ɂ���悤�ɐ���
	ref_img_center[AVS1_PAN] = 0.0;
	ref_img_center[AVS1_TILT] = 0.0;
	ref_img_center[AVS2_PAN] = 0.0;
	ref_img_center[AVS2_TILT] = 0.0;
	return 0;
}


//////////////////////////////////////
// �A�N�e�B�u�r�W���������ݒ�
//////////////////////////////////////
int avsAppSet(AVSALL *avs)
{
	int jnt, num;
	avs->base_homo = avs_base_homo;
	avs->ctrl_coef = &avs_ctrl_coef;
	avs->prepare_jnt_ang = avs_prepare_jnt_ang;
	return 0;
}
