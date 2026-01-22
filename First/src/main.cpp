#include <Arduino.h>


void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  delay(500); // Wait for Serial to initialize
  Serial.println("Hello, ESP32!");
}

void loop() {
  // put your main code here, to run repeatedly:
}
