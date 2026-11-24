#include <Arduino.h>
#include "statistik.h"

// Konfiguration
const int ANTAL_MAALINGER = 10;
const unsigned long INTERVAL_MS = 2000;  // tid mellem hver serie af målinger

int maalinger[ANTAL_MAALINGER];
unsigned long sidsteMaaling = 0;

// Forward declaration: definitionen står nederst i filen
void tagMaalinger(int data[], int antal);

void setup() {
  Serial.begin(115200);
}

void loop() {
  // millis() i stedet for delay(), så loop() ikke står stille
  if (millis() - sidsteMaaling >= INTERVAL_MS) {
    sidsteMaaling = millis();
    tagMaalinger(maalinger, ANTAL_MAALINGER);
    Serial.printf("Gennemsnit: %.1f  Største: %d\n",
                  gennemsnit(maalinger, ANTAL_MAALINGER),
                  stoersteVaerdi(maalinger, ANTAL_MAALINGER));
  }
}

// Simulerer en sensor. Skift random() ud med analogRead(), når der sidder en rigtig sensor på.
void tagMaalinger(int data[], int antal) {
  for (int i = 0; i < antal; i++) {
    data[i] = random(0, 4096);  // 0-4095; øvre grænse er ikke med
  }
}
