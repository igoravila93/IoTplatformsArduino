/*
 *  
 *  Thinger.io slave that has a toggle output method to be used
 * 
 *  Last update: 7/11/2017
 *  Author: Igor Avila Amaral de Souza
 */

#include"Util.h"
#include <ThingerWifi.h>

#define USERNAME "YOUR_USERNAME"
#define DEVICE_ID "YOUR_ID"
#define DEVICE_CREDENTIAL "YOUR_ID_CREDENTIAL"

//Initialize the thing with the credentials above
ThingerWifi thing(USERNAME, DEVICE_ID, DEVICE_CREDENTIAL);

void setup() 
{

  initHardware();

  //Create a toggle method to be called
  thing["toggle"] = [](){
        digitalWrite(LIGHT_OUTPUT_PIN, !digitalRead(LIGHT_OUTPUT_PIN));
    };
    
  //Connect the device to the Thinger.io
  thing.add_wifi(WiFiSSID, WiFiPSK);
}

void loop() 
{
  //Necessary to operate as a Thinger.io device
  thing.handle();
}

