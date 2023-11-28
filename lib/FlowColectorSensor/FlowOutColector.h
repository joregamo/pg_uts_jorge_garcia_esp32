#ifndef FlowOutColector_h
#define FlowOutColector_h

#include <Arduino.h>

class FlowOutColector {
public:
    FlowOutColector(int pin);
    void begin();
    float readFlow();
    static void pulseCounter(); // Esto debe ser público si se usa como ISR

private:
    int _pin;
    static volatile int numPulsesOut;
    static unsigned long lastFlowReadTime; // Añade esta variable para rastrear el último tiempo de lectura
};

#endif // FlowOutColector_h
