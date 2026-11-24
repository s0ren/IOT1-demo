#include <Arduino.h>

// Konfiguration
const int LED_PIN = 19;                // lysdiode via 220 Ω til GND
const uint32_t PWM_FREKVENS = 5000;    // Hz: så hurtigt, at øjet ikke ser blink
const uint8_t PWM_OPLOESNING = 8;      // bit: duty fra 0 til 255
const int MAKS_DUTY = 255;             // højeste duty, vi fader op til
const unsigned long TRIN_MS = 10;      // tid mellem hvert trin i fadet

int duty = 0;
int retning = 1;                       // +1 = op, -1 = ned
unsigned long sidsteTrin = 0;

// Ét trin op eller ned; vender ved enderne
void fadeEtTrin() {
  duty += retning;
  if (duty >= MAKS_DUTY || duty <= 0) {
    retning = -retning;
  }
  ledcWrite(LED_PIN, duty);
}

void setup() {
  Serial.begin(115200);

  // ledcAttach vælger selv en ledig LEDC-kanal til benet
  if (!ledcAttach(LED_PIN, PWM_FREKVENS, PWM_OPLOESNING)) {
    Serial.println("Fejl: PWM kunne ikke sættes op på benet");
  }
}

void loop() {
  unsigned long nu = millis();

  if (nu - sidsteTrin >= TRIN_MS) {
    sidsteTrin = nu;
    fadeEtTrin();
  }
}
