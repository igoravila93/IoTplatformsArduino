
/*
 * Util.h 
 * 
 * Auxiliary start up and configuration functions
 * 
 *  Created on: 1/11/2017
 *      Author: Igor Avila Amaral de Souza
 */

#ifndef Util_h
#define Util_h

// Includes //

#include "Arduino.h"
#include <ESP8266WiFi.h>
#include <ESP8266mDNS.h>

// WiFi Definitions //
extern IPAddress STATIC_IP;
extern IPAddress gateway;
extern IPAddress subnet;

const char WiFiSSID[] = "Igor";
const char WiFiPSK[] = "44074407";

// Pin Definitions //
const int LIGHT_OUTPUT_PIN = 4; 
const int LED_PIN = 2; //Onboard led pin    
const int ANALOG_PIN = A0; // The only analog pin on the Thing
const int DIGITAL_PIN = 12; // Digital pin to be read

// Methods //

/* ************************************************** */
/* Method name:      connectWiFi                      */
/* Method description: start and configure a Wifi connection */
/* Input params:     n/a                              */
/* Outpu params:     n/a                              */
/* ************************************************** */
void  connectWiFi();

/* ************************************************** */
/* Method name:      initHardware             */
/* Method description: inititialize pin configurations          */
/* Input params:     n/a                */
/* Outpu params:     n/a                */
/* ************************************************** */
void initHardware();

/* ************************************************** */
/* Method name:      setupMDNS             */
/* Method description: start mDNS to resolve host names */
/* Input params:     n/a                */
/* Outpu params:     n/a                */
/* ************************************************** */
bool setupMDNS(); 

#endif

