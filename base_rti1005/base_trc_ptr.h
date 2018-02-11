  /*********************** dSPACE target specific file *************************

   Header file base_trc_ptr.h:

   Declaration of function that initializes the global TRC pointers

   RTI1005 6.3 (25-Jun-2009)
   Sun Feb 11 21:54:00 2018

   (c) Copyright 2008, dSPACE GmbH. All rights reserved.

  *****************************************************************************/
  #ifndef RTI_HEADER_base_trc_ptr_h_
  #define RTI_HEADER_base_trc_ptr_h_
  /* Include the model header file. */
  #include "base.h"
  #include "base_private.h"

  #ifdef EXTERN_C
  #undef EXTERN_C
  #endif

  #ifdef __cplusplus
  #define EXTERN_C                       extern "C"
  #else
  #define EXTERN_C                       extern
  #endif

  /*
   *  Declare the global TRC pointers
   */
              EXTERN_C volatile  real_T *p_base_B_real_T_0;
              EXTERN_C volatile  int32_T *p_base_B_int32_T_1;
              EXTERN_C volatile  uint32_T *p_base_B_uint32_T_2;
              EXTERN_C volatile  real_T *p_base_P_real_T_0;
              EXTERN_C volatile  real_T *p_base_DWork_real_T_0;
              EXTERN_C volatile  int_T *p_base_DWork_int_T_2;

   #define RTI_INIT_TRC_POINTERS() \
              p_base_B_real_T_0 = &base_B.DS4504_ETH_Setup_o1;\
              p_base_B_int32_T_1 = &base_B.SystemSetting;\
              p_base_B_uint32_T_2 = &base_B.DS4504_ETH_Receive_o1[0];\
              p_base_P_real_T_0 = &base_P.DS4504_ETH_Setup_P1_Size[0];\
              p_base_DWork_real_T_0 = &base_DWork.Image[0];\
              p_base_DWork_int_T_2 = &base_DWork.DS4504_ETH_Setup_IWORK[0];\

   #endif                       /* RTI_HEADER_base_trc_ptr_h_ */
