#include <Arduino.h>
#include <timer.h>
#include <movement.h>
#include <led.h>

class Motor
{
private:
    int forward;
    int backward;

public:
    Motor(int _forward, int _backward);

    void init();
    void moveForward();
    void moveBackward();
    void stop();
};

Motor leftEngine = Motor(LEFT_MOTOR_FORWARD, LEFT_MOTOR_BACKWARD);
Motor rightEngine = Motor(RIGHT_MOTOR_FORWARD, RIGHT_MOTOR_BACKWARD);

Motor::Motor(int _forward, int _backward)
{
    forward = _forward;
    backward = _backward;
}

void Motor::init()
{
    pinMode(forward, OUTPUT);
    pinMode(backward, OUTPUT);
}

void Motor::moveForward()
{
    digitalWrite(forward, HIGH);
    digitalWrite(backward, LOW);
}

void Motor::moveBackward()
{
    digitalWrite(forward, LOW);
    digitalWrite(backward, HIGH);
}

void Motor::stop()
{
    digitalWrite(forward, LOW);
    digitalWrite(backward, LOW);
}

void initMotors()
{
    leftEngine.init();
    rightEngine.init();
}

void stop()
{
    // stopTimer();
    leftEngine.stop();
    rightEngine.stop();
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

    leftEngine.moveForward();
    rightEngine.moveForward();
    execute(time);
}

void moveBackward(unsigned int time)
{
    leftEngine.moveBackward();
    rightEngine.moveBackward();
    execute(time);
}

void turnLeft(unsigned int time)
{
    leftEngine.moveBackward();
    rightEngine.moveForward();
    execute(time);
}

void turnRight(unsigned int time)
{
    leftEngine.moveForward();
    rightEngine.moveBackward();
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
