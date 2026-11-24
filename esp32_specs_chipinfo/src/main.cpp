#include <Arduino.h>
#include <esp_partition.h>  // ESP-IDF: læs partitionstabellen
#include <esp_ota_ops.h>    // ESP-IDF: hvilken app-partition kører lige nu

// Konfiguration
const unsigned long HEAP_INTERVAL_MS = 5000;  // hvor tit den ledige heap skrives ud

unsigned long sidsteHeapUdskrift = 0;

void skrivChipInfo() {
  Serial.println("--- Chip ---");
  Serial.printf("Model:       %s, revision %u\n", ESP.getChipModel(),
                (unsigned)ESP.getChipRevision());
  Serial.printf("Kerner:      %u\n", (unsigned)ESP.getChipCores());
  Serial.printf("CPU:         %lu MHz\n", (unsigned long)ESP.getCpuFreqMHz());
  Serial.printf("Software:    Arduino-ESP32 %s, ESP-IDF %s\n",
                ESP.getCoreVersion(), ESP.getSdkVersion());

  Serial.println("--- Hukommelse ---");
  Serial.printf("Flash:       %lu bytes\n", (unsigned long)ESP.getFlashChipSize());
  Serial.printf("Heap i alt:  %lu bytes\n", (unsigned long)ESP.getHeapSize());
  Serial.printf("Heap ledig:  %lu bytes\n", (unsigned long)ESP.getFreeHeap());
  Serial.printf("PSRAM:       %lu bytes\n", (unsigned long)ESP.getPsramSize());
  Serial.printf("Program:     %lu bytes\n", (unsigned long)ESP.getSketchSize());
  // Størrelsen på den app-partition, en ny version (OTA) ville blive skrevet til
  Serial.printf("Plads til ny version: %lu bytes\n",
                (unsigned long)ESP.getFreeSketchSpace());
}

// Skriver alle partitioner af én type (app eller data)
void skrivPartitioner(esp_partition_type_t type, const char *typeNavn) {
  const esp_partition_t *koerende = esp_ota_get_running_partition();

  esp_partition_iterator_t it = esp_partition_find(type, ESP_PARTITION_SUBTYPE_ANY, NULL);
  for (; it != NULL; it = esp_partition_next(it)) {
    const esp_partition_t *p = esp_partition_get(it);
    bool koererNu = (p->address == koerende->address);
    Serial.printf("%-9s %-5s 0x%06lX %5lu KB%s\n", p->label, typeNavn,
                  (unsigned long)p->address, (unsigned long)(p->size / 1024),
                  koererNu ? "  <- kører nu" : "");
  }
  esp_partition_iterator_release(it);  // it er NULL her, og det er tilladt
}

void setup() {
  Serial.begin(115200);
  delay(1000);  // giv Serial Monitor tid til at koble på, så starten ikke går tabt

  skrivChipInfo();

  Serial.println("--- Partitioner ---");
  skrivPartitioner(ESP_PARTITION_TYPE_APP, "app");
  skrivPartitioner(ESP_PARTITION_TYPE_DATA, "data");
}

void loop() {
  if (millis() - sidsteHeapUdskrift >= HEAP_INTERVAL_MS) {
    sidsteHeapUdskrift = millis();
    // getMinFreeHeap(): den laveste værdi siden opstart. Nærmer den sig 0, er der fare for nedbrud.
    Serial.printf("Heap ledig: %lu bytes (laveste: %lu)\n",
                  (unsigned long)ESP.getFreeHeap(), (unsigned long)ESP.getMinFreeHeap());
  }
}
