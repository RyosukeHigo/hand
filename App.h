#ifndef APP_H
#define APP_H

#include "DataDef.h"
#include <Hand.h>
#include <WAM.h>
#include <AVS.h>
#include <XYstage.h>

// ���Ԑݒ�
#define START_TIME	(2.0)       // �����p�����珀���p���ւ̎���
#define END_TIME	(3.0)       // �I���p�����珉���p���ւ̎���
#define MOTION_TIME	(15.0)      // ���쎞��
#define ALL_APP_TIME    START_TIME+MOTION_TIME+END_TIME

// �n���h
int handTrajApp(HANDJnt ref_jnt_ang, HANDJnt data, Object obj, double time, double *sensor);
//int hand02TrajDemo1(HANDJnt ref_jnt_ang, HANDJnt data, Object obj, double time, double *sensor, double *camera);
int handAppSet02(HAND *hand02);
int handAppSet03(HAND *hand03);
// �A�[��
int wamTrajApp(WAMJnt ref_jnt_ang, Object obj, double time);
int wamAppSet(WAM *wam);
// �A�N�e�B�u�r�W����
int avsTrajApp(AVSJntAll ref_jnt_ang, double time);
int avsVisualTrajApp(AVSImgCenAll ref_img_center, double time);
int avsAppSet(AVSALL *avs);
// XY�X�e�[�W
int XYstageTrajApp(XYJnt ref_jnt_ang, XYJnt data, Object obj, double time, double *sensor);
int XYstageAppSet(XY *xy);

#endif
