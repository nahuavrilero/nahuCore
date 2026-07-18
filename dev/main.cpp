//Library manages WiFi connection and automatically switches to AP mode if connection fails. It also provides a simple interface to check the connection status and get the IP address.
#include <Arduino.h>
#include <nahuWifi.h>
#include <secrets.h>

NahuWifiConfig wifiConfig;
NahuWifi wifi;

void setup() {
  Serial.begin(115200);
  wifiConfig.ssid = WIFI_SSID; //Input your WiFi SSID here
  wifiConfig.password = WIFI_PASSWORD; //Input your WiFi password here
  wifiConfig.hostname = ""; //Input your device hostname here (optional)
  wifiConfig.APHostname = AP_SSID; //Input your WiFi AP hostname hereS
  wifiConfig.APHostname = AP_PASSWORD; //Input your WiFi AP password here
  wifiConfig.reconnectInterval = 10000; //time interval between reconnection attempts (in milliseconds)
  wifiConfig.timeout = 10000; // Connect timeout before switching to AP mode (in milliseconds)
  wifi.begin(wifiConfig); //Initialize the WiFi connection with the provided configuration. Call it before calling wifi.update() in the loop() function.
  
}

void loop() {
 wifi.update(); //Updates the WiFi connection status and handles reconnection. Also prints on connection and disconnection to the Serial monitor.

 //available functions:
 //wifi.isConnected(); // (bool) Returns true if connected to WiFi, false otherwise
 //wifi.getIPAddress(); //Returns the IP address of the device as an IPAddress object
 //wifi.getStatus(); //Returns the current status of the WiFi connection as a NahuWifiStatus enum value (DISCONNECTED, CONNECTING, CONNECTED, AP_MODE)


}
