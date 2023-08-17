#include <lcd.h>
#include <Wire.h>
#include <name.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(I2C_PORT, 20, 4);

void initLCD()
{
    lcd.init();
    lcd.backlight();
    lcd.print(VENDOR_NAME);
    lcd.setCursor(0, 1);
    lcd.print(ROBOT_NAME);
    lcd.setCursor(strlen(ROBOT_NAME) + 1, 1);
    lcd.print(ROBOT_SOFTWARE_VERSION);
}