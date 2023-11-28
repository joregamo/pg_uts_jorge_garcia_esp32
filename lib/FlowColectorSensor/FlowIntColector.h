#ifndef FlowIntColector_h
#define FlowIntColector_h

#include <Arduino.h>

class FlowIntColector {
public:
    FlowIntColector(int pin);
    void begin();
    float readFlow();
    static void pulseCounter(); // Debe ser accesible como ISR

private:
    int _pin;
    static volatile int numPulsesInt; // Variable para contar pulsos
    static unsigned long lastFlowReadTime; // Variable para rastrear el último tiempo de lectura
};

#endif // FlowIntColector_h
