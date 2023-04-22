#include <Arduino.h>
#include <ESP32Servo.h>
#include "constantDefinition.h"
#include "detectToLift.h"
#include "motorControl.h"

void line_tracking(FourWheel *car){
    int* value_A0 = new int;
    int* value_A1 = new int;
    int* value_A2 = new int;
    int* value_A3 = new int;
    *value_A0 = analogRead(IN_A0); 
    *value_A1 = analogRead(IN_A1) - 700;
    *value_A2 = analogRead(IN_A2);
    *value_A3 = analogRead(IN_A3);

    Serial.print("A0:");
    Serial.print(*value_A0); // prints analog value on the LCD module
    Serial.print("  A1:");
    Serial.print(*value_A1); 
    Serial.print("  A2:");
    Serial.print(*value_A2); 
    Serial.print("  A3:");
    Serial.println(*value_A3);


    // // extreme condition 
    // if (*value_A0 > BLACK_LINE_DETECT_THRESHOLD){
    //     // move drastically until number 2 touches the line 
    //     while (*value_A2 < BLACK_LINE_DETECT_THRESHOLD){
    //         car->turnLeft(200);
    //         delay(20);
    //         *value_A2 = analogRead(IN_A2);
    //     }
    // }
    // // if the right most touches the blackline 
    // if (*value_A1 > BLACK_LINE_DETECT_THRESHOLD){
    //     while (*value_A1 < BLACK_LINE_DETECT_THRESHOLD){
    //         car->turnRight(200);
    //         delay(20);
    //         *value_A1 = analogRead(IN_A1);
    //     }
    // }

    // normal condition 
    if (*value_A1> BLACK_LINE_DETECT_THRESHOLD && *value_A2 > BLACK_LINE_DETECT_THRESHOLD){
        car->moveForward(200);
        delay(200);
    }
    else if (*value_A1 > BLACK_LINE_DETECT_THRESHOLD){ // the left touches the blackline
        // turn left 
        car->turnLeft(100);
        delay(50);
    }
    else if (*value_A2 > BLACK_LINE_DETECT_THRESHOLD){ // the right touches blackline
        // turn right 
        car->turnRight(100);
        delay(50);
    }
    else{
        car->moveForward(200);
        delay(200);
    }
    delete value_A0;
    delete value_A1;
    delete value_A2;
    delete value_A3;
}