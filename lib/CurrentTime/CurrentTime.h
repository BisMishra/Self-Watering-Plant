#ifndef CURRENTTIME_H
#define CURRENTIME_H

#include <WiFi.h>
#include <time.h>
#include "WiFiConnect.h"

class CurrentTime {

    private:
        const char* ntpServer = "pool.ntp.org";
        const long timeOffset = -21600;
        const int daylightOffset = 3600;

    public:
        struct tm timeInfo;   
        char currentHour[3];
        char currentMin[3];

        //Both functions will reach out to the ntp server to get the current time related to the timezone
        int getCurrentHour();
        int getCurrentMin();
    
};
#endif