#include <iostream>
#include <string>
#include "Robot.h"
#include <vector>
using namespace std;
//Declare constants
const int x_max = 21;
const int x_min = 0;
const int y_min = 0;
const int y_max = 13;
const int min_n_robots = 1;
const int max_n_robots = 5;

int a = 0;
int j = 0;
bool detected = false;

//Store user inputs to variables in x, y, and o
void userInput(int &x, int &y, char &o);
//Assure that the input is correct. This func could have been implemented in the robot class
bool validRobot(int x, int y, char o);

//Main method
int main(){

int n_robots;
cout << "How many robots do you want to initialize? (min: " << min_n_robots << " , max: " << max_n_robots << " )" << "\n";
cin >> n_robots;

//Assure number of robots is between min and max allowed. 
while(min_n_robots>n_robots || n_robots>max_n_robots){ 
cout << "Invalid input. Try again" << "\n";
cin >> n_robots;
}

cout << "Enter x,y coordinates and orientation (format 'x y o') for the human robot " << "\n";
int x;
int y;
char o;
userInput(x,y,o);
//Assure input is valid 
while(!validRobot(x,y,o)){
cout << "Invalid input. NOTE:  0<=x<=21, 0<=y<=13, c='n'/'s'/'e'/'w' " << "\n";
userInput(x,y,o);
}
//Initialize human robot and ai-robot vector with n ai-robots
Robot humanRobot(x, y, o);
vector<Robot> aiRobots(n_robots);

//Do the same for the AI robots
for(int i = 0; i < n_robots; i++){
cout << "Enter x,y coordinates and orientation (format 'x y o') for robot " << i + 1 <<"\n";
userInput(x,y,o);

for (a=0; a<n_robots; a++)
	{
	for (j=0; j<n_robots; j++)
	   {
	   if (a != j && aiRobots[a].getX() == aiRobots[j].getX() && aiRobots[a].getY() == aiRobots[j].getY() )       
	    //numbers must be different and positions (X&Y) same, then true
	     {
	     detected = true;
	     break;
	     }
	    }
	 } 
	 
while(!validRobot(x,y,o)||detected){
cout << "Invalid input or the same coordinates for more than one robot. NOTE:  0<=x<=21, 0<=y<=13, c='n'/'s'/'e'/'w' " << "\n";
detected = false; //reset, otherwise loop 
userInput(x,y,o);
}
aiRobots[i] = Robot(x,y,o);
}

//print ai robot i positions 
for(int i = 0; i < n_robots; i++) {
cout << "AI-Robot " << i + 1 << " Position: (" << aiRobots[i].getX() << ", " << aiRobots[i].getY() << ") Orientation: " << aiRobots[i].getDir() << "\n";
}

//print human position
cout << "Human Robot Position: (" << humanRobot.getX() << ", " << humanRobot.getY() << ") Orientation: " << humanRobot.getDir() << "\n";

return 0;
}





bool validRobot(int x, int y, char o){
return (x >= x_min && x <= x_max && y >= y_min && y <= y_max && (o == 'n' || o == 's' || o == 'e' || o == 'w'));
}

//Note: pass by reference
void userInput(int &x, int &y, char &o){
cin >> x;
cin >> y;
cin >> o;
}


