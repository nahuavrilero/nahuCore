#include <nahuWifi.h>

void NahuWifi::begin(const NahuWifiConfig& config) {
    _config = config;
    WiFi.mode(WIFI_STA);
    
  
    if (!_config.hostname.isEmpty()) {
        WiFi.setHostname(_config.hostname.c_str());
    }
    WiFi.begin(_config.ssid.c_str(), _config.password.c_str());
    Serial.print("\nConnecting to WiFi...");
    firstConnectionAttempt = true;
    _connectionStarted = millis();
}

void NahuWifi::update() {
    if (!isConnected() && (millis() - _connectionStarted >= _config.timeout)) {
        if (WiFi.getMode() != WIFI_AP_STA) {
            Serial.println("\nWiFi connection timed out. Switching to AP mode.");
            WiFi.mode(WIFI_AP_STA);
            WiFi.softAP("DummyTEST", "12345678");
            Serial.println("AP mode started. Connect to the ESP32-BA network. Password: 12345678");
        }
       
        handleReconnect();
    }
    else if (isConnected()) {
        if (firstConnectionAttempt) {
            Serial.println("\nConnected to WiFi!");
            Serial.print("IP Address: ");
            Serial.println(getIPAddress());
        }
        firstConnectionAttempt = false;
    }
}

void NahuWifi::handleReconnect() {
    uint32_t currentMillis = millis();
    if (currentMillis - _lastReconnectAttempt >= _config.reconnectInterval) {
        _lastReconnectAttempt = currentMillis;
        Serial.println("Attempting to reconnect to WiFi...");
        WiFi.begin(_config.ssid.c_str(), _config.password.c_str());
        _connectionStarted = currentMillis;
    }
}

bool NahuWifi::isConnected() const {
    return WiFi.status() == WL_CONNECTED;
}

IPAddress NahuWifi::getIPAddress() const {
    return WiFi.localIP();
}
NahuWifiStatus NahuWifi::getStatus() const {
    if (WiFi.getMode() == WIFI_AP_STA) {
        return NahuWifiStatus::AP_MODE;
    }
    else if (WiFi.status() == WL_CONNECTED) {
        return NahuWifiStatus::CONNECTED;
    }
    else if (WiFi.status() == WL_IDLE_STATUS || WiFi.status() == WL_DISCONNECTED) {
        return NahuWifiStatus::DISCONNECTED;
    }
    else {
        return NahuWifiStatus::CONNECTING;
    }
}