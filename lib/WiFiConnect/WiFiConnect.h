#ifndef WIFICONNECT_H
#define WIFICONNECT_H

#include <WiFiClient.h>
#include "Wifi.h"

class WiFiConnect
{
    private: 
    #define WIFI_NETWORK "Your network"
    #define WIFI_PASSWORD "Your Password"
    #define WIFI_TIMEOUT 20000
       
    public:
    void wifiConnect();
    void wifiDisconnect();

};

#endif