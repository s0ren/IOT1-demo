#include <Arduino.h>

#define moistPin 35  // Define the analog pin connected to the potentiometer
#define pumpPin 4   // Define the digital pin connected to the relay, and pump
#define tankLevelPin 33 // Define the analog pin connected to the tank level sensor

#define DEBUG

void setup() {
  // put your setup code here, to run once:
  // int result = myFunction(2, 3);
  Serial.begin(115200);
  pinMode(moistPin, INPUT);   // Set the potentiometer pin as an input
  pinMode(pumpPin, OUTPUT);  // Set the relay pin as an output
  pinMode(tankLevelPin, INPUT_PULLDOWN); // Set the tank level pin as an input
}

void loop() {

  // aflæse sensorer
  // moitsture sensor
  int moistLevel = analogRead(moistPin);
  #ifdef DEBUG
  Serial.print("Moisture Sensor Value: ");  
  Serial.println(moistLevel);
  #endif
  // vandtank niveau sensor
  bool tankLevel = !digitalRead(tankLevelPin);

  // hvis jorden er tør og der er vand i tanken
  if (moistLevel > 2000)
  {
    Serial.println("Soil is dry. Activating relay to water the plant.");
    if(tankLevel == LOW) {
      Serial.println("Cannot water the plant as the water tank is empty.");
    }
    else 
    {
       //   aktivere relay og pumpe i et kort øjeblik 
      digitalWrite(pumpPin, LOW); // Turn the relay ON
      delay(500); // Water for 0.5 seconds
      digitalWrite(pumpPin, HIGH);  // Turn the relay OFF
    }
  }
  else 
  {
    Serial.println("Soil moisture is sufficient. No watering needed.");
  }
 
  // vent et stykke tid, til næste aflæsning
  delay(1000); // 1 seconds delay

/*
  bool tankLevel = !digitalRead(tankLevelPin);
  if (tankLevel == LOW) {
    Serial.println("Water tank is empty! Please refill.");
  }
  else {
    Serial.println("Water tank has sufficient water.");
  }

  // put your main code here, to run repeatedly:
  int moitLevel = analogRead(moistPin);
  Serial.print("Potentiometer Value: ");  
  Serial.println(moitLevel);

  Serial.println("Activating relay and pump to water the plant.");
  digitalWrite(pumpPin, LOW); // Turn the relay ON
  delay(500); // Water for 0.5 seconds
  Serial.println("Deactivating relay and pump.");
  digitalWrite(pumpPin, HIGH);  // Turn the relay OFF

  delay(1000); // Wait for a second before reading again
  */
}
