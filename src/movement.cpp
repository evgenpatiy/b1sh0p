#include <Arduino.h>
#include <movement.h>
#include <led.h>
#include <lcd.h>
#include <config_pins.h>

class Motor
{
private:
    int forward_pin;
    int backward_pin;

public:
    Motor(int _forward_pin, int _backward_pin);

    void init();
    void moveForward();
    void moveBackward();
    void stop();
};

Motor leftMotor = Motor(LEFT_MOTOR_FORWARD_PIN, LEFT_MOTOR_BACKWARD_PIN);
Motor rightMotor = Motor(RIGHT_MOTOR_FORWARD_PIN, RIGHT_MOTOR_BACKWARD_PIN);

Motor::Motor(int _forward_pin, int _backward_pin)
{
    forward_pin = _forward_pin;
    backward_pin = _backward_pin;
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
    leftMotor.init();
    rightMotor.init();
}

void stop()
{
    digitalWrite(LED_BUILTIN, LOW);

    clearRow(2);
    displayLCDMessage(0, 2, "STOP");

    leftMotor.stop();
    rightMotor.stop();
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
    digitalWrite(LED_BUILTIN, HIGH);
    clearRow(2);
    displayLCDMessage(0, 2, "move FORWARD");

    leftMotor.moveForward();
    rightMotor.moveForward();
    execute(time);
}

void moveBackward(unsigned int time)
{
    clearRow(2);
    displayLCDMessage(0, 2, "move BACKWARD");
    leftMotor.moveBackward();
    rightMotor.moveBackward();
    execute(time);
}

void turnLeft(unsigned int time)
{
    leftMotor.moveBackward();
    rightMotor.moveForward();
    execute(time);
}

void turnRight(unsigned int time)
{
    leftMotor.moveForward();
    rightMotor.moveBackward();
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
