#include "SocketIoClientHandler.h"

SocketIoClientHandler::SocketIoClientHandler(const char* server, int port) {
    socketIo.begin(server, port);
}

void SocketIoClientHandler::begin() {
    // Aquí puedes inicializar cosas si es necesario
}

void SocketIoClientHandler::loop() {
    socketIo.loop();
}

void SocketIoClientHandler::onEvent(const char* event, std::function<void(const char * payload, size_t length)> func) {
    socketIo.on(event, func);
}
