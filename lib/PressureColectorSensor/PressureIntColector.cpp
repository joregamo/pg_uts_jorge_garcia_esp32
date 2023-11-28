// PressureIntColector.cpp
#include "PressureIntColector.h"

const float OffSetInt = 0.718;  // Ajusta según la calibración de 0.483V a 0.693V, 0.718V

PressureIntColector::PressureIntColector(int pin) : _pin(pin) {}

void PressureIntColector::begin() {
    pinMode(_pin, INPUT);
}

float PressureIntColector::readPressure() {
    float V = analogRead(_pin) * 5.00 / 4095.0; // Ajuste para ESP32 (3.3V o 5V y 4095 niveles)
    float P_MPa = (V - OffSetInt) / 4;  // Calcular la presión en MPa
    float P_PSI = P_MPa * 145.038; // Convertir de MPa a PSI
    return P_PSI;
}


