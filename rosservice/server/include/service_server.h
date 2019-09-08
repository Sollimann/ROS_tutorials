#include <ros/ros.h>
#include "tutorial_msgs/ControlMode.h"



class Mode
{

    private:
        Mode(ros::NodeHandle &nh_);
        ros::ServiceServer change_control_mode_service;

        bool change_control_mode(tutorial_msgs::ControlMode::Request  &req,
                                 tutorial_msgs::ControlMode::Response &res);        

    public:
        

};


