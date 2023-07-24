#ifndef LED_LIGHT_H
#define LED_LIGHT_H
struct LedLight
{
  unsigned char r;
  unsigned char g;
  unsigned char b;
};
#endif

#ifndef LED_COLOR_H
#define LED_COLOR_H
struct LedColor
{
  unsigned char rLevel;
  unsigned char gLevel;
  unsigned char bLevel;
};
#endif

#define LEFT_LED_RED 9
#define LEFT_LED_GREEN 10
#define LEFT_LED_BLUE 11

#define RIGHT_LED_RED 6
#define RIGHT_LED_GREEN 7
#define RIGHT_LED_BLUE 8

#define BLINK_DURATION 40

void initLedLights();

void blinkNavigationLights();