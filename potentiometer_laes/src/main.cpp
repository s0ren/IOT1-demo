#include <Arduino.h>

// Konfiguration
const int POT_PIN = 32;                 // midterben på GPIO 32 (ADC1, virker også med WiFi)
const unsigned long INTERVAL_MS = 200;  // hvor tit værdien skrives ud
const int ANTAL_MAALINGER = 16;         // gennemsnit af flere målinger dæmper støj

unsigned long sidsteUdskrift = 0;

// Gennemsnit af flere rå målinger (0–4095)
int laesRaa() {
  long sum = 0;  // long, så summen ikke løber over
  for (int i = 0; i < ANTAL_MAALINGER; i++) {
    sum += analogRead(POT_PIN);
  }
  return sum / ANTAL_MAALINGER;
}

// Gennemsnit af flere kalibrerede målinger i millivolt
int laesMilliVolt() {
  long sum = 0;
  for (int i = 0; i < ANTAL_MAALINGER; i++) {
    sum += analogReadMilliVolts(POT_PIN);
  }
  return sum / ANTAL_MAALINGER;
}

void setup() {
  Serial.begin(115200);
  // Ingen opsætning af ADC'en: standarden er 12 bit og 11 dB dæmpning (op mod 3,3 V)
}

void loop() {
  unsigned long nu = millis();

  // Kun hvert INTERVAL_MS; resten af tiden er loop() fri til andet
  if (nu - sidsteUdskrift >= INTERVAL_MS) {
    sidsteUdskrift = nu;

    int raa = laesRaa();
    int milliVolt = laesMilliVolt();
    int procent = map(raa, 0, 4095, 0, 100);

    Serial.printf("Raa: %4d   Spaending: %4d mV   %3d %%\n", raa, milliVolt, procent);
  }
}
