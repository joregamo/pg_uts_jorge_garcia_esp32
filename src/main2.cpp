// /*
//  * WebSocketClient.ino
//  */

// #include <Arduino.h>

// #include <WiFi.h>
// #include <Wire.h>
// #include <WiFiClientSecure.h>
// #include <WebSocketsClient.h>

// WebSocketsClient webSocket;

// #define USE_SERIAL Serial

// const char* ssid = "FAMILIA_VARGAS";      // Tu SSID (nombre de la red WiFi)
// const char* password = "V1102382910";  // Tu contraseña de la red WiFi

// void hexdump(const void *mem, uint32_t len, uint8_t cols = 16) {
//     const uint8_t* src = (const uint8_t*) mem;
//     USE_SERIAL.printf("\n[HEXDUMP] Address: 0x%08X len: 0x%X (%d)", (ptrdiff_t)src, len, len);
//     for(uint32_t i = 0; i < len; i++) {
//         if(i % cols == 0) {
//             USE_SERIAL.printf("\n[0x%08X] 0x%08X: ", (ptrdiff_t)src, i);
//         }
//         USE_SERIAL.printf("%02X ", *src);
//         src++;
//     }
//     USE_SERIAL.printf("\n");
// }

// void webSocketEvent(WStype_t type, uint8_t * payload, size_t length) {
//     switch(type) {
//         case WStype_DISCONNECTED:
//             USE_SERIAL.printf("[WSc] Disconnected!\n");
//             break;
//         case WStype_CONNECTED:
//             USE_SERIAL.printf("[WSc] Connected to url: %s\n", payload);
//             webSocket.sendTXT("Connected");
//             break;
//         case WStype_TEXT:
//             USE_SERIAL.printf("[WSc] get text: %s\n", payload);
//             break;
//         case WStype_BIN:
//             USE_SERIAL.printf("[WSc] get binary length: %u\n", length);
//             hexdump(payload, length);
//             break;
//         default:
//             // No default action needed for other events
//             break;
//     }
// }

// void setup() {
//     USE_SERIAL.begin(115200);
    
//     // Connect to WiFi
//     WiFi.begin(ssid, password);
//     while(WiFi.status() != WL_CONNECTED) {
//         delay(500);
//         USE_SERIAL.println("Connecting to WiFi...");
//     }
//     USE_SERIAL.println("Connected to WiFi");

//     // Setup WebSocket
//     webSocket.begin("192.168.1.8", 3000, "/");
//     webSocket.onEvent(webSocketEvent);
//     webSocket.setReconnectInterval(5000); // Try to reconnect every 5000ms if disconnected
// }

// void loop() {
//     webSocket.loop();
// }
