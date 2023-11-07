#include "WebSocketHandler.h"
#include <Arduino.h>

WebSocketHandler::WebSocketHandler() {}

void WebSocketHandler::begin(const char* server, uint16_t port, const char* url) {
    webSocket.begin(server, port, url);
    webSocket.onEvent(webSocketEvent);
    webSocket.setReconnectInterval(5000); // Reconnect every 5000ms if disconnected
}

void WebSocketHandler::loop() {
    webSocket.loop();
}

const char* WStypeToString(WStype_t type) {
    switch (type) {
        case WStype_DISCONNECTED: return "DISCONNECTED";
        case WStype_CONNECTED:    return "CONNECTED";
        case WStype_TEXT:         return "TEXT";
        case WStype_BIN:          return "BIN";
        case WStype_ERROR:        return "ERROR";
        case WStype_FRAGMENT_TEXT_START: return "FRAGMENT_TEXT_START";
        case WStype_FRAGMENT_BIN_START:  return "FRAGMENT_BIN_START";
        case WStype_FRAGMENT:            return "FRAGMENT";
        case WStype_FRAGMENT_FIN:        return "FRAGMENT_FIN";
        default:                  return "UNKNOWN TYPE";
    }
}

void WebSocketHandler::webSocketEvent(WStype_t type, uint8_t * payload, size_t length) {
    Serial.print("Event type: ");
    Serial.println(WStypeToString(type));
    switch(type) {
        case WStype_DISCONNECTED:
            Serial.printf("[WSc] Disconnected!\n");
            break;
        case WStype_CONNECTED:
            Serial.printf("[WSc] Connected to url: %s\n", payload);
            // sendMessage("Connected");
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