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


    def change_control_mode_client(self,modes):
        print('controlmode')
        rospy.wait_for_service('ControlMode')
        try:
            ControlMode = rospy.ServiceProxy('ControlMode', ControlMode)
            response = ControlMode(modes)
            print('entered try')
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

