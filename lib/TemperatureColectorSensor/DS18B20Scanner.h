#ifndef DS18B20_SCANNER_H
#define DS18B20_SCANNER_H

#include <OneWire.h>
#include <DallasTemperature.h>

class DS18B20Scanner {
public:
    DS18B20Scanner(int pin);
    void begin();
    int getDeviceCount();
    bool getAddress(DeviceAddress address, int index);

private:
    OneWire _oneWire;
    DallasTemperature _sensors;
};

#endif

