#pragma once
#include <Arduino.h>
#include "DFRobot_SHTC3.h"

class DisplayManager;

class TemperatureSensorManager {
private:
    DFRobot_SHTC3 SHTC3;  // Sensor instance
    float temperature;
    float humidity;
    bool initialized;
    int id;
public:
    TemperatureSensorManager();

    bool isInitialized();
    bool initialize();
    void read();
    const float getTemp();
    const float getHumid();
    void displayTempMessage(DisplayManager& displayManager);
    void displayHumidMessage(DisplayManager& displayManager);

    ~TemperatureSensorManager();
};
