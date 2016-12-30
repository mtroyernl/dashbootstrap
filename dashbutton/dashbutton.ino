
/*
  Created by Mark Troyer & Fons Janssen -  30 December 2016
  
  DASH BUTTON APP
  
  BOM: Wemos D1 Mini, a PNP transistor (a BC638), a 100 Ohm resistor and a momentary switch.

  Connections: 
  3.3v supply--transistor emitter
  transistor collector--3.3v on Wemos
  GND supply--GND on Wemos
  transistor base--resistor--switch--GND.   
  D5 pin linked to resistor--switch junction.
  D2 pin--Blue LED--GND
 */
#include <ESP8266WiFi.h>

void setup() {
  // Set up open collector pin ON
  pinMode(D5, OUTPUT);
  digitalWrite(D5, LOW);  // Pull open collector to ground (keep PNP transistor ON)
  
  //WiFi.forceSleepBegin(); // Optionally turn off ESP8266 RF
  //delay(1);               // give RF section time to shutdown
  pinMode(D2, OUTPUT);
}

void loop() {
  // Blink LED to show runnng module
  digitalWrite(D2, HIGH);
  delay(200); 
  digitalWrite(D2, LOW);
  delay(200);

  // After 3 seconds, cut power to ESP8266
  if (millis() > 3000) {
    pinMode(D5, INPUT); // Stop open collector (turn off PNP trnasistor and cut power to ESP8266)
  }
}
