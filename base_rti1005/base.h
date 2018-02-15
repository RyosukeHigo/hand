/*
 * base.h
 *
 * Real-Time Workshop code generation for Simulink model "base.mdl".
 *
 * Model Version              : 1.480
 * Real-Time Workshop version : 7.2  (R2008b)  04-Aug-2008
 * C source code generated on : Thu Feb 15 20:53:42 2018
 */
#ifndef RTW_HEADER_base_h_
#define RTW_HEADER_base_h_
#ifndef base_COMMON_INCLUDES_
# define base_COMMON_INCLUDES_
#include <brtenv.h>
#include <rtkernel.h>
#include <rti_assert.h>
#include <rtidefineddatatypes.h>
#include <rti_sim_engine_exp.h>
#include <stddef.h>
#include <string.h>
#include "rtwtypes.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "rt_i32zcfcn.h"
#include "rt_nonfinite.h"
#endif                                 /* base_COMMON_INCLUDES_ */

#include "base_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetBlkStateChangeFlag
# define rtmGetBlkStateChangeFlag(rtm) ((rtm)->ModelData.blkStateChange)
#endif

#ifndef rtmSetBlkStateChangeFlag
# define rtmSetBlkStateChangeFlag(rtm, val) ((rtm)->ModelData.blkStateChange = (val))
#endif

#ifndef rtmGetBlockIO
# define rtmGetBlockIO(rtm)            ((rtm)->ModelData.blockIO)
#endif

#ifndef rtmSetBlockIO
# define rtmSetBlockIO(rtm, val)       ((rtm)->ModelData.blockIO = (val))
#endif

#ifndef rtmGetChecksums
# define rtmGetChecksums(rtm)          ((rtm)->Sizes.checksums)
#endif

#ifndef rtmSetChecksums
# define rtmSetChecksums(rtm, val)     ((rtm)->Sizes.checksums = (val))
#endif

#ifndef rtmGetConstBlockIO
# define rtmGetConstBlockIO(rtm)       ((rtm)->ModelData.constBlockIO)
#endif

#ifndef rtmSetConstBlockIO
# define rtmSetConstBlockIO(rtm, val)  ((rtm)->ModelData.constBlockIO = (val))
#endif

#ifndef rtmGetContStateDisabled
# define rtmGetContStateDisabled(rtm)  ((rtm)->ModelData.contStateDisabled)
#endif

#ifndef rtmSetContStateDisabled
# define rtmSetContStateDisabled(rtm, val) ((rtm)->ModelData.contStateDisabled = (val))
#endif

#ifndef rtmGetContStates
# define rtmGetContStates(rtm)         ((rtm)->ModelData.contStates)
#endif

#ifndef rtmSetContStates
# define rtmSetContStates(rtm, val)    ((rtm)->ModelData.contStates = (val))
#endif

#ifndef rtmGetDataMapInfo
# define rtmGetDataMapInfo(rtm)        ((rtm)->DataMapInfo)
#endif

#ifndef rtmSetDataMapInfo
# define rtmSetDataMapInfo(rtm, val)   ((rtm)->DataMapInfo = (val))
#endif

#ifndef rtmGetDefaultParam
# define rtmGetDefaultParam(rtm)       ((rtm)->ModelData.defaultParam)
#endif

#ifndef rtmSetDefaultParam
# define rtmSetDefaultParam(rtm, val)  ((rtm)->ModelData.defaultParam = (val))
#endif

#ifndef rtmGetDerivCacheNeedsReset
# define rtmGetDerivCacheNeedsReset(rtm) ((rtm)->ModelData.derivCacheNeedsReset)
#endif

#ifndef rtmSetDerivCacheNeedsReset
# define rtmSetDerivCacheNeedsReset(rtm, val) ((rtm)->ModelData.derivCacheNeedsReset = (val))
#endif

#ifndef rtmGetDirectFeedThrough
# define rtmGetDirectFeedThrough(rtm)  ((rtm)->Sizes.sysDirFeedThru)
#endif

#ifndef rtmSetDirectFeedThrough
# define rtmSetDirectFeedThrough(rtm, val) ((rtm)->Sizes.sysDirFeedThru = (val))
#endif

#ifndef rtmGetErrorStatusFlag
# define rtmGetErrorStatusFlag(rtm)    ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatusFlag
# define rtmSetErrorStatusFlag(rtm, val) ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetFinalTime
# define rtmGetFinalTime(rtm)          ((rtm)->Timing.tFinal)
#endif

#ifndef rtmSetFinalTime
# define rtmSetFinalTime(rtm, val)     ((rtm)->Timing.tFinal = (val))
#endif

#ifndef rtmGetFirstInitCondFlag
# define rtmGetFirstInitCondFlag(rtm)  ((rtm)->Timing.firstInitCondFlag)
#endif

#ifndef rtmSetFirstInitCondFlag
# define rtmSetFirstInitCondFlag(rtm, val) ((rtm)->Timing.firstInitCondFlag = (val))
#endif

#ifndef rtmGetIntgData
# define rtmGetIntgData(rtm)           ((rtm)->ModelData.intgData)
#endif

#ifndef rtmSetIntgData
# define rtmSetIntgData(rtm, val)      ((rtm)->ModelData.intgData = (val))
#endif

#ifndef rtmGetMdlRefGlobalTID
# define rtmGetMdlRefGlobalTID(rtm)    ((rtm)->Timing.mdlref_GlobalTID)
#endif

#ifndef rtmSetMdlRefGlobalTID
# define rtmSetMdlRefGlobalTID(rtm, val) ((rtm)->Timing.mdlref_GlobalTID = (val))
#endif

#ifndef rtmGetMdlRefTriggerTID
# define rtmGetMdlRefTriggerTID(rtm)   ((rtm)->Timing.mdlref_TriggerTID)
#endif

#ifndef rtmSetMdlRefTriggerTID
# define rtmSetMdlRefTriggerTID(rtm, val) ((rtm)->Timing.mdlref_TriggerTID = (val))
#endif

#ifndef rtmGetModelMappingInfo
# define rtmGetModelMappingInfo(rtm)   ((rtm)->SpecialInfo.mappingInfo)
#endif

#ifndef rtmSetModelMappingInfo
# define rtmSetModelMappingInfo(rtm, val) ((rtm)->SpecialInfo.mappingInfo = (val))
#endif

#ifndef rtmGetModelName
# define rtmGetModelName(rtm)          ((rtm)->modelName)
#endif

#ifndef rtmSetModelName
# define rtmSetModelName(rtm, val)     ((rtm)->modelName = (val))
#endif

#ifndef rtmGetNonInlinedSFcns
# define rtmGetNonInlinedSFcns(rtm)    ((rtm)->NonInlinedSFcns)
#endif

#ifndef rtmSetNonInlinedSFcns
# define rtmSetNonInlinedSFcns(rtm, val) ((rtm)->NonInlinedSFcns = (val))
#endif

#ifndef rtmGetNumBlockIO
# define rtmGetNumBlockIO(rtm)         ((rtm)->Sizes.numBlockIO)
#endif

#ifndef rtmSetNumBlockIO
# define rtmSetNumBlockIO(rtm, val)    ((rtm)->Sizes.numBlockIO = (val))
#endif

#ifndef rtmGetNumBlockParams
# define rtmGetNumBlockParams(rtm)     ((rtm)->Sizes.numBlockPrms)
#endif

#ifndef rtmSetNumBlockParams
# define rtmSetNumBlockParams(rtm, val) ((rtm)->Sizes.numBlockPrms = (val))
#endif

