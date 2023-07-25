#include <Arduino.h>
#include <movement.h>
#include <led.h>
#include <config_pins.h>

class Motor
{
private:
    int forward_pin;
    int backward_pin;

public:
    Motor(int _forward, int _backward);

    void init();
    void moveForward();
    void moveBackward();
    void stop();
};

Motor leftEngine = Motor(LEFT_MOTOR_FORWARD_PIN, LEFT_MOTOR_BACKWARD_PIN);
Motor rightEngine = Motor(RIGHT_MOTOR_FORWARD_PIN, RIGHT_MOTOR_BACKWARD_PIN);

Motor::Motor(int _forward, int _backward)
{
    forward_pin = _forward;
    backward_pin = _backward;
}

void Motor::init()
{
    pinMode(forward_pin, OUTPUT);
    pinMode(backward_pin, OUTPUT);
}

void Motor::moveForward()
{
    digitalWrite(forward_pin, HIGH);
    digitalWrite(backward_pin, LOW);
}

void Motor::moveBackward()
{
    digitalWrite(forward_pin, LOW);
    digitalWrite(backward_pin, HIGH);
}

void Motor::stop()
{
    digitalWrite(forward_pin, LOW);
    digitalWrite(backward_pin, LOW);
}

void initMotors()
{
    leftEngine.init();
    rightEngine.init();
}

void stop()
{
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
