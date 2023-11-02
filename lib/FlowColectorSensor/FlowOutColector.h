#ifndef FlowOutColector_h
#define FlowOutColector_h

#include <Arduino.h>

class FlowOutColector {
public:
    FlowOutColector(int pin);
    void begin();
    float readFlow();
private:
    int _pin;
    static void pulseCounter();
    static volatile int numPulses;
};

#endif
