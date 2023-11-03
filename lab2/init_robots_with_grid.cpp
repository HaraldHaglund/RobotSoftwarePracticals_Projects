#include <iostream>
#include <string>
#include "robot_logic.h"
#include "FieldPrinter.h"
#include "Robot.h"
#include <vector>


//Main method
int main(){

//Ask for # robots
int n_robots = RobotLogic::ask_n_robots();
//Ask for the position and orientation of the human controlled robot
int x;
int y;
char o;
std::cout << "For the human controlled robot: " << "\n";
RobotLogic::userInput(x,y,o);
//Initialize human robot
Robot humanRobot(x,y,o);
//Create AI-robot vector with n AI-robots and initialize all the robots with a for-loop
std::vector<Robot> aiRobots(n_robots);
for(int i = 0; i < n_robots; i++)
{
	bool detected = false; //initial state
	while (!detected)
		{
		std::cout << "For AI robot number: " << i+1 <<"\n";
		RobotLogic::userInput(x,y,o);
		aiRobots[i] = Robot(x,y,o);
		
		RobotLogic::posTaken(i+1, aiRobots) = detected;
			{
		        std::cout << "Coordinates already taken. Enter different coordinates.\n";
		        }
                }	
}
//Update and print field
FieldPrinter::updateField(humanRobot, aiRobots);
FieldPrinter::printField();

return 0;
}




RobotLogic::posTaken(n_robots, aiRobots)  //query function to avoid same coordinates
	{ 
	while (!detected)
		{
		std::cout<<"enter different coordinates. Robots must not have same initial coordinates" <<std::endl;
		userInput(x,y,o);
		}
	}
