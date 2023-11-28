#include "CurrentSensor.h"
#include <Arduino.h>

CurrentSensor::CurrentSensor(int pin) : _pin(pin) {
    analogReadResolution(12); // Set the ADC resolution to 12-bit
}

float CurrentSensor::getCurrent() {
    float voltage = analogRead(_pin) * (V_REF / ADC_RESOLUTION); //Este valor de voltaje me ayuda a determinar el offset
    float AmpsRMS = ((voltage - SENSOR_OFFSET) / SENSOR_SENSITIVITY);  // Calcula la corriente y resta el offset
    return abs(AmpsRMS);
}

float CurrentSensor::getAverageCurrent(int n_samples) {
    float current_sum = 0;
    for(int i = 0; i < n_samples; i++) {
        float voltageCurrent = analogRead(_pin) * (V_REF / ADC_RESOLUTION);
        float current = ((voltageCurrent - SENSOR_OFFSET) / SENSOR_SENSITIVITY);
        current_sum += abs(current);
    }
    return current_sum / n_samples;  // Retorna el promedio de la corriente
}
