# Lab 3 - Group 60

	How to launch the files: 

	 -> Enter singularity and ROS
	 
	 -> navigate to directory "catkin_ws"
	 
	 -> run "roscore" on another terminal in ROS 
	 
	 -> "catkin_make"
	 
	 -> source by using: "source ~/yourpath/catkin_ws/devel/setup.bash"
	 
	 -> "roslaunch simple_control launchfile.launch"
 
 

## Record-Launch file

	The record-launch file launches the Mirte simulation and records the user-input to the keyboard teleop:
	
	The file launches the Mirte simulation and the keyboard teleop.
	The user runs the simulation and moves the robot. These velocity data are recorded in a new xterm window.
	The corresponding command in the launchfile therefore is "launch-prefix="xterm -e ""
	Finally the recorded velocity inputs are stored in the "teleop-bag" in the "simple_control" package. 
	

## Play-Launch file

	The play-launch file plays the previously recorded user-input and outputs the movements inside the Mirte-simulation. 
	Note that every simulation is unique due to the random noise added on the vehicles movement.
	

## Simple_Control-Launch file - Control the Mirte

	The Mirte is supposed to run and navigate on a given line automatically. 
	The node subscribes two continuously compared sensor data (topics) to navigate and stay on the path. 
	Even though the program is called "simple_control" it is unfortunately not that simple. 
	
#### The Program contains four files:

	>node: "controls.cpp"

	>node: "simple_control_node.cpp"

	>header-file: "controls.h"

	>launch-file: "simple_control.launch"
	
	
#### How the controls.cpp file is structured:
	
	1. Include the header file and define Class and Constructor. The Constructor retrieves three parameters from ROS. 
	(explained below) 
	
	2. Init a ROS node
	
	3. Subscribes data (massages) from the Robot (specififc topic). In specific the "left/right_intensity" message.
	   The subscriber is reffering to Point 6, the callback functions. 
	   Afterwards a small check is performed to see if the messages were retrieved correctly. (see next step)

	4. Reading or setting the default values of the three following parameters.
	   Checking if messages were retrieved correctly:
		If so, the message will be displayed: "All parameters were sucessfully retrived from launch file"
		It not, the values are set to different default values. (Next Point) 
		
	   Since they might be different from group to group the set default values (in case of set required) are shown as follows: 
		>> linear_velocity_forward = 1.5
		>> linear_velocity_steering = 0.5
		>> angular_velocity_steering = 1
	
	5. Displays these four values by using ROS_INFO_STREAM. 
	
	6. The two Callback Functions are being executed every time a new message arrives. 
	   They receive the two sensor data, store it in the variables and lead to the process functions. 
	
	7. Process Function compares the value and determine the robots behaviour, 
	   based on the intensity of the sensor outputs. e.g. if the left_intensity is higher then the right, it rotates clockwise to the right. 
	   If the left and right intensity are below a spcific threshold, the robot will stop. 
	   As a final step, the processed data has to be published back to the topic, by using "twist_pub_.publish(twist)". 
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
