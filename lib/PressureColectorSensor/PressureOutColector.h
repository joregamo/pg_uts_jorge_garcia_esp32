// PressureOutColector.h
#ifndef PressureOutColector_h
#define PressureOutColector_h

#include <Arduino.h>

class PressureOutColector {
public:
    PressureOutColector(int pin);
    void begin();
    float readPressure();
private:
    int _pin;
};

#endif
