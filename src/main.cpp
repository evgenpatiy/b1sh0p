#include <Arduino.h>
#include <movement.h>
#include <led.h>
#include <turnservo.h>
#include <ultrasonic.h>

#define RUN_LOOP true
#define DEBUG true

#define SERIAL_PORT_SPEED 9600
#define Serial \
  if (DEBUG)   \
  Serial

const char *ROBOT_NAME = {"B1sh0p"};
const char *ROBOT_SOFTWARE_VERSION = {"0.04"};

unsigned long operatedTime = 0;

void initSerialConsole()
{
  Serial.begin(SERIAL_PORT_SPEED);
  Serial.println(F(">>> WEYLAND-YUTANI"));
  Serial.println("--- this is " + (String)ROBOT_NAME + " version " + (String)ROBOT_SOFTWARE_VERSION);
  Serial.println("--- init serial console... speed: " + (String)SERIAL_PORT_SPEED);
  Serial.println();
}

void setup()
{
  initSerialConsole();
  initMotors();
  initLedLights();
  initServo();

  turnWarningLights();
}

void loop()
{
  if (RUN_LOOP)
  {
    unsigned long currentTime = millis();
    if (currentTime - operatedTime >= 1000)
    {
      operatedTime = currentTime;
      blinkNavigationLights();
    }

    delay(SONAR_DELAY);
    unsigned int distance = readDistanceAhead();

    if (distance <= MINIMAL_DISTANCE)
    {
      stop();
      
      int distanceRight = readDistanceByAngle(SERVO_RIGHT_POSITION);
      resetServoPosition();
      
      int distanceLeft = readDistanceByAngle(SERVO_LEFT_POSITION);
      resetServoPosition();

      Serial.println("***SONAR: distance ahead: " + (String)distance + " distance <<left: " + (String)distanceLeft + " distance right>>: " + (String)distanceRight);

      if (distanceRight <= MINIMAL_DISTANCE && distanceLeft <= MINIMAL_DISTANCE)
      {
        moveBackward(500);
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
        switch (random(0, 3))
        {
        case 0:
          turnRightToAngle(90);
          break;
        case 1:
          turnRightToAngle(120);
          break;
        case 2:
          turnRightToAngle(150);
          break;
        default:
          break;
        }
      }
      else if (distanceLeft > distanceRight)
      {
        switch (random(0, 3))
        {
        case 0:
          turnLeftToAngle(90);
          break;
        case 1:
          turnLeftToAngle(120);
          break;
        case 2:
          turnLeftToAngle(150);
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
