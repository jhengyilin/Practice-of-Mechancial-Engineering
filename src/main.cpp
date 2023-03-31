#include <Arduino.h>
#include <ESP32Servo.h>
#include "../include/motorControl.h"
#include "../include/constantDefinition.h"

// Initialize the four motor control object with pulse width 1500 as base 
FourWheel vehicle(1500);

void setup() {
  Serial.begin(115200);

  pinMode (IN_A0, INPUT);
  pinMode (IN_D0, INPUT);
}


int value_A0;
bool value_D0;

void loop() {

  value_A0 = analogRead(IN_A0); // reads the analog input from the IR distance sensor
  value_D0 = digitalRead(IN_D0);// reads the digital input from the IR distance sensor

  Serial.println("Moving backward:");
  vehicle.moveBackward(500);
  delay(2000);

  Serial.println("Pausing for 2 seconds.");
  vehicle.pause_motor();
  delay(2000);  
  
  
  Serial.println("Moving forward:");
  vehicle.moveForward(1000);
  delay(2000);

  Serial.println("Pausing for 2 seconds.");
  vehicle.pause_motor();
  delay(2000);  

  Serial.println("Turning right:");
  vehicle.turnRight(500);
  delay(2000);

  Serial.println("Pausing for 2 seconds.");
  vehicle.pause_motor();
  delay(2000);


  Serial.println("Turning left:");
  vehicle.turnLeft(500);
  delay(2000);

  Serial.println("Pausing for 2 seconds.");
  vehicle.pause_motor();
  delay(2000);  

}
