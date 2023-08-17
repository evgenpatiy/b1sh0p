#include <Arduino.h>
#include <led.h>
#include <config_pins.h>

struct LedColor
{
    unsigned char r_level;
    unsigned char g_level;
    unsigned char b_level;
};

LedColor red = {255, 0, 0};
LedColor green = {0, 255, 0};
LedColor blue = {100, 100, 100};

class LedLight
{
private:
    unsigned char r_pin;
    unsigned char g_pin;
    unsigned char b_pin;

public:
    LedLight(unsigned char _r_pin, unsigned char _g_pin, unsigned char _b_pin);

    void init();
    void on(LedColor *color);
    void off();
};

LedLight::LedLight(unsigned char _r_pin, unsigned char _g_pin, unsigned char _b_pin)
{
    r_pin = _r_pin;
    g_pin = _g_pin;
   // b_pin = _b_pin;
}

void LedLight::init()
{
    pinMode(r_pin, OUTPUT);
    pinMode(g_pin, OUTPUT);
   // pinMode(b_pin, OUTPUT);
}

void LedLight::on(LedColor *color)
{
    analogWrite(r_pin, color->r_level);
    analogWrite(g_pin, color->g_level);
   // analogWrite(b_pin, color->b_level);
}

void LedLight::off()
{
    digitalWrite(r_pin, LOW);
    digitalWrite(g_pin, LOW);
   // digitalWrite(b_pin, LOW);
}

LedLight leftLight = LedLight(LEFT_LED_RED_PIN, LEFT_LED_GREEN_PIN, 1111);
LedLight rightLight = LedLight(RIGHT_LED_RED_PIN, RIGHT_LED_GREEN_PIN, 1111);

void initLedLights()
{
    leftLight.init();
    rightLight.init();
}

void disableLight()
{
    leftLight.off();
    rightLight.off();
}

void blinkNavigationLights()
{
    leftLight.on(&red);
    rightLight.on(&green);
    delay(BLINK_DURATION);

    disableLight();
    delay(BLINK_DURATION);

    leftLight.on(&red);
    rightLight.on(&green);
    delay(BLINK_DURATION);

    disableLight();
    delay(BLINK_DURATION);
}

void turnWarningLights()
{
    leftLight.on(&blue);
    rightLight.on(&blue);
    delay(3000);
    disableLight();
}