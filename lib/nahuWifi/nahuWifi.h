#pragma once
#include <WiFi.h>
struct NahuWifiConfig {
    String ssid;
    String password;
    String hostname;

    uint32_t reconnectInterval = 10000;
    
    
};
class NahuWifi {
    public:
        void begin(const NahuWifiConfig& config);
        bool isConnected() const;
        IPAddress getIPAddress() const;
        void update();
       
    private:
        NahuWifiConfig _config;
        void handleReconnect();
       
        uint32_t _connectionStarted = 0;
        uint32_t _lastReconnectAttempt = 0;
        
};