
/*
 * Util.cpp 
 * 
 * Auxiliary start up and configuration functions
 * 
 *  Created on: 1/11/2017
 *      Author: Igor Avila Amaral de Souza
 */


#include "Util.h"

extern IPAddress STATIC_IP(192, 168, 43, 251);
extern IPAddress gateway(192, 168, 43, 1);
extern IPAddress subnet(255, 255, 255, 0);


/* ************************************************** */
/* Method name:      connectWiFi                      */
/* Method description: start and configure a Wifi connection */
/* Input params:     n/a                              */
/* Outpu params:     n/a                              */
/* ************************************************** */
void  connectWiFi()
{

  // config static IP, not necessary for client
  //WiFi.config(STATIC_IP, gateway, subnet);
  // Set WiFi mode to station (as opposed to AP or AP_STA)
  WiFi.mode(WIFI_STA);

  // WiFI.begin([ssid], [passkey]) initiates a WiFI connection
  // to the stated [ssid], using the [passkey] as a WPA, WPA2,
  // or WEP passphrase.
  WiFi.begin(WiFiSSID, WiFiPSK);
  digitalWrite(LIGHT_OUTPUT_PIN, false);
  // Use the WiFi.status() function to check if the ESP8266
  // is connected to a WiFi network.
  while (WiFi.status() != WL_CONNECTED)
  {
    digitalWrite(LED_PIN, !digitalRead(LED_PIN));
    delay(100);
    //Blinks the LED while the board is not connected
  }
}


/* ************************************************** */
/* Method name:      initHardware             */
/* Method description: inititialize pin configurations          */
/* Input params:     n/a                */
/* Outpu params:     n/a                */
/* ************************************************** */
void initHardware()
{
  pinMode(DIGITAL_PIN, INPUT_PULLUP);
  pinMode(LIGHT_OUTPUT_PIN, OUTPUT);
  pinMode(LED_PIN, OUTPUT);
  pinMode(ANALOG_PIN, INPUT);
}


/* ************************************************** */
/* Method name:      setupMDNS             */
/* Method description: start mDNS to resolve host names */
/* Input params:     n/a                */
/* Outpu params:     n/a                */
/* ************************************************** */
bool setupMDNS()
{
  // Call MDNS.begin(<domain>) to set up mDNS to point to
  // "<domain>.local"
  if (!MDNS.begin("thing")) 
  {
    return false;
  }
  return true;
}

