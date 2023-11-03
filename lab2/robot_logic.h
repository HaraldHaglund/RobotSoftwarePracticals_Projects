#ifndef ROBOT_LOGIC_H
#define ROBOT_LOGIC_H
#include <iostream>
#include <vector>
#include "Robot.h"
#include <climits>
#include <cstdlib>
#include <thread>
#include <chrono>

namespace RobotLogic {
//Store user inputs to variables in x, y, and o.
void userInput(int &x, int &y, char &o);

//Ask user for amount of robots, and check that its within the allowed threshold. Return the number
int ask_n_robots();

<<<<<<< HEAD
=======
//Returns true if player is on a robot square
bool p_on_r(Robot& humanRobot, std::vector<Robot>& aiRobots);

//Returns f, b, l, r if user wants to go forward, backwards, left, or right.
std::string userMove();

//Move the AI robots
void aiMove(Robot& humanRobot, std::vector<Robot>& aiRobots);

//Check if the robot is inside the grid
bool insideGrid(Robot& r);
>>>>>>> feature/task4
}
#endif
