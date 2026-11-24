#include <Arduino.h>

// Konfiguration
const int KNAP_PIN = 33;   // knap mellem GPIO 33 og GND

int forrigeTilstand = HIGH;  // HIGH = ikke trykket (pull-up)
unsigned long antalTryk = 0;

void setup() {
  Serial.begin(115200);
  pinMode(KNAP_PIN, INPUT_PULLUP);  // slår den interne pull-up til
}

void loop() {
  int tilstand = digitalRead(KNAP_PIN);

  // Et tryk er skiftet fra HIGH til LOW
  if (forrigeTilstand == HIGH && tilstand == LOW) {
    antalTryk++;
    Serial.printf("Tryk nr. %lu\n", antalTryk);
  }
  forrigeTilstand = tilstand;
}
