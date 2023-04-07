#include <Arduino.h>
#include <ESP32Servo.h>
#include "../include/motorControl.h"
#include "../include/constantDefinition.h"
#include "../include/detectToLift.h"

FourWheel vehicle(1500);

void setup() {
  Serial.begin(115200);

  // Initialize the four motor control object with pulse width 1500 as base 
  vehicle.setup();

  pinMode (IN_A0, INPUT);
  pinMode (IN_D0, INPUT);
  
  pinMode (IN_A1, INPUT);
  pinMode (IN_D1, INPUT);
  
}

void line_tracking(int analog_0, int analog_1, int digital_0, int digital_1, FourWheel *car){
  // let 0 on the left and 1 on the right
  // we hope that each will not touch the black line so that it can 
  if (analog_0 > BLACK_LINE_DETECT_THRESHOLD){ // the left touchess the blackline
    // turn left 
    car->turnLeft(200);
    delay(50);
  }
  else if (analog_1 > BLACK_LINE_DETECT_THRESHOLD){
    car->turnRight(200);
    delay(50);
  }
  else{
    car->moveForward(200);
    delay(50);
  }
}

int value_A0, value_A1;

bool value_D0, value_D1;

void loop() {
  value_A0 = analogRead(IN_A0); // reads the analog input from the IR distance sensor
  value_D0 = digitalRead(IN_D0);// reads the digital input from the IR distance sensor
  value_A1 = analogRead(IN_A1); // reads the analog input from the IR distance sensor
  value_D1 = digitalRead(IN_D1);// reads the digital input from the IR distance sensor

  line_tracking(value_A0,value_A1, value_D0, value_D1, &vehicle);

}
