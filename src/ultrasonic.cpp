#include <ultrasonic.h>
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

unsigned int getSonarData(RobotSide side)
{
    int positions[SONAR_POINTS];

    int sonarDataStepAngle = abs(SERVO_CENTER_POSITION - SERVO_RIGHT_POSITION) / SONAR_POINTS;
    int angleSign;

    if (side == leftSide)
    {
        angleSign = -1;
    }
    else
    {
        angleSign = 1;
    }

    SonarComplexData sonarData[SONAR_POINTS];
    for (unsigned char i = 0; i <= SONAR_POINTS; i = i + 1)
    {
        int angle = i * sonarDataStepAngle * angleSign;
        sonarData[i].angle = angle;
        sonarData[i].distance = readDistanceByAngle(SERVO_CENTER_POSITION + angle);
        Serial.println("--- sonar angle " + (String)sonarData[i].angle + " DISTANCE " + (String)sonarData[i].distance);
    }

}