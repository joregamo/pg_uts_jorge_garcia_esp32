#ifndef VoltageSensor_h
#define VoltageSensor_h

#include <Arduino.h>

class VoltageSensor {
public:
    VoltageSensor(int pin);
    float readVoltage();
private:
    int _pin;
    const float V_REF = 3.3;
};

#endif
