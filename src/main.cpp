#include <Arduino.h>
#include <movement.h>
#include <led.h>
#include <timer.h>
#include <turnservo.h>
#include <ultrasonic.h>

#define RUN_LOOP true

#define SERIAL_PORT_SPEED 9600
#define DEBUG true
#define Serial \
  if (DEBUG)   \
  Serial

const char *ROBOT_NAME = {"B1sh0p"};
const float ROBOT_SOFTWARE_VERSION = 0.03;

unsigned int distance = 100;

void initSerialConsole()
{
  Serial.begin(SERIAL_PORT_SPEED);
  Serial.println(">>> WEYLAND-YUTANI");
  Serial.println("--- this is " + (String)ROBOT_NAME + " version " + (String)ROBOT_SOFTWARE_VERSION);
  Serial.println("--- init serial console... speed: " + (String)SERIAL_PORT_SPEED);
  Serial.println();
}

void setup()
{
  initSerialConsole();
  initTimers();
  initMotors();
  initLedLights();
  initServo();
}

void loop()
{
  if (RUN_LOOP)
  {
    if (isTimerReady())
    {
      blinkNavigationLights();
    }

    delay(ULTRASONIC_DELAY);
    distance = readDistanceAhead();

    if (distance <= CRITICAL_DISTANCE)
    {
      stop();
      moveBackward(400);

      int distanceRight = readDistanceByAngle(SERVO_RIGHT_POSITION);
      resetServoPosition();
      int distanceLeft = readDistanceByAngle(SERVO_LEFT_POSITION);
      resetServoPosition();

      Serial.println("***SONAR: distance ahead: " + (String)distance + " distance <<left: " + (String)distanceLeft + " distance right>>: " + (String)distanceRight);

      if (distanceRight <= CRITICAL_DISTANCE && distanceLeft <= CRITICAL_DISTANCE)
      {
        switch (random(0, 2))
        {
        case 0:
          turnOverLeft();
          break;
        case 1:
          turnOverRight();
          break;
        default:
          break;
        }
      }
      else if (distanceRight >= distanceLeft)
      {
        switch (random(0, 4))
        {
        case 0:
          turnRightToAngle(45);
          break;
        case 1:
          turnRightToAngle(60);
          break;
        case 2:
          turnRightToAngle(90);
          break;
        case 3:
          turnOverRight();
          break;
        default:
          break;
        }
      }
      else if (distanceLeft >= distanceRight)
      {
        switch (random(0, 4))
        {
        case 0:
          turnLeftToAngle(45);
          break;
        case 1:
          turnLeftToAngle(60);
          break;
        case 2:
          turnLeftToAngle(90);
          break;
        case 3:
          turnOverLeft();
          break;
        default:
          break;
        }
      }
    }
    else
    {
      moveForward(0);
    }
  }
}

