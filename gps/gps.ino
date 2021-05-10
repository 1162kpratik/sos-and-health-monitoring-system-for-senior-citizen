#include "ThingsBoard.h"
#include <ESP8266WiFi.h>
#include <TinyGPS++.h>

#define WIFI_AP             "prat"
#define WIFI_PASSWORD       "162kpratik"
#define TOKEN               "cIRK59mKVDJB4HD95JLQ"
#define THINGSBOARD_SERVER  "demo.thingsboard.io"

WiFiClient espClient;   // Initialize ThingsBoard instance
ThingsBoard tb(espClient);   // the Wifi radio's status
TinyGPSPlus gps; // create gps object

int status = WL_IDLE_STATUS;
 
void setup(){
  Serial.begin(9600); // connect serial
}

void InitWiFi(){
  Serial.println("Connecting to AP ...");
  // attempt to connect to WiFi network

  WiFi.begin(WIFI_AP, WIFI_PASSWORD);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("Connected to AP");
}

void reconnect() {
  // Loop until we're reconnected
  status = WiFi.status();
  if ( status != WL_CONNECTED) {
    InitWiFi();
    while (WiFi.status() != WL_CONNECTED) {
      delay(500);
      Serial.print(".");
    }
    Serial.println("Connected to AP");
  }
}
 
void loop(){

 if (WiFi.status() != WL_CONNECTED) {
   reconnect();
 }
 if (!tb.connected()) {
    // Connect to the ThingsBoard
    Serial.print("Connecting to: ");
    Serial.print(THINGSBOARD_SERVER);
    Serial.print(" with token ");
    Serial.println(TOKEN);
    if (!tb.connect(THINGSBOARD_SERVER, TOKEN)) {
      Serial.println("Failed to connect");
      return;
    }
  }
  
   if(Serial.available() > 0)
  { 
   if(gps.encode(Serial.read()))// encode gps data
   { 
    displayInfo();
   }
   
  }  
}

void displayInfo(){

delay(5000);
Serial.print(F("Location: "));
float  lati=gps.location.lat();
delay(10);
float  longi=gps.location.lng();
delay(10);
float  speed1=gps.speed.kmph();
  Serial.print(18.100138);
  Serial.print(F(","));
  Serial.print(74.212549);
  Serial.print(F(","));
  Serial.print(speed1);
  tb.sendTelemetryFloat("latitude",18.100138);
  delay(10);
  tb.sendTelemetryFloat("longitude",74.212549);
  delay(10);
  tb.sendTelemetryFloat("SPEED",speed1);
  Serial.println();
}
