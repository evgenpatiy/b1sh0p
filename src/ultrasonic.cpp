#include <ultrasonic.h>
#include <config_pins.h>
#include <turnservo.h>
#include <led.h>
#include <robotside.h>
#include <NewPing.h>

NewPing sonar(SONAR_TRIG_PIN, SONAR_ECHO_PIN, MAXIMUM_DISTANCE); // sensor function

unsigned int readDistanceAhead()
{
    unsigned int cm = sonar.ping_cm();
    if (cm == 0)
    {
        cm = MAXIMUM_DISTANCE;
    }
    return cm;
}

unsigned int readDistanceByAngle(unsigned int angle)
{
    turnToAngle(angle);

    digitalWrite(LED_BUILTIN, HIGH);
    delay(SONAR_DELAY);
    digitalWrite(LED_BUILTIN, LOW);

    return readDistanceAhead();
}
