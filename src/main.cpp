#include <Arduino.h>
#include <nahuWifi.h>
// put function declarations here:
NahuWifiConfig wifiConfig;


NahuWifi wifi;

void setup() {
  Serial.begin(115200);
  wifiConfig.ssid = "Fibra Nahuel";
  wifiConfig.password = "micaela1994";
  wifiConfig.hostname = "ESP32-BA";
  wifiConfig.reconnectInterval = 10000; // 10 seconds
  wifi.begin(wifiConfig);
  
}

void loop() {
 wifi.update();
}
