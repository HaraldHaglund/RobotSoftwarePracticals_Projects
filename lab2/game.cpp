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
for(int i = 0; i < n_robots; i++){
std::cout << "For AI robot number: " << i+1 <<"\n";
RobotLogic::userInput(x,y,o);
aiRobots[i] = Robot(x,y,o);
}
//Update and print field.
FieldPrinter::updateField(humanRobot, aiRobots);
FieldPrinter::printField();

//While player is inside grid
while(RobotLogic::insideGrid(humanRobot)){
//If human robot is not on an AI square
if(!RobotLogic::p_on_r(humanRobot,aiRobots)){
std::string move = RobotLogic::userMove();
if(move == "forwards"){//Moves robot forwards
humanRobot.moveForward();
}
else if(move == "backwards"){//Moves robot backwards
humanRobot.moveBackward();
}
else if(move == "left"){//Turns robot left. 
humanRobot.turnLeft();
}
else if(move == "right"){ //Turns robot right. 
humanRobot.turnRight();
}
else{std::cout << "Error: Wrong user input. (This should not be possible) "<<"\n";}

//(Update and print out grid
FieldPrinter::updateField(humanRobot, aiRobots);
FieldPrinter::printField();
//Let AI make the move
RobotLogic::aiMove();
FieldPrinter::updateField(humanRobot, aiRobots);
FieldPrinter::printField();
}else{
//If human on robot square, player lost.
std::cout << "lose" << "\n";
break;
}
}
//If left grid, player won.
if(!(RobotLogic::insideGrid(humanRobot))){
std::cout << "win" << "\n";
}

return 0;
}



