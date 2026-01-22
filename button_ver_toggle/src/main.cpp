#include <Arduino.h>

#define btn1 34
#define LEDblue 2
#define LEDred 4

bool ledToggle = false;
bool prevButtonState = LOW;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  delay(500); // Wait for Serial to initialize

  pinMode(LEDblue, OUTPUT);
  pinMode(LEDred, OUTPUT);
  pinMode(btn1, INPUT);
}

int debounceDelay = 50; // milliseconds
int lastDebounceTime = 0;

void loop() {
  
  if (prevButtonState == LOW && digitalRead(btn1) == HIGH) 
  {
    if (millis() - lastDebounceTime > debounceDelay) {
      ledToggle = !ledToggle;
      prevButtonState = HIGH;
      lastDebounceTime = millis();
    }
  }
  else  
  if (prevButtonState == HIGH && digitalRead(btn1) == LOW) 
  {
    if (millis() - lastDebounceTime > debounceDelay) {
      lastDebounceTime = millis();
      prevButtonState = LOW;
    }
  }


  if (ledToggle)
  {
    digitalWrite(LEDred, HIGH);
    digitalWrite(LEDblue, LOW);
    // Serial.println("ledToggle True - RED ON, BLUE OFF");
  }
  else 
  {
    digitalWrite(LEDred, LOW);
    digitalWrite(LEDblue, HIGH);
    // Serial.println("ledToggle False - RED OFF, BLUE ON");
  }
}
