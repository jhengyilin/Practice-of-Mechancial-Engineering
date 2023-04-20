#include <Arduino.h>
#include <ESP32Servo.h>
#include "../include/motorControl.h"
#include "../include/constantDefinition.h"
#include "../include/detectToLift.h"
#include "../include/line_tracking.h"

FourWheel vehicle(1500);

void setup() {
  Serial.begin(115200);

  // Initialize the four motor control object with pulse width 1500 as base 
  vehicle.setup();

  // initialize the IR sensors with only analog input 
  pinMode (IN_A0, INPUT);
  pinMode (IN_A1, INPUT);
  pinMode (IN_A2, INPUT);
  pinMode (IN_A3, INPUT);
  
}



void loop() {
  // sleep five seconds and use only once 
  if (millis() - startTime >= 5000 && !five_seconds) {
      Lift();
      five_seconds = true;
    }

  // reads the analog input from the IR distance sensor
  line_tracking(&vehicle);
}