#ifndef rtmGetNumBlocks
# define rtmGetNumBlocks(rtm)          ((rtm)->Sizes.numBlocks)
#endif

#ifndef rtmSetNumBlocks
# define rtmSetNumBlocks(rtm, val)     ((rtm)->Sizes.numBlocks = (val))
#endif

#ifndef rtmGetNumContStates
# define rtmGetNumContStates(rtm)      ((rtm)->Sizes.numContStates)
#endif

#ifndef rtmSetNumContStates
# define rtmSetNumContStates(rtm, val) ((rtm)->Sizes.numContStates = (val))
#endif

#ifndef rtmGetNumDWork
# define rtmGetNumDWork(rtm)           ((rtm)->Sizes.numDwork)
#endif

#ifndef rtmSetNumDWork
# define rtmSetNumDWork(rtm, val)      ((rtm)->Sizes.numDwork = (val))
#endif

#ifndef rtmGetNumInputPorts
# define rtmGetNumInputPorts(rtm)      ((rtm)->Sizes.numIports)
#endif

#ifndef rtmSetNumInputPorts
# define rtmSetNumInputPorts(rtm, val) ((rtm)->Sizes.numIports = (val))
#endif

#ifndef rtmGetNumNonSampledZCs
# define rtmGetNumNonSampledZCs(rtm)   ((rtm)->Sizes.numNonSampZCs)
#endif

#ifndef rtmSetNumNonSampledZCs
# define rtmSetNumNonSampledZCs(rtm, val) ((rtm)->Sizes.numNonSampZCs = (val))
#endif

#ifndef rtmGetNumOutputPorts
# define rtmGetNumOutputPorts(rtm)     ((rtm)->Sizes.numOports)
#endif

#ifndef rtmSetNumOutputPorts
# define rtmSetNumOutputPorts(rtm, val) ((rtm)->Sizes.numOports = (val))
#endif

#ifndef rtmGetNumSFcnParams
# define rtmGetNumSFcnParams(rtm)      ((rtm)->Sizes.numSFcnPrms)
#endif

#ifndef rtmSetNumSFcnParams
# define rtmSetNumSFcnParams(rtm, val) ((rtm)->Sizes.numSFcnPrms = (val))
#endif

#ifndef rtmGetNumSFunctions
# define rtmGetNumSFunctions(rtm)      ((rtm)->Sizes.numSFcns)
#endif

#ifndef rtmSetNumSFunctions
# define rtmSetNumSFunctions(rtm, val) ((rtm)->Sizes.numSFcns = (val))
#endif

#ifndef rtmGetNumSampleTimes
# define rtmGetNumSampleTimes(rtm)     ((rtm)->Sizes.numSampTimes)
#endif

#ifndef rtmSetNumSampleTimes
# define rtmSetNumSampleTimes(rtm, val) ((rtm)->Sizes.numSampTimes = (val))
#endif

#ifndef rtmGetNumU
# define rtmGetNumU(rtm)               ((rtm)->Sizes.numU)
#endif

#ifndef rtmSetNumU
# define rtmSetNumU(rtm, val)          ((rtm)->Sizes.numU = (val))
#endif

#ifndef rtmGetNumY
# define rtmGetNumY(rtm)               ((rtm)->Sizes.numY)
#endif

#ifndef rtmSetNumY
# define rtmSetNumY(rtm, val)          ((rtm)->Sizes.numY = (val))
#endif

#ifndef rtmGetOdeF
# define rtmGetOdeF(rtm)               ((rtm)->ModelData.odeF)
#endif

#ifndef rtmSetOdeF
# define rtmSetOdeF(rtm, val)          ((rtm)->ModelData.odeF = (val))
#endif

#ifndef rtmGetOdeY
# define rtmGetOdeY(rtm)               ((rtm)->ModelData.odeY)
#endif

#ifndef rtmSetOdeY
# define rtmSetOdeY(rtm, val)          ((rtm)->ModelData.odeY = (val))
#endif

#ifndef rtmGetOffsetTimeArray
# define rtmGetOffsetTimeArray(rtm)    ((rtm)->Timing.offsetTimesArray)
#endif

#ifndef rtmSetOffsetTimeArray
# define rtmSetOffsetTimeArray(rtm, val) ((rtm)->Timing.offsetTimesArray = (val))
#endif

#ifndef rtmGetOffsetTimePtr
# define rtmGetOffsetTimePtr(rtm)      ((rtm)->Timing.offsetTimes)
#endif

#ifndef rtmSetOffsetTimePtr
# define rtmSetOffsetTimePtr(rtm, val) ((rtm)->Timing.offsetTimes = (val))
#endif

#ifndef rtmGetOptions
# define rtmGetOptions(rtm)            ((rtm)->Sizes.options)
#endif

#ifndef rtmSetOptions
# define rtmSetOptions(rtm, val)       ((rtm)->Sizes.options = (val))
#endif

#ifndef rtmGetParamIsMalloced
# define rtmGetParamIsMalloced(rtm)    ((rtm)->ModelData.paramIsMalloced)
#endif

#ifndef rtmSetParamIsMalloced
# define rtmSetParamIsMalloced(rtm, val) ((rtm)->ModelData.paramIsMalloced = (val))
#endif

#ifndef rtmGetPath
# define rtmGetPath(rtm)               ((rtm)->path)
#endif

#ifndef rtmSetPath
# define rtmSetPath(rtm, val)          ((rtm)->path = (val))
#endif

#ifndef rtmGetPerTaskSampleHits
# define rtmGetPerTaskSampleHits(rtm)  ((rtm)->Timing.RateInteraction)
#endif

#ifndef rtmSetPerTaskSampleHits
# define rtmSetPerTaskSampleHits(rtm, val) ((rtm)->Timing.RateInteraction = (val))
#endif

#ifndef rtmGetPerTaskSampleHitsArray
# define rtmGetPerTaskSampleHitsArray(rtm) ((rtm)->Timing.perTaskSampleHitsArray)
#endif

#ifndef rtmSetPerTaskSampleHitsArray
# define rtmSetPerTaskSampleHitsArray(rtm, val) ((rtm)->Timing.perTaskSampleHitsArray = (val))
#endif

#ifndef rtmGetPerTaskSampleHitsPtr
# define rtmGetPerTaskSampleHitsPtr(rtm) ((rtm)->Timing.perTaskSampleHits)
#endif

#ifndef rtmSetPerTaskSampleHitsPtr
# define rtmSetPerTaskSampleHitsPtr(rtm, val) ((rtm)->Timing.perTaskSampleHits = (val))
#endif

#ifndef rtmGetPrevZCSigState
# define rtmGetPrevZCSigState(rtm)     ((rtm)->ModelData.prevZCSigState)
#endif

#ifndef rtmSetPrevZCSigState
# define rtmSetPrevZCSigState(rtm, val) ((rtm)->ModelData.prevZCSigState = (val))
#endif

#ifndef rtmGetRTWExtModeInfo
# define rtmGetRTWExtModeInfo(rtm)     ((rtm)->extModeInfo)
#endif

#ifndef rtmSetRTWExtModeInfo
# define rtmSetRTWExtModeInfo(rtm, val) ((rtm)->extModeInfo = (val))
#endif

#ifndef rtmGetRTWGeneratedSFcn
# define rtmGetRTWGeneratedSFcn(rtm)   ((rtm)->Sizes.rtwGenSfcn)
#endif

#ifndef rtmSetRTWGeneratedSFcn
# define rtmSetRTWGeneratedSFcn(rtm, val) ((rtm)->Sizes.rtwGenSfcn = (val))
#endif

