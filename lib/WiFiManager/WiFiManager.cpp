#include "WiFiManager.h"

WiFiManager::WiFiManager(const char* ssid, const char* password) {
    WiFi.begin(ssid, password);
}

void WiFiManager::connect() {
    int cont1 = 0;
    Serial.println(F("Conectando al Wifi:"));
    while(WiFi.status() != WL_CONNECTED && cont1 != 60) {
        delay(500);
        Serial.print(F("."));
        cont1++;
    }
    if (WiFi.status() == WL_CONNECTED) {
        Serial.println(F("Conectado al WiFi"));
        Serial.print(F("Direccion IP: "));
        Serial.println(WiFi.localIP());
    } else {
        Serial.println(F("No se pudo conectar al WiFi. Verifique la disponibilidad de red o el usuario y contraseña ingresados"));
        Serial.println(F("Una vez la red este disponible el dispositivo se conectara automaticamente a ella o presione reset para reintentar"));
    }
    Serial.println("--------------------------");
}
