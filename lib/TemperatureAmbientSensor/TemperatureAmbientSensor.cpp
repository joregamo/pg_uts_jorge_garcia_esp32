#include "TemperatureAmbientSensor.h"

TemperatureAmbientSensor::TemperatureAmbientSensor(uint8_t pin) : _oneWire(pin), _sensors(&_oneWire) {}

void TemperatureAmbientSensor::begin() {  // Declara el método aquí
    _sensors.begin();
}

float TemperatureAmbientSensor::readTemperature() {
    _sensors.requestTemperatures();
    return _sensors.getTempCByIndex(0);
}
