#include "FlowIntColector.h"

volatile int FlowIntColector::numPulsesInt = 0;
unsigned long FlowIntColector::lastFlowReadTime = 0; 

FlowIntColector::FlowIntColector(int pin) : _pin(pin) {}

void FlowIntColector::begin() {
    pinMode(_pin, INPUT_PULLUP);
    attachInterrupt(digitalPinToInterrupt(_pin), FlowIntColector::pulseCounter, RISING); 
}

float FlowIntColector::readFlow() {
    float flowrate1 = 0.0;
    if (millis() - lastFlowReadTime > 1000) {
        detachInterrupt(digitalPinToInterrupt(_pin));
        flowrate1 = (numPulsesInt * 60.0) / 7.5;
        numPulsesInt = 0;
        lastFlowReadTime = millis();
        attachInterrupt(digitalPinToInterrupt(_pin), FlowIntColector::pulseCounter, RISING);
        return flowrate1; // Calcula el caudal en L/h
    }
    return -1; // Default return value
}

// ISR para contar pulsos del sensor de flujo interno
void FlowIntColector::pulseCounter() {
    numPulsesInt++;
}
