#ifndef ROBOT_FP_H
#define ROBOT_FP_H
#include <vector>
#include "Robot.h"
class FieldPrinter {
public:
	//Static so we can use it without initiating a FieldPrinter object. 
	
	//Loop through all the squares and put "H" , "R" , or "." if its a human, robot or empty square respectively.
	 static void updateField(Robot& humanRobot, std::vector<Robot>& aiRobots);
	 //print out the field to the console
	 static void printField();
};
#endif
