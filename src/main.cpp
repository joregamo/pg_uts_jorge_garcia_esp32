#include <Arduino.h>
#include "VoltageSensor.h"
#include "CurrentSensor.h"
#include "TemperatureAmbientSensor.h" 
#include "TemperatureColectorSensor.h"
#include "DS18B20Scanner.h"

// const int DS18B20_PIN = 4;
// DS18B20Scanner scanner(DS18B20_PIN);

// Sensor de voltaje
const int voltageSensorPin = 32;
VoltageSensor voltageSensor(voltageSensorPin);

// Sensor de corriente
const int currentSensorPin = 27;
CurrentSensor currentSensor(currentSensorPin);

// Sensor de temperatura ambiente
const int temperatureSensorPin = 15;
TemperatureAmbientSensor tempSensor(temperatureSensorPin);

// Sensores de temperatura Colector Solar
const int temperatureColectorPin = 4;
TemperatureColectorSensor colectorSensors(temperatureColectorPin);

void setup() {
    Serial.begin(115200);
    // scanner.begin();
  
    // int numberOfDevices = scanner.getDeviceCount();
    // Serial.print("Cantidad de termocuplas encontradas en el colector: ");
    // Serial.println(numberOfDevices);
  
    // for (int i = 0; i < numberOfDevices; i++) {
    //     DeviceAddress tempDeviceAddress;
    //     if (scanner.getAddress(tempDeviceAddress, i)) {
    //         Serial.print("Dispositivo ");
    //         Serial.print(i);
    //         Serial.print(" Dirección: ");
    //         for (uint8_t j = 0; j < 8; j++) {
    //             Serial.print(tempDeviceAddress[j], HEX);
    //             if (j < 7) Serial.print(":");
    //         }
    //         Serial.println();
    //     }
    // }
    tempSensor.begin();  // Inicializa el sensor de temperatura
    colectorSensors.begin(); // Inicializa los sensores de temperatura del colector
}

void loop() {
    
    Serial.print("--------------------\n");
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

    // Lectura y despliegue de la temperatura a la entrada del colector
    float temperatureInt = colectorSensors.readTemperatureInt();
    Serial.print("Temperature Int Colector: ");
    Serial.print(temperatureInt, 2);
    Serial.println(" °C");

    // Lectura y despliegue de la temperatura a la salida del colector
    float temperatureOut = colectorSensors.readTemperatureOut();
    Serial.print("Temperature Out Colector: ");
    Serial.print(temperatureOut, 2);
    Serial.println(" °C");

    delay(1000);
}




