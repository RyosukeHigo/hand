/*
 * base.c
 *
 * Real-Time Workshop code generation for Simulink model "base.mdl".
 *
 * Model Version              : 1.480
 * Real-Time Workshop version : 7.2  (R2008b)  04-Aug-2008
 * C source code generated on : Thu Feb 15 20:53:42 2018
 */

#include "base_trc_ptr.h"
#include "base.h"
#include "base_private.h"

/* Block signals (auto storage) */
BlockIO_base base_B;

/* Block states (auto storage) */
D_Work_base base_DWork;

/* Previous zero-crossings (trigger) states */
PrevZCSigStates_base base_PrevZCSigState;

/* Real-time model */
RT_MODEL_base base_M_;
RT_MODEL_base *base_M = &base_M_;
real_T base_RGND = 0.0;                /* real_T ground */

/* Initial conditions for function-call system: '<S2>/AliveGenSubsystem' */
void base_AliveGenSubsystem_Init(void)
{
  /* Level2 S-Function Block: '<S7>/DS100x_AliveFunction' (ds4504_DS100xAlive) */
  {
    SimStruct *rts = base_M->childSfunctions[10];
    sfcnInitializeConditions(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }
}

/* Start for function-call system: '<S2>/AliveGenSubsystem' */
void base_AliveGenSubsystem_Start(void)
{
  /* Level2 S-Function Block: '<S7>/DS100x_AliveFunction' (ds4504_DS100xAlive) */
  {
    SimStruct *rts = base_M->childSfunctions[10];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }
}

/* Output and update for function-call system: '<S2>/AliveGenSubsystem' */
void base_AliveGenSubsystemTID2(int_T controlPortIdx)
{
  /* Level2 S-Function Block: '<S7>/DS100x_AliveFunction' (ds4504_DS100xAlive) */
  {
    SimStruct *rts = base_M->childSfunctions[10];
    sfcnOutputs(rts, 2);
  }

  /* Level2 S-Function Block: '<S7>/DS100x_AliveFunction' (ds4504_DS100xAlive) */
  {
    SimStruct *rts = base_M->childSfunctions[10];
    sfcnUpdate(rts, 2);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }
}

/* Terminate for function-call system: '<S2>/AliveGenSubsystem' */
void base_AliveGenSubsystem_Term(void)
{
  /* Level2 S-Function Block: '<S7>/DS100x_AliveFunction' (ds4504_DS100xAlive) */
  {
    SimStruct *rts = base_M->childSfunctions[10];
    sfcnTerminate(rts);
  }
}

/* Model output function */
static void base_output(int_T tid)
{
  /* Level2 S-Function Block: '<Root>/System Setting' (SystemSet) */
  {
    SimStruct *rts = base_M->childSfunctions[11];
    sfcnOutputs(rts, 1);
  }

  /* Outputs for enable SubSystem: '<Root>/Application' incorporates:
   *  EnablePort: '<S1>/Enable'
   */
  if (base_B.SystemSetting > 0) {
    if (base_DWork.Application_MODE == SUBSYS_DISABLED) {
      base_DWork.Application_MODE = SUBSYS_ENABLED;
    }
  } else {
    if (base_DWork.Application_MODE == SUBSYS_ENABLED) {
      base_DWork.Application_MODE = SUBSYS_DISABLED;
    }
  }

  if (base_DWork.Application_MODE == SUBSYS_ENABLED) {
    /* Level2 S-Function Block: '<S1>/CPV Image Processing' (cpvStart) */
    {
      SimStruct *rts = base_M->childSfunctions[0];
      sfcnOutputs(rts, 1);
    }

    /* DataStoreWrite: '<S1>/Data Store Write' */
    memcpy((void *)(&base_DWork.Image[0]), (void *)(&base_B.CPVImageProcessing[0]),
           (uint32_T)((char_T *)(&base_B.CPVImageProcessing[1]) - (char_T *)
                      (&base_B.CPVImageProcessing[0])) << 4U);

    /* Level2 S-Function Block: '<S1>/Task Setting' (TaskSet) */
    {
      SimStruct *rts = base_M->childSfunctions[1];
      sfcnOutputs(rts, 1);
    }

    /* DataStoreRead: '<S6>/Data Store Read' */
    memcpy((void *)(&base_B.DataStoreRead[0]), (void *)(&base_DWork.Object[0]),
           (uint32_T)((char_T *)(&base_DWork.Object[1]) - (char_T *)
                      (&base_DWork.Object[0])) << 4U);

    /* Level2 S-Function Block: '<S1>/DS4504_ETH_Receive' (ds4504_read_uint32_array) */
    {
      SimStruct *rts = base_M->childSfunctions[2];
      sfcnOutputs(rts, 1);
    }

    /* Level2 S-Function Block: '<S1>/DSDecode32 ' (dsa_dsdecode32) */
    {
      SimStruct *rts = base_M->childSfunctions[3];
      sfcnOutputs(rts, 1);
    }

    /* Level2 S-Function Block: '<S6>/hand02Traj' (hand02Traj) */
    {
      SimStruct *rts = base_M->childSfunctions[4];
      sfcnOutputs(rts, 1);
    }

    /* Level2 S-Function Block: '<S6>/hand02JntAngLimit' (hand02JntAngLimit) */
    {
      SimStruct *rts = base_M->childSfunctions[5];
      sfcnOutputs(rts, 1);
    }

    /* Level2 S-Function Block: '<S5>/hand02Enc2JntAng' (hand02Enc2JntAng) */
    {
      SimStruct *rts = base_M->childSfunctions[6];
      sfcnOutputs(rts, 1);
    }

    /* Level2 S-Function Block: '<S5>/hand02Ctrl' (hand02Ctrl) */
    {
      SimStruct *rts = base_M->childSfunctions[7];
      sfcnOutputs(rts, 1);
    }

    /* Level2 S-Function Block: '<S5>/hand02JntTrq2DA' (hand02JntTrq2DA) */
    {
      SimStruct *rts = base_M->childSfunctions[8];
      sfcnOutputs(rts, 1);
    }

    /* Level2 S-Function Block: '<S5>/hand02DALimit' (hand02DALimit) */
    {
      SimStruct *rts = base_M->childSfunctions[9];
      sfcnOutputs(rts, 1);
    }
  }

  /* end of Outputs for SubSystem: '<Root>/Application' */

  /* Outputs for trigger SubSystem: '<Root>/simState SET' incorporates:
   *  TriggerPort: '<S4>/Trigger'
   */
  if (rt_I32ZCFcn(FALLING_ZERO_CROSSING,
                  &base_PrevZCSigState.simStateSET_Trig_ZCE,
                  (base_B.SystemSetting)) != NO_ZCEVENT) {
    /* This comment workarounds a Real-Time Workshop code generation problem */

    /* dSPACE S-Function Block: <S4>/S-Function1 (simState SET) */
    simState = STOP;
  }

  /* end of Outputs for SubSystem: '<Root>/simState SET' */

  /* Level2 S-Function Block: '<Root>/DS4504_ETH_Setup' (ds4504_init) */
  {
    SimStruct *rts = base_M->childSfunctions[12];
    sfcnOutputs(rts, 1);
  }

  /* This comment workarounds a Real-Time Workshop code generation problem */

  /* user code (Output function Trailer) */
  /* dSPACE Data Capture block: (none) */
  /* ... Service number: 1 */
  /* ... Service name:   (default) */
  if (rtmIsContinuousTask(base_M, 0) && rtmIsMajorTimeStep(base_M)) {
    host_service(1, rtk_current_task_absolute_time_ptr_get());

#ifdef RTT_ENABLE

    DsDaq_Service(1, (DsDaqSTimestampStruct *)
                  rtk_current_task_absolute_time_ptr_get());

#endif

  }

  /* tid is required for a uniform function interface.
   * Argument tid is not used in the function. */
  UNUSED_PARAMETER(tid);
}

/* Model update function */
static void base_update(int_T tid)
{
  /* Level2 S-Function Block: '<Root>/DS4504_ETH_Setup' (ds4504_init) */
  {
    SimStruct *rts = base_M->childSfunctions[12];
    sfcnUpdate(rts, 1);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Update absolute time for base rate */
  if (!(++base_M->Timing.clockTick0))
    ++base_M->Timing.clockTickH0;
  base_M->Timing.t[0] = base_M->Timing.clockTick0 * base_M->Timing.stepSize0 +
    base_M->Timing.clockTickH0 * base_M->Timing.stepSize0 * 4294967296.0;

  {
    /* Update absolute timer for sample time: [0.001s, 0.0s] */
    if (!(++base_M->Timing.clockTick1))
      ++base_M->Timing.clockTickH1;
    base_M->Timing.t[1] = base_M->Timing.clockTick1 * base_M->Timing.stepSize1 +
      base_M->Timing.clockTickH1 * base_M->Timing.stepSize1 * 4294967296.0;
  }

  /* tid is required for a uniform function interface.
   * Argument tid is not used in the function. */
  UNUSED_PARAMETER(tid);
}

/* Model initialize function */
void base_initialize(boolean_T firstTime)
{
  (void)firstTime;

  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)base_M,0,
                sizeof(RT_MODEL_base));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&base_M->solverInfo, &base_M->Timing.simTimeStep);
    rtsiSetTPtr(&base_M->solverInfo, &rtmGetTPtr(base_M));
    rtsiSetStepSizePtr(&base_M->solverInfo, &base_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&base_M->solverInfo, (&rtmGetErrorStatus(base_M)));
    rtsiSetRTModelPtr(&base_M->solverInfo, base_M);
  }

  rtsiSetSimTimeStep(&base_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetSolverName(&base_M->solverInfo,"FixedStepDiscrete");
  base_M->solverInfoPtr = (&base_M->solverInfo);

  /* Initialize timing info */
  {
    int_T *mdlTsMap = base_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    base_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    base_M->Timing.sampleTimes = (&base_M->Timing.sampleTimesArray[0]);
    base_M->Timing.offsetTimes = (&base_M->Timing.offsetTimesArray[0]);

    /* task periods */
    base_M->Timing.sampleTimes[0] = (0.0);
    base_M->Timing.sampleTimes[1] = (0.001);

    /* task offsets */
    base_M->Timing.offsetTimes[0] = (0.0);
    base_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(base_M, &base_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = base_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    base_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(base_M, -1);
  base_M->Timing.stepSize0 = 0.001;
  base_M->Timing.stepSize1 = 0.001;
  base_M->Timing.stepSize2 = 2.3283064365386963E-010;
  base_M->solverInfoPtr = (&base_M->solverInfo);
  base_M->Timing.stepSize = (0.001);
  rtsiSetFixedStepSize(&base_M->solverInfo, 0.001);
  rtsiSetSolverMode(&base_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  base_M->ModelData.blockIO = ((void *) &base_B);
  (void) memset(((void *) &base_B),0,
                sizeof(BlockIO_base));

  {
    int_T i;
    for (i = 0; i < 16; i++) {
      base_B.CPVImageProcessing[i] = 0.0;
    }

    for (i = 0; i < 16; i++) {
      base_B.DataStoreRead[i] = 0.0;
    }

    for (i = 0; i < 10; i++) {
      base_B.hand02Traj[i] = 0.0;
    }

    for (i = 0; i < 10; i++) {
      base_B.hand02JntAngLimit[i] = 0.0;
    }

    for (i = 0; i < 10; i++) {
      base_B.hand02Enc2JntAng[i] = 0.0;
    }

    for (i = 0; i < 10; i++) {
      base_B.hand02Ctrl[i] = 0.0;
    }

    for (i = 0; i < 10; i++) {
      base_B.hand02JntTrq2DA[i] = 0.0;
    }

    for (i = 0; i < 10; i++) {
      base_B.hand02DALimit[i] = 0.0;
    }

    base_B.DS4504_ETH_Setup_o1 = 0.0;
    base_B.DS4504_ETH_Setup_o2 = 0.0;
    base_B.DS4504_ETH_Setup_o3 = 0.0;
    base_B.TaskSetting = 0.0;
    base_B.DS4504_ETH_Receive_o2 = 0.0;
    base_B.DS4504_ETH_Receive_o3 = 0.0;
    base_B.DS4504_ETH_Receive_o4 = 0.0;
    base_B.DS4504_ETH_Receive_o5[0] = 0.0;
    base_B.DS4504_ETH_Receive_o5[1] = 0.0;
    base_B.DS4504_ETH_Receive_o5[2] = 0.0;
    base_B.DS4504_ETH_Receive_o5[3] = 0.0;
    base_B.DSDecode32[0] = 0.0;
    base_B.DSDecode32[1] = 0.0;
    base_B.DSDecode32[2] = 0.0;
    base_B.DSDecode32[3] = 0.0;
  }

  /* parameters */
  base_M->ModelData.defaultParam = ((real_T *) &base_P);

  /* states (dwork) */
  base_M->Work.dwork = ((void *) &base_DWork);
  (void) memset((void *)&base_DWork, 0,
                sizeof(D_Work_base));

  {
    int_T i;
    for (i = 0; i < 16; i++) {
      base_DWork.Image[i] = 0.0;
    }
  }

  {
    int_T i;
    for (i = 0; i < 16; i++) {
      base_DWork.Object[i] = 0.0;
    }
  }

  base_DWork.SystemSetting_RWORK = 0.0;

  {
    int_T i;
    for (i = 0; i < 16; i++) {
      base_DWork.CPVImageProcessing_RWORK[i] = 0.0;
    }
  }

  base_DWork.TaskSetting_RWORK = 0.0;

  {
    int_T i;
    for (i = 0; i < 10; i++) {
      base_DWork.hand02Traj_RWORK[i] = 0.0;
    }
  }

  {
    int_T i;
    for (i = 0; i < 10; i++) {
      base_DWork.hand02Ctrl_RWORK[i] = 0.0;
    }
  }

  base_DWork.hand02DALimit_RWORK = 0.0;

  /* child S-Function registration */
  {
    RTWSfcnInfo *sfcnInfo = &base_M->NonInlinedSFcns.sfcnInfo;
    base_M->sfcnInfo = (sfcnInfo);
    rtssSetErrorStatusPtr(sfcnInfo, (&rtmGetErrorStatus(base_M)));
    rtssSetNumRootSampTimesPtr(sfcnInfo, &base_M->Sizes.numSampTimes);
    rtssSetTPtrPtr(sfcnInfo, &rtmGetTPtr(base_M));
    rtssSetTStartPtr(sfcnInfo, &rtmGetTStart(base_M));
    rtssSetTFinalPtr(sfcnInfo, &rtmGetTFinal(base_M));
    rtssSetTimeOfLastOutputPtr(sfcnInfo, &rtmGetTimeOfLastOutput(base_M));
    rtssSetStepSizePtr(sfcnInfo, &base_M->Timing.stepSize);
    rtssSetStopRequestedPtr(sfcnInfo, &rtmGetStopRequested(base_M));
    rtssSetDerivCacheNeedsResetPtr(sfcnInfo,
      &base_M->ModelData.derivCacheNeedsReset);
    rtssSetZCCacheNeedsResetPtr(sfcnInfo, &base_M->ModelData.zCCacheNeedsReset);
    rtssSetBlkStateChangePtr(sfcnInfo, &base_M->ModelData.blkStateChange);
    rtssSetSampleHitsPtr(sfcnInfo, &base_M->Timing.sampleHits);
    rtssSetPerTaskSampleHitsPtr(sfcnInfo, &base_M->Timing.perTaskSampleHits);
    rtssSetSimModePtr(sfcnInfo, &base_M->simMode);
    rtssSetSolverInfoPtr(sfcnInfo, &base_M->solverInfoPtr);
  }

  base_M->Sizes.numSFcns = (13);

  /* register each child */
  {
    (void) memset((void *)&base_M->NonInlinedSFcns.childSFunctions[0],0,
                  13*sizeof(SimStruct));
    base_M->childSfunctions = (&base_M->NonInlinedSFcns.childSFunctionPtrs[0]);

    {
      int_T i;
      for (i = 0; i < 13; i++) {
        base_M->childSfunctions[i] = (&base_M->NonInlinedSFcns.childSFunctions[i]);
      }
    }

    /* Level2 S-Function Block: base/<S1>/CPV Image Processing (cpvStart) */
    {
      SimStruct *rts = base_M->childSfunctions[0];

      /* timing info */
      time_T *sfcnPeriod = base_M->NonInlinedSFcns.Sfcn0.sfcnPeriod;
      time_T *sfcnOffset = base_M->NonInlinedSFcns.Sfcn0.sfcnOffset;
      int_T *sfcnTsMap = base_M->NonInlinedSFcns.Sfcn0.sfcnTsMap;
      (void) memset((void*)sfcnPeriod,0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset,0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &base_M->NonInlinedSFcns.blkInfo2[0]);
        ssSetRTWSfcnInfo(rts, base_M->sfcnInfo);
      }

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &base_M->NonInlinedSFcns.methods2[0]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &base_M->NonInlinedSFcns.methods3[0]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &base_M->NonInlinedSFcns.Sfcn0.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 16);
          ssSetOutputPortSignal(rts, 0, ((real_T *) base_B.CPVImageProcessing));
        }
      }

      /* path info */
      ssSetModelName(rts, "CPV Image Processing");
      ssSetPath(rts, "base/Application/CPV Image Processing");
      ssSetRTModel(rts,base_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* work vectors */
      ssSetRWork(rts, (real_T *) &base_DWork.CPVImageProcessing_RWORK[0]);
      ssSetIWork(rts, (int_T *) &base_DWork.CPVImageProcessing_IWORK[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &base_M->NonInlinedSFcns.Sfcn0.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &base_M->NonInlinedSFcns.Sfcn0.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 2);

        /* RWORK */
        ssSetDWorkWidth(rts, 0, 16);
        ssSetDWorkDataType(rts, 0,SS_DOUBLE);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &base_DWork.CPVImageProcessing_RWORK[0]);

        /* IWORK */
        ssSetDWorkWidth(rts, 1, 2);
        ssSetDWorkDataType(rts, 1,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 1, 0);
        ssSetDWork(rts, 1, &base_DWork.CPVImageProcessing_IWORK[0]);
      }

      /* registration */
      cpvStart(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.001);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
    }

    /* Level2 S-Function Block: base/<S1>/Task Setting (TaskSet) */
    {
      SimStruct *rts = base_M->childSfunctions[1];

      /* timing info */
      time_T *sfcnPeriod = base_M->NonInlinedSFcns.Sfcn1.sfcnPeriod;
      time_T *sfcnOffset = base_M->NonInlinedSFcns.Sfcn1.sfcnOffset;
      int_T *sfcnTsMap = base_M->NonInlinedSFcns.Sfcn1.sfcnTsMap;
      (void) memset((void*)sfcnPeriod,0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset,0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &base_M->NonInlinedSFcns.blkInfo2[1]);
        ssSetRTWSfcnInfo(rts, base_M->sfcnInfo);
      }

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &base_M->NonInlinedSFcns.methods2[1]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &base_M->NonInlinedSFcns.methods3[1]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &base_M->NonInlinedSFcns.Sfcn1.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *) &base_B.TaskSetting));
        }
      }

      /* path info */
      ssSetModelName(rts, "Task Setting");
      ssSetPath(rts, "base/Application/Task Setting");
      ssSetRTModel(rts,base_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* work vectors */
      ssSetRWork(rts, (real_T *) &base_DWork.TaskSetting_RWORK);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &base_M->NonInlinedSFcns.Sfcn1.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &base_M->NonInlinedSFcns.Sfcn1.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* RWORK */
        ssSetDWorkWidth(rts, 0, 1);
        ssSetDWorkDataType(rts, 0,SS_DOUBLE);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &base_DWork.TaskSetting_RWORK);
      }

      /* registration */
      TaskSet(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.001);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
    }

    /* Level2 S-Function Block: base/<S1>/DS4504_ETH_Receive (ds4504_read_uint32_array) */
    {
      SimStruct *rts = base_M->childSfunctions[2];

      /* timing info */
      time_T *sfcnPeriod = base_M->NonInlinedSFcns.Sfcn2.sfcnPeriod;
      time_T *sfcnOffset = base_M->NonInlinedSFcns.Sfcn2.sfcnOffset;
      int_T *sfcnTsMap = base_M->NonInlinedSFcns.Sfcn2.sfcnTsMap;
      (void) memset((void*)sfcnPeriod,0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset,0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &base_M->NonInlinedSFcns.blkInfo2[2]);
        ssSetRTWSfcnInfo(rts, base_M->sfcnInfo);
      }

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &base_M->NonInlinedSFcns.methods2[2]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &base_M->NonInlinedSFcns.methods3[2]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts, &base_M->
          NonInlinedSFcns.Sfcn2.inputPortInfo[0]);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &base_M->NonInlinedSFcns.Sfcn2.UPtrs0;
          sfcnUPtrs[0] = &base_P.Constant_Value;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &base_M->NonInlinedSFcns.Sfcn2.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 5);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 8);
          ssSetOutputPortSignal(rts, 0, ((uint32_T *)
            base_B.DS4504_ETH_Receive_o1));
        }

        /* port 1 */
        {
          _ssSetOutputPortNumDimensions(rts, 1, 1);
          ssSetOutputPortWidth(rts, 1, 1);
          ssSetOutputPortSignal(rts, 1, ((real_T *)
            &base_B.DS4504_ETH_Receive_o2));
        }

        /* port 2 */
        {
          _ssSetOutputPortNumDimensions(rts, 2, 1);
          ssSetOutputPortWidth(rts, 2, 1);
          ssSetOutputPortSignal(rts, 2, ((real_T *)
            &base_B.DS4504_ETH_Receive_o3));
        }

        /* port 3 */
        {
          _ssSetOutputPortNumDimensions(rts, 3, 1);
          ssSetOutputPortWidth(rts, 3, 1);
          ssSetOutputPortSignal(rts, 3, ((real_T *)
            &base_B.DS4504_ETH_Receive_o4));
        }

        /* port 4 */
        {
          _ssSetOutputPortNumDimensions(rts, 4, 1);
          ssSetOutputPortWidth(rts, 4, 4);
          ssSetOutputPortSignal(rts, 4, ((real_T *) base_B.DS4504_ETH_Receive_o5));
        }
      }

      /* path info */
      ssSetModelName(rts, "DS4504_ETH_Receive");
      ssSetPath(rts, "base/Application/DS4504_ETH_Receive");
      ssSetRTModel(rts,base_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &base_M->NonInlinedSFcns.Sfcn2.params;
        ssSetSFcnParamsCount(rts, 6);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)&base_P.DS4504_ETH_Receive_P1_Size[0]);
        ssSetSFcnParam(rts, 1, (mxArray*)&base_P.DS4504_ETH_Receive_P2_Size[0]);
        ssSetSFcnParam(rts, 2, (mxArray*)&base_P.DS4504_ETH_Receive_P3_Size[0]);
        ssSetSFcnParam(rts, 3, (mxArray*)&base_P.DS4504_ETH_Receive_P4_Size[0]);
        ssSetSFcnParam(rts, 4, (mxArray*)&base_P.DS4504_ETH_Receive_P5_Size[0]);
        ssSetSFcnParam(rts, 5, (mxArray*)&base_P.DS4504_ETH_Receive_P6_Size[0]);
      }

      /* work vectors */
      ssSetIWork(rts, (int_T *) &base_DWork.DS4504_ETH_Receive_IWORK[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &base_M->NonInlinedSFcns.Sfcn2.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &base_M->NonInlinedSFcns.Sfcn2.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* IWORK */
        ssSetDWorkWidth(rts, 0, 5);
        ssSetDWorkDataType(rts, 0,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &base_DWork.DS4504_ETH_Receive_IWORK[0]);
      }

      /* registration */
      ds4504_read_uint32_array(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.001);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortConnected(rts, 1, 0);
      _ssSetOutputPortConnected(rts, 2, 0);
      _ssSetOutputPortConnected(rts, 3, 0);
      _ssSetOutputPortConnected(rts, 4, 0);
      _ssSetOutputPortBeingMerged(rts, 0, 0);
      _ssSetOutputPortBeingMerged(rts, 1, 0);
      _ssSetOutputPortBeingMerged(rts, 2, 0);
      _ssSetOutputPortBeingMerged(rts, 3, 0);
      _ssSetOutputPortBeingMerged(rts, 4, 0);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
    }

    /* Level2 S-Function Block: base/<S1>/DSDecode32  (dsa_dsdecode32) */
    {
      SimStruct *rts = base_M->childSfunctions[3];

      /* timing info */
      time_T *sfcnPeriod = base_M->NonInlinedSFcns.Sfcn3.sfcnPeriod;
      time_T *sfcnOffset = base_M->NonInlinedSFcns.Sfcn3.sfcnOffset;
      int_T *sfcnTsMap = base_M->NonInlinedSFcns.Sfcn3.sfcnTsMap;
      (void) memset((void*)sfcnPeriod,0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset,0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &base_M->NonInlinedSFcns.blkInfo2[3]);
        ssSetRTWSfcnInfo(rts, base_M->sfcnInfo);
      }

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &base_M->NonInlinedSFcns.methods2[3]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &base_M->NonInlinedSFcns.methods3[3]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts, &base_M->
          NonInlinedSFcns.Sfcn3.inputPortInfo[0]);

        /* port 0 */
        {
          uint32_T const **sfcnUPtrs = (uint32_T const **)
            &base_M->NonInlinedSFcns.Sfcn3.UPtrs0;

          {
            int_T i1;
            const uint32_T *u0 = base_B.DS4504_ETH_Receive_o1;
            for (i1=0; i1 < 8; i1++) {
              sfcnUPtrs[i1] = &u0[i1];
            }
          }

          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 8);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &base_M->NonInlinedSFcns.Sfcn3.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 4);
          ssSetOutputPortSignal(rts, 0, ((real_T *) base_B.DSDecode32));
        }
      }

      /* path info */
      ssSetModelName(rts, "DSDecode32 ");
      ssSetPath(rts, "base/Application/DSDecode32 ");
      ssSetRTModel(rts,base_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &base_M->NonInlinedSFcns.Sfcn3.params;
        ssSetSFcnParamsCount(rts, 6);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)&base_P.DSDecode32_P1_Size[0]);
        ssSetSFcnParam(rts, 1, (mxArray*)&base_P.DSDecode32_P2_Size[0]);
        ssSetSFcnParam(rts, 2, (mxArray*)&base_P.DSDecode32_P3_Size[0]);
        ssSetSFcnParam(rts, 3, (mxArray*)&base_P.DSDecode32_P4_Size[0]);
        ssSetSFcnParam(rts, 4, (mxArray*)&base_P.DSDecode32_P5_Size[0]);
        ssSetSFcnParam(rts, 5, (mxArray*)&base_P.DSDecode32_P6_Size[0]);
      }

      /* work vectors */
      ssSetIWork(rts, (int_T *) &base_DWork.DSDecode32_IWORK);
      ssSetPWork(rts, (void **) &base_DWork.DSDecode32_PWORK);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &base_M->NonInlinedSFcns.Sfcn3.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &base_M->NonInlinedSFcns.Sfcn3.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 2);

        /* IWORK */
        ssSetDWorkWidth(rts, 0, 1);
        ssSetDWorkDataType(rts, 0,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &base_DWork.DSDecode32_IWORK);

        /* PWORK */
        ssSetDWorkWidth(rts, 1, 1);
        ssSetDWorkDataType(rts, 1,SS_POINTER);
        ssSetDWorkComplexSignal(rts, 1, 0);
        ssSetDWork(rts, 1, &base_DWork.DSDecode32_PWORK);
      }

      /* registration */
      dsa_dsdecode32(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.001);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetInputPortWidth(rts, 0, 8);
      ssSetInputPortDataType(rts, 0, SS_UINT32);
      ssSetInputPortComplexSignal(rts, 0, 0);
      ssSetInputPortFrameData(rts, 0, 0);
      ssSetOutputPortWidth(rts, 0, 4);
      ssSetOutputPortDataType(rts, 0, SS_DOUBLE);
      ssSetOutputPortComplexSignal(rts, 0, 0);
      ssSetOutputPortFrameData(rts, 0, 0);
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
    }

    /* Level2 S-Function Block: base/<S6>/hand02Traj (hand02Traj) */
    {
      SimStruct *rts = base_M->childSfunctions[4];

      /* timing info */
      time_T *sfcnPeriod = base_M->NonInlinedSFcns.Sfcn4.sfcnPeriod;
      time_T *sfcnOffset = base_M->NonInlinedSFcns.Sfcn4.sfcnOffset;
      int_T *sfcnTsMap = base_M->NonInlinedSFcns.Sfcn4.sfcnTsMap;
      (void) memset((void*)sfcnPeriod,0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset,0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &base_M->NonInlinedSFcns.blkInfo2[4]);
        ssSetRTWSfcnInfo(rts, base_M->sfcnInfo);
      }

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &base_M->NonInlinedSFcns.methods2[4]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &base_M->NonInlinedSFcns.methods3[4]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 4);
        ssSetPortInfoForInputs(rts, &base_M->
          NonInlinedSFcns.Sfcn4.inputPortInfo[0]);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &base_M->NonInlinedSFcns.Sfcn4.UPtrs0;
          sfcnUPtrs[0] = &base_B.TaskSetting;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }

        /* port 1 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &base_M->NonInlinedSFcns.Sfcn4.UPtrs1;

          {
            int_T i1;
            const real_T *u1 = base_B.DataStoreRead;
            for (i1=0; i1 < 16; i1++) {
              sfcnUPtrs[i1] = &u1[i1];
            }
          }

          ssSetInputPortSignalPtrs(rts, 1, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 1, 1);
          ssSetInputPortWidth(rts, 1, 16);
        }

        /* port 2 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &base_M->NonInlinedSFcns.Sfcn4.UPtrs2;

          {
            int_T i1;
            for (i1=0; i1 < 18; i1++) {
              sfcnUPtrs[i1] = &base_RGND;
            }
          }

          ssSetInputPortSignalPtrs(rts, 2, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 2, 1);
          ssSetInputPortWidth(rts, 2, 18);
        }

        /* port 3 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &base_M->NonInlinedSFcns.Sfcn4.UPtrs3;
          sfcnUPtrs[0] = base_B.DSDecode32;
          sfcnUPtrs[1] = &base_B.DSDecode32[1];
          sfcnUPtrs[2] = &base_B.DSDecode32[2];
          sfcnUPtrs[3] = &base_B.DSDecode32[3];
          ssSetInputPortSignalPtrs(rts, 3, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 3, 1);
          ssSetInputPortWidth(rts, 3, 4);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &base_M->NonInlinedSFcns.Sfcn4.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 10);
          ssSetOutputPortSignal(rts, 0, ((real_T *) base_B.hand02Traj));
        }
      }

      /* path info */
      ssSetModelName(rts, "hand02Traj");
      ssSetPath(rts, "base/Application/Hand02 Trajectory/hand02Traj");
      ssSetRTModel(rts,base_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* work vectors */
      ssSetRWork(rts, (real_T *) &base_DWork.hand02Traj_RWORK[0]);
      ssSetIWork(rts, (int_T *) &base_DWork.hand02Traj_IWORK);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &base_M->NonInlinedSFcns.Sfcn4.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &base_M->NonInlinedSFcns.Sfcn4.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 2);

        /* RWORK */
        ssSetDWorkWidth(rts, 0, 10);
        ssSetDWorkDataType(rts, 0,SS_DOUBLE);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &base_DWork.hand02Traj_RWORK[0]);

        /* IWORK */
        ssSetDWorkWidth(rts, 1, 1);
        ssSetDWorkDataType(rts, 1,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 1, 0);
        ssSetDWork(rts, 1, &base_DWork.hand02Traj_IWORK);
      }

      /* registration */
      hand02Traj(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.001);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);
      _ssSetInputPortConnected(rts, 1, 1);
      _ssSetInputPortConnected(rts, 2, 1);
      _ssSetInputPortConnected(rts, 3, 1);
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
      ssSetInputPortBufferDstPort(rts, 1, -1);
      ssSetInputPortBufferDstPort(rts, 2, -1);
      ssSetInputPortBufferDstPort(rts, 3, -1);
    }

    /* Level2 S-Function Block: base/<S6>/hand02JntAngLimit (hand02JntAngLimit) */
    {
      SimStruct *rts = base_M->childSfunctions[5];

      /* timing info */
      time_T *sfcnPeriod = base_M->NonInlinedSFcns.Sfcn5.sfcnPeriod;
      time_T *sfcnOffset = base_M->NonInlinedSFcns.Sfcn5.sfcnOffset;
      int_T *sfcnTsMap = base_M->NonInlinedSFcns.Sfcn5.sfcnTsMap;
      (void) memset((void*)sfcnPeriod,0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset,0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &base_M->NonInlinedSFcns.blkInfo2[5]);
        ssSetRTWSfcnInfo(rts, base_M->sfcnInfo);
      }

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &base_M->NonInlinedSFcns.methods2[5]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &base_M->NonInlinedSFcns.methods3[5]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts, &base_M->
          NonInlinedSFcns.Sfcn5.inputPortInfo[0]);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &base_M->NonInlinedSFcns.Sfcn5.UPtrs0;

          {
            int_T i1;
            const real_T *u0 = base_B.hand02Traj;
            for (i1=0; i1 < 10; i1++) {
              sfcnUPtrs[i1] = &u0[i1];
            }
          }

          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 10);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &base_M->NonInlinedSFcns.Sfcn5.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 10);
          ssSetOutputPortSignal(rts, 0, ((real_T *) base_B.hand02JntAngLimit));
        }
      }

      /* path info */
      ssSetModelName(rts, "hand02JntAngLimit");
      ssSetPath(rts, "base/Application/Hand02 Trajectory/hand02JntAngLimit");
      ssSetRTModel(rts,base_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* registration */
      hand02JntAngLimit(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.001);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
    }

    /* Level2 S-Function Block: base/<S5>/hand02Enc2JntAng (hand02Enc2JntAng) */
    {
      SimStruct *rts = base_M->childSfunctions[6];

      /* timing info */
      time_T *sfcnPeriod = base_M->NonInlinedSFcns.Sfcn6.sfcnPeriod;
      time_T *sfcnOffset = base_M->NonInlinedSFcns.Sfcn6.sfcnOffset;
      int_T *sfcnTsMap = base_M->NonInlinedSFcns.Sfcn6.sfcnTsMap;
      (void) memset((void*)sfcnPeriod,0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset,0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &base_M->NonInlinedSFcns.blkInfo2[6]);
        ssSetRTWSfcnInfo(rts, base_M->sfcnInfo);
      }

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &base_M->NonInlinedSFcns.methods2[6]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &base_M->NonInlinedSFcns.methods3[6]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &base_M->NonInlinedSFcns.Sfcn6.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 10);
          ssSetOutputPortSignal(rts, 0, ((real_T *) base_B.hand02Enc2JntAng));
        }
      }

      /* path info */
      ssSetModelName(rts, "hand02Enc2JntAng");
      ssSetPath(rts, "base/Application/Hand02 Control/hand02Enc2JntAng");
      ssSetRTModel(rts,base_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* registration */
      hand02Enc2JntAng(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.001);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
    }

    /* Level2 S-Function Block: base/<S5>/hand02Ctrl (hand02Ctrl) */
    {
      SimStruct *rts = base_M->childSfunctions[7];

      /* timing info */
      time_T *sfcnPeriod = base_M->NonInlinedSFcns.Sfcn7.sfcnPeriod;
      time_T *sfcnOffset = base_M->NonInlinedSFcns.Sfcn7.sfcnOffset;
      int_T *sfcnTsMap = base_M->NonInlinedSFcns.Sfcn7.sfcnTsMap;
      (void) memset((void*)sfcnPeriod,0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset,0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &base_M->NonInlinedSFcns.blkInfo2[7]);
        ssSetRTWSfcnInfo(rts, base_M->sfcnInfo);
      }

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &base_M->NonInlinedSFcns.methods2[7]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &base_M->NonInlinedSFcns.methods3[7]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 2);
        ssSetPortInfoForInputs(rts, &base_M->
          NonInlinedSFcns.Sfcn7.inputPortInfo[0]);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &base_M->NonInlinedSFcns.Sfcn7.UPtrs0;

          {
            int_T i1;
            const real_T *u0 = base_B.hand02JntAngLimit;
            for (i1=0; i1 < 10; i1++) {
              sfcnUPtrs[i1] = &u0[i1];
            }
          }

          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 10);
        }

        /* port 1 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &base_M->NonInlinedSFcns.Sfcn7.UPtrs1;

          {
            int_T i1;
            const real_T *u1 = base_B.hand02Enc2JntAng;
            for (i1=0; i1 < 10; i1++) {
              sfcnUPtrs[i1] = &u1[i1];
            }
          }

          ssSetInputPortSignalPtrs(rts, 1, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 1, 1);
          ssSetInputPortWidth(rts, 1, 10);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &base_M->NonInlinedSFcns.Sfcn7.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 10);
          ssSetOutputPortSignal(rts, 0, ((real_T *) base_B.hand02Ctrl));
        }
      }

      /* path info */
      ssSetModelName(rts, "hand02Ctrl");
      ssSetPath(rts, "base/Application/Hand02 Control/hand02Ctrl");
      ssSetRTModel(rts,base_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* work vectors */
      ssSetRWork(rts, (real_T *) &base_DWork.hand02Ctrl_RWORK[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &base_M->NonInlinedSFcns.Sfcn7.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &base_M->NonInlinedSFcns.Sfcn7.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* RWORK */
        ssSetDWorkWidth(rts, 0, 10);
        ssSetDWorkDataType(rts, 0,SS_DOUBLE);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &base_DWork.hand02Ctrl_RWORK[0]);
      }

      /* registration */
      hand02Ctrl(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.001);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);
      _ssSetInputPortConnected(rts, 1, 1);
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
      ssSetInputPortBufferDstPort(rts, 1, -1);
    }

    /* Level2 S-Function Block: base/<S5>/hand02JntTrq2DA (hand02JntTrq2DA) */
    {
      SimStruct *rts = base_M->childSfunctions[8];

      /* timing info */
      time_T *sfcnPeriod = base_M->NonInlinedSFcns.Sfcn8.sfcnPeriod;
      time_T *sfcnOffset = base_M->NonInlinedSFcns.Sfcn8.sfcnOffset;
      int_T *sfcnTsMap = base_M->NonInlinedSFcns.Sfcn8.sfcnTsMap;
      (void) memset((void*)sfcnPeriod,0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset,0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &base_M->NonInlinedSFcns.blkInfo2[8]);
        ssSetRTWSfcnInfo(rts, base_M->sfcnInfo);
      }

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &base_M->NonInlinedSFcns.methods2[8]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &base_M->NonInlinedSFcns.methods3[8]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts, &base_M->
          NonInlinedSFcns.Sfcn8.inputPortInfo[0]);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &base_M->NonInlinedSFcns.Sfcn8.UPtrs0;

          {
            int_T i1;
            const real_T *u0 = base_B.hand02Ctrl;
            for (i1=0; i1 < 10; i1++) {
              sfcnUPtrs[i1] = &u0[i1];
            }
          }

          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 10);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &base_M->NonInlinedSFcns.Sfcn8.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 10);
          ssSetOutputPortSignal(rts, 0, ((real_T *) base_B.hand02JntTrq2DA));
        }
      }

      /* path info */
      ssSetModelName(rts, "hand02JntTrq2DA");
      ssSetPath(rts, "base/Application/Hand02 Control/hand02JntTrq2DA");
      ssSetRTModel(rts,base_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* registration */
      hand02JntTrq2DA(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.001);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
    }

    /* Level2 S-Function Block: base/<S5>/hand02DALimit (hand02DALimit) */
    {
      SimStruct *rts = base_M->childSfunctions[9];

      /* timing info */
      time_T *sfcnPeriod = base_M->NonInlinedSFcns.Sfcn9.sfcnPeriod;
      time_T *sfcnOffset = base_M->NonInlinedSFcns.Sfcn9.sfcnOffset;
      int_T *sfcnTsMap = base_M->NonInlinedSFcns.Sfcn9.sfcnTsMap;
      (void) memset((void*)sfcnPeriod,0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset,0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &base_M->NonInlinedSFcns.blkInfo2[9]);
        ssSetRTWSfcnInfo(rts, base_M->sfcnInfo);
      }

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &base_M->NonInlinedSFcns.methods2[9]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &base_M->NonInlinedSFcns.methods3[9]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts, &base_M->
          NonInlinedSFcns.Sfcn9.inputPortInfo[0]);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &base_M->NonInlinedSFcns.Sfcn9.UPtrs0;

          {
            int_T i1;
            const real_T *u0 = base_B.hand02JntTrq2DA;
            for (i1=0; i1 < 10; i1++) {
              sfcnUPtrs[i1] = &u0[i1];
            }
          }

          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 10);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &base_M->NonInlinedSFcns.Sfcn9.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 10);
          ssSetOutputPortSignal(rts, 0, ((real_T *) base_B.hand02DALimit));
        }
      }

      /* path info */
      ssSetModelName(rts, "hand02DALimit");
      ssSetPath(rts, "base/Application/Hand02 Control/hand02DALimit");
      ssSetRTModel(rts,base_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* work vectors */
      ssSetRWork(rts, (real_T *) &base_DWork.hand02DALimit_RWORK);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &base_M->NonInlinedSFcns.Sfcn9.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &base_M->NonInlinedSFcns.Sfcn9.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* RWORK */
        ssSetDWorkWidth(rts, 0, 1);
        ssSetDWorkDataType(rts, 0,SS_DOUBLE);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &base_DWork.hand02DALimit_RWORK);
      }

      /* registration */
      hand02DALimit(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.001);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);
      _ssSetOutputPortConnected(rts, 0, 0);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
    }

    /* Level2 S-Function Block: base/<S7>/DS100x_AliveFunction (ds4504_DS100xAlive) */
    {
      SimStruct *rts = base_M->childSfunctions[10];

      /* timing info */
      time_T *sfcnPeriod = base_M->NonInlinedSFcns.Sfcn10.sfcnPeriod;
      time_T *sfcnOffset = base_M->NonInlinedSFcns.Sfcn10.sfcnOffset;
      int_T *sfcnTsMap = base_M->NonInlinedSFcns.Sfcn10.sfcnTsMap;
      (void) memset((void*)sfcnPeriod,0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset,0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &base_M->NonInlinedSFcns.blkInfo2[10]);
        ssSetRTWSfcnInfo(rts, base_M->sfcnInfo);
      }

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &base_M->NonInlinedSFcns.methods2[10]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &base_M->NonInlinedSFcns.methods3[10]);
      }

      /* path info */
      ssSetModelName(rts, "DS100x_AliveFunction");
      ssSetPath(rts,
                "base/DS100x_AliveFunctionality/AliveGenSubsystem/DS100x_AliveFunction");
      ssSetRTModel(rts,base_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &base_M->NonInlinedSFcns.Sfcn10.params;
        ssSetSFcnParamsCount(rts, 1);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)&base_P.DS100x_AliveFunction_P1_Size[0]);
      }

      /* registration */
      ds4504_DS100xAlive(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, -1.0);
      ssSetOffsetTime(rts, 0, -2.0);
      sfcnTsMap[0] = 2;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      /* Update the BufferDstPort flags for each input port */
    }

    /* Level2 S-Function Block: base/<Root>/System Setting (SystemSet) */
    {
      SimStruct *rts = base_M->childSfunctions[11];

      /* timing info */
      time_T *sfcnPeriod = base_M->NonInlinedSFcns.Sfcn11.sfcnPeriod;
      time_T *sfcnOffset = base_M->NonInlinedSFcns.Sfcn11.sfcnOffset;
      int_T *sfcnTsMap = base_M->NonInlinedSFcns.Sfcn11.sfcnTsMap;
      (void) memset((void*)sfcnPeriod,0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset,0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &base_M->NonInlinedSFcns.blkInfo2[11]);
        ssSetRTWSfcnInfo(rts, base_M->sfcnInfo);
      }

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &base_M->NonInlinedSFcns.methods2[11]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &base_M->NonInlinedSFcns.methods3[11]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &base_M->NonInlinedSFcns.Sfcn11.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((int32_T *) &base_B.SystemSetting));
        }
      }

      /* path info */
      ssSetModelName(rts, "System Setting");
      ssSetPath(rts, "base/System Setting");
      ssSetRTModel(rts,base_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* work vectors */
      ssSetRWork(rts, (real_T *) &base_DWork.SystemSetting_RWORK);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &base_M->NonInlinedSFcns.Sfcn11.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &base_M->NonInlinedSFcns.Sfcn11.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* RWORK */
        ssSetDWorkWidth(rts, 0, 1);
        ssSetDWorkDataType(rts, 0,SS_DOUBLE);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &base_DWork.SystemSetting_RWORK);
      }

      /* registration */
      SystemSet(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.001);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
    }

    /* Level2 S-Function Block: base/<Root>/DS4504_ETH_Setup (ds4504_init) */
    {
      SimStruct *rts = base_M->childSfunctions[12];

      /* timing info */
      time_T *sfcnPeriod = base_M->NonInlinedSFcns.Sfcn12.sfcnPeriod;
      time_T *sfcnOffset = base_M->NonInlinedSFcns.Sfcn12.sfcnOffset;
      int_T *sfcnTsMap = base_M->NonInlinedSFcns.Sfcn12.sfcnTsMap;
      (void) memset((void*)sfcnPeriod,0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset,0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &base_M->NonInlinedSFcns.blkInfo2[12]);
        ssSetRTWSfcnInfo(rts, base_M->sfcnInfo);
      }

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &base_M->NonInlinedSFcns.methods2[12]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &base_M->NonInlinedSFcns.methods3[12]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &base_M->NonInlinedSFcns.Sfcn12.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 3);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *) &base_B.DS4504_ETH_Setup_o1));
        }

        /* port 1 */
        {
          _ssSetOutputPortNumDimensions(rts, 1, 1);
          ssSetOutputPortWidth(rts, 1, 1);
          ssSetOutputPortSignal(rts, 1, ((real_T *) &base_B.DS4504_ETH_Setup_o2));
        }

        /* port 2 */
        {
          _ssSetOutputPortNumDimensions(rts, 2, 1);
          ssSetOutputPortWidth(rts, 2, 1);
          ssSetOutputPortSignal(rts, 2, ((real_T *) &base_B.DS4504_ETH_Setup_o3));
        }
      }

      /* path info */
      ssSetModelName(rts, "DS4504_ETH_Setup");
      ssSetPath(rts, "base/DS4504_ETH_Setup");
      ssSetRTModel(rts,base_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &base_M->NonInlinedSFcns.Sfcn12.params;
        ssSetSFcnParamsCount(rts, 35);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)&base_P.DS4504_ETH_Setup_P1_Size[0]);
        ssSetSFcnParam(rts, 1, (mxArray*)&base_P.DS4504_ETH_Setup_P2_Size[0]);
        ssSetSFcnParam(rts, 2, (mxArray*)&base_P.DS4504_ETH_Setup_P3_Size[0]);
        ssSetSFcnParam(rts, 3, (mxArray*)&base_P.DS4504_ETH_Setup_P4_Size[0]);
        ssSetSFcnParam(rts, 4, (mxArray*)&base_P.DS4504_ETH_Setup_P5_Size[0]);
        ssSetSFcnParam(rts, 5, (mxArray*)&base_P.DS4504_ETH_Setup_P6_Size[0]);
        ssSetSFcnParam(rts, 6, (mxArray*)&base_P.DS4504_ETH_Setup_P7_Size[0]);
        ssSetSFcnParam(rts, 7, (mxArray*)&base_P.DS4504_ETH_Setup_P8_Size[0]);
        ssSetSFcnParam(rts, 8, (mxArray*)&base_P.DS4504_ETH_Setup_P9_Size[0]);
        ssSetSFcnParam(rts, 9, (mxArray*)&base_P.DS4504_ETH_Setup_P10_Size[0]);
        ssSetSFcnParam(rts, 10, (mxArray*)&base_P.DS4504_ETH_Setup_P11_Size[0]);
        ssSetSFcnParam(rts, 11, (mxArray*)&base_P.DS4504_ETH_Setup_P12_Size[0]);
        ssSetSFcnParam(rts, 12, (mxArray*)&base_P.DS4504_ETH_Setup_P13_Size[0]);
        ssSetSFcnParam(rts, 13, (mxArray*)&base_P.DS4504_ETH_Setup_P14_Size[0]);
        ssSetSFcnParam(rts, 14, (mxArray*)&base_P.DS4504_ETH_Setup_P15_Size[0]);
        ssSetSFcnParam(rts, 15, (mxArray*)&base_P.DS4504_ETH_Setup_P16_Size[0]);
        ssSetSFcnParam(rts, 16, (mxArray*)&base_P.DS4504_ETH_Setup_P17_Size[0]);
        ssSetSFcnParam(rts, 17, (mxArray*)&base_P.DS4504_ETH_Setup_P18_Size[0]);
        ssSetSFcnParam(rts, 18, (mxArray*)&base_P.DS4504_ETH_Setup_P19_Size[0]);
        ssSetSFcnParam(rts, 19, (mxArray*)&base_P.DS4504_ETH_Setup_P20_Size[0]);
        ssSetSFcnParam(rts, 20, (mxArray*)&base_P.DS4504_ETH_Setup_P21_Size[0]);
        ssSetSFcnParam(rts, 21, (mxArray*)&base_P.DS4504_ETH_Setup_P22_Size[0]);
        ssSetSFcnParam(rts, 22, (mxArray*)&base_P.DS4504_ETH_Setup_P23_Size[0]);
        ssSetSFcnParam(rts, 23, (mxArray*)&base_P.DS4504_ETH_Setup_P24_Size[0]);
        ssSetSFcnParam(rts, 24, (mxArray*)&base_P.DS4504_ETH_Setup_P25_Size[0]);
        ssSetSFcnParam(rts, 25, (mxArray*)&base_P.DS4504_ETH_Setup_P26_Size[0]);
        ssSetSFcnParam(rts, 26, (mxArray*)&base_P.DS4504_ETH_Setup_P27_Size[0]);
        ssSetSFcnParam(rts, 27, (mxArray*)&base_P.DS4504_ETH_Setup_P28_Size[0]);
        ssSetSFcnParam(rts, 28, (mxArray*)&base_P.DS4504_ETH_Setup_P29_Size[0]);
        ssSetSFcnParam(rts, 29, (mxArray*)&base_P.DS4504_ETH_Setup_P30_Size[0]);
        ssSetSFcnParam(rts, 30, (mxArray*)&base_P.DS4504_ETH_Setup_P31_Size[0]);
        ssSetSFcnParam(rts, 31, (mxArray*)&base_P.DS4504_ETH_Setup_P32_Size[0]);
        ssSetSFcnParam(rts, 32, (mxArray*)&base_P.DS4504_ETH_Setup_P33_Size[0]);
        ssSetSFcnParam(rts, 33, (mxArray*)&base_P.DS4504_ETH_Setup_P34_Size[0]);
        ssSetSFcnParam(rts, 34, (mxArray*)&base_P.DS4504_ETH_Setup_P35_Size[0]);
      }

      /* work vectors */
      ssSetIWork(rts, (int_T *) &base_DWork.DS4504_ETH_Setup_IWORK[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &base_M->NonInlinedSFcns.Sfcn12.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &base_M->NonInlinedSFcns.Sfcn12.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* IWORK */
        ssSetDWorkWidth(rts, 0, 2);
        ssSetDWorkDataType(rts, 0,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &base_DWork.DS4504_ETH_Setup_IWORK[0]);
      }

      /* registration */
      ds4504_init(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.001);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortConnected(rts, 1, 1);
      _ssSetOutputPortConnected(rts, 2, 0);
      _ssSetOutputPortBeingMerged(rts, 0, 0);
      _ssSetOutputPortBeingMerged(rts, 1, 0);
      _ssSetOutputPortBeingMerged(rts, 2, 0);

      /* Update the BufferDstPort flags for each input port */
    }
  }

  {
    /* user code (registration function declaration) */
    /*Call the macro that initializes the global TRC pointers
       inside the model initialization/registration function. */
    RTI_INIT_TRC_POINTERS();
  }

  base_PrevZCSigState.simStateSET_Trig_ZCE = UNINITIALIZED_ZCSIG;
}