#ifndef rtmGetRTWLogInfo
# define rtmGetRTWLogInfo(rtm)         ((rtm)->rtwLogInfo)
#endif

#ifndef rtmSetRTWLogInfo
# define rtmSetRTWLogInfo(rtm, val)    ((rtm)->rtwLogInfo = (val))
#endif

#ifndef rtmGetRTWRTModelMethodsInfo
# define rtmGetRTWRTModelMethodsInfo(rtm) ((rtm)->modelMethodsInfo)
#endif

#ifndef rtmSetRTWRTModelMethodsInfo
# define rtmSetRTWRTModelMethodsInfo(rtm, val) ((rtm)->modelMethodsInfo = (val))
#endif

#ifndef rtmGetRTWSfcnInfo
# define rtmGetRTWSfcnInfo(rtm)        ((rtm)->sfcnInfo)
#endif

#ifndef rtmSetRTWSfcnInfo
# define rtmSetRTWSfcnInfo(rtm, val)   ((rtm)->sfcnInfo = (val))
#endif

#ifndef rtmGetRTWSolverInfo
# define rtmGetRTWSolverInfo(rtm)      ((rtm)->solverInfo)
#endif

#ifndef rtmSetRTWSolverInfo
# define rtmSetRTWSolverInfo(rtm, val) ((rtm)->solverInfo = (val))
#endif

#ifndef rtmGetRTWSolverInfoPtr
# define rtmGetRTWSolverInfoPtr(rtm)   ((rtm)->solverInfoPtr)
#endif

#ifndef rtmSetRTWSolverInfoPtr
# define rtmSetRTWSolverInfoPtr(rtm, val) ((rtm)->solverInfoPtr = (val))
#endif

#ifndef rtmGetReservedForXPC
# define rtmGetReservedForXPC(rtm)     ((rtm)->SpecialInfo.xpcData)
#endif

#ifndef rtmSetReservedForXPC
# define rtmSetReservedForXPC(rtm, val) ((rtm)->SpecialInfo.xpcData = (val))
#endif

#ifndef rtmGetRootDWork
# define rtmGetRootDWork(rtm)          ((rtm)->Work.dwork)
#endif

#ifndef rtmSetRootDWork
# define rtmSetRootDWork(rtm, val)     ((rtm)->Work.dwork = (val))
#endif

#ifndef rtmGetSFunctions
# define rtmGetSFunctions(rtm)         ((rtm)->childSfunctions)
#endif

#ifndef rtmSetSFunctions
# define rtmSetSFunctions(rtm, val)    ((rtm)->childSfunctions = (val))
#endif

#ifndef rtmGetSampleHitArray
# define rtmGetSampleHitArray(rtm)     ((rtm)->Timing.sampleHitArray)
#endif

#ifndef rtmSetSampleHitArray
# define rtmSetSampleHitArray(rtm, val) ((rtm)->Timing.sampleHitArray = (val))
#endif

#ifndef rtmGetSampleHitPtr
# define rtmGetSampleHitPtr(rtm)       ((rtm)->Timing.sampleHits)
#endif

#ifndef rtmSetSampleHitPtr
# define rtmSetSampleHitPtr(rtm, val)  ((rtm)->Timing.sampleHits = (val))
#endif

#ifndef rtmGetSampleTimeArray
# define rtmGetSampleTimeArray(rtm)    ((rtm)->Timing.sampleTimesArray)
#endif

#ifndef rtmSetSampleTimeArray
# define rtmSetSampleTimeArray(rtm, val) ((rtm)->Timing.sampleTimesArray = (val))
#endif

#ifndef rtmGetSampleTimePtr
# define rtmGetSampleTimePtr(rtm)      ((rtm)->Timing.sampleTimes)
#endif

#ifndef rtmSetSampleTimePtr
# define rtmSetSampleTimePtr(rtm, val) ((rtm)->Timing.sampleTimes = (val))
#endif

#ifndef rtmGetSampleTimeTaskIDArray
# define rtmGetSampleTimeTaskIDArray(rtm) ((rtm)->Timing.sampleTimeTaskIDArray)
#endif

#ifndef rtmSetSampleTimeTaskIDArray
# define rtmSetSampleTimeTaskIDArray(rtm, val) ((rtm)->Timing.sampleTimeTaskIDArray = (val))
#endif

#ifndef rtmGetSampleTimeTaskIDPtr
# define rtmGetSampleTimeTaskIDPtr(rtm) ((rtm)->Timing.sampleTimeTaskIDPtr)
#endif

#ifndef rtmSetSampleTimeTaskIDPtr
# define rtmSetSampleTimeTaskIDPtr(rtm, val) ((rtm)->Timing.sampleTimeTaskIDPtr = (val))
#endif

#ifndef rtmGetSimMode
# define rtmGetSimMode(rtm)            ((rtm)->simMode)
#endif

#ifndef rtmSetSimMode
# define rtmSetSimMode(rtm, val)       ((rtm)->simMode = (val))
#endif

#ifndef rtmGetSimTimeStep
# define rtmGetSimTimeStep(rtm)        ((rtm)->Timing.simTimeStep)
#endif

#ifndef rtmSetSimTimeStep
# define rtmSetSimTimeStep(rtm, val)   ((rtm)->Timing.simTimeStep = (val))
#endif

#ifndef rtmGetStartTime
# define rtmGetStartTime(rtm)          ((rtm)->Timing.tStart)
#endif

#ifndef rtmSetStartTime
# define rtmSetStartTime(rtm, val)     ((rtm)->Timing.tStart = (val))
#endif

#ifndef rtmGetStepSize
# define rtmGetStepSize(rtm)           ((rtm)->Timing.stepSize)
#endif

#ifndef rtmSetStepSize
# define rtmSetStepSize(rtm, val)      ((rtm)->Timing.stepSize = (val))
#endif

#ifndef rtmGetStopRequestedFlag
# define rtmGetStopRequestedFlag(rtm)  ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequestedFlag
# define rtmSetStopRequestedFlag(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetTaskCounters
# define rtmGetTaskCounters(rtm)       ((rtm)->Timing.TaskCounters)
#endif

#ifndef rtmSetTaskCounters
# define rtmSetTaskCounters(rtm, val)  ((rtm)->Timing.TaskCounters = (val))
#endif

#ifndef rtmGetTaskTimeArray
# define rtmGetTaskTimeArray(rtm)      ((rtm)->Timing.tArray)
#endif

#ifndef rtmSetTaskTimeArray
# define rtmSetTaskTimeArray(rtm, val) ((rtm)->Timing.tArray = (val))
#endif

#ifndef rtmGetTimePtr
# define rtmGetTimePtr(rtm)            ((rtm)->Timing.t)
#endif

#ifndef rtmSetTimePtr
# define rtmSetTimePtr(rtm, val)       ((rtm)->Timing.t = (val))
#endif

#ifndef rtmGetTimingData
# define rtmGetTimingData(rtm)         ((rtm)->Timing.timingData)
#endif

#ifndef rtmSetTimingData
# define rtmSetTimingData(rtm, val)    ((rtm)->Timing.timingData = (val))
#endif

#ifndef rtmGetU
# define rtmGetU(rtm)                  ((rtm)->ModelData.inputs)
#endif

#ifndef rtmSetU
# define rtmSetU(rtm, val)             ((rtm)->ModelData.inputs = (val))
#endif

