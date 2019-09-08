

#include "service_server.h"

Mode::Mode(ros::NodeHandle nh_){

    /** Services **/
    control_mode_service_ = nh_.advertiseService("controlmode_service",&Mode::changeControlMode, this);
	ROS_INFO("Ready to change mode");

}

void getControlMode(std::vector<bool> const &input){

	for (int i = 0; i < input.size(); i++) {
		std::cout << input.at(i) << ' ';
	}

}


bool Mode::changeControlMode(tutorial_msgs::ControlMode::Request  	&req,
                               tutorial_msgs::ControlMode::Response &res)
{
	ROS_INFO("entered callback");

	std::vector<bool> mode {false, false, false, false, false, false};
	mode[0] = req.ControlMode[0];
	mode[1] = req.ControlMode[1];
	mode[2] = req.ControlMode[2];
	mode[3] = req.ControlMode[3];
	mode[4] = req.ControlMode[4];
	mode[5] = req.ControlMode[5];	

	getControlMode(mode);

	try {

		  // fundamental types:
 		std::cout << "type: ";
  		std::cout << typeid(req.ControlMode).name() << '\n';  		
  		//std::cout << ( typeid(bool[6]) == typeid(req.ControlMode) ) << '\n';


	    cout << "size " << req.ControlMode.size() << endl;

		res.mode = "success";
		ROS_INFO("successfull callback");
	} catch (const std::exception& e){
		res.mode = "failed";
		ROS_INFO("failed callback");
	}
	return true;
}





int main(int argc, char **argv)
{
  ros::init(argc, argv, "ControlMode");
  ros::NodeHandle nh;
  Mode Mode(nh);

	while(ros::ok()){
		ros::spinOnce();
	}

	return 0;
}
