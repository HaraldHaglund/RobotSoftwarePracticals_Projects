class Robot{
private:
	int x_;
	int y_;
	char dir_; // ’n’, ’w’,’e’,’s’ for north, west, east and south respectively
public:
	//Constructor. Needs x, y and dir for initialization. 
	Robot(int x, int y, char dir);
	//Default constructor
	Robot();
	//Moves robot forwards one step
	void moveForward();
	//Moves robot backwards one step
	void moveBackward();
	//Changes direction counter-clockwise
	void turnLeft();
	//Changes direction clockwise
	void turnRight();
	//Return x position
	int getX() const;
	//Return y positiona
	int getY() const;
	//Returns the direction
	char getDir() const;
};
