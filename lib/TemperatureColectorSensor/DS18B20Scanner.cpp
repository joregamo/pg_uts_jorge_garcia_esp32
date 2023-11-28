#include "DS18B20Scanner.h"

DS18B20Scanner::DS18B20Scanner(int pin) : _oneWire(pin), _sensors(&_oneWire) {}

void DS18B20Scanner::begin() {
    _sensors.begin();
}

int DS18B20Scanner::getDeviceCount() {
    return _sensors.getDeviceCount();
}

bool DS18B20Scanner::getAddress(DeviceAddress address, int index) {
    return _sensors.getAddress(address, index);
}
