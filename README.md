# NahuCore

> ⚠️ **Work in Progress**

NahuCore es una colección de bibliotecas para ESP32 y ESP8266 diseñada para reducir el código repetitivo (boilerplate), unificar APIs y facilitar la reutilización de componentes entre proyectos.

El objetivo no es reemplazar las bibliotecas existentes, sino ofrecer una capa de abstracción simple y consistente sobre ellas.

> **Importante:** Durante esta etapa inicial no se garantiza compatibilidad entre versiones. La API puede cambiar sin previo aviso mientras el proyecto evoluciona.

---

# Objetivos

- Reducir el tiempo de inicio de nuevos proyectos.
- Centralizar funcionalidades comunes.
- Mantener una API simple y consistente.
- Evitar copiar y pegar código entre proyectos.
- Aprender y experimentar con el diseño de bibliotecas reutilizables.

---

# Estado del proyecto

## ✅ Implementado

### NahuWifi

- Conexión WiFi simplificada.
- Reconexión automática configurable.
- Configuración mediante `NahuWifiConfig`.
- Obtención de IP.
- Gestión básica de reconexión.
- AP Fallback.

> La documentación y los ejemplos de uso se encuentran en el directorio /examples/nahuWifi.

### NahuButton

- Detecta click, botón presionado/soltado.
- Debounce integrado.
  
---

## 🚧 En desarrollo

- NahuMqtt

---

# Roadmap

| Biblioteca | Estado | Descripción |
|------------|:------:|-------------|
| NahuWifi | ✅ | Gestión simplificada de WiFi |
| NahuButton | ✅ | Manejo de botones |
| NahuMqtt | 🚧 | Cliente MQTT |
| NahuConfig | 📋 | Persistencia de configuración |
| NahuRelay | 📋 | Control de relés |
| NahuLogger | 📋 | Sistema de logs |
| NahuDisplay | 📋 | Abstracción para displays |
| NahuSensor | 📋 | Lectura unificada de sensores |
| NahuOTA | 📋 | Actualizaciones OTA |
| NahuWebServer | 📋 | Servidor web |
| NahuBLE | 📋 | Bluetooth Low Energy |
| NahuLoRa | 📋 | Comunicación LoRa |
| NahuHomeAssistant | 📋 | Integración con Home Assistant |

---

# Filosofía

NahuCore no busca reemplazar las bibliotecas existentes, sino proporcionar una capa de abstracción sencilla y consistente sobre ellas para acelerar el desarrollo de proyectos.

Siempre que sea posible se priorizará:

- APIs simples.
- Bajo acoplamiento.
- Configuración sencilla.
- Reutilización.
- Código fácil de leer y mantener.

---

# Compatibilidad

Actualmente orientado a:

- ESP32
- ESP8266 (cuando sea posible)

Frameworks soportados:

- Arduino IDE
- PlatformIO

---

# Contribuciones

Las contribuciones son bienvenidas.

Si querés agregar una nueva funcionalidad, corregir un bug o mejorar la documentación, hacé un fork del repositorio y abrí un Pull Request.

Si tenés una idea para una nueva biblioteca o una mejora en la API, también podés abrir un Issue para discutirla.

---

# Licencia

Este proyecto se distribuye bajo la licencia MIT.
