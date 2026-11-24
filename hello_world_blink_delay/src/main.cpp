#include <Arduino.h>

// Konfiguration
const int LED_PIN = 2;             // indbygget lysdiode på DEVKIT-V1 (LED_BUILTIN)
const unsigned long BLINK_MS = 500; // tid tændt og tid slukket

void setup() {
  Serial.begin(115200);
  pinMode(LED_PIN, OUTPUT);  // benet skal sættes op som output, før det kan tænde lysdioden
}

void loop() {
  digitalWrite(LED_PIN, HIGH);  // tænd
  Serial.println("Tændt");
  delay(BLINK_MS);              // vent: her står loop() stille
  digitalWrite(LED_PIN, LOW);   // sluk
  Serial.println("Slukket");
  delay(BLINK_MS);
}
