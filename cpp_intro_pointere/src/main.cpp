#include <Arduino.h>

// Forward declarations: definitionerne står efter loop()
void fordoblKopi(int tal);
void fordoblPointer(int* tal);
void fordoblReference(int& tal);

void setup() {
  Serial.begin(115200);

  int maaling = 21;
  int* p = &maaling;  // p peger på maaling

  Serial.printf("maaling   = %d\n", maaling);
  Serial.printf("&maaling  = %p  (adressen)\n", (void*)&maaling);
  Serial.printf("p         = %p  (samme adresse)\n", (void*)p);
  Serial.printf("*p        = %d  (værdien, p peger på)\n", *p);
  Serial.printf("sizeof(int) = %u, sizeof(int*) = %u\n",
                (unsigned)sizeof(int), (unsigned)sizeof(int*));

  *p = 42;  // ændrer maaling gennem pointeren
  Serial.printf("Efter *p = 42:          maaling = %d\n", maaling);

  fordoblKopi(maaling);  // får en kopi: maaling ændres ikke
  Serial.printf("Efter fordoblKopi:      maaling = %d\n", maaling);

  fordoblPointer(&maaling);  // får adressen: maaling ændres
  Serial.printf("Efter fordoblPointer:   maaling = %d\n", maaling);

  fordoblReference(maaling);  // får en reference: maaling ændres
  Serial.printf("Efter fordoblReference: maaling = %d\n", maaling);
}

void loop() {
  // Intet her: eksemplet kører kun én gang i setup()
}

void fordoblKopi(int tal) {
  tal = tal * 2;  // ændrer kun den lokale kopi
}

void fordoblPointer(int* tal) {
  *tal = *tal * 2;  // ændrer værdien på kalderens adresse
}

void fordoblReference(int& tal) {
  tal = tal * 2;  // tal ER kalderens variabel
}
