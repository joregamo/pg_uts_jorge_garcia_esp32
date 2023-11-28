#ifndef TemperatureColectorSensor_h
#define TemperatureColectorSensor_h

#include <Arduino.h>
#include <OneWire.h>
#include <DallasTemperature.h>

class TemperatureColectorSensor {
public:
    TemperatureColectorSensor(int pin);
    void begin();
    float readTemperatureInt();
    float readTemperatureOut();

private:
    OneWire _oneWire;
    DallasTemperature _sensors;
};

#endif
