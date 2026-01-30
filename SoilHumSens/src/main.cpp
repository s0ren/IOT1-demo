#include <Arduino.h>

#define moistPin 35  // Define the analog pin connected to the potentiometer
#define tankLevelPin 33 // Define the analog pin connected to the tank level sensor
#define relayPin 4   // Define the digital pin connected to the relay

// variable for storing the potentiometer value
int potValue = 0;

float moistSensor2Pct(int sensorValue) {
  // Map the sensor value (0-4095) to a percentage (0-100)
  float min = 1200;  // Dry soil value
  float max = 4095;  // Wet soil value
  if (sensorValue < min) 
    sensorValue = min;
  return 1.0 - ((sensorValue - min) / (max - min)) ;
}

float getMoistPct(int pin) {
  int potValue = analogRead(moistPin);
  return moistSensor2Pct(potValue);
}

void setup() {
  Serial.begin(115200);
  delay(1000);
  pinMode(moistPin, INPUT);   // Set the potentiometer pin as an input
  pinMode(tankLevelPin, INPUT_PULLDOWN); // Set the tank level pin as an input
  pinMode(relayPin, OUTPUT);  // Set the relay pin as an output
}

void loop() {
  
  bool tankLevel = !digitalRead(tankLevelPin);

  if (tankLevel == LOW) {
    Serial.println("Water tank is empty! Please refill.");
  }
  else {
    Serial.println("Water tank has sufficient water.");
  }

  
  float soilMoisture = getMoistPct(moistPin);
  Serial.print("Moisture: ");
  Serial.println(getMoistPct(soilMoisture));

  float threshold = 0.20; // % moisture threshold
  
  if (soilMoisture < threshold) {
    Serial.println("Soil is dry. Activating relay to water the plant.");
    if(tankLevel == LOW) {
      Serial.println("Cannot water the plant as the water tank is empty.");
    }
    else 
    {
      digitalWrite(relayPin, LOW); // Turn the relay ON
      delay(200); // Water for 0.2 seconds
      digitalWrite(relayPin, HIGH);  // Turn the relay OFF
    }
  }
  else {
    Serial.println("Soil moisture is sufficient. No watering needed.");
    digitalWrite(relayPin, HIGH);  // Ensure the relay is OFF
  }
  
  delay(5000); 

}
