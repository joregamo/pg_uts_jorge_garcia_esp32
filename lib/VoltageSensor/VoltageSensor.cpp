#include "VoltageSensor.h"

VoltageSensor::VoltageSensor(int pin) : _pin(pin) {
    analogReadResolution(12);
}

float VoltageSensor::readVoltage() {
    int adcValue = analogRead(_pin);
    return (adcValue / 4095.0) * V_REF;
}
