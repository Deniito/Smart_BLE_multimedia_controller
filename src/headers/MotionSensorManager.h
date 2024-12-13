#pragma once

#include "FS.h"
#include "SPIFFS.h"
#include <SD.h>
#include <M5Dial.h>

#include "Arduino.h"



class MotionSensorManager {
private:
    unsigned long lastMotionTime;
    bool motionDetected;
    const int pirSensorPin;

    // Private method to handle motion detection
    static void IRAM_ATTR motionDetectedISR(); 

public:
    MotionSensorManager(int pin);
    void initialize();
    bool read();
    bool detectMotion();
    bool detectMotionInLastMinute(); 

    // Method to set up interrupts
    void setupInterrupt();
};
