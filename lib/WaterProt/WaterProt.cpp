#include "WaterProt.h"
#include <Arduino.h>

void WaterProt::waterPlant(int motorPin, int waterDuration){
        Serial.println("Watering...");
        digitalWrite(motorPin, HIGH);
        delay(waterDuration);
        digitalWrite(motorPin, LOW);
        Serial.println("Done!");
}

int WaterProt::getWateringHour(int waterState) {
    switch (waterState) {
        case 0:
        waterHour = 6;
        break;
        case 1:
        waterHour = 12;
        break;
        case 2:
        waterHour = 21;
        break;
        case 3:
        waterHour = 0;
        break;
    }
    return waterHour;
}