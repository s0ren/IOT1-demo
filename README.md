# Demo er til faget IOT 1. del

## Eksempler fra undervisningssiderne

Hvert projekt er et eksempel fra en side på [fagets site](https://s0ren.github.io/FAG_17682_IoT_II/). Koden er den samme som på siden; retter du den ene, så ret også den anden.

Alle projekter bruger `platform = espressif32@8.0.0` og kortet ESP32-DEVKIT-V1. De kompilerer (24. nov. 2026), men er ikke alle testet på hardware endnu.

| Side | Projekt | Indhold |
|---|---|---|
| [Hello World](https://s0ren.github.io/FAG_17682_IoT_II/Grundlag/hello_world.html) | [`hello_world_serial`](hello_world_serial) | skriver "Hej fra ESP32!" i Serial Monitor |
|  | [`hello_world_blink_delay`](hello_world_blink_delay) | blinker den indbyggede lysdiode med delay() |
|  | [`hello_world_blink_millis`](hello_world_blink_millis) | blinker uden at blokere, med millis() |
| [PlatformIO](https://s0ren.github.io/FAG_17682_IoT_II/Grundlag/platformio.html) | [`platformio_test`](platformio_test) | test af build og upload |
| [Intro til C++](https://s0ren.github.io/FAG_17682_IoT_II/Grundlag/cpp_intro.html) | [`cpp_intro_statistik`](cpp_intro_statistik) | et program i tre filer: .h og .cpp |
|  | [`cpp_intro_pointere`](cpp_intro_pointere) | pointere og referencer |
| [ESP32 specifikationer](https://s0ren.github.io/FAG_17682_IoT_II/Grundlag/esp32_specs.html) | [`esp32_specs_chipinfo`](esp32_specs_chipinfo) | ESP32 fortæller om chip, hukommelse og partitioner |
| [Debouncing](https://s0ren.github.io/FAG_17682_IoT_II/Grundlag/debouncing.html) | [`debouncing_uden`](debouncing_uden) | knap uden debouncing |
|  | [`debouncing_ezbutton`](debouncing_ezbutton) | knap med ezButton |
| [Knapper](https://s0ren.github.io/FAG_17682_IoT_II/Grundlag/knapper.html) | [`knapper_knap_led`](knapper_knap_led) | lysdioden lyser, mens knappen holdes nede |
| [Lysdioder](https://s0ren.github.io/FAG_17682_IoT_II/Grundlag/lysdioder.html) | [`lysdioder_blink_millis`](lysdioder_blink_millis) | blink med millis() |
|  | [`lysdioder_fade_pwm`](lysdioder_fade_pwm) | fade med PWM (ledcWrite) |
| [Potentiometer](https://s0ren.github.io/FAG_17682_IoT_II/Grundlag/potentiometer.html) | [`potentiometer_laes`](potentiometer_laes) | læs potentiometeret med ADC |
| [Standardopstilling](https://s0ren.github.io/FAG_17682_IoT_II/Grundlag/standardopstilling.html) | [`standardopstilling_test`](standardopstilling_test) | test af knap, lysdiode og potentiometer |
| [WiFi](https://s0ren.github.io/FAG_17682_IoT_II/Grundlag/wifi.html) | [`wifi_forbind`](wifi_forbind) | forbind med tidsgrænse og genforbind; kopiér include/secrets_eksempel.h til secrets.h |