#ifndef rtmGetVarNextHitTimesListPtr
# define rtmGetVarNextHitTimesListPtr(rtm) ((rtm)->Timing.varNextHitTimesList)
#endif

#ifndef rtmSetVarNextHitTimesListPtr
# define rtmSetVarNextHitTimesListPtr(rtm, val) ((rtm)->Timing.varNextHitTimesList = (val))
#endif

#ifndef rtmGetY
# define rtmGetY(rtm)                  ((rtm)->ModelData.outputs)
#endif

#ifndef rtmSetY
# define rtmSetY(rtm, val)             ((rtm)->ModelData.outputs = (val))
#endif

#ifndef rtmGetZCCacheNeedsReset
# define rtmGetZCCacheNeedsReset(rtm)  ((rtm)->ModelData.zCCacheNeedsReset)
#endif

#ifndef rtmSetZCCacheNeedsReset
# define rtmSetZCCacheNeedsReset(rtm, val) ((rtm)->ModelData.zCCacheNeedsReset = (val))
#endif

#ifndef rtmGetZCSignalValues
# define rtmGetZCSignalValues(rtm)     ((rtm)->ModelData.zcSignalValues)
#endif

#ifndef rtmSetZCSignalValues
# define rtmSetZCSignalValues(rtm, val) ((rtm)->ModelData.zcSignalValues = (val))
#endif

#ifndef rtmGet_TimeOfLastOutput
# define rtmGet_TimeOfLastOutput(rtm)  ((rtm)->Timing.timeOfLastOutput)
#endif

#ifndef rtmSet_TimeOfLastOutput
# define rtmSet_TimeOfLastOutput(rtm, val) ((rtm)->Timing.timeOfLastOutput = (val))
#endif

#ifndef rtmGetdX
# define rtmGetdX(rtm)                 ((rtm)->ModelData.derivs)
#endif

#ifndef rtmSetdX
# define rtmSetdX(rtm, val)            ((rtm)->ModelData.derivs = (val))
#endif

#ifndef rtmGetChecksumVal
# define rtmGetChecksumVal(rtm, idx)   ((rtm)->Sizes.checksums[idx])
#endif

#ifndef rtmSetChecksumVal
# define rtmSetChecksumVal(rtm, idx, val) ((rtm)->Sizes.checksums[idx] = (val))
#endif

#ifndef rtmGetDWork
# define rtmGetDWork(rtm, idx)         ((rtm)->Work.dwork[idx])
#endif

#ifndef rtmSetDWork
# define rtmSetDWork(rtm, idx, val)    ((rtm)->Work.dwork[idx] = (val))
#endif

#ifndef rtmGetOffsetTime
# define rtmGetOffsetTime(rtm, idx)    ((rtm)->Timing.offsetTimes[idx])
#endif

#ifndef rtmSetOffsetTime
# define rtmSetOffsetTime(rtm, idx, val) ((rtm)->Timing.offsetTimes[idx] = (val))
#endif

#ifndef rtmGetSFunction
# define rtmGetSFunction(rtm, idx)     ((rtm)->childSfunctions[idx])
#endif

#ifndef rtmSetSFunction
# define rtmSetSFunction(rtm, idx, val) ((rtm)->childSfunctions[idx] = (val))
#endif

#ifndef rtmGetSampleTime
# define rtmGetSampleTime(rtm, idx)    ((rtm)->Timing.sampleTimes[idx])
#endif

#ifndef rtmSetSampleTime
# define rtmSetSampleTime(rtm, idx, val) ((rtm)->Timing.sampleTimes[idx] = (val))
#endif

#ifndef rtmGetSampleTimeTaskID
# define rtmGetSampleTimeTaskID(rtm, idx) ((rtm)->Timing.sampleTimeTaskIDPtr[idx])
#endif

#ifndef rtmSetSampleTimeTaskID
# define rtmSetSampleTimeTaskID(rtm, idx, val) ((rtm)->Timing.sampleTimeTaskIDPtr[idx] = (val))
#endif

#ifndef rtmGetVarNextHitTime
# define rtmGetVarNextHitTime(rtm, idx) ((rtm)->Timing.varNextHitTimesList[idx])
#endif

#ifndef rtmSetVarNextHitTime
# define rtmSetVarNextHitTime(rtm, idx, val) ((rtm)->Timing.varNextHitTimesList[idx] = (val))
#endif

#ifndef rtmIsContinuousTask
# define rtmIsContinuousTask(rtm, tid) ((tid) == 0)
#endif

#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmIsMajorTimeStep
# define rtmIsMajorTimeStep(rtm)       (((rtm)->Timing.simTimeStep) == MAJOR_TIME_STEP)
#endif

#ifndef rtmIsMinorTimeStep
# define rtmIsMinorTimeStep(rtm)       (((rtm)->Timing.simTimeStep) == MINOR_TIME_STEP)
#endif

#ifndef rtmIsSampleHit
# define rtmIsSampleHit(rtm, sti, tid) ((rtmIsMajorTimeStep((rtm)) && (rtm)->Timing.sampleHits[(rtm)->Timing.sampleTimeTaskIDPtr[sti]]))
#endif

#ifndef rtmGetStopRequested
# define rtmGetStopRequested(rtm)      ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
# define rtmSetStopRequested(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
# define rtmGetStopRequestedPtr(rtm)   (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
# define rtmGetT(rtm)                  (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmSetT
# define rtmSetT(rtm, val)                                       /* Do Nothing */
#endif

#ifndef rtmGetTFinal
# define rtmGetTFinal(rtm)             ((rtm)->Timing.tFinal)
#endif

#ifndef rtmSetTFinal
# define rtmSetTFinal(rtm, val)        ((rtm)->Timing.tFinal = (val))
#endif

#ifndef rtmGetTPtr
# define rtmGetTPtr(rtm)               ((rtm)->Timing.t)
#endif

#ifndef rtmSetTPtr
# define rtmSetTPtr(rtm, val)          ((rtm)->Timing.t = (val))
#endif

#ifndef rtmGetTStart
# define rtmGetTStart(rtm)             ((rtm)->Timing.tStart)
#endif

#ifndef rtmSetTStart
# define rtmSetTStart(rtm, val)        ((rtm)->Timing.tStart = (val))
#endif

#ifndef rtmGetTaskTime
# define rtmGetTaskTime(rtm, sti)      (rtmGetTPtr((rtm))[(rtm)->Timing.sampleTimeTaskIDPtr[sti]])
#endif

#ifndef rtmSetTaskTime
# define rtmSetTaskTime(rtm, sti, val) (rtmGetTPtr((rtm))[sti] = (val))
#endif

#ifndef rtmGetTimeOfLastOutput
# define rtmGetTimeOfLastOutput(rtm)   ((rtm)->Timing.timeOfLastOutput)
#endif

#ifdef rtmGetRTWSolverInfo
#undef rtmGetRTWSolverInfo
#endif

#define rtmGetRTWSolverInfo(rtm)       &((rtm)->solverInfo)

/* Definition for use in the target main file */
#define base_rtModel                   RT_MODEL_base