/* Model terminate function */
void base_terminate(void)
{
  /* Level2 S-Function Block: '<Root>/System Setting' (SystemSet) */
  {
    SimStruct *rts = base_M->childSfunctions[11];
    sfcnTerminate(rts);
  }

  /* Terminate for enable SubSystem: '<Root>/Application' */

  /* Level2 S-Function Block: '<S1>/CPV Image Processing' (cpvStart) */
  {
    SimStruct *rts = base_M->childSfunctions[0];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S1>/Task Setting' (TaskSet) */
  {
    SimStruct *rts = base_M->childSfunctions[1];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S1>/DS4504_ETH_Receive' (ds4504_read_uint32_array) */
  {
    SimStruct *rts = base_M->childSfunctions[2];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S1>/DSDecode32 ' (dsa_dsdecode32) */
  {
    SimStruct *rts = base_M->childSfunctions[3];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S6>/hand02Traj' (hand02Traj) */
  {
    SimStruct *rts = base_M->childSfunctions[4];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S6>/hand02JntAngLimit' (hand02JntAngLimit) */
  {
    SimStruct *rts = base_M->childSfunctions[5];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S5>/hand02Enc2JntAng' (hand02Enc2JntAng) */
  {
    SimStruct *rts = base_M->childSfunctions[6];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S5>/hand02Ctrl' (hand02Ctrl) */
  {
    SimStruct *rts = base_M->childSfunctions[7];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S5>/hand02JntTrq2DA' (hand02JntTrq2DA) */
  {
    SimStruct *rts = base_M->childSfunctions[8];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S5>/hand02DALimit' (hand02DALimit) */
  {
    SimStruct *rts = base_M->childSfunctions[9];
    sfcnTerminate(rts);
  }

  /* end of Terminate for SubSystem: '<Root>/Application' */

  /* Level2 S-Function Block: '<Root>/DS4504_ETH_Setup' (ds4504_init) */
  {
    SimStruct *rts = base_M->childSfunctions[12];
    sfcnTerminate(rts);
  }

  /* Terminate for function call SubSystem: '<S2>/AliveGenSubsystem' */
  base_AliveGenSubsystem_Term();

  /* end of Terminate for SubSystem: '<S2>/AliveGenSubsystem' */
}

/*========================================================================*
 * Start of GRT compatible call interface                                 *
 *========================================================================*/
void MdlOutputs(int_T tid)
{
  base_output(tid);
}

void MdlUpdate(int_T tid)
{
  base_update(tid);
}

void MdlInitializeSizes(void)
{
  base_M->Sizes.numContStates = (0);   /* Number of continuous states */
  base_M->Sizes.numY = (0);            /* Number of model outputs */
  base_M->Sizes.numU = (0);            /* Number of model inputs */
  base_M->Sizes.sysDirFeedThru = (0);  /* The model is not direct feedthrough */
  base_M->Sizes.numSampTimes = (2);    /* Number of sample times */
  base_M->Sizes.numBlocks = (26);      /* Number of blocks */
  base_M->Sizes.numBlockIO = (19);     /* Number of block outputs */
  base_M->Sizes.numBlockPrms = (178);  /* Sum of parameter "widths" */
}

void MdlInitializeSampleTimes(void)
{
}

void MdlInitialize(void)
{
  /* Level2 S-Function Block: '<Root>/DS4504_ETH_Setup' (ds4504_init) */
  {
    SimStruct *rts = base_M->childSfunctions[12];
    sfcnInitializeConditions(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  base_AliveGenSubsystem_Init();
}

void MdlStart(void)
{
  {
    int32_T i;

    /* Level2 S-Function Block: '<Root>/System Setting' (SystemSet) */
    {
      SimStruct *rts = base_M->childSfunctions[11];
      sfcnStart(rts);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* Start for enable SubSystem: '<Root>/Application' */
    base_DWork.Application_MODE = SUBSYS_DISABLED;

    /* Level2 S-Function Block: '<S1>/CPV Image Processing' (cpvStart) */
    {
      SimStruct *rts = base_M->childSfunctions[0];
      sfcnStart(rts);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* Level2 S-Function Block: '<S1>/Task Setting' (TaskSet) */
    {
      SimStruct *rts = base_M->childSfunctions[1];
      sfcnStart(rts);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* Level2 S-Function Block: '<S1>/DS4504_ETH_Receive' (ds4504_read_uint32_array) */
    {
      SimStruct *rts = base_M->childSfunctions[2];
      sfcnStart(rts);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* Level2 S-Function Block: '<S1>/DSDecode32 ' (dsa_dsdecode32) */
    {
      SimStruct *rts = base_M->childSfunctions[3];
      sfcnStart(rts);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* Level2 S-Function Block: '<S6>/hand02Traj' (hand02Traj) */
    {
      SimStruct *rts = base_M->childSfunctions[4];
      sfcnStart(rts);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* Level2 S-Function Block: '<S5>/hand02Ctrl' (hand02Ctrl) */
    {
      SimStruct *rts = base_M->childSfunctions[7];
      sfcnStart(rts);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* Level2 S-Function Block: '<S5>/hand02DALimit' (hand02DALimit) */
    {
      SimStruct *rts = base_M->childSfunctions[9];
      sfcnStart(rts);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    for (i = 0; i < 16; i++) {
      /* Start for DataStoreMemory: '<S1>/Data Store Memory Image' */
      base_DWork.Image[i] = base_P.DataStoreMemoryImage_InitialVal[i];

      /* Start for DataStoreMemory: '<S1>/Data Store Memory Object' */
      base_DWork.Object[i] = base_P.DataStoreMemoryObject_InitialVa[i];
    }

    /* end of Start for SubSystem: '<Root>/Application' */

    /* Level2 S-Function Block: '<Root>/DS4504_ETH_Setup' (ds4504_init) */
    {
      SimStruct *rts = base_M->childSfunctions[12];
      sfcnStart(rts);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    base_AliveGenSubsystem_Start();
  }

  MdlInitialize();
}

RT_MODEL_base *base(void)
{
  base_initialize(1);
  return base_M;
}

void MdlTerminate(void)
{
  base_terminate();
}

/*========================================================================*
 * End of GRT compatible call interface                                   *
 *========================================================================*/
