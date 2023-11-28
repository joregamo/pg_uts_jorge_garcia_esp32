// #pragma once
// #include <WiFi.h>

// class WiFiManager {
// public:
//     WiFiManager(const char* ssid, const char* password);
//     void connectToWiFi();
// private:
//     const char* ssid;
//     const char* password;
// };
#ifndef WiFiManager_h
#define WiFiManager_h

class WiFiManager {
public:
    WiFiManager(const char* ssid, const char* password);
    void addWiFi(const char* ssid, const char* password);
    void connectToWiFi();
};

#endif

