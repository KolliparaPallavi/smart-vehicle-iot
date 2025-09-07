#include "madBlocks.h"
#include <ESP8266WiFi.h>

madBlocks mb;

String apiKey = "537e5d0b08a14e647818c37882cc6654";

String data;
String reqData = "";

/*-----------------------------------------------WiFi Details--------------------------------------------------*/

String hotspotName = "ground";
String hotspotPassword = "123456789";

/*--------------------------------------------------------------------------------------------------------------*/

void setup() 
{
  Serial.begin(9600);
  WiFi.begin(hotspotName,hotspotPassword);
  while ((!(WiFi.status() == WL_CONNECTED)))
  {
    delay(300);
    Serial.println(".");
  }
  Serial.println("Connected");
}

void loop() 
{
  data = mb.read(apiKey);
  Serial.println(data);
  delay(2500);
}
