# NahuCore

> ⚠️ **Work in Progress**
>
> Biblioteca personal en desarrollo para proyectos con ESP32/ESP8266.
> El objetivo es reducir código repetitivo (boilerplate), unificar APIs entre proyectos y reutilizar módulos que utilizo frecuentemente.
>
> No se garantiza compatibilidad entre versiones. La API puede cambiar sin previo aviso mientras el proyecto evoluciona.

## Objetivos

- Reducir el tiempo de inicio de nuevos proyectos.
- Centralizar funcionalidades comunes.
- Mantener una API simple y consistente.
- Evitar copiar y pegar el mismo código entre proyectos.
- Aprender y experimentar con el diseño de bibliotecas reutilizables.

## Estado actual

### ✅ Implementado

- **NahuWifi**
  - Conexión WiFi
  - Reconexión automática
  - Configuración mediante `NahuWifiConfig`
  - Obtención de IP
  - Gestión básica de reconexión

### 🚧 En desarrollo

- Mejoras en la lógica de reconexión
- Modo AP de respaldo (Fallback AP)
- Ejemplos de uso
- Documentación

## Bibliotecas planificadas

- NahuWifi
- NahuMqtt
- NahuConfig
- NahuRelay
- NahuLogger
- NahuButton
- NahuDisplay
- NahuSensor
- NahuOTA
- NahuWebServer
- NahuBLE
- NahuLoRa
- NahuHomeAssistant

## Filosofía del proyecto

La idea no es reemplazar las bibliotecas existentes, sino construir una capa de abstracción simple y reutilizable sobre ellas, orientada a mis propios proyectos.

Siempre que sea posible se priorizará:

- APIs simples
- Bajo acoplamiento
- Configuración sencilla
- Reutilización
- Código fácil de leer y mantener

## Compatibilidad

Actualmente orientado a:

- ESP32
- ESP8266 (cuando sea posible)

Framework:

- Arduino

## Licencia

Por el momento este proyecto se publica únicamente con fines personales y de aprendizaje.