/* Block signals (auto storage) */
typedef struct {
  real_T DS4504_ETH_Setup_o1;          /* '<Root>/DS4504_ETH_Setup' */
  real_T DS4504_ETH_Setup_o2;          /* '<Root>/DS4504_ETH_Setup' */
  real_T DS4504_ETH_Setup_o3;          /* '<Root>/DS4504_ETH_Setup' */
  real_T CPVImageProcessing[16];       /* '<S1>/CPV Image Processing' */
  real_T TaskSetting;                  /* '<S1>/Task Setting' */
  real_T DataStoreRead[16];            /* '<S6>/Data Store Read' */
  real_T DS4504_ETH_Receive_o2;        /* '<S1>/DS4504_ETH_Receive' */
  real_T DS4504_ETH_Receive_o3;        /* '<S1>/DS4504_ETH_Receive' */
  real_T DS4504_ETH_Receive_o4;        /* '<S1>/DS4504_ETH_Receive' */
  real_T DS4504_ETH_Receive_o5[4];     /* '<S1>/DS4504_ETH_Receive' */
  real_T DSDecode32[4];                /* '<S1>/DSDecode32 ' */
  real_T hand02Traj[10];               /* '<S6>/hand02Traj' */
  real_T hand02JntAngLimit[10];        /* '<S6>/hand02JntAngLimit' */
  real_T hand02Enc2JntAng[10];         /* '<S5>/hand02Enc2JntAng' */
  real_T hand02Ctrl[10];               /* '<S5>/hand02Ctrl' */
  real_T hand02JntTrq2DA[10];          /* '<S5>/hand02JntTrq2DA' */
  real_T hand02DALimit[10];            /* '<S5>/hand02DALimit' */
  int32_T SystemSetting;               /* '<Root>/System Setting' */
  uint32_T DS4504_ETH_Receive_o1[8];   /* '<S1>/DS4504_ETH_Receive' */
} BlockIO_base;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T Image[16];                    /* '<S1>/Data Store Memory Image' */
  real_T Object[16];                   /* '<S1>/Data Store Memory Object' */
  real_T SystemSetting_RWORK;          /* '<Root>/System Setting' */
  real_T CPVImageProcessing_RWORK[16]; /* '<S1>/CPV Image Processing' */
  real_T TaskSetting_RWORK;            /* '<S1>/Task Setting' */
  real_T hand02Traj_RWORK[10];         /* '<S6>/hand02Traj' */
  real_T hand02Ctrl_RWORK[10];         /* '<S5>/hand02Ctrl' */
  real_T hand02DALimit_RWORK;          /* '<S5>/hand02DALimit' */
  void *DSDecode32_PWORK;              /* '<S1>/DSDecode32 ' */
  int_T DS4504_ETH_Setup_IWORK[2];     /* '<Root>/DS4504_ETH_Setup' */
  int_T CPVImageProcessing_IWORK[2];   /* '<S1>/CPV Image Processing' */
  int_T DS4504_ETH_Receive_IWORK[5];   /* '<S1>/DS4504_ETH_Receive' */
  int_T DSDecode32_IWORK;              /* '<S1>/DSDecode32 ' */
  int_T hand02Traj_IWORK;              /* '<S6>/hand02Traj' */
  int_T Application_MODE;              /* '<Root>/Application' */
} D_Work_base;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCSigState simStateSET_Trig_ZCE;     /* '<Root>/simState SET' */
} PrevZCSigStates_base;

/* Backward compatible GRT Identifiers */
#define rtB                            base_B
#define BlockIO                        BlockIO_base
#define rtXdot                         base_Xdot
#define StateDerivatives               StateDerivatives_base
#define tXdis                          base_Xdis
#define StateDisabled                  StateDisabled_base
#define rtP                            base_P
#define Parameters                     Parameters_base
#define rtDWork                        base_DWork
#define D_Work                         D_Work_base
#define rtPrevZCSigState               base_PrevZCSigState
#define PrevZCSigStates                PrevZCSigStates_base

