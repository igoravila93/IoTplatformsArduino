
/*
 *  
 *  ThingSpeak master
 *  Keep changing the value from 0 to 1024 each 15 seconds of the channel configured *  Use the link to change value https://api.thingspeak.com/update?api_key=1G4M9YHGMDF2WQF5&field1=1024
 *  Channel link: https://thingspeak.com/channels/129007 
 * 
 *  Last update: 7/11/2017
 *      Author: Igor Avila Amaral de Souza
 */
 
#include"Util.h"

bool toggle_flag = true;

void setup() 
{
  //Serial.begin(9600);
  initHardware();
  connectWiFi();
//  Serial.println("WiFi connected");  
//  Serial.println("IP address: ");
//  Serial.println(WiFi.localIP());

  setupMDNS();
}

void loop() 
{
  
  WiFiClient client;
  IPAddress server(184,106,153,149);

  if (client.connect(server, 80)) {


      int value = toggle_flag ? 0 : 1024;
      toggle_flag = !toggle_flag;

      String getRequest = "GET /update?key=<YOUR_KEY_HERE>&field1=" +  String(value) + "HTTP/1.0\n\n";

      //Toggle output pin
      digitalWrite(LIGHT_OUTPUT_PIN, !digitalRead(LIGHT_OUTPUT_PIN));
      
      //Change the channel value
      client.println(getRequest);
   } else {
      //Serial.println("Fail");
   }

  //Wait for 15 seconds
  delay(15000);
}

