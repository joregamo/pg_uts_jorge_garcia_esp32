#include <Arduino.h>
// #include "Wifi.h"
#include "Wire.h"
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
#include "ArduinoJson.h"
#include "WebSocketsClient.h"

// const int DS18B20_PIN = 4;
// DS18B20Scanner scanner(DS18B20_PIN);

WebSocketsClient webSocket;
//WiFi
const char* ssid = "FAMILIA_VARGAS"; //NombreDeTuRed
const char* password = "V1102382910"; //ContraseñaDeTuRed

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

void hexdump(const void *mem, uint32_t len, uint8_t cols = 16) {
    const uint8_t* src = (const uint8_t*) mem;
    Serial.printf("\n[HEXDUMP] Address: 0x%08X len: 0x%X (%d)", (ptrdiff_t)src, len, len);
    for(uint32_t i = 0; i < len; i++) {
        if(i % cols == 0) {
            Serial.printf("\n[0x%08X] 0x%08X: ", (ptrdiff_t)src, i);
        }
        Serial.printf("%02X ", *src);
        src++;
    }
    Serial.printf("\n");
}

void webSocketEvent(WStype_t type, uint8_t * payload, size_t length) {
    switch(type) {
        case WStype_DISCONNECTED:
            Serial.printf("[WSc] Disconnected!\n");
            break;
        case WStype_CONNECTED:
            Serial.printf("[WSc] Connected to url: %s\n", payload);
            webSocket.sendTXT("Connected");
            break;
        case WStype_TEXT:
            Serial.printf("[WSc] get text: %s\n", payload);
            break;
        case WStype_BIN:
            Serial.printf("[WSc] get binary length: %u\n", length);
            hexdump(payload, length);
            break;
        default:
            // No default action needed for other events
            break;
    }
}

void setup() {
    Serial.begin(115200);
    tempSensor.begin();  // Inicializa el sensor de temperatura
    colectorSensors.begin(); // Inicializa los sensores de temperatura del colector
    pressureIntColector.begin();  // Inicializa el sensor de presión en la entrada
    pressureOutColector.begin();  // Inicializa el sensor de presión en la salida
    flowIntColector.begin();  // Inicializa el sensor de flujo en la entrada
    flowOutColector.begin();  // Inicializa el sensor de flujo en la salida
    wifiManager.connectToWiFi(); // Conecta a la red WiFi
    // lcdManager.begin();  // Inicializa la LCD

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

    webSocket.begin("192.168.1.8", 3000, "/");
    webSocket.onEvent(webSocketEvent);
    webSocket.setReconnectInterval(5000);
}

void loop() {
    static unsigned long lastSensorReadTime = 0;
    unsigned long currentMillis = millis();

    webSocket.loop();

    if (currentMillis - lastSensorReadTime > 10000) {
        lastSensorReadTime = currentMillis;

        StaticJsonDocument<512> jsonDoc;

        // Leer datos de los sensores
        float voltage = voltageSensor.readVoltage();
        float voltageReal = voltage / 0.14;
        float averageCurrent = currentSensor.getAverageCurrent(200);
        float temperature = tempSensor.readTemperature();
        float temperatureInt = colectorSensors.readTemperatureInt();
        float temperatureOut = colectorSensors.readTemperatureOut();
        float pressureInt = pressureIntColector.readPressure();
        float pressureOut = pressureOutColector.readPressure();
        float flowInt = flowIntColector.readFlow();
        float flowOut = flowOutColector.readFlow();

        // Asignar valores al objeto JSON
        jsonDoc["voltage"] = voltageReal;
        jsonDoc["current"] = averageCurrent;
        jsonDoc["temperatureAmbient"] = temperature;
        jsonDoc["temperatureIntCollector"] = temperatureInt;
        jsonDoc["temperatureOutCollector"] = temperatureOut;
        jsonDoc["pressureIntCollector"] = pressureInt;
        jsonDoc["pressureOutCollector"] = pressureOut;
        jsonDoc["flowIntCollector"] = flowInt;
        jsonDoc["flowOutCollector"] = flowOut;

        // Convertir a String JSON
        String jsonString;
        serializeJson(jsonDoc, jsonString);

        // Enviar JSON como texto al WebSocket server
        Serial.println(jsonString);
        webSocket.sendTXT(jsonString);
    }
}