/* Parameters (auto storage) */
struct Parameters_base_ {
  real_T DS4504_ETH_Setup_P1_Size[2];  /* Computed Parameter: P1Size
                                        * '<Root>/DS4504_ETH_Setup'
                                        */
  real_T DS4504_ETH_Setup_P1;          /* Expression: evalin('base',['DS4504_base(',get_param(gcbh,'boardID'),').BoardID'])
                                        * '<Root>/DS4504_ETH_Setup'
                                        */
  real_T DS4504_ETH_Setup_P2_Size[2];  /* Computed Parameter: P2Size
                                        * '<Root>/DS4504_ETH_Setup'
                                        */
  real_T DS4504_ETH_Setup_P2;          /* Expression: evalin('base',['DS4504_base(',get_param(gcbh,'boardID'),').WatchdogTimeoutSteps'])
                                        * '<Root>/DS4504_ETH_Setup'
                                        */
  real_T DS4504_ETH_Setup_P3_Size[2];  /* Computed Parameter: P3Size
                                        * '<Root>/DS4504_ETH_Setup'
                                        */
  real_T DS4504_ETH_Setup_P3;          /* Expression: evalin('base',['DS4504_base(',get_param(gcbh,'boardID'),').NumberSendFrames(1)'])
                                        * '<Root>/DS4504_ETH_Setup'
                                        */
  real_T DS4504_ETH_Setup_P4_Size[2];  /* Computed Parameter: P4Size
                                        * '<Root>/DS4504_ETH_Setup'
                                        */
  real_T DS4504_ETH_Setup_P4;          /* Expression: evalin('base',['DS4504_base(',get_param(gcbh,'boardID'),').NumberReceiveFrames(1)'])
                                        * '<Root>/DS4504_ETH_Setup'
                                        */
  real_T DS4504_ETH_Setup_P5_Size[2];  /* Computed Parameter: P5Size
                                        * '<Root>/DS4504_ETH_Setup'
                                        */
  real_T DS4504_ETH_Setup_P5;          /* Expression: evalin('base',['DS4504_base(',get_param(gcbh,'boardID'),').SendFrame(1).LengthBytes'])
                                        * '<Root>/DS4504_ETH_Setup'
                                        */
  real_T DS4504_ETH_Setup_P6_Size[2];  /* Computed Parameter: P6Size
                                        * '<Root>/DS4504_ETH_Setup'
                                        */
  real_T DS4504_ETH_Setup_P6;          /* Expression: evalin('base',['DS4504_base(',get_param(gcbh,'boardID'),').ReceiveFrame(1).LengthBytes'])
                                        * '<Root>/DS4504_ETH_Setup'
                                        */
  real_T DS4504_ETH_Setup_P7_Size[2];  /* Computed Parameter: P7Size
                                        * '<Root>/DS4504_ETH_Setup'
                                        */
  real_T DS4504_ETH_Setup_P7;          /* Expression: evalin('base',['DS4504_base(',get_param(gcbh,'boardID'),').SendFrame(1).SendMACADDR1'])
                                        * '<Root>/DS4504_ETH_Setup'
                                        */
  real_T DS4504_ETH_Setup_P8_Size[2];  /* Computed Parameter: P8Size
                                        * '<Root>/DS4504_ETH_Setup'
                                        */
  real_T DS4504_ETH_Setup_P8;          /* Expression: evalin('base',['DS4504_base(',get_param(gcbh,'boardID'),').SendFrame(1).SendMACADDR2'])
                                        * '<Root>/DS4504_ETH_Setup'
                                        */
  real_T DS4504_ETH_Setup_P9_Size[2];  /* Computed Parameter: P9Size
                                        * '<Root>/DS4504_ETH_Setup'
                                        */
  real_T DS4504_ETH_Setup_P9;          /* Expression: evalin('base',['DS4504_base(',get_param(gcbh,'boardID'),').SendFrame(1).SendMACADDR3'])
                                        * '<Root>/DS4504_ETH_Setup'
                                        */
  real_T DS4504_ETH_Setup_P10_Size[2]; /* Computed Parameter: P10Size
                                        * '<Root>/DS4504_ETH_Setup'
                                        */
  real_T DS4504_ETH_Setup_P10;         /* Expression: evalin('base',['DS4504_base(',get_param(gcbh,'boardID'),').SendFrame(1).SendMACADDR4'])
                                        * '<Root>/DS4504_ETH_Setup'
                                        */
  real_T DS4504_ETH_Setup_P11_Size[2]; /* Computed Parameter: P11Size
                                        * '<Root>/DS4504_ETH_Setup'
                                        */
  real_T DS4504_ETH_Setup_P11;         /* Expression: evalin('base',['DS4504_base(',get_param(gcbh,'boardID'),').SendFrame(1).SharePort'])
                                        * '<Root>/DS4504_ETH_Setup'
                                        */
  real_T DS4504_ETH_Setup_P12_Size[2]; /* Computed Parameter: P12Size
                                        * '<Root>/DS4504_ETH_Setup'
                                        */
  real_T DS4504_ETH_Setup_P12;         /* Expression: evalin('base',['DS4504_base(',get_param(gcbh,'boardID'),').SendFrame(1).SendType'])
                                        * '<Root>/DS4504_ETH_Setup'
                                        */
  real_T DS4504_ETH_Setup_P13_Size[2]; /* Computed Parameter: P13Size
                                        * '<Root>/DS4504_ETH_Setup'
                                        */
  real_T DS4504_ETH_Setup_P13;         /* Expression: evalin('base',['DS4504_base(',get_param(gcbh,'boardID'),').ReceiveFrame(1).SendMACADDR1'])
                                        * '<Root>/DS4504_ETH_Setup'
                                        */
  real_T DS4504_ETH_Setup_P14_Size[2]; /* Computed Parameter: P14Size
                                        * '<Root>/DS4504_ETH_Setup'
                                        */
  real_T DS4504_ETH_Setup_P14;         /* Expression: evalin('base',['DS4504_base(',get_param(gcbh,'boardID'),').ReceiveFrame(1).SendMACADDR2'])
                                        * '<Root>/DS4504_ETH_Setup'
                                        */
  real_T DS4504_ETH_Setup_P15_Size[2]; /* Computed Parameter: P15Size
                                        * '<Root>/DS4504_ETH_Setup'
                                        */
  real_T DS4504_ETH_Setup_P15;         /* Expression: evalin('base',['DS4504_base(',get_param(gcbh,'boardID'),').ReceiveFrame(1).SendMACADDR3'])
                                        * '<Root>/DS4504_ETH_Setup'
                                        */
  real_T DS4504_ETH_Setup_P16_Size[2]; /* Computed Parameter: P16Size
                                        * '<Root>/DS4504_ETH_Setup'
                                        */
  real_T DS4504_ETH_Setup_P16;         /* Expression: evalin('base',['DS4504_base(',get_param(gcbh,'boardID'),').ReceiveFrame(1).SendMACADDR4'])
                                        * '<Root>/DS4504_ETH_Setup'
                                        */
  real_T DS4504_ETH_Setup_P17_Size[2]; /* Computed Parameter: P17Size
                                        * '<Root>/DS4504_ETH_Setup'
                                        */
  real_T DS4504_ETH_Setup_P17;         /* Expression: evalin('base',['DS4504_base(',get_param(gcbh,'boardID'),').ReceiveFrame(1).ReceiveType'])
                                        * '<Root>/DS4504_ETH_Setup'
                                        */
  real_T DS4504_ETH_Setup_P18_Size[2]; /* Computed Parameter: P18Size
                                        * '<Root>/DS4504_ETH_Setup'
                                        */
  real_T DS4504_ETH_Setup_P18;         /* Expression: evalin('base',['DS4504_base(',get_param(gcbh,'boardID'),').ReceiveFrame(1).ReceiveETH_LocalQueueSize'])
                                        * '<Root>/DS4504_ETH_Setup'
                                        */
  real_T DS4504_ETH_Setup_P19_Size[2]; /* Computed Parameter: P19Size
                                        * '<Root>/DS4504_ETH_Setup'
                                        */
  real_T DS4504_ETH_Setup_P19;         /* Expression: evalin('base',['DS4504_base(',get_param(gcbh,'boardID'),').ETH_MyIP(1)'])
                                        * '<Root>/DS4504_ETH_Setup'
                                        */
  real_T DS4504_ETH_Setup_P20_Size[2]; /* Computed Parameter: P20Size
                                        * '<Root>/DS4504_ETH_Setup'
                                        */
  real_T DS4504_ETH_Setup_P20;         /* Expression: evalin('base',['DS4504_base(',get_param(gcbh,'boardID'),').ETH_DetectMyIP(1)'])
                                        * '<Root>/DS4504_ETH_Setup'
                                        */
  real_T DS4504_ETH_Setup_P21_Size[2]; /* Computed Parameter: P21Size
                                        * '<Root>/DS4504_ETH_Setup'
                                        */
  real_T DS4504_ETH_Setup_P21;         /* Expression: evalin('base',['DS4504_base(',get_param(gcbh,'boardID'),').ETH_Generally_accept_any_IP(1)'])
                                        * '<Root>/DS4504_ETH_Setup'
                                        */
  real_T DS4504_ETH_Setup_P22_Size[2]; /* Computed Parameter: P22Size
                                        * '<Root>/DS4504_ETH_Setup'
                                        */
  real_T DS4504_ETH_Setup_P22;         /* Expression: evalin('base',['DS4504_base(',get_param(gcbh,'boardID'),').ReceiveFrame(1).ETH_AcceptAnyIP'])
                                        * '<Root>/DS4504_ETH_Setup'
                                        */
  real_T DS4504_ETH_Setup_P23_Size[2]; /* Computed Parameter: P23Size
                                        * '<Root>/DS4504_ETH_Setup'
                                        */
  real_T DS4504_ETH_Setup_P23;         /* Expression: evalin('base',['DS4504_base(',get_param(gcbh,'boardID'),').SendFrame(1).ETH_Protocol'])
                                        * '<Root>/DS4504_ETH_Setup'
                                        */
  real_T DS4504_ETH_Setup_P24_Size[2]; /* Computed Parameter: P24Size
                                        * '<Root>/DS4504_ETH_Setup'
                                        */
  real_T DS4504_ETH_Setup_P24;         /* Expression: evalin('base',['DS4504_base(',get_param(gcbh,'boardID'),').ReceiveFrame(1).ETH_Protocol'])
                                        * '<Root>/DS4504_ETH_Setup'
                                        */
  real_T DS4504_ETH_Setup_P25_Size[2]; /* Computed Parameter: P25Size
                                        * '<Root>/DS4504_ETH_Setup'
                                        */
  real_T DS4504_ETH_Setup_P25;         /* Expression: evalin('base',['DS4504_base(',get_param(gcbh,'boardID'),').QNXReceiveTimerFactor'])
                                        * '<Root>/DS4504_ETH_Setup'
                                        */
  real_T DS4504_ETH_Setup_P26_Size[2]; /* Computed Parameter: P26Size
                                        * '<Root>/DS4504_ETH_Setup'
                                        */
  real_T DS4504_ETH_Setup_P26;         /* Expression: evalin('base',['DS4504_base(',get_param(gcbh,'boardID'),').ETH_SubnetMask'])
                                        * '<Root>/DS4504_ETH_Setup'
                                        */
  real_T DS4504_ETH_Setup_P27_Size[2]; /* Computed Parameter: P27Size
                                        * '<Root>/DS4504_ETH_Setup'
                                        */
  real_T DS4504_ETH_Setup_P27;         /* Expression: evalin('base',['DS4504_base(',get_param(gcbh,'boardID'),').UDP_ChecksumOn'])
                                        * '<Root>/DS4504_ETH_Setup'
                                        */
  real_T DS4504_ETH_Setup_P28_Size[2]; /* Computed Parameter: P28Size
                                        * '<Root>/DS4504_ETH_Setup'
                                        */
  real_T DS4504_ETH_Setup_P28;         /* Expression: evalin('base',['DS4504_base(',get_param(gcbh,'boardID'),').SendFrame(1).VariableFrameSize'])
                                        * '<Root>/DS4504_ETH_Setup'
                                        */
  real_T DS4504_ETH_Setup_P29_Size[2]; /* Computed Parameter: P29Size
                                        * '<Root>/DS4504_ETH_Setup'
                                        */
  real_T DS4504_ETH_Setup_P29;         /* Expression: evalin('base',['DS4504_base(',get_param(gcbh,'boardID'),').ReceiveFrame(1).VariableFrameSize'])
                                        * '<Root>/DS4504_ETH_Setup'
                                        */
  real_T DS4504_ETH_Setup_P30_Size[2]; /* Computed Parameter: P30Size
                                        * '<Root>/DS4504_ETH_Setup'
                                        */
  real_T DS4504_ETH_Setup_P30;         /* Expression: evalin('base',['DS4504_base(',get_param(gcbh,'boardID'),').SendFrame(1).PredefinedSendPort'])
                                        * '<Root>/DS4504_ETH_Setup'
                                        */
  real_T DS4504_ETH_Setup_P31_Size[2]; /* Computed Parameter: P31Size
                                        * '<Root>/DS4504_ETH_Setup'
                                        */
  real_T DS4504_ETH_Setup_P31;         /* Expression: evalin('base',['DS4504_base(',get_param(gcbh,'boardID'),').SendFrame(1).SendPort'])
                                        * '<Root>/DS4504_ETH_Setup'
                                        */
  real_T DS4504_ETH_Setup_P32_Size[2]; /* Computed Parameter: P32Size
                                        * '<Root>/DS4504_ETH_Setup'
                                        */
  real_T DS4504_ETH_Setup_P32;         /* Expression: evalin('base',['DS4504_base(',get_param(gcbh,'boardID'),').ReceiveFrame(1).ReceiveAsClient'])
                                        * '<Root>/DS4504_ETH_Setup'
                                        */
  real_T DS4504_ETH_Setup_P33_Size[2]; /* Computed Parameter: P33Size
                                        * '<Root>/DS4504_ETH_Setup'
                                        */
  real_T DS4504_ETH_Setup_P33;         /* Expression: evalin('base',['DS4504_base(',get_param(gcbh,'boardID'),').QNXSchedulerTimeInterval'])
                                        * '<Root>/DS4504_ETH_Setup'
                                        */
  real_T DS4504_ETH_Setup_P34_Size[2]; /* Computed Parameter: P34Size
                                        * '<Root>/DS4504_ETH_Setup'
                                        */
  real_T DS4504_ETH_Setup_P34;         /* Expression: evalin('base',['DS4504_base(',get_param(gcbh,'boardID'),').RebootDS4504'])
                                        * '<Root>/DS4504_ETH_Setup'
                                        */
  real_T DS4504_ETH_Setup_P35_Size[2]; /* Computed Parameter: P35Size
                                        * '<Root>/DS4504_ETH_Setup'
                                        */
  real_T DS4504_ETH_Setup_P35;         /* Expression: evalin('base',['DS4504_base(',get_param(gcbh,'boardID'),').MessageDisplayMode'])
                                        * '<Root>/DS4504_ETH_Setup'
                                        */
  real_T Constant_Value;               /* Expression: 1
                                        * '<S1>/Constant'
                                        */
  real_T DS4504_ETH_Receive_P1_Size[2];/* Computed Parameter: P1Size
                                        * '<S1>/DS4504_ETH_Receive'
                                        */
  real_T DS4504_ETH_Receive_P1;        /* Expression: evalin('base',['DS4504_base(',get_param(gcbh,'boardID'),').BoardID'])
                                        * '<S1>/DS4504_ETH_Receive'
                                        */
  real_T DS4504_ETH_Receive_P2_Size[2];/* Computed Parameter: P2Size
                                        * '<S1>/DS4504_ETH_Receive'
                                        */
  real_T DS4504_ETH_Receive_P2;        /* Expression: evalin('base',['DS4504_base(',get_param(gcbh,'boardID'),').ReceiveFrame(1).ID(',num2str(str2double(get_param(gcbh,'blockID'))+1),')'])
                                        * '<S1>/DS4504_ETH_Receive'
                                        */
  real_T DS4504_ETH_Receive_P3_Size[2];/* Computed Parameter: P3Size
                                        * '<S1>/DS4504_ETH_Receive'
                                        */
  real_T DS4504_ETH_Receive_P3;        /* Expression: evalin('base',['DS4504_base(',get_param(gcbh,'boardID'),').ReceiveFrame(1).DPMEMAddress(',num2str(str2double(get_param(gcbh,'blockID'))+1),')'])
                                        * '<S1>/DS4504_ETH_Receive'
                                        */
  real_T DS4504_ETH_Receive_P4_Size[2];/* Computed Parameter: P4Size
                                        * '<S1>/DS4504_ETH_Receive'
                                        */
  real_T DS4504_ETH_Receive_P4;        /* Expression: evalin('base',['DS4504_base(',get_param(gcbh,'boardID'),').ReceiveFrame(1).LengthWords(',num2str(str2double(get_param(gcbh,'blockID'))+1),')'])
                                        * '<S1>/DS4504_ETH_Receive'
                                        */
  real_T DS4504_ETH_Receive_P5_Size[2];/* Computed Parameter: P5Size
                                        * '<S1>/DS4504_ETH_Receive'
                                        */
  real_T DS4504_ETH_Receive_P5;        /* Expression: bool2num(get_param(gcbh,'variableFrameLength'))
                                        * '<S1>/DS4504_ETH_Receive'
                                        */
  real_T DS4504_ETH_Receive_P6_Size[2];/* Computed Parameter: P6Size
                                        * '<S1>/DS4504_ETH_Receive'
                                        */
  real_T DS4504_ETH_Receive_P6;        /* Expression: bool2num(get_param(gcbh,'dynamicIPFiltering'))
                                        * '<S1>/DS4504_ETH_Receive'
                                        */
  real_T DSDecode32_P1_Size[2];        /* Computed Parameter: P1Size
                                        * '<S1>/DSDecode32 '
                                        */
  real_T DSDecode32_P1;                /* Expression: byteordering
                                        * '<S1>/DSDecode32 '
                                        */
  real_T DSDecode32_P2_Size[2];        /* Computed Parameter: P2Size
                                        * '<S1>/DSDecode32 '
                                        */
  real_T DSDecode32_P2;                /* Expression: offset
                                        * '<S1>/DSDecode32 '
                                        */
  real_T DSDecode32_P3_Size[2];        /* Computed Parameter: P3Size
                                        * '<S1>/DSDecode32 '
                                        */
  real_T DSDecode32_P3;                /* Expression: auto_offset
                                        * '<S1>/DSDecode32 '
                                        */
  real_T DSDecode32_P4_Size[2];        /* Computed Parameter: P4Size
                                        * '<S1>/DSDecode32 '
                                        */
  real_T DSDecode32_P4;                /* Expression: datatype
                                        * '<S1>/DSDecode32 '
                                        */
  real_T DSDecode32_P5_Size[2];        /* Computed Parameter: P5Size
                                        * '<S1>/DSDecode32 '
                                        */
  real_T DSDecode32_P5;                /* Expression: one_datatype
                                        * '<S1>/DSDecode32 '
                                        */
  real_T DSDecode32_P6_Size[2];        /* Computed Parameter: P6Size
                                        * '<S1>/DSDecode32 '
                                        */
  real_T DSDecode32_P6;                /* Expression: sampletime
                                        * '<S1>/DSDecode32 '
                                        */
  real_T DataStoreMemoryImage_InitialVal[16];/* Expression: [-1 -1 0 0 0 0 0 0 0 0 0 0 0 0 0 0]
                                              * '<S1>/Data Store Memory Image'
                                              */
  real_T DataStoreMemoryObject_InitialVa[16];/* Expression: [-1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0]
                                              * '<S1>/Data Store Memory Object'
                                              */
  real_T DS100x_AliveFunction_P1_Size[2];/* Computed Parameter: P1Size
                                          * '<S7>/DS100x_AliveFunction'
                                          */
  real_T DS100x_AliveFunction_P1;      /* Expression: boardID-1
                                        * '<S7>/DS100x_AliveFunction'
                                        */
  real_T SFunction2_P1;                /* Expression: 0
                                        * '<S4>/S-Function2'
                                        */
};

