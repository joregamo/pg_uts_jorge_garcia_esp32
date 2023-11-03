#include "WiFiManager.h"

WiFiManager::WiFiManager(const char* ssid, const char* password) : ssid(ssid), password(password) {}

void WiFiManager::connectToWiFi() {
    Serial.print("Conectando al WiFi: ");
    WiFi.begin(ssid, password);
    
    int cont1 = 0;
    while(WiFi.status() != WL_CONNECTED && cont1 != 60) {
        delay(500);
        Serial.print(".");
        cont1++;
    }
    
    if (WiFi.status() == WL_CONNECTED) {
        Serial.println("Conectado al WiFi");
        Serial.print("Direccion IP: ");
        Serial.println(WiFi.localIP());
    } else {
        Serial.println("No se pudo conectar al WiFi. Verifique la disponibilidad de red o el usuario y contraseña ingresados");
        Serial.println("Una vez la red este disponible el dispositivo se conectara automaticamente a ella o presione reset para reintentar");
    }
    Serial.println("--------------------------");
}
