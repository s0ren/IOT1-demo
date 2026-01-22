#include <Arduino.h>

#define potPin 35  // Define the analog pin connected to the potentiometer
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
  int potValue = analogRead(potPin);
  return moistSensor2Pct(potValue);
}

void setup() {
  Serial.begin(115200);
  delay(1000);
  pinMode(potPin, INPUT);   // Set the potentiometer pin as an input
  pinMode(relayPin, OUTPUT);  // Set the relay pin as an output
}

void loop() {
  // Reading potentiometer value
  // potValue = analogRead(potPin);
  // Serial.println(potValue);
  float soilMoisture = getMoistPct(potPin);
  Serial.print("Moisture: ");
  Serial.println(getMoistPct(soilMoisture));

  float threshold = 0.3; // 30% moisture threshold
  if (soilMoisture < threshold) {
    Serial.println("Soil is dry. Activating relay to water the plant.");
    digitalWrite(relayPin, LOW); // Turn the relay ON
    delay(200); // Water for 0.2 seconds
    digitalWrite(relayPin, HIGH);  // Turn the relay OFF
  }
  else {
    Serial.println("Soil moisture is sufficient. No watering needed.");
    digitalWrite(relayPin, HIGH);  // Ensure the relay is OFF
  }
  
  delay(5000); 

}
