#include <WiFi.h>
#include <Arduino.h>
#include "WiFiConnect.h"
#include "WiFiServer.h"
#include "ScheduleProt.h"

int ScheduleProt::scheduleWatering() {
  int waterState = -1;

  WiFiConnect newConnection;
  newConnection.wifiConnect();

  WiFiServer server(80);
  server.begin();

  while (waterState == -1) {
    WiFiClient client = server.available();
    delay(10);
     if (client) {
          String req = client.readStringUntil('\r');
          Serial.println("Waiting for user input...");
          //Watering Times
            if(req.indexOf("/morning/") != -1){
              client.print("Morning");
              waterState = 0;
            } 
            else if(req.indexOf("/noon/") != -1){
              waterState = 1;
              client.print("Noon");
            }  
            else if(req.indexOf("/evening/") != -1){
              waterState = 2;
              client.print("Evening");
            }      
            else if(req.indexOf("/midnight/") != -1){
              waterState = 3;
              client.print("Midnight");
            }
        }
  }
  Serial.println("User input recieved, Huzzah!" + waterState);
  newConnection.wifiDisconnect();
  return waterState; 
}