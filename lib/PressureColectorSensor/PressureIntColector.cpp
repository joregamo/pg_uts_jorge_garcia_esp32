// PressureIntColector.cpp
#include "PressureIntColector.h"

const float OffSetInt = 0.693;  // Ajusta según la calibración de 0.483V a 0.693V

PressureIntColector::PressureIntColector(int pin) : _pin(pin) {}

void PressureIntColector::begin() {
    pinMode(_pin, INPUT);
}

float PressureIntColector::readPressure() {
    float V = analogRead(_pin) * 5.00 / 4095.0; // Ajuste para ESP32 (3.3V o 5V y 4095 niveles)
    float P = (V - OffSetInt) / 4;  // Calcular la presión en MPa
    // float P = V - OffSetInt;
    return P;
}

