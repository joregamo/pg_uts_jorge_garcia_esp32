// PressureIntColector.h
#ifndef PressureIntColector_h
#define PressureIntColector_h

#include <Arduino.h>

class PressureIntColector {
public:
    PressureIntColector(int pin);
    void begin();
    float readPressure();
private:
    int _pin;
};

#endif
