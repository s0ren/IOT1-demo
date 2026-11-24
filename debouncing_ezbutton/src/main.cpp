#include <Arduino.h>
#include <ezButton.h>

// Konfiguration
const int KNAP_PIN = 33;               // knap mellem GPIO 33 og GND
const unsigned long DEBOUNCE_MS = 50;  // hvor længe signalet skal være stabilt

ezButton knap(KNAP_PIN);  // bruger INPUT_PULLUP, når der ikke angives andet

void setup() {
  Serial.begin(115200);
  knap.setDebounceTime(DEBOUNCE_MS);  // standard er 0 ms, altså ingen debouncing
}

void loop() {
  knap.loop();  // aflæser knappen; skal kaldes i hvert gennemløb af loop()

  if (knap.isPressed()) {
    Serial.printf("Tryk nr. %lu\n", knap.getCount());
  }
  if (knap.isReleased()) {
    Serial.println("Sluppet");
  }
}
