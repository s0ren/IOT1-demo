#include <Arduino.h>

// Konfiguration
const int LED_PIN = 19;               // ekstern lysdiode via 220 Ω til GND
const unsigned long BLINK_MS = 500;   // tid tændt og tid slukket

bool ledTaendt = false;
unsigned long sidsteSkift = 0;

// Skifter begge lysdioder; den indbyggede lyser, når den eksterne er slukket
void skiftLysdioder() {
  ledTaendt = !ledTaendt;
  digitalWrite(LED_PIN, ledTaendt ? HIGH : LOW);
  digitalWrite(LED_BUILTIN, ledTaendt ? LOW : HIGH);
}

void setup() {
  Serial.begin(115200);
  pinMode(LED_PIN, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);  // GPIO 2 på ESP32-DEVKIT-V1
}

void loop() {
  unsigned long nu = millis();

  // Subtraktionen virker også, når millis() løber rundt (efter ca. 49 dage),
  // fordi begge tal er unsigned long
  if (nu - sidsteSkift >= BLINK_MS) {
    sidsteSkift = nu;
    skiftLysdioder();
  }

  // Her kan loop() lave andre ting, fx læse knapper eller sende data
}
