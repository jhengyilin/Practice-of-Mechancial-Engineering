#ifndef constantDefinition_h
#define constantDefinition_h

// Pins for 4 wheel servo motors
const int frontRightPin = 21;
const int frontLeftPin = 23;
const int backRightPin = 32;
const int backLeftPin = 25; 
// Pin definition for the lifting servo motor
#define LIFT_SERVO_PIN_Front 5
#define LIFT_SERVO_PIN_Back 19


// Pins for IR sensors
// The ADC driver API supports ADC1 (8 channels, attached to GPIOs 32 - 39)
// and ADC2 (10 channels, attached to GPIOs 0, 2, 4, 12 - 15 and 25 - 27)
const int IN_A0 = 100; // analog input
const int IN_A1 = 2; // analog input

const int IN_A2 = 14; // digital input
const int IN_A3 = 99; // digital input


// lifiting variable 
const int shifter = 135;
const int upper = 90;
const int pos = 90;

// Threshold value++ for the IR sensors to detect black line 
#define BLACK_LINE_DETECT_THRESHOLD 800

// Pulse width values for servo motor
#define WING_DOWN_PAUSE_PULSE 1500
#define WING_UP_PULSE 1300

// // start time 
// const unsigned long startTime = 0;
// bool five_seconds = false;


#endif // constatDefinition_h