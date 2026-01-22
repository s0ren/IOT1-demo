#include <Arduino.h>

#define INTERNAL 2 // GPIO2 is often connected to the internal LED on ESP32 boards

// const int ledPin = 2;
// constexpr int minIntLED = 2;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  delay(500); // Wait for Serial to initialize  
  Serial.println("Hello, ESP32!");

  pinMode(INTERNAL, OUTPUT);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.write("LED ON\n");
  digitalWrite(INTERNAL, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(500);                      // wait for a second
  Serial.write("LED OFF\n");
  digitalWrite(INTERNAL, LOW);    // turn the LED off by making the voltage LOW   
  delay(500);                      // wait for a second
}
