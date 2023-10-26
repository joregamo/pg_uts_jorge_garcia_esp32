#include <Arduino.h>
#include "VoltageSensor.h"
#include "CurrentSensor.h"

// Sensor de voltaje
const int voltageSensorPin = 32;
VoltageSensor voltageSensor(voltageSensorPin);

// Sensor de corriente
const int currentSensorPin = 27;
CurrentSensor currentSensor(currentSensorPin);

void setup() {
    Serial.begin(115200);
}

void loop() {
    // Lectura y despliegue del voltaje
    float voltage = voltageSensor.readVoltage();
    float voltageReal = voltage / 0.1; // Factor de conversión para el voltaje
  
    Serial.print("Voltage: ");
    Serial.print(voltageReal, 2);
    Serial.println(" V");

    // Lectura y despliegue de la corriente
    float current = currentSensor.getCurrent();
  
    Serial.print("Current: ");
    Serial.print(current, 2);
    Serial.println(" A");

    delay(1000);
}



