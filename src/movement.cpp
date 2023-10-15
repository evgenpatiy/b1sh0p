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

Motor LF_Motor = Motor(LF_MOTOR_FORWARD_PIN, LF_MOTOR_BACKWARD_PIN);
Motor RF_Motor = Motor(RF_MOTOR_FORWARD_PIN, RF_MOTOR_BACKWARD_PIN);

Motor LB_Motor = Motor(LB_MOTOR_FORWARD_PIN, LB_MOTOR_BACKWARD_PIN);
Motor RB_Motor = Motor(RB_MOTOR_FORWARD_PIN, RB_MOTOR_BACKWARD_PIN);

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
    LF_Motor.init();
    RF_Motor.init();

    LB_Motor.init();
    RB_Motor.init();
}

void stop()
{
    digitalWrite(LED_BUILTIN, LOW);

    clearRow(2);
    displayLCDMessage(0, 2, "STOP");

    LF_Motor.stop();
    RF_Motor.stop();

    LB_Motor.stop();
    RB_Motor.stop();
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

    LF_Motor.moveForward();
    RF_Motor.moveForward();

    LB_Motor.moveForward();
    RB_Motor.moveForward();

    execute(time);
}

void moveBackward(unsigned int time)
{
    clearRow(2);
    displayLCDMessage(0, 2, "move BACKWARD");

    LF_Motor.moveBackward();
    RF_Motor.moveBackward();

    LB_Motor.moveBackward();
    RB_Motor.moveBackward();

    execute(time);
}

void turnLeft(unsigned int time)
{
    LF_Motor.moveBackward();
    RF_Motor.moveForward();

    LB_Motor.moveBackward();
    RB_Motor.moveForward();

    execute(time);
}

void turnRight(unsigned int time)
{
    LF_Motor.moveForward();
    RF_Motor.moveBackward();

    LB_Motor.moveForward();
    RB_Motor.moveBackward();

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
