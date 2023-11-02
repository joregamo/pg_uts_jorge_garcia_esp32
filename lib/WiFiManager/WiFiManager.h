#pragma once
<<<<<<< HEAD
#include <WiFi.h>
=======
#include <ETH.h> 
#include <WiFi.h> 
#include <WiFiAP.h> 
#include <WiFiClient.h> 
#include <WiFiGeneric.h> 
#include <WiFiMulti.h> 
#include <WiFiSTA.h> 
#include <WiFiScan.h> 
#include <WiFiServer.h> 
#include <WiFiType.h> 
#include <WiFiUdp.h>
>>>>>>> 8b2dfef (Se ajustó el main.cpp para que funcionará la funcion de la LCD y el del sensor de flujo, en la pantalla LCD solo imprime dos variables cada dos segundos)

class WiFiManager {
public:
    WiFiManager(const char* ssid, const char* password);
<<<<<<< HEAD
    void connectToWiFi();
private:
    const char* ssid;
    const char* password;
=======
    void connect();
>>>>>>> 8b2dfef (Se ajustó el main.cpp para que funcionará la funcion de la LCD y el del sensor de flujo, en la pantalla LCD solo imprime dos variables cada dos segundos)
};

