#pragma once

class CurrentSensor {
public:
    explicit CurrentSensor(int pin);
    float getCurrent();
    float getAverageCurrent(int n_samples);  // Nuevo método para obtener el promedio de corriente

private:
    int _pin;
    static constexpr float ADC_RESOLUTION = 4095.0; // ESP32 ADC is 12-bit
    static constexpr float V_REF = 3.3; // Reference voltage for ESP32 ADC
    static constexpr float SENSOR_OFFSET = 0.6167; // 0.617 a 0.98V for the ACS712 when no current (con 10mA de diferencia con respecto a la lectura real)
    static constexpr float SENSOR_SENSITIVITY = 0.1; // Sensitivity of the ACS712 20A module (100 mV/A)
};


