**NOTE:** 
For detailed information on how each exercise was solved, there are several comments added in the scripts. All Skripts can be executed by using the standard "make" command. No specific functions and packages to be installed. 

*********************************************
**Task0:**

	"halfway_checkpoint.cpp"

Description:
reading the user input. Asks the user if read from file or from STDIN. 
If file selected, the whole content will be displayed

*********************************************
**Task1:**

	"init_robots.cpp"; "Robot.cpp"; "Robot.h"

Description:
Reads the user input of the robot coordinates and initialize robot. Allows the user only to enter valid input. Wrong input and the same coordinates for more than one robot are beeing prevented. 
using header file for storing the class without proper information about the code, included in main program. 

**********************************************
**Task2:**

	"init_robots_with_grid"; "FieldPrinter.cpp"; "FieldPrinter.h"; "robot_logic.cpp"; "robot_logic.h"

Description:
similar to the previous task, implementes grid and associated restrictions for the movement of the robot. The functions also checks if positions are already taken. Prints the grid.

**********************************************
**Task3:**

	"game_static_robots.cpp"; 

Description:
implements the movements of the several robots my user Input. If the user robot is at the same coordinate, as the AI robot, the user loses. 

**********************************************
**Task4:**

	"game.cpp"; 

Description:
the final game by using AI generated robots. Creates AI-robot vector with n AI-robots and initialize all the robots with a for-loop. If human on robot square, user player lost.

**********************************************
