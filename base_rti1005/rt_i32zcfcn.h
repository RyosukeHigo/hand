/*
 * rt_i32zcfcn.h
 *
 * Real-Time Workshop code generation for Simulink model "base.mdl".
 *
 * Model Version              : 1.480
 * Real-Time Workshop version : 7.2  (R2008b)  04-Aug-2008
 * C source code generated on : Thu Feb 15 20:53:42 2018
 */

#ifndef RTW_HEADER_rt_i32zcfcn_h_
#define RTW_HEADER_rt_i32zcfcn_h_
#include "rtwtypes.h"
#include "solver_zc.h"
#ifndef slZcHadEvent
#define slZcHadEvent(ev, zcsDir)       ( (ev & zcsDir) != 0x00 )
#endif

#ifndef slZcUnAliasEvents
#define slZcUnAliasEvents(evL, evR)    ( ( ( slZcHadEvent(evL,SL_ZCS_EVENT_N2Z) && slZcHadEvent(evR,SL_ZCS_EVENT_Z2P) ) || ( slZcHadEvent(evL,SL_ZCS_EVENT_P2Z) && slZcHadEvent(evR,SL_ZCS_EVENT_Z2N) ) ) ? SL_ZCS_EVENT_NUL : evR )
#endif

extern ZCEventType rt_I32ZCFcn(ZCDirection direction,
  ZCSigState *prevzc,
  int32_T zcSig);

#endif                                 /* RTW_HEADER_rt_i32zcfcn_h_ */
