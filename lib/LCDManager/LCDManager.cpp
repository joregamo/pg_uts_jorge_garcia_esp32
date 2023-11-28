#include "LCDManager.h"

LCDManager::LCDManager(uint8_t lcdAddr, uint8_t lcdCols, uint8_t lcdRows) : lcd(lcdAddr, lcdCols, lcdRows) {}

void LCDManager::begin() {
    lcd.init(); 
    lcd.backlight();
    lcd.clear();
    lcd.print("Sistema híbrido UTS");
}

void LCDManager::displayData(float voltage, float current, float tempAmbient, float tempInt, float tempOut, 
                             float pressureInt, float pressureOut, float flowInt, float flowOut) {
    static int state = 0;
    lcd.clear();
    
    switch(state) {
        case 0:
            lcd.setCursor(0, 0);
            lcd.print("V: ");
            lcd.print(voltage, 2);
            lcd.print(" V");
            
            lcd.setCursor(0, 1);
            lcd.print("I: ");
            lcd.print(current, 1);
            lcd.print(" A");
            break;

        case 1:
            lcd.setCursor(0, 0);
            lcd.print("T Amb: ");
            lcd.print(tempAmbient, 1);
            lcd.print(" C");
            
            lcd.setCursor(0, 1);
            lcd.print("T In: ");
            lcd.print(tempInt, 1);
            lcd.print(" C");
            break;

        case 2:
            lcd.setCursor(0, 0);
            lcd.print("T Out: ");
            lcd.print(tempOut, 2);
            lcd.print(" C");
            
            lcd.setCursor(0, 1);
            lcd.print("P In: ");
            lcd.print(pressureInt, 1);
            lcd.print(" MPa");
            break;

        case 3:
            lcd.setCursor(0, 0);
            lcd.print("P Out: ");
            lcd.print(pressureOut, 1);
            lcd.print(" MPa");

            lcd.setCursor(0, 1);
            lcd.print("F In: ");
            lcd.print(flowInt, 1);
            lcd.print(" mL/h");
            break;

        case 4:
            lcd.setCursor(0, 0);
            lcd.print("F Out: ");
            lcd.print(flowOut, 1);
            lcd.print(" mL/h");
            
            
            break;
    }

    state = (state + 1) % 5;  // Cíclicamente alterna entre 0, 1, 2, 3 y 4
}
