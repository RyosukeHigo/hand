clear mex
% カレントディレクトリ
delete *.dll *.exp *.lib *.map *.ppc *.sdf base.trc
rmdir('base_rti1005','s')
rmdir('slprj','s')
% ライブラリ
delete ../../hand/*.mexw32
delete ../../hand02/*.mexw32
delete ../../hand03/*.mexw32
delete ../../wam/*.mexw32
delete ../../tactile/*.mexw32
delete ../../xystage/*.mexw32
delete ../../avs/*.mexw32
delete ../../cpv/*.mexw32
clear mex
