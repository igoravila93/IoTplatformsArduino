
/*
 *  
 * 
 * Connects to Channel at ThingSpeak and set Output Pin LOW if channel = 0 and HIGH if channel = 1024 at IP declared 
 *  Use the link to change value https://api.thingspeak.com/update?api_key=1G4M9YHGMDF2WQF5&field1=1024
 *  Channel link: https://thingspeak.com/channels/129007 
 * 
 *  Last update: 7/11/2017
 *      Author: Igor Avila Amaral de Souza
 */


#include"Util.h"

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

      //Make a GET request
      client.println("GET /channels/129007/fields/1/last HTTP/1.1");
      client.println("Host: api.thingspeak.com");
      client.println("Connection: close");
      client.println();
      
      // wait till something comes in; may add a timeout here
      while (client.available() == 0);  

      //Get the value out of the message received
      String value_string = "";
      while(client.available()){
        value_string = client.readStringUntil('\r');
        if(value_string == "\n"){ 
          break;
        }
      }
      value_string = client.readStringUntil('\r');
      value_string.remove(0,1); //remove first \n

      client.stop();  // close socket

      //Set output pin depending on value read
      int value = value_string.toInt();
      if(value == 0){
          digitalWrite(LIGHT_OUTPUT_PIN, LOW);
      } else if (value == 1024){
          digitalWrite(LIGHT_OUTPUT_PIN, HIGH);
      }
   } else {
      //Serial.println("Fail");
   }
  
}

