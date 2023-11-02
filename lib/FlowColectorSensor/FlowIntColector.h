#ifndef FlowIntColector_h
#define FlowIntColector_h

#include <Arduino.h>

class FlowIntColector {
public:
    FlowIntColector(int pin);
    void begin();
    float readFlow();
private:
    int _pin;
    static void pulseCounter();
    static volatile int numPulses;
};

#endif
