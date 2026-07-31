# nahuCore

![GitHub release](https://img.shields.io/github/v/release/nahuavrilero/nahuCore)
![Licencia](https://img.shields.io/badge/licencia-MIT-blue)
![Plataformas](https://img.shields.io/badge/plataformas-ESP32%20%7C%20ESP8266-informational)
![Frameworks](https://img.shields.io/badge/frameworks-Arduino%20IDE%20%7C%20PlatformIO-lightgrey)

> ⚠️ **Work in Progress** — durante esta etapa inicial no se garantiza compatibilidad entre versiones. La API puede cambiar sin previo aviso mientras el proyecto evoluciona.

NahuCore es una colección de bibliotecas para ESP32 y ESP8266 diseñada para reducir el código repetitivo (boilerplate), unificar APIs y facilitar la reutilización de componentes entre proyectos.

El objetivo no es reemplazar las bibliotecas existentes, sino ofrecer una capa de abstracción simple y consistente sobre ellas.

NahuCore se instala como un único paquete, pero cada biblioteca puede utilizarse de forma independiente incluyendo solo los módulos necesarios para cada proyecto:

```cpp
#include <nahuWifi.h>
#include <nahuButton.h>
```

---

## Instalación

**PlatformIO** — agregá la dependencia en tu `platformio.ini`:

```ini
lib_deps =
    https://github.com/nahuavrilero/nahuCore.git
```

**Arduino IDE** — descargá el repositorio como `.zip` (`Code` → `Download ZIP`) e instalalo desde `Sponsor → Include Library → Add .ZIP Library...`.

---

## Ejemplo de uso: NahuWifi

Conexión WiFi con reconexión automática y fallback a modo Access Point si falla:

```cpp
// #include <Arduino.h> // Descomentar esta línea si usás PlatformIO. Dejar comentada si usás Arduino IDE.
#include <nahuWifi.h>

const char* WIFI_SSID = "YOUR_WIFI_SSID";
const char* WIFI_PASSWORD = "YOUR_WIFI_PASSWORD";

const char* AP_SSID = "NahuWifi-Setup";
const char* AP_PASSWORD = "12345678";

NahuWifi wifi;

void setup() {
    Serial.begin(115200);
    delay(1000);

    NahuWifiConfig config;

    config.ssid = WIFI_SSID;
    config.password = WIFI_PASSWORD;
    config.hostname = "nahu-device";

    config.APHostname = AP_SSID;
    config.APPassword = AP_PASSWORD;

    config.timeout = 10000;
    config.reconnectInterval = 10000;

    wifi.begin(config);
}

void loop() {
    wifi.update();
}
```

Más ejemplos disponibles en [`/examples`](./examples).

---

## Objetivos

- Reducir el tiempo de inicio de nuevos proyectos.
- Centralizar funcionalidades comunes.
- Mantener una API simple y consistente.
- Evitar copiar y pegar código entre proyectos.
- Aprender y experimentar con el diseño de bibliotecas reutilizables.

---

## Roadmap

| Biblioteca        | Estado | Descripción                    |
| ------------------ | :----: | ------------------------------- |
| NahuWifi          |   ✅   | Gestión simplificada de WiFi. Conexión, reconexión automática configurable, `NahuWifiConfig`, obtención de IP, AP Fallback. |
| NahuButton        |   ✅   | Manejo de botones: detección de presión, liberación, clic y pulsación larga, con debounce integrado. |
| NahuMqtt          |   🚧   | Cliente MQTT.                   |
| NahuConfig        |   📋   | Persistencia de configuración.  |
| NahuRelay         |   📋   | Control de relés.               |
| NahuLogger        |   📋   | Sistema de logs.                |
| NahuDisplay       |   📋   | Abstracción para displays.      |
| NahuSensor        |   📋   | Lectura unificada de sensores.  |
| NahuOTA           |   📋   | Actualizaciones OTA.            |
| NahuWebServer     |   📋   | Servidor web.                   |
| NahuBLE           |   📋   | Bluetooth Low Energy.           |
| NahuLoRa          |   📋   | Comunicación LoRa.              |
| NahuHomeAssistant |   📋   | Integración con Home Assistant. |

✅ Implementado &nbsp;&nbsp; 🚧 En desarrollo &nbsp;&nbsp; 📋 Planeado

---

## Filosofía

NahuCore no busca reemplazar las bibliotecas existentes, sino proporcionar una capa de abstracción sencilla y consistente sobre ellas para acelerar el desarrollo de proyectos.

Siempre que sea posible se priorizará:

- APIs simples.
- Bajo acoplamiento.
- Configuración sencilla.
- Reutilización.
- Código fácil de leer y mantener.

---

## Compatibilidad

Actualmente orientado a:

- ESP32
- ESP8266 (cuando sea posible)

Frameworks soportados:

- Arduino IDE
- PlatformIO

---

## Contribuciones

Las contribuciones son bienvenidas.

Si querés agregar una nueva funcionalidad, corregir un bug o mejorar la documentación, hacé un fork del repositorio y abrí un Pull Request.

Si tenés una idea para una nueva biblioteca o una mejora en la API, también podés abrir un [Issue](https://github.com/nahuavrilero/nahuCore/issues) para discutirla.

---

## Licencia

Este proyecto se distribuye bajo la licencia MIT.
