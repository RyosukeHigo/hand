/******************************************************************************

   Include file base_usr.c:

   Definition of functions for user-defined initialization,
   system I/O, and background process code.

   RTI1005 5.2.5 (18-Mar-2005)
   Wed Feb 15 14:18:53 2006

   Copyright (c) 1997-2003 dSPACE GmbH, GERMANY

 *****************************************************************************/

/* ========================================================================= */
/* =====  Define file version macro. Never change this value.  ============= */
/* ========================================================================= */
#define USER_CODE_FILE_VERSION 5
/* ========================================================================= */

/* Insert #include directives for header files here. */
#include <cpv_ctrl.h>
#include <cpv_io.h>


#if defined(_INLINE)
# define __INLINE static inline
#else
# define __INLINE static
#endif

/////////////////////////////////////////////////
// デモ番号
// Control Desk で値を設定
/////////////////////////////////////////////////
unsigned int     app_num = 0;

/////////////////////////////////////////////////
// CPV プログラムホスト通信変数
/////////////////////////////////////////////////
int    host_access_flag = HOST2RTP;
unsigned int    prog_addr = 0x0;
unsigned int    prog_data = 0x0;


static void usr_initialize(void)
{
}


__INLINE void usr_sample_input(void)
{
}


__INLINE void usr_input(void)
{
}


__INLINE void usr_output(void)
{
}


static void usr_terminate(void)
{
}


static void usr_background(void)
{
	/*
	if(host_access_flag == RTP2CPV){         // ホストからデータ受信
		CPV_download_prog(CPV1, prog_addr, prog_data);
		host_access_flag = HOST2RTP;
	}else if(host_access_flag == RTP2CPV_2){         // ホストからデータ受信
		CPV_download_prog(CPV2, prog_addr, prog_data);
		host_access_flag = HOST2RTP_2;
    }else if(host_access_flag == CPV_READY){    // CPVプログラム開始
        CPV_start_prog(CPV1);
        CPV_start_prog(CPV2);
        host_access_flag = CPV_START;
    }else if(host_access_flag == CPV_END){   // CPVプログラム終了
        CPV_stop_prog(CPV1);
        CPV_stop_prog(CPV2);
        host_access_flag = CPV_PAUSE;        
    }
	*/
}


#undef __INLINE

/****** [EOF] ****************************************************************/
