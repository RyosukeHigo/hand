#define S_FUNCTION_NAME SystemSet
#define S_FUNCTION_LEVEL 2

#include "simstruc.h"
#include <stdio.h>
#include <math.h>
#include "SysDef.h"
#include <Hand.h>
#include <WAM.h>
#include <AVS.h>
#include <XYstage.h>
#include <cpv_ctrl.h>
#include <cpv_io.h>
#include <vision.h>

#ifndef MATLAB_MEX_FILE
// dSPACE�p�w�b�_�t�@�C��
#include <brtenv.h>
#include <ds3001.h>
#include <ds3002.h>
#include <ds2103.h>
#include <ds4003.h>

int dSPACE_init()
{

	// DA�|�[�g�̒�`
	//�n���h02
	Int32  ch_hand02[HAND_JNT] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	//�n���h03
	Int32  ch_hand03[HAND_JNT] = {11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
	// XY�X�e�[�W
	Int32  ch_xy[XY_JNT] = {21, 22};
    // �A�N�e�B�u�r�W����
	Int32  ch_avs[AVS_JNT_ALL] = {23, 24, 27, 28};
    Int32  ch_servo[AVS_JNT_ALL] = {25, 26, 29, 30};	// �T�[�{�M��(WAM) + SEN�M��(AVS)


	// �v���Z�b�T�{�[�h(�K����ԏ��߂Ɏ��s!)
	ds1005_init();


	// DA�{�[�h
	ds2103_init(DS2103_1_BASE);

	#if SYSTEM_HAND
		ds2103_init_scantbl(DS2103_1_BASE, TBL_HAND02, HAND_JNT, ch_hand02);
	//#endif

	//#if SYSTEM_HAND
		ds2103_init_scantbl(DS2103_1_BASE, TBL_HAND03, HAND_JNT, ch_hand03);
	#endif
	
	#if SYSTEM_XYstage
		ds2103_init_scantbl(DS2103_1_BASE, TBL_XY, XY_JNT, ch_xy);
	#endif

	#if SYSTEM_AVS
		ds2103_init_scantbl(DS2103_1_BASE, TBL_AVS, AVS_JNT_ALL, ch_avs);
	#endif

	ds2103_init_scantbl(DS2103_1_BASE, TBL_SERVO, AVS_JNT_ALL, ch_servo);
	ds2103_set_range(DS2103_1_BASE, DS2103_CH_ALL, DS2103_RNG10);
	ds2103_set_errmode(DS2103_1_BASE, DS2103_CH_ALL, DS2103_KEEP);


	// ENC�{�[�h
	#if SYSTEM_HAND
		ds3001_init(DS3001_1_BASE);
		ds3001_init(DS3001_2_BASE);
	//	ds3001_set_line_type(DS3001_1_BASE, DS3001_CH_ALL, DS3001_DIFF);
	//	ds3001_set_line_type(DS3001_2_BASE, DS3001_CH_ALL, DS3001_DIFF);
		ds3001_set_line_type(DS3001_1_BASE, DS3001_CH_ALL, DS3001_SINGLE);
		ds3001_set_line_type(DS3001_2_BASE, DS3001_CH_ALL, DS3001_SINGLE);
		ds3001_clear_counter(DS3001_1_BASE, DS3001_CH_ALL);
		ds3001_clear_counter(DS3001_2_BASE, DS3001_CH_ALL);
	#endif

//	#if SYSTEM_HAND
	#if 0
		ds3001_init(DS3001_3_BASE);
	//	ds3001_set_line_type(DS3001_3_BASE, DS3001_CH_ALL, DS3001_DIFF);
		ds3001_set_line_type(DS3001_3_BASE, DS3001_CH_ALL, DS3001_SINGLE);
		ds3001_clear_counter(DS3001_3_BASE, DS3001_CH_ALL);
		ds3002_init(DS3002_2_BASE);
	#endif

	#if SYSTEM_XYstage
		ds3002_init(DS3002_1_BASE);
	#endif

	#if SYSTEM_AVS
		ds3002_init(DS3002_1_BASE);
	#endif

	// DIO�{�[�h
		/*
	#if SYSTEM_CPV
		ds4003_init(DS4003_1_BASE);
		ds4003_init(DS4003_2_BASE);
		ds4003_pio_init(DS4003_1_BASE, 1, DS4003_OUT_0|DS4003_OUT_1|DS4003_IN_2|DS4003_IN_3, DS4003_NON_STRB);
		ds4003_pio_init(DS4003_1_BASE, 2, DS4003_OUT, DS4003_NON_STRB);
		ds4003_pio_init(DS4003_2_BASE, 1, DS4003_OUT_0|DS4003_OUT_1|DS4003_IN_2|DS4003_IN_3, DS4003_NON_STRB);
		ds4003_pio_init(DS4003_2_BASE, 2, DS4003_OUT, DS4003_NON_STRB);
	#endif
	*/

	return 0;
}
#endif

///////////////////////////////
// �z�X�gPC�Ƃ̒ʐM�ϐ�
// [model]_usr.c ���Œ�`
///////////////////////////////
#ifndef MATLAB_MEX_FILE
extern unsigned int     app_num;
extern int    host_access_flag;
#else
extern unsigned int     app_num = 0;
extern int    host_access_flag = HOST2RTP;
#endif

static void mdlInitializeSizes(SimStruct *S)
{
    // S-function�ւ̈����̐ݒ�
    ssSetNumSFcnParams(S, 0);
    if(ssGetNumSFcnParams(S) != ssGetSFcnParamsCount(S))    return;
    // ���̓|�[�g�̐ݒ�
    if(!ssSetNumInputPorts(S, 0))    return;
    // �o�̓|�[�g�̐ݒ�
    if(!ssSetNumOutputPorts(S, 1))   return;
	ssSetOutputPortDataType(S, 0, SS_INT32);
    ssSetOutputPortWidth(S, 0, 1);
	// ���[�N�x�N�g���̐ݒ�   
	ssSetNumRWork(S, 1);
	// ���̑�
    ssSetNumSampleTimes(S, 1);    
    ssSetOptions(S, SS_OPTION_EXCEPTION_FREE_CODE);
}


static void mdlInitializeSampleTimes(SimStruct *S)
{
    ssSetSampleTime(S, 0, SYS_INT_INTERVAL);
    ssSetOffsetTime(S, 0, 0.0);
}


#define MDL_START
#if defined(MDL_START)
static void mdlStart(SimStruct *S)
{
    int     jnt;
    HANDJnt     hand_da_init02;
    HANDJnt     hand_da_init03;
	XYJnt		xy_da_init;
    AVSJntAll   avs_da_init;
//    double      servo_on[1+AVS_JNT_ALL] = {0.5, 0.5, 0.5, 0.5, 0.5};
    double      servo_on[AVS_JNT_ALL] = {0.5, 0.5, 0.5, 0.5};

	ssSetRWorkValue(S, 0, 0.0);
    for(jnt=0;jnt<HAND_JNT;jnt++)   hand_da_init02[jnt] = 0.0;
    for(jnt=0;jnt<HAND_JNT;jnt++)   hand_da_init03[jnt] = 0.0;
    for(jnt=0;jnt<XY_JNT;jnt++)   xy_da_init[jnt] = 0.0;
    for(jnt=0;jnt<AVS_JNT_ALL;jnt++)   avs_da_init[jnt] = 0.0;

	#ifndef MATLAB_MEX_FILE
		dSPACE_init();      // dSPACE������
		ds2103_out(DS2103_1_BASE , TBL_SERVO, servo_on);
		#if SYSTEM_HAND
			ds2103_out(DS2103_1_BASE , TBL_HAND02, hand_da_init02);
		#endif
		#if SYSTEM_HAND
			ds2103_out(DS2103_1_BASE , TBL_HAND03, hand_da_init03);
		#endif
		#if SYSTEM_XYstage
			ds2103_out(DS2103_1_BASE , TBL_XY, xy_da_init);
		#endif
		#if SYSTEM_AVS
			ds2103_out(DS2103_1_BASE , TBL_AVS, avs_da_init);
			ds1005_tic_delay(0.15);		// AVS�̐�Βl�f�[�^�̑��M�҂�
		#endif
		#if SYSTEM_CPV
		//	CPV_connect();
			CPV_init(CPV1);
			CPV_init(CPV2);
		#endif
	#endif
}
#endif


static void mdlOutputs(SimStruct *S,int_T tid)
{
    int		*trigger= ssGetOutputPortSignal(S, 0);
	double	time = ssGetRWorkValue(S, 0);
    HANDJnt		hand_da_zero02;
    HANDJnt		hand_da_zero03;
	XYJnt		xy_da_zero;
    AVSJntAll	avs_da_zero;
    int jnt;
	static int incount = 0;

    for(jnt=0;jnt<HAND_JNT;jnt++)   hand_da_zero02[jnt] = 0.0;
    for(jnt=0;jnt<HAND_JNT;jnt++)   hand_da_zero03[jnt] = 0.0;
    for(jnt=0;jnt<XY_JNT;jnt++)   xy_da_zero[jnt] = 0.0;
    for(jnt=0;jnt<AVS_JNT_ALL;jnt++)   avs_da_zero[jnt] = 0.0;

    if(app_num == 0){
		incount = 0;
//		#if SYSTEM_CPV
//			if(host_access_flag == CPV_START)     host_access_flag = CPV_END;      // CPV �v���O�����I������
//		#endif

		#ifndef MATLAB_MEX_FILE
			#if SYSTEM_HAND
				ds2103_out(DS2103_1_BASE , TBL_HAND02, hand_da_zero02);
			#endif
			#if SYSTEM_HAND
				ds2103_out(DS2103_1_BASE , TBL_HAND03, hand_da_zero03);
			#endif
			#if SYSTEM_XYstage
				ds2103_out(DS2103_1_BASE , TBL_XY, xy_da_zero);
			#endif
			#if SYSTEM_AVS
				ds2103_out(DS2103_1_BASE , TBL_AVS, avs_da_zero);
			#endif
		#endif
    		*trigger = 0;
    }else{
//		#if SYSTEM_CPV
//			if(host_access_flag == CPV_PAUSE)       host_access_flag = CPV_READY;      // CPV �v���O�����J�n����
//	        if(host_access_flag == CPV_START)      // CPV �v���O�����J�n
//		#endif
		if(incount > 0)		*trigger = 1;
		incount++;
	}
    ssSetRWorkValue(S, 0, time+SYS_INT_INTERVAL);		// ���ԍX�V
}


static void mdlTerminate(SimStruct *S){}

#ifdef MATLAB_MEX_FILE
#include "simulink.c"
#else
#include "cg_sfun.h"
#endif
