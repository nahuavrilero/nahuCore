#include <Arduino.h>
#include <nahuWifi.h>
#include <secrets.h>
// put function declarations here:
NahuWifiConfig wifiConfig;


NahuWifi wifi;

void setup() {
  Serial.begin(115200);
  wifiConfig.ssid = WIFI_SSID; //Input your WiFi SSID here
  wifiConfig.password = WIFI_PASSWORD; //Input your WiFi password here
  wifiConfig.hostname = AP_SSID; //Input your WiFi hostname here
  wifiConfig.APHostname = AP_PASSWORD; //Input your WiFi AP password here
  wifiConfig.reconnectInterval = 10000; // 10 seconds
  wifiConfig.timeout = 10000; // 10 seconds
  wifi.begin(wifiConfig);
  
}

void loop() {
 wifi.update();
}
