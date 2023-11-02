#include "FlowOutColector.h"

volatile int FlowOutColector::numPulses = 0;

FlowOutColector::FlowOutColector(int pin) : _pin(pin) {}

void FlowOutColector::begin() {
    pinMode(_pin, INPUT_PULLUP);
    attachInterrupt(digitalPinToInterrupt(_pin), pulseCounter, RISING);
}

float FlowOutColector::readFlow() {
    numPulses = 0;
    delay(1000);
    float flowRate = numPulses * 60 / 7.5 * 1000;  // Convert to mL/hour
    return flowRate;
}

void FlowOutColector::pulseCounter() {
    numPulses++;
}
