#ifndef SocketIoClientHandler_h
#define SocketIoClientHandler_h

#include <Arduino.h>
#include <SocketIoClient.h>

class SocketIoClientHandler {
public:
    SocketIoClientHandler(const char* server, int port);
    void begin();
    void loop();
    void onEvent(const char* event, std::function<void(const char * payload, size_t length)> func);

private:
    SocketIoClient socketIo;
};

#endif
