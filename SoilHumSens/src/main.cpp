#include <Arduino.h>

#define potPin 35  // Define the analog pin connected to the potentiometer
#define relayPin 4   // Define the digital pin connected to the relay

// variable for storing the potentiometer value
int potValue = 0;

void setup() {
  Serial.begin(115200);
  delay(1000);
  pinMode(potPin, INPUT);   // Set the potentiometer pin as an input
  pinMode(relayPin, OUTPUT);  // Set the relay pin as an output
}

void loop() {
  // Reading potentiometer value
  potValue = analogRead(potPin);
  Serial.println(potValue);

  digitalWrite(relayPin, LOW); // Turn the relay ON
  delay(200);
  digitalWrite(relayPin, HIGH);  // Turn the relay OFF
  delay(5000); 

}
