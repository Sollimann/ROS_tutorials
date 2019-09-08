#!/usr/bin/env python

import rospy
#import sys
#print(sys.path)
#sys.path.append('/rosservice/client/')
#print(sys.path)
from tutorial_msgs.srv import ControlMode



class Mode:


    def __init__(self):
    	rospy.init_node('change_control_mode')


    def change_control_mode_client(self,requested_mode):

        rospy.wait_for_service('controlmode_service')
        try:
            control_mode = rospy.ServiceProxy('controlmode_service', ControlMode)
            response = control_mode(requested_mode)
            print(response.mode)
            return response.mode
        except rospy.ServiceException, e:
            print "Service call failed"
    

if __name__ == '__main__':
    
    try:
        control_mode = Mode()
        control_mode.change_control_mode_client([False, True, False, False, False, False])
        rospy.spin()

    except rospy.ROSInterruptException:
        print('caught exeption')
        pass

