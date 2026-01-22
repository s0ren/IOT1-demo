#include <Arduino.h>

#define INTERNAL 2 // GPIO2 is often connected to the internal LED on ESP32 boards
#define ledBlue INTERNAL
#define ledRed  4

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  delay(500); // Wait for Serial to initialize  
  
  pinMode(INTERNAL, OUTPUT);
  pinMode(ledRed, OUTPUT);
}

void loop() {
  // rød
  if (millis() % 1000 < 700) 
  {
    digitalWrite(ledRed, LOW);
  }
  else 
  {
    digitalWrite(ledRed, HIGH);
    Serial.println("LED red OFF");
  }
  
  // blå
  if (millis() % 700 < 300) 
    digitalWrite(ledBlue, LOW);
  else 
    digitalWrite(ledBlue, HIGH);
}
