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

  // initialize the IR sensors with only analog input 
  pinMode (IN_A0, INPUT);
  pinMode (IN_A1, INPUT);
  pinMode (IN_A2, INPUT);
  pinMode (IN_A3, INPUT);
  
}
// set up four tcrt from left to right as 0, 1, 2, 3
// mainly we use 1 and 2 to detect the black line
void line_tracking(int analog_0, int analog_1, int analog_2, int analog_3, FourWheel *car){
  // extreme condition 
  if (analog_0 > BLACK_LINE_DETECT_THRESHOLD){
    // move drastically until number 2 touches the line 
    while (value_A2 < BLACK_LINE_DETECT_THRESHOLD){
      car->turnLeft(200);
      delay(50);
      value_A2 = analogRead(IN_A2);
    }
  }
  // if the right most touches the blackline 
  if (analog_3 > BLACK_LINE_DETECT_THRESHOLD){
    while (value_A1 < BLACK_LINE_DETECT_THRESHOLD){
      car->turnRight(200);
      delay(50);
      value_A1 = analogRead(IN_A1);
    }
  }
  // normal condition 
  if (analog_1 > BLACK_LINE_DETECT_THRESHOLD && analog_2 > BLACK_LINE_DETECT_THRESHOLD){
    car->moveForward(200);
    delay(200);
  }
  else if (analog_1 > BLACK_LINE_DETECT_THRESHOLD){ // the left touchess the blackline
    // turn left 
    car->turnLeft(100);
    delay(50);
  }
  else if (analog_2 > BLACK_LINE_DETECT_THRESHOLD){ // the right touches blackline
    car->turnRight(100);
    delay(50);
  }
  else{
    car->moveForward(200);
    delay(200);
  }
}

int value_A0, value_A1, value_A2, value_A3;

void loop() {
  // reads the analog input from the IR distance sensor
  value_A0 = analogRead(IN_A0); 
  value_A1 = analogRead(IN_A1);// reads the digital input from the IR distance sensor
  value_A2 = analogRead(IN_A2); // reads the analog input from the IR distance sensor
  value_A3 = analogRead(IN_A3);// reads the digital input from the IR distance sensor

  line_tracking(value_A0,value_A1, value_A2, value_A3, &vehicle);

}
