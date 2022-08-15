#include "CurrentTime.h"
#include <WiFi.h>
#include <time.h>
#include "WiFiConnect.h"

WiFiConnect timeConnection;

int CurrentTime::getCurrentHour() {
 timeConnection.wifiConnect();

  configTime(timeOffset,daylightOffset,ntpServer);

  if(!getLocalTime(&timeInfo)){
    Serial.println("Failed to obtain time");
    return -1;
  }

  strftime(currentHour, 3, "%H", &timeInfo);
  int returnNum = atoi(currentHour);

  timeConnection.wifiDisconnect();
 
  return returnNum;
}

int CurrentTime::getCurrentMin() {
 timeConnection.wifiConnect();

  configTime(timeOffset,daylightOffset,ntpServer);

  if(!getLocalTime(&timeInfo)){
    Serial.println("Failed to obtain time");
    return -1;
  }

  strftime(currentMin, 3, "%M", &timeInfo);
  int returnNum = atoi(currentMin);

 timeConnection.wifiDisconnect();

  return returnNum;
}