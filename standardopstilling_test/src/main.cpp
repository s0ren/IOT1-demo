#include <Arduino.h>

// Standardopstillingen
const int KNAP_PIN = 33;        // knap mellem GPIO 33 og GND
const int LED_PIN = 19;         // lysdiode via 220 Ω til GND
const int POT_PIN = 32;         // potentiometerets midterben (ADC1)
const int INDBYGGET_LED = 2;    // lysdioden på kortet

const unsigned long BLINK_MS = 500;   // den indbyggede lysdiode blinker
const unsigned long UDSKRIFT_MS = 500; // så ofte skrives målingen

unsigned long sidsteBlink = 0;
unsigned long sidsteUdskrift = 0;
bool indbyggetTaendt = false;

void setup() {
  Serial.begin(115200);
  pinMode(KNAP_PIN, INPUT_PULLUP);   // intern pull-up: trykket = LOW
  pinMode(LED_PIN, OUTPUT);
  pinMode(INDBYGGET_LED, OUTPUT);
  Serial.println("Test af standardopstillingen");
}

void loop() {
  unsigned long nu = millis();

  // Knap -> lysdiode: ingen debouncing, fordi lysdioden bare følger knappen
  bool trykket = (digitalRead(KNAP_PIN) == LOW);
  digitalWrite(LED_PIN, trykket ? HIGH : LOW);

  // Den indbyggede lysdiode viser, at loop() kører
  if (nu - sidsteBlink >= BLINK_MS) {
    sidsteBlink = nu;
    indbyggetTaendt = !indbyggetTaendt;
    digitalWrite(INDBYGGET_LED, indbyggetTaendt ? HIGH : LOW);
  }

  // Potentiometer og knap i Serial Monitor
  if (nu - sidsteUdskrift >= UDSKRIFT_MS) {
    sidsteUdskrift = nu;
    Serial.printf("Potentiometer: %4lu mV   Knap: %s\n",
                  analogReadMilliVolts(POT_PIN),
                  trykket ? "trykket" : "-");
  }
}
