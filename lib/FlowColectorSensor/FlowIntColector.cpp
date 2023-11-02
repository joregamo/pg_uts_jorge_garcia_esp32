#include "FlowIntColector.h"

volatile int FlowIntColector::numPulses = 0;

FlowIntColector::FlowIntColector(int pin) : _pin(pin) {}

void FlowIntColector::begin() {
    pinMode(_pin, INPUT_PULLUP);
    attachInterrupt(digitalPinToInterrupt(_pin), pulseCounter, RISING);
}

float FlowIntColector::readFlow() {
    numPulses = 0;
    delay(1000);
    float flowRate = numPulses * 60 / 7.5 * 1000;  // Convert to mL/hour
    return flowRate;
}

void FlowIntColector::pulseCounter() {
    numPulses++;
}
