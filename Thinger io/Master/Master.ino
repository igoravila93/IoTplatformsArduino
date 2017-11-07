
/*
 *  
 *  Thinger.io master that makes a toggle request for the Slave each 1 sec
 * 
 *  Last update: 7/11/2017
 *  Author: Igor Avila Amaral de Souza
 */

#include"Util.h"
#include <ThingerWifi.h>


#define USERNAME "IgorAvila"
#define DEVICE_ID "Master"
#define DEVICE_CREDENTIAL "123456"

//Initialize the thing with the credentials above
ThingerWifi thing(USERNAME, DEVICE_ID, DEVICE_CREDENTIAL);

void setup() 
{

  initHardware();

  //Connect the device to the Thinger.io
  thing.add_wifi(WiFiSSID, WiFiPSK);
}

void loop() 
{
  //Necessary to operate as a Thinger.io device
  thing.handle();

  //Toggle output pin
  digitalWrite(LIGHT_OUTPUT_PIN, !digitalRead(LIGHT_OUTPUT_PIN));

  //Call the action toggle at the Slave
  thing.call_device("Slave", "toggle"); 

  delay(1000);
}

