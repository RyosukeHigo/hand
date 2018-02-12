/*********************** dSPACE target specific file *************************

   Include file base_rti.c:

   Definition of functions and variables for the system I/O and for
   the hardware and software interrupts used.

   RTI1005 6.3 (25-Jun-2009)
   Mon Feb 12 16:09:19 2018

   (c) Copyright 2006, dSPACE GmbH. All rights reserved.

 *****************************************************************************/

#if !(defined(__RTI_SIMENGINE__) || defined(RTIMP_FRAME))
# error This file may be included only by the RTI(-MP) simulation engine.
#endif

/* Include the model header file. */
#include "base.h"
#include "base_private.h"

/* Defines for block output and parameter structure existence */
#define RTI_rtB_STRUCTURE_EXISTS       1
#define RTI_rtP_STRUCTURE_EXISTS       1
#define RTB_STRUCTURE_NAME             base_B
#define RTP_STRUCTURE_NAME             base_P

/* dSPACE generated includes for header files */
#include <brtenv.h>
#include <rtkernel.h>
#include <rti_assert.h>
#include <rtidefineddatatypes.h>
#include <rti_sim_engine_exp.h>

/****** Definitions: task functions for timer tasks *********************/

/* Timer Task 1. (Base rate). */
static void rti_TIMERA(rtk_p_task_control_block task)
{
  /* Task entry code BEGIN */
  /* -- None. -- */
  /* Task entry code END */

  /* Task code. */
  baseRateService(task);

  /* Task exit code BEGIN */
  /* -- None. -- */
  /* Task exit code END */
}

/* ===== Declarations of RTI blocks ======================================== */

/* dSPACE Test-Automation Stimulus Engine */
#define TA_STIMULUS_ENGINE_ENABLE      0

/* dSPACE Background Task Block: <S2>/Background */
void base_AliveGenSubsystem(int_T controlPortIdx);

/* ===== Definition of interface functions for simulation engine =========== */
#ifdef MULTITASKING
# define dsIsSampleHit(RTM,sti)        rtmGetSampleHitPtr(RTM)[sti]
#else
# define dsIsSampleHit(RTM,sti)        rtmIsSampleHit(RTM,sti,0)
#endif

#if defined(_INLINE)
# define __INLINE                      static inline
#else
# define __INLINE                      static
#endif

static void rti_mdl_initialize_host_services(void)
{
  {
    ts_timestamp_type ts = { 0, 0 };

    host_service(1, &ts);

#ifdef RTT_ENABLE

    DsDaq_Init(32, 1);

#endif

  }
}

static void rti_mdl_initialize_io_boards(void)
{
  /* Registering of RTI products and modules at VCM */
  {
    vcm_module_register(VCM_MID_RTI1005, (void *) 0,
                        VCM_TXT_RTI1005, 6, 3, 0,
                        VCM_VERSION_RELEASE, 0, 0, 0, VCM_CTRL_NO_ST);

    {
      vcm_module_descriptor_type* msg_mod_ptr;
      msg_mod_ptr = vcm_module_register(VCM_MID_MATLAB, (void *) 0,
        VCM_TXT_MATLAB, 7, 7, 0,
        VCM_VERSION_RELEASE, 0, 0, 0, VCM_CTRL_NO_ST);
      vcm_module_register(VCM_MID_SIMULINK, msg_mod_ptr,
                          VCM_TXT_SIMULINK, 7, 2, 0,
                          VCM_VERSION_RELEASE, 0, 0, 0, VCM_CTRL_NO_ST);
      vcm_module_register(VCM_MID_RTW, msg_mod_ptr,
                          VCM_TXT_RTW, 7, 2, 0,
                          VCM_VERSION_RELEASE, 0, 0, 0, VCM_CTRL_NO_ST);
    }
  }
}

/* Function rti_mdl_slave_load() is empty */
#define rti_mdl_slave_load()

/* Function rti_mdl_rtk_initialize() is empty */
#define rti_mdl_rtk_initialize()

/* Function rti_mdl_initialize_io_units() is empty */
#define rti_mdl_initialize_io_units()

/* Function rti_mdl_acknowledge_interrupts() is empty */
#define rti_mdl_acknowledge_interrupts()

/* Function rti_mdl_timetables_register() is empty */
#define rti_mdl_timetables_register()

/* Function rti_mdl_timesync_simstate() is empty */
#define rti_mdl_timesync_simstate()

/* Function rti_mdl_timesync_baserate() is empty */
#define rti_mdl_timesync_baserate()

static void rti_mdl_background(void)
{
  /* Local variables for absolute time support */
  rtk_timestamp_type absTaskTime;
  double absTime = 0;

  /* Get counter values for absolute time */
  ts_timestamp_read(&absTaskTime);
  absTime = ts_time_calculate(&absTaskTime);

  /* Update absolute time counters for block: <S2>/Background */
  base_M->Timing.clockTickH2 = (UInt32)(absTime);
  base_M->Timing.clockTick2 = (UInt32)((absTime-(UInt32)(absTime))*4294967296.0);
  base_M->Timing.t[2] = base_M->Timing.clockTick2 * base_M->Timing.stepSize2 +
    base_M->Timing.clockTickH2 * base_M->Timing.stepSize2 * 4294967296.0;

#ifdef RTT_ENABLE

  /* DsDaq background call */
  DsDaq_Background();

#endif

  /* dSPACE Background Task Block: <S2>/Background */
  /* ... Execute for: PAUSE */
  if (simState == PAUSE) {
    base_AliveGenSubsystemTID2(0);
  }
}

/* Function rti_mdl_sample_input() is empty */
#define rti_mdl_sample_input()
#undef __INLINE

/****** [EOF] ****************************************************************/
