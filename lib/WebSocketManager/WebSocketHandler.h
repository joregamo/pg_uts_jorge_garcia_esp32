// WebSocketHandler.h
#ifndef WEBSOCKETHANDLER_H
#define WEBSOCKETHANDLER_H

#include <WebSocketsClient.h>

class WebSocketHandler {
public:
    WebSocketHandler();
    void begin(const char* server, uint16_t port, const char* url = "/");
    void sendMessage(const String& message);
    void loop();

private:
    WebSocketsClient webSocket;
    static void webSocketEvent(WStype_t type, uint8_t * payload, size_t length);
};

#endif
