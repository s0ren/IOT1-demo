#include <Arduino.h>

// Konfiguration
const int LED_PIN = 2;              // indbygget lysdiode på DEVKIT-V1 (LED_BUILTIN)
const unsigned long BLINK_MS = 500; // tid mellem hvert skift

unsigned long sidsteSkift = 0;  // tidspunktet for sidste skift, i ms
bool ledTaendt = false;

void setup() {
  Serial.begin(115200);
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  // Er der gået BLINK_MS, siden vi sidst skiftede?
  if (millis() - sidsteSkift >= BLINK_MS) {
    sidsteSkift = millis();
    ledTaendt = !ledTaendt;  // skift mellem tændt og slukket
    digitalWrite(LED_PIN, ledTaendt ? HIGH : LOW);
    Serial.printf("%lu ms: lysdioden er %s\n", sidsteSkift, ledTaendt ? "tændt" : "slukket");
  }

  // Her er plads til andet arbejde, fx at læse en knap.
  // Det bliver ikke forsinket af blinket.
}
