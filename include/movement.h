#define FULL_TURNOVER_TIME 500UL

void initMotors();

void stop();

void moveForward(unsigned int time);

void moveBackward(unsigned int time);

void turnLeft(unsigned int time);

void turnRight(unsigned int time);

void turnOverLeft();

void turnOverRight();

void turnLeftToAngle(unsigned int angle);

void turnRightToAngle(unsigned int angle);

