
#include "Arduino.h"
#include <WiFi.h>
#include <Wire.h>

volatile int pulseCount = 0;
unsigned long lastPulseTime = 0;
const unsigned long pulseTimeout = 2000; // 2 segundos sin pulsos antes de resetear

void IRAM_ATTR pulseCounter() {
  pulseCount++;
  lastPulseTime = millis(); // Actualizar el momento del último pulso
}

void setup() {
  Serial.begin(115200);
  pinMode(13, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(13), pulseCounter, RISING);
}

void loop() {
  if ((millis() - lastPulseTime > pulseTimeout) && (pulseCount != 0)) {
    // Si han pasado más de 2 segundos desde el último pulso, asume que no hay flujo
    pulseCount = 0; // Reinicia el conteo de pulsos
  }

  Serial.print("Pulsos: ");
  Serial.println(pulseCount);
  delay(1000); // Simple delay para la demostración
}

