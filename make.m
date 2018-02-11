clear mex
% パスの設定
addpath ../../hand02 ../../hand03 ../../wam ../../cpv ../../avs ../../tactile ../../xystage
% システム初期設定,タスク初期設定
mex -I. -I../../basis -I../../hand02 -I../../hand03 -I../../wam -I../../cpv -I../../avs -I../../xystage SystemSet.c
mex -I. -I../../basis -I../../hand02 -I../../hand03 -I../../wam -I../../cpv -I../../avs -I../../xystage TaskSet.c Hand02App.c Hand03App.c WAMApp.c AVSApp.c XYstageApp.c
% ハンド
% mex -I. -I../../basis -I../../hand -I../../hand02 -I../../hand03 -I../../wam -I../../cpv -I../../avs -I../../xystage -outdir ../../hand ../../hand/handCtrl.c HandApp.c
% mex -I. -I../../basis -I../../hand -outdir ../../hand ../../hand/handDALimit.c
% mex -I. -I../../basis -I../../hand -outdir ../../hand ../../hand/handEnc2JntAng.c
% mex -I. -I../../basis -I../../hand -outdir ../../hand ../../hand/handJntAngLimit.c
% mex -I. -I../../basis -I../../hand -outdir ../../hand ../../hand/handJntTrq2DA.c
%mex -I. -I../../basis -I../../basis -I../../hand -I../../hand02 -I../../hand03 -I../../wam -I../../cpv -I../../avs -I../../xystage -outdir ../../hand ../../hand/handTraj.c HandApp.c
% ハンド02
mex -I. -I../../basis -I../../hand02 -I../../wam -I../../cpv -I../../avs -I../../xystage -outdir ../../hand02 ../../hand02/hand02Ctrl.c Hand02App.c
mex -I. -I../../basis -I../../hand02 -outdir ../../hand02 ../../hand02/hand02DALimit.c
mex -I. -I../../basis -I../../hand02 -outdir ../../hand02 ../../hand02/hand02Enc2JntAng.c
mex -I. -I../../basis -I../../hand02 -outdir ../../hand02 ../../hand02/hand02JntAngLimit.c
mex -I. -I../../basis -I../../hand02 -outdir ../../hand02 ../../hand02/hand02JntTrq2DA.c
mex -I. -I../../basis -I../../hand02 -I../../wam -I../../cpv -I../../avs -I../../xystage -outdir ../../hand02 ../../hand02/hand02Traj.c Hand02App.c
% ハンド03
mex -I. -I../../basis -I../../hand03 -I../../wam -I../../cpv -I../../avs -I../../xystage -outdir ../../hand03 ../../hand03/hand03Ctrl.c Hand03App.c
mex -I. -I../../basis -I../../hand03 -outdir ../../hand03 ../../hand03/hand03DALimit.c
mex -I. -I../../basis -I../../hand03 -outdir ../../hand03 ../../hand03/hand03Enc2JntAng.c
mex -I. -I../../basis -I../../hand03 -outdir ../../hand03 ../../hand03/hand03JntAngLimit.c
mex -I. -I../../basis -I../../hand03 -outdir ../../hand03 ../../hand03/hand03JntTrq2DA.c
mex -I. -I../../basis -I../../hand03 -I../../wam -I../../cpv -I../../avs -I../../xystage -outdir ../../hand03 ../../hand03/hand03Traj.c Hand03App.c
% アクティブビジョン
mex -I. -I../../basis -I../../hand -I../../hand02 -I../../hand03 -I../../wam -I../../cpv -I../../avs -I../../xystage -outdir ../../avs ../../avs/avs3Dcalc.c AVSApp.c ../../basis/LinkHomoMat.c ../../basis/vec3DRot.c ../../basis/vec3DInProduct.c
mex -I. -I../../basis -I../../hand -I../../hand02 -I../../hand03 -I../../wam -I../../cpv -I../../avs -I../../xystage -outdir ../../avs ../../avs/avsCtrl.c AVSApp.c ../../basis/LinkHomoMat.c ../../basis/vec3DRot.c ../../basis/vec3DInProduct.c
mex -I. -I../../basis -I../../avs -outdir ../../avs ../../avs/avsDALimit.c
mex -I. -I../../basis -I../../avs -outdir ../../avs ../../avs/avsEnc2JntAng.c
mex -I. -I../../basis -I../../avs -outdir ../../avs ../../avs/avsJntAngLimit.c
mex -I. -I../../basis -I../../avs -outdir ../../avs ../../avs/avsJntTrq2DA.c
mex -I. -I../../basis -I../../hand -I../../hand02 -I../../hand03 -I../../wam -I../../cpv -I../../avs -I../../xystage -outdir ../../avs ../../avs/avsTraj.c AVSApp.c
mex -I. -I../../basis -I../../hand -I../../hand02 -I../../hand03 -I../../wam -I../../cpv -I../../avs -I../../xystage -outdir ../../avs ../../avs/avsVisualTraj.c AVSApp.c
% CPV
mex -I. -I../../cpv -outdir ../../cpv ../../cpv/cpvStart.c
% Tactile
mex -I. -I../../tactile -outdir ../../tactile ../../tactile/tactile.c
mex -I. -I../../tactile -outdir ../../tactile ../../tactile/tactile02.c
mex -I. -I../../tactile -outdir ../../tactile ../../tactile/tactile03.c
% XY-stage
mex -I. -I../../basis -I../../hand -I../../hand02 -I../../hand03 -I../../wam -I../../cpv -I../../avs -I../../xystage -outdir ../../xystage ../../xystage/xystageCtrl.c XYstageApp.c
mex -I. -I../../basis -I../../xystage -outdir ../../xystage ../../xystage/xystageDALimit.c
mex -I. -I../../basis -I../../xystage -outdir ../../xystage ../../xystage/xystageEnc2JntAng.c
mex -I. -I../../basis -I../../xystage -outdir ../../xystage ../../xystage/xystageAngLimit.c
mex -I. -I../../basis -I../../xystage -outdir ../../xystage ../../xystage/xystageTrq2DA.c
mex -I. -I../../basis -I../../hand -I../../hand02 -I../../hand03 -I../../wam -I../../cpv -I../../avs -I../../xystage -outdir ../../xystage ../../xystage/xystageTraj.c XYstageApp.c
clear mex
