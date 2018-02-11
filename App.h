#ifndef APP_H
#define APP_H

#include "DataDef.h"
#include <Hand.h>
#include <WAM.h>
#include <AVS.h>
#include <XYstage.h>

// 時間設定
#define START_TIME	(2.0)       // 初期姿勢から準備姿勢への時間
#define END_TIME	(3.0)       // 終了姿勢から初期姿勢への時間
#define MOTION_TIME	(15.0)      // 動作時間
#define ALL_APP_TIME    START_TIME+MOTION_TIME+END_TIME

// ハンド
int handTrajApp(HANDJnt ref_jnt_ang, HANDJnt data, Object obj, double time, double *sensor);
//int hand02TrajDemo1(HANDJnt ref_jnt_ang, HANDJnt data, Object obj, double time, double *sensor, double *camera);
int handAppSet02(HAND *hand02);
int handAppSet03(HAND *hand03);
// アーム
int wamTrajApp(WAMJnt ref_jnt_ang, Object obj, double time);
int wamAppSet(WAM *wam);
// アクティブビジョン
int avsTrajApp(AVSJntAll ref_jnt_ang, double time);
int avsVisualTrajApp(AVSImgCenAll ref_img_center, double time);
int avsAppSet(AVSALL *avs);
// XYステージ
int XYstageTrajApp(XYJnt ref_jnt_ang, XYJnt data, Object obj, double time, double *sensor);
int XYstageAppSet(XY *xy);

#endif
