// (c) Michael Schoeffler 2017, http://www.mschoeffler.de
// #include <Wire.h>
#include <Arduino.h>

// The ADC driver API supports ADC1 (8 channels, attached to GPIOs 32 - 39), and ADC2 (10 channels, attached to GPIOs 0, 2, 4, 12 - 15 and 25 - 27).
const int IN_A0 = 4; // analog input
const int IN_D0 = 18; // digital input

void setup() {
  pinMode (IN_A0, INPUT);
  pinMode (IN_D0, INPUT);
  Serial.begin(115200);
}

int value_A0;
bool value_D0;

void loop() {

  value_A0 = analogRead(IN_A0); // reads the analog input from the IR distance sensor
  value_D0 = digitalRead(IN_D0);// reads the digital input from the IR distance sensor
  

  Serial.println("Analog:");
  Serial.println(value_A0); // prints analog value on the LCD module
  

  Serial.println("Digital:");

  Serial.println(value_D0); // prints digital value on the LCD module
  
  delay(500);
}