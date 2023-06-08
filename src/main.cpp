#include <Arduino.h>
#include <ESP32Servo.h>
#include "../include/motorControl.h"
#include "../include/constantDefinition.h"
#include "../include/detectToLift.h"
#include "../include/line_tracking.h"

FourWheel vehicle(1500);
bool liftActivated = false;
unsigned long startTime = 0;

void setup() {
  Serial.begin(115200);

  // Initialize the four motor control object with pulse width 1500 as base 
  vehicle.setup();

  // initialize the IR sensors with only analog input 
  pinMode (IN_A0, INPUT);
  pinMode (IN_A1, INPUT);
  pinMode (IN_A2, INPUT);
  pinMode (IN_A3, INPUT);
  
  startTime = millis();
  
}

void loop() {
  // sleep five seconds and use only once 
  // current not needed in midterm test
  if (millis() - startTime >= 8000 && !liftActivated) {
    Lift();
    liftActivated = true;
  }

  if (millis() - startTime <= 18000){// assume 
    vehicle.moveForward(200);
  }
  else if(millis() - startTime >= 22000){
    line_tracking(&vehicle, true);
  }
  else{
    line_tracking(&vehicle, false);
  }


  // reads the analog input from the IR distance sensor
  
}
