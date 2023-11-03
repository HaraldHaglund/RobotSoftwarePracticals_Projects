#include "Robot.h"

//Constructor
Robot::Robot(int x, int y, char dir) : x_(x), y_(y), dir_(dir) {}
//Default constructor
Robot::Robot() : x_(0), y_(0), dir_('n') {}

void Robot::moveForward() {
    char direction = getDir();
    //NOTE: Think about the matrix implementation [][]. If we head north we need to decrease the y value.
    switch (direction) {
    case 'n':
    y_--;
    break;
    case 's':
    y_++;
    break;
    case 'e':
    x_++;
    break;
    case 'w':
    x_--;
    break;
    }
}

//Inverse implementation to that of moveForward.
void Robot::moveBackward() {
    char direction = getDir();
    switch (direction) {
    case 'n':
    y_++;
    break;
    case 's':
    y_--;
    break;
    case 'e':
    x_--;
    break;
    case 'w':
    x_++;
    break;
    }
}

void Robot::turnLeft() {
    char direction = getDir();
    switch (direction) {
    case 'n':
    dir_ = 'w';
    break;
    case 's':
    dir_ = 'e';
    break;
    case 'e':
    dir_ = 'n';
    break;
    case 'w':
    dir_ = 's';
    break;
    }
}

void Robot::turnRight() {
    char direction = getDir();
    switch (direction) {
    case 'n':
    dir_ = 'e';
    break;
    case 's':
    dir_ = 'w';
    break;
    case 'e':
    dir_ = 's';
    break;
    case 'w':
    dir_ = 'n';
    break;
    }
}

int Robot::getX() const {
    return x_;
}

int Robot::getY() const {
    return y_;
}

char Robot::getDir() const {
    return dir_;
}







