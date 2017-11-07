
/*
 * Connects to webserver at IP declared 
 *
 *  Last edit on: 6/11/2017
 *      Author: Igor Avila Amaral de Souza
 */

#include"Util.h"


void setup() 
{
  Serial.begin(9600);
  initHardware();
  connectWiFi();
  Serial.println("WiFi connected");  
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());

  setupMDNS();
  Serial.println("DNS OK");
}

void loop() 
{
  
  WiFiClient client;
  //Create a server object with the right IP
  IPAddress server(192, 168, 43, 252);

  //Set output to HIGH
  digitalWrite(LIGHT_OUTPUT_PIN, HIGH);

  //Connect and send a toggle command
  if (client.connect(server, 80)) {
      // Make a HTTP request:
      client.println("/toogle");
      //Clear the output pin to LOW
      digitalWrite(LIGHT_OUTPUT_PIN, LOW);
   } else {
      Serial.println("Fail");
   }
   
  //Wait 1 second
  delay(1000);
}

