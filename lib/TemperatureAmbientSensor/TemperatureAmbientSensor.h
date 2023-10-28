#ifndef TemperatureAmbientSensor_h
#define TemperatureAmbientSensor_h

#include <Arduino.h>
#include <Wire.h>
#include <OneWire.h>
#include <DallasTemperature.h>

class TemperatureAmbientSensor {
public:
    TemperatureAmbientSensor(uint8_t pin);
    void begin();
    float readTemperature();
private:
    OneWire _oneWire;
    DallasTemperature _sensors;
};

#endif
