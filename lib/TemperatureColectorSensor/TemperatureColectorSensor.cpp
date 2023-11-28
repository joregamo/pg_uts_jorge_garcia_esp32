#include "TemperatureColectorSensor.h"

TemperatureColectorSensor::TemperatureColectorSensor(int pin) : _oneWire(pin), _sensors(&_oneWire) {}

void TemperatureColectorSensor::begin() {
    _sensors.begin();
}

float TemperatureColectorSensor::readTemperatureInt() {
    _sensors.requestTemperatures();
    return _sensors.getTempCByIndex(0); // 0 para el primer sensor en el bus
}

float TemperatureColectorSensor::readTemperatureOut() {
    _sensors.requestTemperatures();
    return _sensors.getTempCByIndex(1); // 1 para el segundo sensor en el bus
}
