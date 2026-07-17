#include <Arduino.h>
#include <nahuWifi.h>
#include <secrets.h>
// put function declarations here:
NahuWifiConfig wifiConfig;


NahuWifi wifi;

void setup() {
  Serial.begin(115200);
  wifiConfig.ssid = WIFI_SSID;
  wifiConfig.password = WIFI_PASSWORD;
  wifiConfig.hostname = "ESP32-BA";
  wifiConfig.reconnectInterval = 10000; // 10 seconds
  wifiConfig.timeout = 10000; // 10 seconds
  wifi.begin(wifiConfig);
  
}

void loop() {
 wifi.update();
}
