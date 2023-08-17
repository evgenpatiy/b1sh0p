#include <lcd.h>
#include <Wire.h>
#include <name.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(I2C_PORT, 20, 4);

void initLCD()
{
    lcd.init();
    lcd.backlight();

    displayLCDMessage(0, 0, VENDOR_NAME);
    displayLCDMessage(0, 1, ROBOT_NAME);
    displayLCDMessage(strlen(ROBOT_NAME) + 1, 1, ROBOT_SOFTWARE_VERSION);
}

void clearRow(unsigned int row)
{
    displayLCDMessage(0, row, "                    ");
}

void displayLCDMessage(unsigned int col, unsigned int row, const char *message)
{
    lcd.setCursor(col, row);
    lcd.print(message);
}