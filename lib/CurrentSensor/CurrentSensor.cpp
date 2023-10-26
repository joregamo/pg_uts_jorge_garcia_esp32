#include "CurrentSensor.h"
#include <Arduino.h>

CurrentSensor::CurrentSensor(int pin) : _pin(pin) {
    analogReadResolution(12); // Set the ADC resolution to 12-bit
}

float CurrentSensor::getCurrent() {
    float voltage = analogRead(_pin) * (V_REF / ADC_RESOLUTION);
    float voltageDifference = voltage - SENSOR_OFFSET;
    float current = voltageDifference / SENSOR_SENSITIVITY; //0.3 is the error I got for my sensor
    return current;
}
