#include <Arduino.h>
#include <timer.h>
#include <movement.h>
#include <led.h>

const Motor leftMotor = Motor{LEFT_MOTOR_FORWARD, LEFT_MOTOR_BACKWARD};
const Motor rightMotor = Motor{RIGHT_MOTOR_FORWARD, RIGHT_MOTOR_BACKWARD};

void initMotor(Motor motor)
{
    pinMode(motor.forward, OUTPUT);
    pinMode(motor.backward, OUTPUT);
}

void motorForward(Motor motor)
{
    digitalWrite(motor.forward, HIGH);
    digitalWrite(motor.backward, LOW);
}

void motorBackward(Motor motor)
{
    digitalWrite(motor.forward, LOW);
    digitalWrite(motor.backward, HIGH);
}

void stopMotor(Motor motor)
{
    digitalWrite(motor.forward, LOW);
    digitalWrite(motor.backward, LOW);
}

void initMotors()
{
    initMotor(leftMotor);
    initMotor(rightMotor);
}

void stop()
{
   //stopTimer();

    stopMotor(leftMotor);
    stopMotor(rightMotor);
}

void execute(unsigned int time)
{
    if (time > 0)
    {
        delay(time);
        stop();
    }
}

void moveForward(unsigned int time)
{
    startTimer();

    motorForward(leftMotor);
    motorForward(rightMotor);
    execute(time);
}

void moveBackward(unsigned int time)
{
    motorBackward(leftMotor);
    motorBackward(rightMotor);
    execute(time);
}

void turnLeft(unsigned int time)
{
    motorBackward(leftMotor);
    motorForward(rightMotor);
    execute(time);
}

void turnRight(unsigned int time)
{
    motorForward(leftMotor);
    motorBackward(rightMotor);
    execute(time);
}

unsigned long getAngleTurnTime(unsigned int angle)
{
    return ((float)angle * float(FULL_TURNOVER_TIME)) / 180.0;
}

void turnLeftToAngle(unsigned int angle)
{
    turnLeft(getAngleTurnTime(angle));
}

void turnRightToAngle(unsigned int angle)
{
    turnRight(getAngleTurnTime(angle));
}

void turnOverLeft()
{
    turnLeft(FULL_TURNOVER_TIME);
}

void turnOverRight()
{
    turnRight(FULL_TURNOVER_TIME);
}
