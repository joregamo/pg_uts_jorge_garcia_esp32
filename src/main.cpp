#include <Arduino.h>
#include "WiFiManager.h"
#include "VoltageSensor.h"
#include "CurrentSensor.h"
#include "TemperatureAmbientSensor.h" 
#include "TemperatureColectorSensor.h"
#include "DS18B20Scanner.h"
#include "PressureIntColector.h"
#include "PressureOutColector.h"
#include "FlowIntColector.h"
#include "FlowOutColector.h"
#include "LCDManager.h"

// const int DS18B20_PIN = 4;
// DS18B20Scanner scanner(DS18B20_PIN);

//WiFi
const char* ssid = "FLIA_GARCIA_GOMEZ"; //NombreDeTuRed
const char* password = "1098797932"; //ContraseñaDeTuRed

WiFiManager wifiManager(ssid, password);

// Sensor de voltaje
const int voltageSensorPin = 32;
VoltageSensor voltageSensor(voltageSensorPin);

// Sensor de corriente
const int currentSensorPin = 33;
CurrentSensor currentSensor(currentSensorPin);

// Sensor de temperatura ambiente
const int temperatureSensorPin = 15;
TemperatureAmbientSensor tempSensor(temperatureSensorPin);

// Sensores de temperatura Colector Solar
const int temperatureColectorPin = 4;
TemperatureColectorSensor colectorSensors(temperatureColectorPin);

// Sensores de Presión
const int pressureIntColectorPin = 34;
const int pressureOutColectorPin = 35;
PressureIntColector pressureIntColector(pressureIntColectorPin);
PressureOutColector pressureOutColector(pressureOutColectorPin);

// Sensores de Flujo
const int flowIntColectorPin = 12;
const int flowOutColectorPin = 13;
FlowIntColector flowIntColector(flowIntColectorPin);
FlowOutColector flowOutColector(flowOutColectorPin);

//LCD
const uint8_t lcdAddr = 0x27;  // Dirección I2C de la LCD
const uint8_t lcdCols = 16;
const uint8_t lcdRows = 2;
LCDManager lcdManager(lcdAddr, lcdCols, lcdRows);


void setup() {
    Serial.begin(115200);
    wifiManager.connectToWiFi(); // Conecta a la red WiFi
    tempSensor.begin();  // Inicializa el sensor de temperatura
    colectorSensors.begin(); // Inicializa los sensores de temperatura del colector
    pressureIntColector.begin();  // Inicializa el sensor de presión en la entrada
    pressureOutColector.begin();  // Inicializa el sensor de presión en la salida
    flowIntColector.begin();  // Inicializa el sensor de flujo en la entrada
    flowOutColector.begin();  // Inicializa el sensor de flujo en la salida
    lcdManager.begin();  // Inicializa la LCD

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
    float averageCurrent = currentSensor.getAverageCurrent(200);
  
    Serial.print("Current: ");
    Serial.print(averageCurrent, 3);
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

    // Lectura y despliegue de la presión a la entrada del colector
    float pressureInt = pressureIntColector.readPressure();
    Serial.print("Pressure Int Colector: ");
    Serial.print(pressureInt, 2);
    Serial.println(" MPa");

    // Lectura y despliegue de la presión a la salida del colector
    float pressureOut = pressureOutColector.readPressure();
    Serial.print("Pressure Out Colector: ");
    Serial.print(pressureOut, 2);
    Serial.println(" MPa");

    // Lectura y despliegue del flujo a la entrada del colector
    float flowInt = flowIntColector.readFlow();
    Serial.print("Flow Int Colector: ");
    Serial.print(flowInt, 2);
    Serial.println(" mL/min");

    // Lectura y despliegue del flujo a la salida del colector
    float flowOut = flowOutColector.readFlow();
    Serial.print("Flow Out Colector: ");
    Serial.print(flowOut, 2);
    Serial.println(" mL/min");

    
    lcdManager.displayData(voltageReal, averageCurrent, temperature, temperatureInt, temperatureOut, 
                            pressureInt, pressureOut, flowInt, flowOut);
   
        

    delay(2000);
}




