#include <Arduino.h>
#include <led.h>

LedLight leftLight = {LEFT_LED_RED, LEFT_LED_GREEN, LEFT_LED_BLUE};
LedLight rightLight = {RIGHT_LED_RED, RIGHT_LED_GREEN, RIGHT_LED_BLUE};

LedColor red = {255, 0, 0};
LedColor green = {0, 255, 0};
LedColor blue = {0, 0, 255};
LedColor yellow = {255, 255, 0};
LedColor white = {255, 255, 255};

void initLED(LedLight light)
{
    pinMode(light.r, OUTPUT);
    pinMode(light.g, OUTPUT);
    pinMode(light.b, OUTPUT);
}

void initLedLights()
{
    initLED(leftLight);
    initLED(rightLight);
}

void lightOn(LedLight light, LedColor color)
{
    analogWrite(light.r, color.rLevel);
    analogWrite(light.g, color.gLevel);
    analogWrite(light.b, color.bLevel);
}

void lightOff(LedLight light)
{
    digitalWrite(light.r, LOW);
    digitalWrite(light.g, LOW);
    digitalWrite(light.b, LOW);
}

void forwardLightsOn()
{
    lightOn(leftLight, red);
    lightOn(rightLight, green);
}

void disableLight()
{
    lightOff(leftLight);
    lightOff(rightLight);
}

void blinkNavigationLights()
{
    forwardLightsOn();
    delay(BLINK_DURATION);
    disableLight();
    delay(BLINK_DURATION);

    forwardLightsOn();
    delay(BLINK_DURATION);
    disableLight();
    delay(BLINK_DURATION);
}