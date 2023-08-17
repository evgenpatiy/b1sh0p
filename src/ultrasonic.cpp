#include <ultrasonic.h>
#include <config_pins.h>
#include <turnservo.h>
#include <led.h>
#include <lcd.h>
#include <robotside.h>
#include <NewPing.h>

using namespace std;

NewPing sonar(SONAR_TRIG_PIN, SONAR_ECHO_PIN, MAXIMUM_DISTANCE); // sensor function

unsigned int readDistanceAhead()
{
    unsigned int cm = sonar.ping_cm();
    if (cm == 0)
    {
        cm = MAXIMUM_DISTANCE;
    }
    
    clearRow(3);
    String distanceMessage = "DISTANCE: " + (String)cm;
    displayLCDMessage(0, 3, distanceMessage.c_str());
    return cm;
}

unsigned int readDistanceByAngle(unsigned int angle)
{
    turnToAngle(angle);
    return readDistanceAhead();
}
