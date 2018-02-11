#define S_FUNCTION_NAME TaskSet
#define S_FUNCTION_LEVEL 2

#include "simstruc.h"
#include <stdio.h>
#include <math.h>
#include "SysDef.h"
#include "App.h"

extern unsigned int		app_num;
extern HAND		hand02;
extern HAND		hand03;
extern WAM		wam;
extern AVSALL	avs;
extern XY		xy;

static void mdlInitializeSizes(SimStruct *S)
{
    // S-functionへの引数の設定
    ssSetNumSFcnParams(S, 0);
    if(ssGetNumSFcnParams(S) != ssGetSFcnParamsCount(S))    return;
    // 入力ポートの設定
    if(!ssSetNumInputPorts(S, 0))    return;
    // 出力ポートの設定
    if(!ssSetNumOutputPorts(S, 1))   return;
    ssSetOutputPortWidth(S, 0, 1);
	// ワークベクトルの設定   
	ssSetNumRWork(S, 1);
	// その他
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
	ssSetRWorkValue(S, 0, 0.0);
	// 構造体初期設定
#if SYSTEM_HAND
	handAppSet02(&hand02);
	handAppSet03(&hand03);
#endif
#if SYSTEM_WAM
	wamAppSet(&wam);
#endif
#if SYSTEM_AVS
    avsAppSet(&avs);
#endif
#if SYSTEM_XYstage
    xyAppSet(&xy);
#endif
}
#endif


static void mdlOutputs(SimStruct *S,int_T tid)
{
    real_T *app_time = ssGetOutputPortRealSignal(S, 0);
	double	time = ssGetRWorkValue(S, 0);

    *app_time = time;
    if(time < ALL_APP_TIME)		ssSetRWorkValue(S, 0, time+SYS_INT_INTERVAL);		// 時間更新
	else	app_num = 0;       // リセット
}


static void mdlTerminate(SimStruct *S){}
    
#ifdef MATLAB_MEX_FILE
#include "simulink.c"
#else
#include "cg_sfun.h"
#endif
