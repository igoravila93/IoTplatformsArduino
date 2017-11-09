
/*
 *  Firebase slave
 *  When the value of the variable at database changes it toggles its output
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

#define FIREBASE_HOST "<YOUR HOST>"
#define FIREBASE_AUTH "<YOUR DATABASE SECRET>"

void setup() 
{
  //Serial.begin(9600);
  initHardware();
  connectWiFi();
//  Serial.println("WiFi connected");  
//  Serial.println("IP address: ");
//  Serial.println(WiFi.localIP());
  setupMDNS();
  //Serial.println("DNS OK");

  //Start conection to Firebase
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
}

void loop() 
{
  //Read the value from database and writes at the output pin
  bool lampValue = Firebase.getBool("value");
  digitalWrite(LIGHT_OUTPUT_PIN, lampValue ? HIGH : LOW);
}

