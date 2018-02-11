#include <stdio.h>
#include <math.h>
#include <XYstage.h>
#include "App.h"

// �\���̐錾
XY	xy;

// �O���[�o�����W�ɂ�����n���h�ʒu
static HomoMat xy_base_homo ={{1.0, 0.0, 0.0},
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
XYCtrlCoef xy_ctrl_coef = {{80.0, 80.0},	// Kp
							{0.0, 0.0},	// Ti
							{340.0, 340.0},	// Td
							{0.0, 0.0},	// Cf
							1.2};	// Kg

//���g���̒�`
#define OMEGA	1.0

//�X���C�_�̏����ʒu
#define XY_INIT02	-0.0
#define XY_INIT03	-0.0

// �����p��
static XYJnt	prepare_jnt_ang = {XY_INIT02, XY_INIT03};
//////////////////////////////////////////////////////
int xyTrajApp(XYJnt ref_jnt_ang, XYJnt data, double time, double *sensor, double *camera)
{
	//�֐ߊp�x�̒�`
	#define DIS1_M1		-0.05//�X���C�_�����ɓ��������C�n���h02����
	#define DIS1_M2		-0.05//�X���C�_�����ɓ��������C�n���h03����
	//�X���C�_�̔z�u����
	//���S�V�[�����\���Ă���������v���X
	//XY_M1��XY_M2�͋t�����ɂ��邱��

	//����Q�C��
	//I(x, y)��1�Ƃ��Čv�Z
	#define KP_XY2	0.0005
	#define KD_XY2	0.00
	//I(x, y)��255�Ƃ��Čv�Z
	#define KP_XY1	KP_XY2/255
	#define KD_XY1	KD_XY2/255

	//���Ԃ̒�`
	#define TIME1	5.0//�z���Z�b�g���鎞��
	#define TIME11	15.0//�摜�����̐ݒ莞��
	#define TIME2	16.0//�������ɃZ�b�g���鎞��
	#define TIME3	17.0//�z�̂��𖳂������߂̎���
	#define TIME4	17.1//�z��ό`�����鎞�ԁi������ɋȂ���j
	#define TIME45	17.2//�z��ό`�����鎞�ԁi������ɋȂ���j
	#define TIME5	17.3//���{�b�g���~�߂鎞��
	#define TIME6	17.4//�z��c�����鎞��

	//�X���C�_�ړ������̒����Q�C��
	#define DIS_GAIN	4.0
	#define DIS_GAIN2	2.0

	int jnt, crd;

	//�J�����̒l�̕ۑ�
	static double c0;//camera[0]�C�n���h03�p�̎w�ix���W���ʐρj
	static double c1;//camera[1]�C�n���h03�p�̎w�iy���W�j
	static double c2;//camera[2]�C�n���h02�p�̎w�ix���W���ʐρj
	static double c3;//camera[3]�C�n���h02�p�̎w�iy���W�j
	static double c4;//camera[4]�C�n���h03�p�̕z�ix���W���ʐρj
	static double c5;//camera[5]�C�n���h03�p�̕z�iy���W�j
	static double c6;//camera[6]�C�n���h02�p�̕z�ix���W���ʐρj
	static double c7;//camera[7]�C�n���h02�p�̕z�iy���W�j

	//�X���C�_�̈ʒu�̒l�̕ۑ�
	static double xy_m1;
	static double xy_m2;

	//�z�Ǝw���قڈ�v�������̃t���O
	static int flag_xy;

	//PD�o��
	double xy_pd;

	//�z�Ǝw���قڈ�v�������̔����臒l
	//define GAMMA	100/255//*255��0�����[�����g���v�Z����Ƃ��ɁCI(x, y)��255�Ƃ��Čv�Z���Ă��邽��
	#define GAMMA	100

	//M1�̓n���h03����
	//M2�̓n���h02����

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
	}else if(time <= TIME4){//�ł���΃r�W���A���t�B�[�h�o�b�N�̕����i�`��w��j
		ref_jnt_ang[XY_M1] = XY_INIT02 + DIS1_M1*(time-TIME3)/(TIME4-TIME3);
		ref_jnt_ang[XY_M2] = XY_INIT03 + DIS1_M2*(time-TIME3)/(TIME4-TIME3);
*/
	}else if(time <= TIME45){//�ł���΃r�W���A���t�B�[�h�o�b�N�̕����i�`��w��j
		ref_jnt_ang[XY_M1] = XY_INIT02 + (DIS_GAIN+1)*DIS1_M1*(time-TIME3)/(TIME45-TIME3);
		ref_jnt_ang[XY_M2] = XY_INIT03 + (DIS_GAIN+1)*DIS1_M2*(time-TIME3)/(TIME45-TIME3);
	}else if(time <= TIME5){
		ref_jnt_ang[XY_M1] = XY_INIT02 + DIS1_M1+DIS_GAIN*DIS1_M1;
		ref_jnt_ang[XY_M2] = XY_INIT03 + DIS1_M2+DIS_GAIN*DIS1_M2;
		xy_m1 = ref_jnt_ang[XY_M1];
		xy_m2 = ref_jnt_ang[XY_M2];
		flag_xy = 0;
	}else if(time <= TIME6){//�r�W���A���t�B�[�h�o�b�N�̕����i�c�����邽�߂̐���j
		if(flag_xy ==1){//�z�Ƃ̖ʐς���v������
			ref_jnt_ang[XY_M1] = xy_m1;
			ref_jnt_ang[XY_M2] = xy_m2;
		}else if(camera[0]!=0){//�g���b�L���O�ł��Ă���Ƃ�
			//�J�����̒l�̕ۑ�
			//static double c0;//camera[0]�C�n���h03�p�̎w�ix���W���ʐρj
			//static double c1;//camera[1]�C�n���h03�p�̎w�iy���W�j
			//static double c2;//camera[2]�C�n���h02�p�̎w�ix���W���ʐρj
			//static double c3;//camera[3]�C�n���h02�p�̎w�iy���W�j
			//static double c4;//camera[4]�C�n���h03�p�̕z�ix���W���ʐρj
			//static double c5;//camera[5]�C�n���h03�p�̕z�iy���W�j
			//static double c6;//camera[6]�C�n���h02�p�̕z�ix���W���ʐρj
			//static double c7;//camera[7]�C�n���h02�p�̕z�iy���W�j

			//���s�����قړ����Ƃ�
			if( ((camera[4]+camera[6])/2/255 - (camera[0]+camera[2])/2/255) <= GAMMA || flag_xy==1){
				flag_xy = 1;
				ref_jnt_ang[XY_M1] = xy_m1;
				ref_jnt_ang[XY_M2] = xy_m2;
				xy_m1 = ref_jnt_ang[XY_M1];
				xy_m2 = ref_jnt_ang[XY_M2];
			}else{
			//�z�ɂ����}�[�J�[�̖ʐςɈ�v����悤�ɃX���C�_�̑O��ʒu�𐧌�
			//xy_pd = KP_XY1*( (camera[4]+camera[6])/2 - (camera[0]+camera[2])/2) + KD_XY1*( ((camera[4]-c4)+(camera[6]-c6))/2 - ((camera[0]-c0)+(camera[2]-c2))/2);//PD�o��
				xy_pd = KP_XY2*( (camera[4]+camera[6])/2/255 - (camera[0]+camera[2])/2/255) + KD_XY2*( ((camera[4]-c4)+(camera[6]-c6))/2/255 - ((camera[0]-c0)+(camera[2]-c2))/2/255);//PD�o��
				ref_jnt_ang[XY_M1] = xy_m1 + xy_pd;
				ref_jnt_ang[XY_M2] = xy_m2 + xy_pd;
				//�ڕW�l����
				if (ref_jnt_ang[XY_M1] > -0.1){
					ref_jnt_ang[XY_M1] = -0.1;
				}
				if (ref_jnt_ang[XY_M2] > -0.1){
					ref_jnt_ang[XY_M2] = -0.1;
				}
				xy_m1 = ref_jnt_ang[XY_M1];
				xy_m2 = ref_jnt_ang[XY_M2];
			}
		}else{//�g���b�L���O�ł��Ă��Ȃ��Ƃ�
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

	//�J�����̒l�̑��
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
// �n���h�����ݒ�
//////////////////////////////////////
int xyAppSet(XY *xy)
{
	int jnt;
	xy->base_homo = &xy_base_homo;
	xy->ctrl_coef = &xy_ctrl_coef;
	xy->prepare_jnt_ang = prepare_jnt_ang;
	return 0;
}
