#define ULTRASONIC_DELAY 50UL
#define SONAR_DELAY 500UL
#define SONAR_POINTS 6

#define MAXIMUM_DISTANCE 400
#define MINIMAL_DISTANCE 30

unsigned int readDistanceAhead();

unsigned int readDistanceByAngle(unsigned int angle);
