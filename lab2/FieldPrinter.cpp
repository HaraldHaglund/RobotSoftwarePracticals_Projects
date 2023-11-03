#include <iostream>
#include <string>
#include "Robot.h"
#include "FieldPrinter.h"
#include <vector>


const int n_grid_col = 22;
const int n_grid_row = 14;
//Is it better to use std vector instead of vla?
char grid[n_grid_col][n_grid_col];

void FieldPrinter::updateField(Robot& humanRobot, std::vector<Robot>& aiRobots){
//Loop thorugh all grids
for (int i = 0; i < n_grid_row; i++){
	for(int j = 0; j < n_grid_col; j++){
	//Check if human robot is inside square
		if(humanRobot.getY() == i && humanRobot.getX() == j){
		grid[i][j] = 'H';
		}
	//No human robot found, check if any of the robots is inside the square
		else{
		for(int k = 0; k < aiRobots.size(); k++){
			if(aiRobots[k].getY() == i && aiRobots[k].getX() == j){
				grid[i][j] = 'R';
				break;
				}
				//If no robots and no human in this square, print ".".
			else{
			grid[i][j] = '.';
			}
			}	
		}
}
}
}

void FieldPrinter::printField(){
std::cout << "\n" << "\n";
for (int i = 0; i < n_grid_row; i++) {
        for (int j = 0; j < n_grid_col; j++) {
            std::cout << grid[i][j] << " ";
        }
        std::cout << std::endl;
    }
std::cout << "\n" << "\n";  
}






