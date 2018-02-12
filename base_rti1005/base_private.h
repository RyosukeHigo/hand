/*
 * base_private.h
 *
 * Real-Time Workshop code generation for Simulink model "base.mdl".
 *
 * Model Version              : 1.480
 * Real-Time Workshop version : 7.2  (R2008b)  04-Aug-2008
 * C source code generated on : Mon Feb 12 16:09:19 2018
 */
#ifndef RTW_HEADER_base_private_h_
#define RTW_HEADER_base_private_h_
#include "rtwtypes.h"
#ifndef __RTWTYPES_H__
#error This file requires rtwtypes.h to be included
#else
#ifdef TMWTYPES_PREVIOUSLY_INCLUDED
#error This file requires rtwtypes.h to be included before tmwtypes.h
#else

/* Check for inclusion of an incorrect version of rtwtypes.h */
#ifndef RTWTYPES_ID_C08S16I32L32N32F1
#error This code was generated with a different "rtwtypes.h" than the file included
#endif                                 /* RTWTYPES_ID_C08S16I32L32N32F1 */
#endif                                 /* TMWTYPES_PREVIOUSLY_INCLUDED */
#endif                                 /* __RTWTYPES_H__ */

/*
 * UNUSED_PARAMETER(x)
 *   Used to specify that a function parameter (argument) is required but not
 *   accessed by the function body.
 */
#ifndef UNUSED_PARAMETER
# if defined(__LCC__)
#   define UNUSED_PARAMETER(x)                                   /* do nothing */
# else

/*
 * This is the semi-ANSI standard way of indicating that an
 * unused function parameter is required.
 */
#   define UNUSED_PARAMETER(x)         (void) (x)
# endif
#endif

extern void cpvStart(SimStruct *rts);
extern void TaskSet(SimStruct *rts);
extern void ds4504_read_uint32_array(SimStruct *rts);
extern void dsa_dsdecode32(SimStruct *rts);
extern void hand02Traj(SimStruct *rts);
extern void hand02JntAngLimit(SimStruct *rts);
extern void hand02Enc2JntAng(SimStruct *rts);
extern void hand02Ctrl(SimStruct *rts);
extern void hand02JntTrq2DA(SimStruct *rts);
extern void hand02DALimit(SimStruct *rts);
extern void ds4504_DS100xAlive(SimStruct *rts);
extern void SystemSet(SimStruct *rts);
extern void ds4504_init(SimStruct *rts);
void base_AliveGenSubsystem_Init(void);
void base_AliveGenSubsystem_Start(void);
void base_AliveGenSubsystem(int_T controlPortIdx);
void base_AliveGenSubsystemTID2(int_T controlPortIdx);
void base_AliveGenSubsystem_Term(void);

#endif                                 /* RTW_HEADER_base_private_h_ */
