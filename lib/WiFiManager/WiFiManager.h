#pragma once
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

class WiFiManager {
public:
    WiFiManager(const char* ssid, const char* password);
    void connect();
};

