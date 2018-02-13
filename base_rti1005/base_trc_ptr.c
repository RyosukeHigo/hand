/***************************************************************************

   Source file base_trc_ptr.c:

   Definition of function that initializes the global TRC pointers

   RTI1005 6.3 (25-Jun-2009)
   Tue Feb 13 22:42:09 2018

   (c) Copyright 2008, dSPACE GmbH. All rights reserved.

 *****************************************************************************/

/* Include header file. */
#include "base_trc_ptr.h"

/* Definition of Global pointers to data type transitions (for TRC-file access) */
volatile real_T *p_base_B_real_T_0 = 0;
volatile int32_T *p_base_B_int32_T_1 = 0;
volatile uint32_T *p_base_B_uint32_T_2 = 0;
volatile real_T *p_base_P_real_T_0 = 0;
volatile real_T *p_base_DWork_real_T_0 = 0;
volatile int_T *p_base_DWork_int_T_2 = 0;
