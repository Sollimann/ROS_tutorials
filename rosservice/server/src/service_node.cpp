

#include "service_server.h"


bool Mode::change_control_mode(tutorial_msgs::ControlMode::Request  &req,
                               tutorial_msgs::ControlMode::Response &res)
{

	return true;
}


int main(int argc, char **argv)
{
	ros::init(argc, argv, "server");
	ros::NodeHandle nh_;

	while(ros::ok()){
		ros::spinOnce();
	}

	return 0;
}
