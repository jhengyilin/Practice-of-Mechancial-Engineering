#include <Arduino.h>
#include <ESP32Servo.h>
#include "constantDefinition.h"
#include "detectToLift.h"

// Initialize the servo motor
Servo WingServo_front, WingServo_back;

void attachAndSetServo(Servo &servo, int pin) {
  servo.setPeriodHertz(50);
  servo.attach(pin, 500, 2500);
}

void setupTwoServo() {
  // Configure the IR sensor pins as input
  attachAndSetServo(WingServo_front, LIFT_SERVO_PIN_Front);
  attachAndSetServo(WingServo_back, LIFT_SERVO_PIN_Back);
}


void Lift() {
  setupTwoServo();

  // WingServo_front.write(pos);
  // WingServo_back.write(shifter-pos);


  for (int pos = 0; pos <= upper; pos += 5) { // goes from 0 degrees to 180 degrees
		// in steps of 1 degree
		WingServo_back.write(pos);

		WingServo_front.write((shifter-pos));     // shifter is the shifting for front motor, the larger the 120, the lower the front motor shift  
		delay(100);            
	}
	
  Serial.println("Lift");
}

