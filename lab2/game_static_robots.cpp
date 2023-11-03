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
//Ask for the position and orientation of the human controlled robot.
int x;
int y;
char o;
std::cout << "For the human controlled robot: " << "\n";
RobotLogic::userInput(x,y,o);
//Initialize human robot
Robot humanRobot(x,y,o);
//Create AI-robot vector with n AI-robots and initialize all the robots with a for-loop
std::vector<Robot> aiRobots(n_robots);
for(int i = 0; i < n_robots; i++){
std::cout << "For AI robot number: " << i+1 <<"\n";
RobotLogic::userInput(x,y,o);
//also implemented, the user should not be able to give the same coordinates to more than one robot
aiRobots[i] = Robot(x,y,o);
}
//Update and print field
FieldPrinter::updateField(humanRobot, aiRobots);
FieldPrinter::printField();

//While player is inside grid
while(0 <= humanRobot.getX() && humanRobot.getX() <= 21 && 0 <= humanRobot.getY() && humanRobot.getY() <= 14){
//If human robot is not on an AI square
if(!RobotLogic::p_on_r(humanRobot,aiRobots)){
std::string move = RobotLogic::userMove();
if(move == "forwards"){//Moves robot forwards
humanRobot.moveForward();
}
else if(move == "backwards"){//Moves robot backwards
humanRobot.moveBackward();
}
else if(move == "left"){//Turns robot left. Add moveforward?
humanRobot.turnLeft();
}
else if(move == "right"){ //Turns robot right. Add moveforward?
humanRobot.turnRight();
}
else{std::cout << "Error: Wrong user input. (This should not be possible) "<<"\n";}

//Ask for input f, b, l, r (Implement function in robotlogic)
//Move robot accordingly
//(update? and) Print out grid
FieldPrinter::updateField(humanRobot, aiRobots);
FieldPrinter::printField();
}else{
//If go into robot, player lost.
std::cout << "lose" << "\n";
break;
}
}
if(!(0 <= humanRobot.getX() && humanRobot.getX() <= 21 && 0 <= humanRobot.getY() && humanRobot.getY() <= 14)){
std::cout << "win" << "\n";
}


//If left grid, player won.



return 0;
}



