#  -*- coding: cp932 -*-


def On_Instrumentation_StartAnimation():
    """
    Syntax      : On_Instrumentation_StartAnimation()

    Purpose     : Fired if the animation is started

    Parameters  : None

    """
    print "On_Instrumentation_StartAnimation called"

    import os
    import threading
#    import cdautomationlib

#    prog_path = '..\\..\\host_cpv'
#    prog_path = 'C:\\MATLAB701\\work\\yamakawa\\Force_Control\\Knotting_20071213\\host_cpvII'
#    prog_name = 'host_cpv.exe'
#    def cpv_download():
#        os.chdir(prog_path)
#        os.system(prog_name)
#    CPV = threading.Thread(target=cpv_download,args=())
#    CPV.start()
#    Obj = cdautomationlib.Application()
#    Obj.Visible