/* Real-time Model Data Structure */
struct RT_MODEL_base {
  const char_T *path;
  const char_T *modelName;
  struct SimStruct_tag * *childSfunctions;
  const char_T *errorStatus;
  SS_SimMode simMode;
  RTWExtModeInfo *extModeInfo;
  RTWSolverInfo solverInfo;
  RTWSolverInfo *solverInfoPtr;
  void *sfcnInfo;

  /*
   * NonInlinedSFcns:
   * The following substructure contains information regarding
   * non-inlined s-functions used in the model.
   */
  struct {
    RTWSfcnInfo sfcnInfo;
    SimStruct childSFunctions[13];
    SimStruct *childSFunctionPtrs[13];
    struct _ssBlkInfo2 blkInfo2[13];
    struct _ssSFcnModelMethods2 methods2[13];
    struct _ssSFcnModelMethods3 methods3[13];
    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      struct _ssDWorkRecord dWork[2];
      struct _ssDWorkAuxRecord dWorkAux[2];
    } Sfcn0;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn1;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      real_T const *UPtrs0[1];
      struct _ssPortOutputs outputPortInfo[5];
      uint_T attribs[6];
      mxArray *params[6];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn2;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      real_T const *UPtrs0[8];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[6];
      mxArray *params[6];
      struct _ssDWorkRecord dWork[2];
      struct _ssDWorkAuxRecord dWorkAux[2];
    } Sfcn3;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[4];
      real_T const *UPtrs0[1];
      real_T const *UPtrs1[16];
      real_T const *UPtrs2[18];
      real_T const *UPtrs3[4];
      struct _ssPortOutputs outputPortInfo[1];
      struct _ssDWorkRecord dWork[2];
      struct _ssDWorkAuxRecord dWorkAux[2];
    } Sfcn4;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      real_T const *UPtrs0[10];
      struct _ssPortOutputs outputPortInfo[1];
    } Sfcn5;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
    } Sfcn6;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[2];
      real_T const *UPtrs0[10];
      real_T const *UPtrs1[10];
      struct _ssPortOutputs outputPortInfo[1];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn7;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      real_T const *UPtrs0[10];
      struct _ssPortOutputs outputPortInfo[1];
    } Sfcn8;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      real_T const *UPtrs0[10];
      struct _ssPortOutputs outputPortInfo[1];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn9;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      uint_T attribs[1];
      mxArray *params[1];
    } Sfcn10;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn11;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[3];
      uint_T attribs[35];
      mxArray *params[35];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn12;
  } NonInlinedSFcns;

  /*
   * ModelData:
   * The following substructure contains information regarding
   * the data used in the model.
   */
  struct {
    void *blockIO;
    const void *constBlockIO;
    real_T *defaultParam;
    ZCSigState *prevZCSigState;
    real_T *contStates;
    real_T *derivs;
    real_T *zcSignalValues;
    void *inputs;
    void *outputs;
    boolean_T *contStateDisabled;
    boolean_T zCCacheNeedsReset;
    boolean_T derivCacheNeedsReset;
    boolean_T blkStateChange;
  } ModelData;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T checksums[4];
    uint32_T options;
    int_T numContStates;
    int_T numU;
    int_T numY;
    int_T numSampTimes;
    int_T numBlocks;
    int_T numBlockIO;
    int_T numBlockPrms;
    int_T numDwork;
    int_T numSFcnPrms;
    int_T numSFcns;
    int_T numIports;
    int_T numOports;
    int_T numNonSampZCs;
    int_T sysDirFeedThru;
    int_T rtwGenSfcn;
  } Sizes;

  /*
   * SpecialInfo:
   * The following substructure contains special information
   * related to other components that are dependent on RTW.
   */
  struct {
    const void *mappingInfo;
    void *xpcData;
  } SpecialInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T stepSize;
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    uint32_T clockTick1;
    uint32_T clockTickH1;
    time_T stepSize1;
    uint32_T clockTick2;
    uint32_T clockTickH2;
    time_T stepSize2;
    struct {
      uint8_T TID[2];
    } TaskCounters;

    time_T tStart;
    time_T tFinal;
    time_T timeOfLastOutput;
    void *timingData;
    real_T *varNextHitTimesList;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *sampleTimes;
    time_T *offsetTimes;
    int_T *sampleTimeTaskIDPtr;
    int_T *sampleHits;
    int_T *perTaskSampleHits;
    time_T *t;
    time_T sampleTimesArray[2];
    time_T offsetTimesArray[2];
    int_T sampleTimeTaskIDArray[2];
    int_T sampleHitArray[2];
    int_T perTaskSampleHitsArray[4];
    time_T tArray[3];
  } Timing;

  /*
   * Work:
   * The following substructure contains information regarding
   * the work vectors in the model.
   */
  struct {
    void *dwork;
  } Work;
};

