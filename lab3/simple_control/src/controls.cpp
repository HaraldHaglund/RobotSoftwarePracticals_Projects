#include "controls.h"

SimpleControlNode::SimpleControlNode(){
// Initialize ROS node
nh_ = ros::NodeHandle("simple_control_node");
// Subscribe to intensity messages. The respective callback-function is called.
left_intensity_sub_ = nh_.subscribe("/mirte/intensity/left", 100, &SimpleControlNode::leftIntensityCallback, this); 
right_intensity_sub_ = nh_.subscribe("/mirte/intensity/right", 100, &SimpleControlNode::rightIntensityCallback, this);
//Determine the topic where Twist messages will be published
twist_pub_ = nh_.advertise<geometry_msgs::Twist>("/mirte/mobile_base_controller/cmd_vel", 100);

//Retrive the parameters from launch file.  
if(ros::param::get("linear_velocity_forward", linear_velocity_forward_) && ros::param::get("linear_velocity_steering", linear_velocity_steering_) && 
ros::param::get("angular_velocity_steering", angular_velocity_steering_) && ros::param::get("threshold_intensity",threshold_intensity_)){
ROS_INFO_STREAM("All parameters were sucessfully retrived from launch file");
}
//Assign default values if they are not found.
else{
ROS_INFO_STREAM("Parameters not found in launchfile, using standard values: ");
linear_velocity_forward_ = 1.5;
linear_velocity_steering_ = 0.5;
angular_velocity_steering_ = 1;
threshold_intensity_ = 5;
}
//Print out the values
ROS_INFO_STREAM("linear_velocity_forward: " << linear_velocity_forward_);
ROS_INFO_STREAM("linear_velocity_steering: " << linear_velocity_steering_);
ROS_INFO_STREAM("angular_velocity_steering: " << angular_velocity_steering_);
ROS_INFO_STREAM("threshold_intensity: " << threshold_intensity_);

}

void SimpleControlNode::leftIntensityCallback(const mirte_msgs::Intensity msg){
left_intensity_ = msg.value;
processIntensity();
}

void SimpleControlNode::rightIntensityCallback(const mirte_msgs::Intensity msg){
right_intensity_ = msg.value;
processIntensity();
}
	
void SimpleControlNode::processIntensity(){
geometry_msgs::Twist twist;
//Rotate counter clockwise
if (left_intensity_ < right_intensity_){
twist.angular.z = angular_velocity_steering_;
twist.linear.x = linear_velocity_steering_;
}
//Rotate clockwise
else if(left_intensity_ > right_intensity_){
twist.angular.z = -angular_velocity_steering_;
twist.linear.x = linear_velocity_steering_;
}
//Stop. 
else if(left_intensity_ < threshold_intensity_  && right_intensity_ < threshold_intensity_){
twist.angular.z = 0;
twist.linear.x = 0;
}
//Drive forward
else{
twist.linear.x = linear_velocity_forward_;
}
//Publish twist
twist_pub_.publish(twist);
}
