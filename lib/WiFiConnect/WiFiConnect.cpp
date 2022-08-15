#include <WiFi.h>
#include <WiFiConnect.h>


void WiFiConnect::wifiConnect() {

    Serial.print("Connecting to WiFi");
    WiFi.mode(WIFI_AP);
    WiFi.begin(WIFI_NETWORK, WIFI_PASSWORD);

    unsigned long startAttemptTime = millis();

    //Connection Protocol
    while(WiFi.status() != WL_CONNECTED && (millis() - startAttemptTime) < WIFI_TIMEOUT) {
        Serial.println("...");
        delay(100);
    }
    if(WiFi.status() != WL_CONNECTED) {
        Serial.println("Failed, attempting again...");
        delay(5000); 
        }
    else{
        Serial.print("Connected: ");
        Serial.println(WiFi.localIP());
        }
    
}

void WiFiConnect::wifiDisconnect() {
  Serial.println("Disconnecting from WiFi...");
}

