/*
    Self Watering Plant code for ESP32
    Summer 2022
    Bis Mishra

*/
#include <Arduino.h>
#include <time.h>
#include "Wifi.h"
#include "ScheduleProt.h"
#include "WaterProt.h"
#include "CurrentTime.h"

//These can be adjusted depending on your requirements
#define DEEP_SLEEP_TIME 1800000000
#define WATER_DURATION 1000000
#define MOTORPIN 23

//This class takes the data from other classes and calculates watering times
WaterProt waterProtocol;
//This class connects to the ntp server to get the current time
CurrentTime currentTime;
//This class creates an http server for the app to connect to
ScheduleProt newSchedule;

//This saves the water state between deep sleep cycles
RTC_DATA_ATTR int waterState = -1;

void startDeepSleep() {
    Serial.println("Entering Deep Sleep...");
    esp_sleep_enable_timer_wakeup(DEEP_SLEEP_TIME);
    delay(100);
    esp_deep_sleep_start();
}

void setup() {
    Serial.begin(9600);
    
    if (waterState == - 1){
        waterState = newSchedule.scheduleWatering();
    }

    pinMode(MOTORPIN, OUTPUT);

}

void loop() {

    int currentHour = -1;
    while (currentHour == -1) {
    currentHour = currentTime.getCurrentHour();
    }

    if (waterProtocol.getWateringHour(waterState) == currentHour){
            waterProtocol.waterPlant(MOTORPIN, WATER_DURATION);    
        }
    startDeepSleep();
}

