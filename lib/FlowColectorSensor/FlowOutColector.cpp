#include "FlowOutColector.h"

volatile int FlowOutColector::numPulsesOut = 0;
unsigned long FlowOutColector::lastFlowReadTime = 0; // Inicializa la variable estática

FlowOutColector::FlowOutColector(int pin) : _pin(pin) {}

void FlowOutColector::begin() {
    pinMode(_pin, INPUT_PULLUP);
    attachInterrupt(digitalPinToInterrupt(_pin), FlowOutColector::pulseCounter, RISING); // Usa el nombre de la clase
}

float FlowOutColector::readFlow() {
    float flowrate2 = 0.0;
    if (millis() - lastFlowReadTime > 1000) {
        detachInterrupt(digitalPinToInterrupt(_pin));
        flowrate2 = (numPulsesOut * 60.0) / 7.5;
        numPulsesOut = 0;
        lastFlowReadTime = millis();
        attachInterrupt(digitalPinToInterrupt(_pin), FlowOutColector::pulseCounter, RISING);
        return flowrate2; // Calcula el caudal en L/h
    }
    return -1; // Default return value
}

// ISR para contar pulsos del sensor de flujo interno
void FlowOutColector::pulseCounter() {
    numPulsesOut++;
}