/* Block parameters (auto storage) */
extern Parameters_base base_P;

/* Block signals (auto storage) */
extern BlockIO_base base_B;

/* Block states (auto storage) */
extern D_Work_base base_DWork;

/* External data declarations for dependent source files */
extern real_T base_RGND;               /* real_T ground */
extern real_T base_RGND;               /* real_T ground */

/* Zero-crossing (trigger) state */
extern PrevZCSigStates_base base_PrevZCSigState;

/* Real-time Model object */
extern RT_MODEL_base *base_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : base
 * '<S1>'   : base/Application
 * '<S2>'   : base/DS100x_AliveFunctionality
 * '<S3>'   : base/RTI Data
 * '<S4>'   : base/simState SET
 * '<S5>'   : base/Application/Hand02 Control
 * '<S6>'   : base/Application/Hand02 Trajectory
 * '<S7>'   : base/DS100x_AliveFunctionality/AliveGenSubsystem
 * '<S8>'   : base/DS100x_AliveFunctionality/Background
 * '<S9>'   : base/RTI Data/RTI Data Store
 * '<S10>'  : base/RTI Data/RTI Data Store/RTI Data Store
 * '<S11>'  : base/RTI Data/RTI Data Store/RTI Data Store/RTI Data Store
 */
#endif                                 /* RTW_HEADER_base_h_ */
