#pragma once
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

class LCDManager {
public:
    LCDManager(uint8_t lcdAddr, uint8_t lcdCols, uint8_t lcdRows);
    void begin();
    void displayData(float voltage, float current, float tempAmbient, float tempInt, float tempOut, 
                    float pressureInt, float pressureOut, float flowInt, float flowOut);
private:
    LiquidCrystal_I2C lcd;
};
