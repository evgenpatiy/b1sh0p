#include <robotside.h>
#define SONAR_TRIG_PIN A0 // analog input 1
#define SONAR_ECHO_PIN A1 // analog input 2

#define ULTRASONIC_DELAY 50UL
#define SONAR_DELAY 500UL
#define SONAR_POINTS 6

#define MAXIMUM_DISTANCE 300
#define CRITICAL_DISTANCE 30

#ifndef SONAR_COMPLEX_DATA_H
#define SONAR_COMPLEX_DATA_H
struct SonarComplexData
{
  int angle;
  int distance;
};
#endif

unsigned int readDistanceAhead();

unsigned int readDistanceByAngle(unsigned int angle);

unsigned int getSonarData(RobotSide side);