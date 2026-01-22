#include <Arduino.h>
#include <OneButton.h>

#define BUTTON_PIN 34
#define LEDblue 2
#define LEDred 4

OneButton btn;

bool ledToggle = false;

static void handleClick() {
  // Serial.println("Clicked!");
  ledToggle = !ledToggle;
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

void setup() {
  Serial.begin(115200);
  btn.setup(BUTTON_PIN, INPUT, false);
  btn.attachClick(handleClick);
  
  pinMode(LEDblue, OUTPUT);
  pinMode(LEDred, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  btn.tick();
}
