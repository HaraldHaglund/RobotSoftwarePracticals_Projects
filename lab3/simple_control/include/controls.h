#ifndef CONTROLS_H
#define CONTROLS_H
//Include libraries that could be of use.
#include <mirte_msgs/Intensity.h>
#include <geometry_msgs/Twist.h>
#include <ros/ros.h>

class SimpleControlNode {
	private:
	//Initialize node, subscribers, and publisher
    	ros::NodeHandle nh_;
   	ros::Subscriber left_intensity_sub_;
  	ros::Subscriber right_intensity_sub_;
    	ros::Publisher twist_pub_;
    	
    	//The two intensities
   	double left_intensity_;
   	double right_intensity_;
   	//Threshhold-intensity
  	double threshold_intensity_;
   	//The velocities
   	double linear_velocity_forward_;
  	double linear_velocity_steering_;
   	double angular_velocity_steering_;
  	
	public:
	//Constructor. 
	SimpleControlNode();
	//Stores the left intensity and calls processIntensity
	void leftIntensityCallback(const mirte_msgs::Intensity msg);
	//Stores the right intensity and calls processIntensity
	void rightIntensityCallback(const mirte_msgs::Intensity msg);
	//Decides the robots next movement based on the intensity inputs
	void processIntensity();
};
#endif // CONTROLS_H

