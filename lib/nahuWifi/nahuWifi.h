#pragma once
#include <WiFi.h>

struct NahuWifiConfig {
    String ssid;
    String password;
    String hostname;
    uint32_t timeout = 10000; // 10 seconds
    uint32_t reconnectInterval = 10000;
    String APHostname;
    String APPassword;
    
    
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
        bool startAP();
        uint32_t _connectionStarted = 0;
        uint32_t _lastReconnectAttempt = 0;
        bool _firstConnectionAttempt = true;
        bool _wasConnected = false;
        bool _apStarted = false;
        
};