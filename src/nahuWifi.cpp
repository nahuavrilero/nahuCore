#include <nahuWifi.h>
#define SERIAL_PREFIX "[nahuWifi] "
void NahuWifi::begin(const NahuWifiConfig& config) {
    _config = config;
    WiFi.mode(WIFI_STA);
    
  
    if (!_config.hostname.isEmpty()) {
        WiFi.setHostname(_config.hostname.c_str());
    }
    WiFi.begin(_config.ssid.c_str(), _config.password.c_str());
    Serial.println(SERIAL_PREFIX "Connecting to WiFi...");
    
    _connectionStarted = millis();
}

void NahuWifi::update() {
    if (!isConnected() && _wasConnected) {
        _wasConnected = false;
        _connectionStarted = millis(); // Reset the connection start time for the next attempt
    }
    else if (!isConnected() && (millis() - _connectionStarted >= _config.timeout)) {
        if (!_apStarted) {
            Serial.printf("\n" SERIAL_PREFIX "Failed to connect to WiFi. Starting AP mode...\n");
            startAP();
        }
        handleReconnect();
    }
    else if(!isConnected() && !_wasConnected) {
        handleReconnect();  
    }
    
    else if (isConnected()) {
        if (!_wasConnected) {
            Serial.println(SERIAL_PREFIX "Connected to WiFi!");
            Serial.print(SERIAL_PREFIX "IP Address: ");
            Serial.print(getIPAddress());
            _wasConnected = true;
        }
        if (_apStarted){
            WiFi.softAPdisconnect(true);
            WiFi.mode(WIFI_STA);
            _apStarted = false;
        }
    }
}

void NahuWifi::handleReconnect() {
    uint32_t currentMillis = millis();
    if (currentMillis - _lastReconnectAttempt >= _config.reconnectInterval && getStatus() != NahuWifiStatus::CONNECTING) {
        _lastReconnectAttempt = currentMillis;
        Serial.println(SERIAL_PREFIX "Attempting to reconnect to WiFi...");
        WiFi.begin(_config.ssid.c_str(), _config.password.c_str());
        
    }
}

bool NahuWifi::isConnected() const {
    return WiFi.status() == WL_CONNECTED;
}

IPAddress NahuWifi::getIPAddress() const {
    return WiFi.localIP();
}
NahuWifiStatus NahuWifi::getStatus() const {
    wl_status_t wifiStatus = WiFi.status();
    if (WiFi.getMode() == WIFI_AP && !isConnected()) {
        return NahuWifiStatus::AP_MODE;
    }
    else if (isConnected()) {
        return NahuWifiStatus::CONNECTED;
    }
    else if (wifiStatus == WL_IDLE_STATUS || 
             wifiStatus == WL_DISCONNECTED || 
             wifiStatus == WL_CONNECTION_LOST || 
             wifiStatus == WL_NO_SSID_AVAIL || 
             wifiStatus == WL_CONNECT_FAILED
            ){
        return NahuWifiStatus::DISCONNECTED;
    }
    else {
        return NahuWifiStatus::CONNECTING;
    }
}
bool NahuWifi::startAP(){
    if (WiFi.getMode() != WIFI_AP_STA) {
        WiFi.mode(WIFI_AP_STA);
    }

    _apStarted = WiFi.softAP(_config.APHostname.c_str(), _config.APPassword.c_str());
   
    
    
    if (!_apStarted) {
        Serial.println(SERIAL_PREFIX "Failed to start AP mode.");
        return false;
    }
    Serial.printf(SERIAL_PREFIX "AP mode started. Connect to the %s network. Password: %s\nIP: ", _config.APHostname.c_str(), _config.APPassword.c_str());
    Serial.println(WiFi.softAPIP());
    return true;    
}