#include <Arduino.h>

// Konfiguration
const int LED_PIN = 2;                 // indbygget lysdiode på DEVKIT-V1
const unsigned long INTERVAL_MS = 1000; // tid mellem skift

unsigned long sidsteSkift = 0;
bool ledTaendt = false;

void setup() {
  Serial.begin(115200);  // skal passe med monitor_speed
  pinMode(LED_PIN, OUTPUT);
  Serial.println("PlatformIO virker!");
}

void loop() {
  // millis() i stedet for delay(), så loop() aldrig står stille
  if (millis() - sidsteSkift >= INTERVAL_MS) {
    sidsteSkift = millis();
    ledTaendt = !ledTaendt;
    digitalWrite(LED_PIN, ledTaendt ? HIGH : LOW);
    Serial.printf("Kørt i %lu s\n", millis() / 1000);
  }
}
