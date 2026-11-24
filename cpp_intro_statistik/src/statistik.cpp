#include "statistik.h"  // så compileren tjekker, at definitionerne passer med deklarationerne

float gennemsnit(const int data[], int antal) {
  if (antal <= 0) {
    return 0.0f;  // undgå division med 0
  }
  long sum = 0;
  for (int i = 0; i < antal; i++) {
    sum += data[i];
  }
  return (float)sum / antal;
}

int stoersteVaerdi(const int data[], int antal) {
  if (antal <= 0) {
    return 0;  // tomt array: data[0] findes ikke
  }
  int stoerst = data[0];
  for (int i = 1; i < antal; i++) {
    if (data[i] > stoerst) {
      stoerst = data[i];
    }
  }
  return stoerst;
}
