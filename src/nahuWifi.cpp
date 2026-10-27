#include <nahuWifi.h>
#define SERIAL_PREFIX "[nahuWifi] "

void NahuWifi::begin(const NahuWifiConfig& config) {
    _config = config;
    _wasConnected = false;
    _apStarted = false;
    _connectionStarted = millis();
    _lastReconnectAttempt = _connectionStarted;
#if defined(ESP8266)
    WiFi.persistent(false); // los reintentos no deben escribir la flash del SDK
#endif
    WiFi.mode(WIFI_STA);
    if (!_config.hostname.isEmpty()) {
#if defined(ESP8266)
        WiFi.hostname(_config.hostname);
#else
        WiFi.setHostname(_config.hostname.c_str());
#endif
    }
    if (_config.ssid.isEmpty()) {
        startAP();
        return;
    }
    WiFi.begin(_config.ssid.c_str(), _config.password.c_str());
    Serial.println(SERIAL_PREFIX "Connecting to WiFi...");
}

void NahuWifi::update() {
    const uint32_t now = millis();
    if (isConnected()) {
        if (!_wasConnected) {
            Serial.print(SERIAL_PREFIX "Connected. IP: ");
            Serial.println(getIPAddress());
            _wasConnected = true;
        }
        if (_apStarted) {
            WiFi.softAPdisconnect(true);
            WiFi.mode(WIFI_STA);
            _apStarted = false;
        }
        return;
    }
    if (_wasConnected) {
        _wasConnected = false;
        _connectionStarted = now;
        _lastReconnectAttempt = now;
        Serial.println(SERIAL_PREFIX "WiFi disconnected.");
    }
    if (!_apStarted && now - _connectionStarted >= _config.timeout) startAP();
    if (!_config.ssid.isEmpty()) handleReconnect();
}

void NahuWifi::handleReconnect() {
    const uint32_t now = millis();
    const uint32_t interval = _config.reconnectInterval ? _config.reconnectInterval : 10000;
    // Reintentar aunque status() siga en WL_IDLE_STATUS/CONNECTING.
    if (now - _lastReconnectAttempt < interval) return;
    _lastReconnectAttempt = now;
    Serial.println(SERIAL_PREFIX "Retrying WiFi...");
    WiFi.disconnect(false);
    WiFi.begin(_config.ssid.c_str(), _config.password.c_str());
}

bool NahuWifi::isConnected() const { return WiFi.status() == WL_CONNECTED; }
IPAddress NahuWifi::getIPAddress() const { return WiFi.localIP(); }

NahuWifiStatus NahuWifi::getStatus() const {
    if (isConnected()) return NahuWifiStatus::CONNECTED;
    if (_apStarted) return NahuWifiStatus::AP_MODE;
    if (_config.ssid.isEmpty()) return NahuWifiStatus::DISCONNECTED;
    return NahuWifiStatus::CONNECTING;
}

bool NahuWifi::startAP() {
    if (_config.APHostname.isEmpty()) return false;
    if (!_config.APPassword.isEmpty() && _config.APPassword.length() < 8) {
        Serial.println(SERIAL_PREFIX "AP password must have at least 8 characters.");
        return false;
    }
    WiFi.mode(WIFI_AP_STA);
    _apStarted = _config.APPassword.isEmpty()
        ? WiFi.softAP(_config.APHostname.c_str())
        : WiFi.softAP(_config.APHostname.c_str(), _config.APPassword.c_str());
    if (!_apStarted) {
        Serial.println(SERIAL_PREFIX "Failed to start AP.");
        return false;
    }
    Serial.print(SERIAL_PREFIX "Fallback AP active. IP: ");
    Serial.println(WiFi.softAPIP());
    return true;
}
