// #include "WiFiManager.h"
// #include <ETH.h> 
// #include <WiFi.h> 
// #include <WiFiAP.h> 
// #include <WiFiClient.h> 
// #include <WiFiGeneric.h> 
// #include <WiFiMulti.h> 
// #include <WiFiSTA.h> 
// #include <WiFiScan.h> 
// #include <WiFiServer.h> 
// #include <WiFiType.h> 
// #include <WiFiUdp.h>

// WiFiManager::WiFiManager(const char* ssid, const char* password) : ssid(ssid), password(password) {}

// void WiFiManager::connectToWiFi() {
//     Serial.print("Conectando al WiFi: ");
//     WiFi.begin(ssid, password);
    
//     int cont1 = 0;
//     while(WiFi.status() != WL_CONNECTED && cont1 != 60) {
//         delay(500);
//         Serial.print(".");
//         cont1++;
//     }
    
//     if (WiFi.status() == WL_CONNECTED) {
//         Serial.println("Conectado al WiFi");
//         Serial.print("Direccion IP: ");
//         Serial.println(WiFi.localIP());
//     } else {
//         Serial.println("No se pudo conectar al WiFi. Verifique la disponibilidad de red o el usuario y contraseña ingresados");
//         Serial.println("Una vez la red este disponible el dispositivo se conectara automaticamente a ella o presione reset para reintentar");
//     }
//     Serial.println("--------------------------");
// }
#include "WiFiManager.h"
#include <WiFiMulti.h>

WiFiMulti wifiMulti;

// Constructor actualizado con parámetros
WiFiManager::WiFiManager(const char* ssid, const char* password) {
    addWiFi(ssid, password); // Añade la red WiFi inicial
}

void WiFiManager::addWiFi(const char* ssid, const char* password) {
    wifiMulti.addAP(ssid, password);
}

void WiFiManager::connectToWiFi() {
    Serial.println("Conectando a WiFi...");
    
    // WiFiMulti intentará conectarse a las redes añadidas con addWiFi
    if(wifiMulti.run() == WL_CONNECTED) {
        Serial.println("Conectado a WiFi");
        Serial.print("Direccion IP: ");
        Serial.println(WiFi.localIP());
    } else {
        Serial.println("No se pudo conectar a ninguna de las redes WiFi configuradas.");
    }
}


