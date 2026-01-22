#include <Arduino.h>

#define btn1 34
#define LEDblue 2
#define LEDred 4

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  delay(500); // Wait for Serial to initialize

  pinMode(LEDblue, OUTPUT);
  pinMode(LEDred, OUTPUT);
  pinMode(btn1, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (digitalRead(btn1) == HIGH) 
  {
    digitalWrite(LEDred, HIGH);
    digitalWrite(LEDblue, LOW);
    Serial.println("Button HIGH - RED ON, BLUE OFF");
  }
  else 
  {
    digitalWrite(LEDred, LOW);
    digitalWrite(LEDblue, HIGH);
    Serial.println("Button LOW - RED OFF, BLUE ON");
  }
}
