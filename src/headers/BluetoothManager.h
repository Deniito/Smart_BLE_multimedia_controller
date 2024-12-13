#pragma once

#include "FS.h"
#include "SPIFFS.h"
#include <SD.h>
#include <M5Dial.h>

#include <vector>
#include <string>
#include <memory>
#include <mutex>
#include <BleKeyboard.h>


#include "headers/DisplayManager.h"


class BluetoothManager {
private:
    BleKeyboard bleKeyboard;
    bool connected = 0;
    // Private constructor
    BluetoothManager(const char* deviceName, const char* manufacturer, uint8_t batteryLevel)
        : bleKeyboard(deviceName, manufacturer, batteryLevel) {}
public:
    // Delete copy constructor and assignment operator to prevent copying
    BluetoothManager(const BluetoothManager&) = delete;
    BluetoothManager& operator=(const BluetoothManager&) = delete;

    // Static method to access the single instance
    static BluetoothManager& getInstance();
    void initialize();
    bool isConnected();
    void waitForConnection(DisplayManager& displayManager);
    void sendKeyPress(const std::vector<unsigned int>& keys);
    BleKeyboard& getBleKeyboard();
    void changeVolume(int volumeDelta);
};