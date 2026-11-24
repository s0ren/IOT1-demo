#include <Arduino.h>

void setup() {
  Serial.begin(115200);  // skal passe med monitor_speed i platformio.ini
  Serial.println("Hej fra ESP32!");
}

void loop() {
  // Tom: alt sker i setup(), så teksten skrives kun én gang
}
