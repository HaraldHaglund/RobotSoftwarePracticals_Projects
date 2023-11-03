#include "robot_logic.h"
#include <iostream>
#include <vector>
#include "Robot.h"
#include <climits>
#include <cstdlib>
#include <thread>
#include <chrono>

namespace RobotLogic {

void posTaken(int n_robots, const std::vector<Robot>& aiRobots)
{
	int a = 0;
	int j = 0;
	bool detected = false;
	
  for (a=0; a<n_robots; a++)
	{
	for (j=0; j<n_robots; j++)
	   {
	   if (a != j && aiRobots[a].getX() == aiRobots[j].getX() && aiRobots[a].getY() == aiRobots[j].getY() )       
	     {
	     detected = true;
	     break;
	     }
	     
	  if (detected=true) 
	  {
          break;
          } 
	  }
	}
}

void userInput(int &x, int &y, char &o){

while (true) {
        std::cout << "Enter x coordinate: " << "\n";
        std::cin >> x;
        // Check if input is valid
        if (std::cin.fail() || !(x >= Robot::x_min && x <= Robot::x_max)) {
            std::cin.clear(); // Clear the error flag
            std::cin.ignore(INT_MAX, '\n'); // Discard invalid input
            std::cout << "Invalid input. Please enter a valid integer for x." << "\n";
        } else {break;}
    }

    while (true) {
        std::cout << "Enter y coordinate: "<< "\n";
        std::cin >> y;

        // Check if input is valid
        if (std::cin.fail() || !(y >= Robot::y_min && y <= Robot::y_max)) {
            std::cin.clear(); // Clear the error flag
            std::cin.ignore(INT_MAX, '\n'); // Discard invalid input
            std::cout << "Invalid input. Please enter a valid integer for y." << "\n";
        } else {break;}
    }

    while (true) {
        std::cout << "Enter orientation (n/s/e/w): " << "\n";
        std::cin >> o;

        // Check if input is valid
        if (std::cin.fail() || (o != 'n' && o != 's' && o != 'e' && o != 'w')) {
            std::cin.clear(); // Clear the error flag
            std::cin.ignore(INT_MAX, '\n'); // Discard invalid input
            std::cout << "Invalid input. Please enter a valid orientation (n/s/e/w)." << "\n";
        } else {break;}
    }

}

//Ask user for amount of AI robots, return the number
int ask_n_robots(){
int n_robots;
while(true){
std::cout << "How many robots do you want to initialize? (min: " << Robot::min_n_robots << " , max: " << Robot::max_n_robots << " )" << "\n";
std::cin >> n_robots;

//Assure number of robots is between min and max allowed. 
if(std::cin.fail() || Robot::min_n_robots>n_robots || n_robots>Robot::max_n_robots){
std::cin.clear(); // Clear the error flag
std::cin.ignore(INT_MAX, '\n'); // Discard invalid input
std::cout << "Invalid input. Try again" << "\n";
}else{break;}

}
return n_robots;
}
<<<<<<< HEAD
=======

bool p_on_r(Robot& humanRobot, std::vector<Robot>& aiRobots){
for(int i = 0; i < aiRobots.size(); i++){
if(humanRobot.getX() == aiRobots[i].getX() && humanRobot.getY() == aiRobots[i].getY()){
return true;
}
}
return false;
}

std::string userMove(){
std::string move;
while(true){
std::cout << "Do you want to move forwards, backwards, left, or right? " << "\n";
std::cin >> move;

//Assure number of robots is between min and max allowed. 
if(std::cin.fail() || !(move == "forwards" || move == "backwards" || move == "left" || move == "right")){
std::cin.clear(); // Clear the error flag
std::cin.ignore(INT_MAX, '\n'); // Discard invalid input
std::cout << "Invalid input. Try again" << "\n";
}else{break;}
}
return move;
}

void aiMove(Robot& humanRobot, std::vector<Robot>& aiRobots){
//Move all the robots, sleep 500ms between each one, so the user can see the movements?
for(int i = 0; i < aiRobots.size(); i+++){
std::this_thread::sleep_for(std::chrono::milliseconds(500));
int dx = std::abs(humanRobot.getX() - aiRobots[i].getX());
int dy = std::abs(humanRobot.getX() - aiRobots[i].getX());


}
}
bool insideGrid(Robot& r){
return (0 <= r.getX() && r.getX() <= 21 && 0 <= r.getY() && r.getY() <= 14);
}

>>>>>>> feature/task4
}

