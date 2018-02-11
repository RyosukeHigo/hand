#include <stdio.h>
#include <math.h>
#include <WAM.h>
#include "App.h"
#include "DataDef.h"

// �\���̐錾
WAM		wam;

// �O���[�o�����W�ɂ�����A�[���ʒu
static HomoMat wam_base_homo ={{1.0, 0.0, 0.0},
		                        {0.0, 1.0, 0.0},
		                        {0.0, 0.0, 1.0},
								{0.0, 0.675, 0.0}};
// ����Q�C��
WAMCtrlCoef wam_ctrl_coef = {{8.0, 8.0, 8.0, 8.0, 1000.0},				// Kp
							{0.0, 0.0, 0.0, 0.0, 0.0},					// Ti
							{120.0, 120.0, 80.0, 80.0, 3000.0},			//Td
							{0.0, 0.0, 0.0, 0.0, 0.0},					// Cf
							120};										// Kg
// �����p��
//static WAMJnt	prepare_jnt_ang = {-PI/4, PI/5.0, 0.0, PI/6.0, 0.0};
static WAMJnt	prepare_jnt_ang = {0.0, PI/5.0, 0.0, PI/6.0, 0.0};


//////////////////////////////////////////////////////
int wamTrajApp(WAMJnt ref_jnt_ang, Object obj, double time)
{
	int jnt, crd;
    double zero[WAM_JNT];
	static int	visible_flag = 0;		// �O�t���[���ŉ���Ԃ̂Ƃ���1
	static Vector3D prev_pos;			// �O�t���[���̑Ώۈʒu

//	ref_jnt_ang[WAM_M1] = PI/4*(1.0-cos(2.0*PI*time)) + prepare_jnt_ang[WAM_M1];

////////////////////////
// �r�W�����A��
////////////////////////
#if 1
#define WAM_VISION_GAIN	0.8
	// �����ݒ�
	if(time < 0.001){
		visible_flag = 0;
		for(crd=0;crd<3;crd++)	prev_pos[crd] = 0.0;
    }
	// �O��
	if(obj[OBJ_VISIBLE] > 0 && visible_flag == 1){
		ref_jnt_ang[WAM_M1] += -WAM_VISION_GAIN*(obj[OBJ_POS_Y]-prev_pos[1]);
		ref_jnt_ang[WAM_M4] += -WAM_VISION_GAIN*(obj[OBJ_POS_Z]-prev_pos[2]);
	}
	// �t���O�ݒ�
	if(obj[OBJ_VISIBLE] > 0)	visible_flag = 1;
	else	visible_flag = 0;
	// �ۑ�
	prev_pos[0] = obj[OBJ_POS_X];	prev_pos[1] = obj[OBJ_POS_Y];	prev_pos[2] = obj[OBJ_POS_Z];
#endif

	return 0;
}


//////////////////////////////////////
// �A�[�������ݒ�
//////////////////////////////////////
int wamAppSet(WAM *wam)
{
	int jnt;
	wam->base_homo = &wam_base_homo;
	wam->ctrl_coef = &wam_ctrl_coef;
	wam->prepare_jnt_ang = prepare_jnt_ang;
	return 0;
}
