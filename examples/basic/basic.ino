//#include <Arduino.h>
#include <nahuWifi.h>

const char* WIFI_SSID = "YOUR_WIFI_SSID";
const char* WIFI_PASSWORD = "YOUR_WIFI_PASSWORD";

const char* AP_SSID = "NahuWifi-Setup";
const char* AP_PASSWORD = "12345678";

NahuWifi wifi;

void setup() {
    Serial.begin(115200);
    delay(1000);

    NahuWifiConfig config;

    config.ssid = WIFI_SSID;
    config.password = WIFI_PASSWORD;
    config.hostname = "nahu-device";

    config.APHostname = AP_SSID;
    config.APPassword = AP_PASSWORD;

    config.timeout = 10000;
    config.reconnectInterval = 10000;

    wifi.begin(config);
}

void loop() {
    wifi.update();
}