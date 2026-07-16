#include <nahuWifi.h>

void NahuWifi::begin(const NahuWifiConfig& config) {
    _config = config;
    WiFi.mode(WIFI_STA);
    
  
    if (!_config.hostname.isEmpty()) {
        WiFi.setHostname(_config.hostname.c_str());
    }
    WiFi.begin(_config.ssid.c_str(), _config.password.c_str());
    Serial.print("\nConnecting to WiFi...");
    for (int i=0; i<20; i++)  {
        delay(500);
        Serial.print(".");
    }
    if (WiFi.status() == WL_CONNECTED) {
        Serial.println("\nConnected to WiFi!");
        Serial.print("IP Address: ");
        Serial.println(WiFi.localIP());
    } else {
        Serial.println("\nFailed to connect to WiFi.");
    }
    _connectionStarted = millis();
}

void NahuWifi::update() {
    if (!isConnected()) {
        handleReconnect();
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