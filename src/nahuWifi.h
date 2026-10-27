#pragma once
#include <Arduino.h>
#if defined(ESP8266)
  #include <ESP8266WiFi.h>
#elif defined(ESP32)
  #include <WiFi.h>
#else
  #error NahuWifi requires ESP8266 or ESP32
#endif

struct NahuWifiConfig {
    String ssid;
    String password;
    String hostname;
    uint32_t timeout = 10000;
    uint32_t reconnectInterval = 10000;
    String APHostname;
    String APPassword;
};
enum class NahuWifiStatus { DISCONNECTED, CONNECTING, CONNECTED, AP_MODE };
class NahuWifi {
public:
    void begin(const NahuWifiConfig& config);
    bool isConnected() const;
    IPAddress getIPAddress() const;
    void update();
    NahuWifiStatus getStatus() const;
private:
    NahuWifiConfig _config;
    void handleReconnect();
    bool startAP();
    uint32_t _connectionStarted = 0;
    uint32_t _lastReconnectAttempt = 0;
    bool _wasConnected = false;
    bool _apStarted = false;
};
