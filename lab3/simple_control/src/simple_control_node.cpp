#include "controls.h"

int main (int argc, char** argv){
//Init ROS system.
ros::init(argc, argv, "simple_control_node");
//Create a SimpleControlNode object. (The nodes are created inside the constructor)
SimpleControlNode scn;
//Let ros take over
ros::spin();
return 0;
}
