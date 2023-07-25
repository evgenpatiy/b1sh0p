#include <Arduino.h>
#include <led.h>

struct LedColor
{
    unsigned char rLevel;
    unsigned char gLevel;
    unsigned char bLevel;
};

class LedLight
{
private:
    unsigned char r_pin;
    unsigned char g_pin;
    unsigned char b_pin;

public:
    LedLight(unsigned char _r, unsigned char _g, unsigned char _b);

    void init();
    void on(LedColor color);
    void off();
};

LedLight::LedLight(unsigned char _r, unsigned char _g, unsigned char _b)
{
    r_pin = _r;
    g_pin = _g;
    b_pin = _b;
}

void LedLight::init()
{
    pinMode(r_pin, OUTPUT);
    pinMode(g_pin, OUTPUT);
    pinMode(b_pin, OUTPUT);
}

void LedLight::on(LedColor color)
{
    analogWrite(r_pin, color.rLevel);
    analogWrite(g_pin, color.gLevel);
    analogWrite(b_pin, color.bLevel);
}

void LedLight::off()
{
    digitalWrite(r_pin, LOW);
    digitalWrite(g_pin, LOW);
    digitalWrite(b_pin, LOW);
}

LedLight leftLight = LedLight(LEFT_LED_RED, LEFT_LED_GREEN, LEFT_LED_BLUE);
LedLight rightLight = LedLight(RIGHT_LED_RED, RIGHT_LED_GREEN, RIGHT_LED_BLUE);

void initLedLights()
{
    leftLight.init();
    rightLight.init();
}

void forwardLightsOn()
{
    LedColor red = {255, 0, 0};
    LedColor green = {0, 255, 0};

    leftLight.on(red);
    rightLight.on(green);
}

void disableLight()
{
    leftLight.off();
    rightLight.off();
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

void turnWarningLights()
{
    LedColor blue = {100, 100, 100};

    leftLight.on(blue);
    rightLight.on(blue);
    delay(3000);
    disableLight();
}