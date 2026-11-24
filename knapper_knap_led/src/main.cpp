#include <Arduino.h>

// Konfiguration
const int KNAP_PIN = 33;  // knap mellem GPIO 33 og GND
const int LED_PIN = 2;    // den indbyggede lysdiode

int forrigeTilstand = HIGH;  // HIGH = ikke trykket (pull-up)

void setup() {
  Serial.begin(115200);
  pinMode(KNAP_PIN, INPUT_PULLUP);  // intern pull-up, så benet ikke svæver
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  int tilstand = digitalRead(KNAP_PIN);

  // Med pull-up betyder LOW, at knappen er trykket
  if (tilstand == LOW) {
    digitalWrite(LED_PIN, HIGH);
  } else {
    digitalWrite(LED_PIN, LOW);
  }

  // Skriv kun, når tilstanden skifter, ellers drukner Serial Monitor
  if (tilstand != forrigeTilstand) {
    Serial.println(tilstand == LOW ? "Trykket" : "Sluppet");
    forrigeTilstand = tilstand;
  }
}
