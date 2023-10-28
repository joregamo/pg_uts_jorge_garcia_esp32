#include <Arduino.h>
#include "VoltageSensor.h"
#include "CurrentSensor.h"
#include "TemperatureAmbientSensor.h" 

// Sensor de voltaje
const int voltageSensorPin = 32;
VoltageSensor voltageSensor(voltageSensorPin);

// Sensor de corriente
const int currentSensorPin = 27;
CurrentSensor currentSensor(currentSensorPin);

// Sensor de temperatura ambiente
const int temperatureSensorPin = 15;
TemperatureAmbientSensor tempSensor(temperatureSensorPin);

void setup() {
    Serial.begin(115200);
    tempSensor.begin();  // Inicializa el sensor de temperatura
}

void loop() {
    // Lectura y despliegue del voltaje
    float voltage = voltageSensor.readVoltage();
    float voltageReal = voltage/ 0.14; // 0.1 a 0.15 Factor de conversión para el voltaje
  
    Serial.print("Voltage: ");
    Serial.print(voltageReal, 2);
    Serial.println(" V");

    // Lectura y despliegue de la corriente
    float current = currentSensor.getCurrent();
  
    Serial.print("Current: ");
    Serial.print(current, 2);
    Serial.println(" A");

    // Lectura y despliegue de la temperatura ambiente
    float temperature = tempSensor.readTemperature();
    
    Serial.print("Temperature ambient: ");
    Serial.print(temperature, 2);
    Serial.println(" °C");

    delay(1000);
}




