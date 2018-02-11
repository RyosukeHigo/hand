#ifndef SYSTEM_DEFINE_H
#define SYSTEM_DEFINE_H

//////////////////////////////////////////////////
// �V�X�e���g�p�ݒ�
// �g�p����Ƃ��� 1 , �g�p���Ȃ��Ƃ��� 0 ��ݒ�
//////////////////////////////////////////////////
#define SYSTEM_HAND		1
#define SYSTEM_WAM		0
#define SYSTEM_CPV		1
#define SYSTEM_AVS		1
#define SYSTEM_XYstage	1

// �T�C�N���^�C��
#define SYS_INT_INTERVAL (1.0e-3)

// �p�����[�^�ۑ���
#define SYS_SAVE_MAX (5000)

// ENC
#define NORMALIZE_ENC	pow(2.0,23)
// DA (scan table number ��4�܂�)
#define TBL_HAND02 1
#define TBL_HAND03 2
//#define TBL_WAM  2
#define TBL_SERVO  4
#define TBL_XY  3
#define TBL_AVS  4
#define DA_LIMIT_HAND	1.0
#define DA_LIMIT_WAM	0.3
#define DA_LIMIT_AVS	0.6
#define DA_LIMIT_XY		0.9

#endif
