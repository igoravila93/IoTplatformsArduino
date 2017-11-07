/*
 * Toggles output pin everytime receives a HTTP toogle request 
 *
 *  Last edit on: 6/11/2017
 *      Author: Igor Avila Amaral de Souza
 */
 
#include"Util.h"


//Creat a webserver at port 80
WiFiServer server(80);

void setup() 
{
  Serial.begin(9600);
  initHardware();
  connectWiFi();
  Serial.println("WiFi connected");  
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
  server.begin();
  
  setupMDNS();
  Serial.println("DNS OK");
}

void loop() 
{
  
  // Check if a client has connected
  WiFiClient client = server.available();
  if (!client) {
    //If no client, restart the loop
    return;
  }

  // Read the first line of the request
  String req = client.readStringUntil('\r');
  Serial.println(req);
  client.flush();

  bool toggle_command = false;
  bool read_command = false;
  
  // If toggle request toggle the output pin
  if (req.indexOf("/toggle") != -1){
      digitalWrite(LIGHT_OUTPUT_PIN, !digitalRead(LIGHT_OUTPUT_PIN));
      toggle_command = true;
  }

  if(req.indexOf("/read") != -1){
      read_command = true;
  }
  
  client.flush();

  // Otherwise request will be invalid.
  
  // Prepare the response. Start with the common header:
  String s = "HTTP/1.1 200 OK\r\n";
  s += "Content-Type: text/html\r\n\r\n";
  s += "<!DOCTYPE HTML>\r\n<html>\r\n";
  // If we're setting the LED, print out a message saying we did
  if (toggle_command)
  {
    s += "OUTPUT Toggled";
  }
  else if (read_command)
  { // If we're reading pins, print out those values:
    s += "Analog Pin = ";
    s += String(analogRead(ANALOG_PIN));
    s += "<br>"; // Go to the next line.
    s += "INPUT Digital Pin = ";
    s += String(digitalRead(DIGITAL_PIN));
  }
  else
  {
    s += "Invalid Request.<br> Try /toggle, or /read.";
  }
  s += "</html>\n";

  // Send the response to the client
  client.print(s);
  delay(1);

  // The client will actually be disconnected 
  // when the function returns and 'client' object is detroyed
}

