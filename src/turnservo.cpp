
#include <Servo.h>
#include <Arduino.h>
#include <turnservo.h>
#include <config_pins.h>

Servo servo;

void turnToAngle(unsigned int angle)
{
    servo.write(angle);
    delay(SERVO_MOTOR_DELAY);
}

void resetServoPosition()
{
    turnToAngle(SERVO_CENTER_POSITION);
}

void initServo()
{
    servo.attach(SERVO_MOTOR_PIN);

    turnToAngle(SERVO_LEFT_POSITION);
    delay(2000);
    turnToAngle(SERVO_RIGHT_POSITION);
    delay(2000);

    resetServoPosition();
}
