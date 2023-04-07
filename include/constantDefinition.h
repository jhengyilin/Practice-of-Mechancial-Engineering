#ifndef constantDefinition_h
#define constantDefinition_h

// Pins for 4 wheel servo motors
const int frontRightPin = 33;
const int frontLeftPin = 32;
const int backRightPin = 22;
const int backLeftPin = 23;

// Pins for IR sensors
// The ADC driver API supports ADC1 (8 channels, attached to GPIOs 32 - 39)
// and ADC2 (10 channels, attached to GPIOs 0, 2, 4, 12 - 15 and 25 - 27)
const int IN_A0 = 34; // analog input
const int IN_A1 = 35; // analog input

const int IN_D0 = 18; // digital input
const int IN_D1 = 19; // digital input

// Pin definition for the lifting servo motor
#define LIFT_SERVO_PIN 14
// Threshold value for the IR sensors to detect black line
#define BLACK_LINE_DETECT_THRESHOLD 800

// Pulse width values for servo motor
#define WING_DOWN_PAUSE_PULSE 1500
#define WING_UP_PULSE 1300


#endif // constatDefinition_h