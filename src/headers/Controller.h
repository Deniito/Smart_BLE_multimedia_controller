#pragma once

#include <BleKeyboard.h>


#include <vector>
#include <string>

#include "DisplayManager.h"
#include "BluetoothManager.h"
#include "MotionSensorManager.h"
#include "LightSensorManager.h"


class Controller {
private:
    DisplayManager displayManager;
    BluetoothManager& bluetoothManager;

    LightSensorManager lightSensor;
    MotionSensorManager motionSensor;

    unsigned long lastTrueTimestamp = 0; // Tracks the last time a 'true' was returned
    const unsigned long timeout = 60000;

public:
    Controller();
    void initialize();
    void run();
};