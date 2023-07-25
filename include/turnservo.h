#define SERVO_CENTER_POSITION 90
#define SERVO_LEFT_POSITION 180
#define SERVO_RIGHT_POSITION 0

#define SERVO_MOTOR_DELAY 20

void initServo();

void turnToAngle(unsigned int angle);

void resetServoPosition();