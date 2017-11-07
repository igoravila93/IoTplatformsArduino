/*
 *  Firebase master
 *  Keep toggling the value from true and false each 1 second of the database configured
 *  
 *  Last update: 7/11/2017
 *  Author: Igor Avila Amaral de Souza
 */

#include <Firebase.h>
#include <FirebaseArduino.h>
#include <FirebaseCloudMessaging.h>
#include <FirebaseError.h>
#include <FirebaseHttpClient.h>
#include <FirebaseObject.h>
#include"Util.h"


#define FIREBASE_HOST "luznanet-917c2.firebaseio.com"
#define FIREBASE_AUTH "1tthWDWECLl9GJ0i9sMjXfmIIMcntcVzExUNdVgM"

void setup() 
{
  //Serial.begin(9600);
  initHardware();
  connectWiFi();
//  Serial.println("WiFi connected");  
//  Serial.println("IP address: ");
//  Serial.println(WiFi.localIP());

  setupMDNS();

  //Start conection to Firebase
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
}

void loop() 
{
  //Set output pin and set value to true at database
  digitalWrite(LIGHT_OUTPUT_PIN, HIGH);
  Firebase.setBool("value", true);

  delay(1000);

  //Clear output pin and set value to false at database
  digitalWrite(LIGHT_OUTPUT_PIN, LOW);
  Firebase.setBool("value", false);

  delay(1000);

}

