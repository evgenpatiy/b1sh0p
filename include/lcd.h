#define I2C_PORT 0x3F

void initLCD();

void clearRow(unsigned int row);

void displayLCDMessage(unsigned int col, unsigned int row, const char* message);