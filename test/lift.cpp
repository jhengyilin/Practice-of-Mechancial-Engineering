#include <ESP32Servo.h>

Servo myservo1;  // create servo object to control a servo
Servo myservo2; 
Servo myservo3;
// 16 servo objects can be created on the ESP32

int pos = 0;    // variable to store the servo position
// Recommended PWM GPIO pins on the ESP32 include 2,4,12-19,21-23,25-27,32-33 
// Possible PWM GPIO pins on the ESP32-S2: 0(used by on-board button),1-17,18(used by on-board LED),19-21,26,33-42

int servo1Pin = 18;
int servo2Pin = 19;
int servo3Pin = 21;


void setup() {

	myservo1.setPeriodHertz(50);    // standard 50 hz servo
	myservo1.attach(servo1Pin, 500, 2500); // attaches the servo on pin 18 to the servo object
	myservo2.setPeriodHertz(50);    // standard 50 hz servo
	myservo2.attach(servo2Pin, 500, 2500);
	myservo3.setPeriodHertz(50);    // standard 50 hz servo
	myservo3.attach(servo3Pin, 500, 2500);
	// using default min/max of 1000us and 2000us
	// different servos may require different min/max settings
	// for an accurate 0 to 180 sweep
}
bool check = true;

void loop() {



	// front = 18 back = 19
	// for the front motor its upper height is limited by pos = 40 and lower height is limited by pos = 90
	// the larger the  40, the higher front motor 
	
	// for (pos = 40; pos <= 90; pos += 1) { // goes from 0 degrees to 180 degrees
	// 	// in steps of 1 degree
	// 	myservo1.write(pos);

	// 	myservo2.write((120-pos));    // 65 is the shifting for rear motor the larger, the larger the 120, the higher the rear motor shift  
	// 	delay(100);             // waits 15ms for the servo to reach the position
	// }
	
	// delay(3000);

	if(check == true){
		for (pos = 90; pos >= 40; pos -= 1) { // goes from 180 degrees to 0 degrees
			myservo1.write(pos);
			myservo2.write((120 - pos));    // tell servo to go to position in variable 'pos'
			delay(100);             // waits 15ms for the servo to reach the position
		}
		
		delay(2000);
		check = false;

	}
	else{
		return;
	}

	

	



	
}
