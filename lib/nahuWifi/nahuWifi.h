#pragma once
#include <WiFi.h>

struct NahuWifiConfig {
    String ssid;
    String password;
    String hostname;
    uint32_t timeout = 10000; // 10 seconds
    uint32_t reconnectInterval = 10000;
    
    
};
enum class NahuWifiStatus {
    DISCONNECTED,
    CONNECTING,
    CONNECTED,
    AP_MODE
};
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
       
        uint32_t _connectionStarted = 0;
        uint32_t _lastReconnectAttempt = 0;
        
};