#pragma once

class CurrentSensor {
public:
    explicit CurrentSensor(int pin);
    float getCurrent();

private:
    int _pin;
    static constexpr float ADC_RESOLUTION = 4095.0; // ESP32 ADC is 12-bit
    static constexpr float V_REF = 3.3; // Reference voltage for ESP32 ADC
    static constexpr float SENSOR_OFFSET = 0.88; // 0.63 a 0.98V for the ACS712 when no current
    static constexpr float SENSOR_SENSITIVITY = 0.1; // Sensitivity of the ACS712 20A module (100 mV/A)
};

