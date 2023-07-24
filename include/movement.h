#ifndef MOTOR_H
#define MOTOR_H
struct Motor
{
  int forward;
  int backward;
};
#endif

#define LEFT_MOTOR_FORWARD 3
#define LEFT_MOTOR_BACKWARD 2
#define RIGHT_MOTOR_FORWARD 5
#define RIGHT_MOTOR_BACKWARD 4

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

