#include <Arduino.h>
#include <WiFi.h>
#include "secrets.h"   // WIFI_SSID og WIFI_PASSWORD

// Konfiguration
const unsigned long FORBIND_TIMEOUT_MS = 20000;  // max ventetid i setup()
const unsigned long TJEK_INTERVAL_MS   = 30000;  // hvor tit loop() tjekker forbindelsen
const unsigned long RSSI_INTERVAL_MS   = 5000;   // hvor tit signalstyrken skrives ud

unsigned long sidsteTjek = 0;
unsigned long sidsteRssi = 0;

// Starter forbindelsen og venter højst timeoutMs.
// Returnerer true, hvis ESP32 kom på nettet.
bool forbindWiFi(unsigned long timeoutMs) {
  WiFi.mode(WIFI_STA);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);  // vender tilbage med det samme
  Serial.printf("Forbinder til %s", WIFI_SSID);

  unsigned long start = millis();
  while (WiFi.status() != WL_CONNECTED && millis() - start < timeoutMs) {
    delay(500);  // OK her: setup() har ikke andet at lave endnu
    Serial.print(".");
  }
  Serial.println();
  return WiFi.status() == WL_CONNECTED;
}

void skrivForbindelse() {
  Serial.print("Forbundet. IP-adresse: ");
  Serial.println(WiFi.localIP());
  Serial.printf("Signalstyrke: %d dBm\n", WiFi.RSSI());
}

void setup() {
  Serial.begin(115200);

  if (forbindWiFi(FORBIND_TIMEOUT_MS)) {
    skrivForbindelse();
  } else {
    // Vi giver ikke op: loop() prøver igen senere
    Serial.printf("Ingen forbindelse. Status: %d\n", WiFi.status());
  }
}

void loop() {
  unsigned long nu = millis();

  // Tjek forbindelsen med fast interval, uden at blokere loop()
  if (nu - sidsteTjek >= TJEK_INTERVAL_MS) {
    sidsteTjek = nu;
    if (WiFi.status() != WL_CONNECTED) {
      Serial.printf("WiFi er nede (status %d). Prøver igen.\n", WiFi.status());
      WiFi.reconnect();
    }
  }

  // Skriv signalstyrken ud, når vi er forbundet
  if (WiFi.status() == WL_CONNECTED && nu - sidsteRssi >= RSSI_INTERVAL_MS) {
    sidsteRssi = nu;
    Serial.printf("RSSI: %d dBm\n", WiFi.RSSI());
  }

  // Her kan programmet læse sensorer og knapper, også mens WiFi er nede
}
