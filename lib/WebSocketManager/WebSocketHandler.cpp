// WebSocketHandler.cpp
#include "WebSocketHandler.h"
#include <Arduino.h>

WebSocketHandler::WebSocketHandler() {}

void WebSocketHandler::begin(const char* server, uint16_t port, const char* url) {
    webSocket.begin(server, port, url);
    webSocket.onEvent(webSocketEvent);
    webSocket.setReconnectInterval(5000);
}

void WebSocketHandler::loop() {
    webSocket.loop();
}

void WebSocketHandler::webSocketEvent(WStype_t type, uint8_t * payload, size_t length) {
    switch(type) {
        case WStype_DISCONNECTED:
            Serial.printf("[WSc] Disconnected!\n");
            break;
        case WStype_CONNECTED:
            Serial.printf("[WSc] Connected to url: %s\n", payload);
            // webSocket.sendTXT("Connected"); // Uncomment if you want to send a message upon connection
            break;
        case WStype_TEXT:
            Serial.printf("[WSc] get text: %s\n", payload);
            break;
        case WStype_BIN:
            // Handle binary message
            break;
        default:
            // No default action needed for other events
            break;
    }
}

void WebSocketHandler::sendMessage(const String& message) {
    webSocket.sendTXT(message.c_str()); // Convert String to const char* using c_str()
}
