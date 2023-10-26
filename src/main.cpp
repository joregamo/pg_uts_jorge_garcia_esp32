#include <Arduino.h>
#include "VoltageSensor.h"



//Sensor Voltaje para medir el panel.

const int voltageSensorPin = 32;
VoltageSensor sensor(voltageSensorPin);

void setup() {
    Serial.begin(115200);
}

void loop() {
    float voltage = sensor.readVoltage();
    float voltageReal = voltage/0.1; // 0.13 factor de conversion
  
    Serial.print("Voltage: ");
    Serial.print(voltageReal, 2);
    Serial.println(" V");

    delay(1000);
}


