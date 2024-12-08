#include "headers/BluetoothManager.h"

void BluetoothManager::initialize() {

    Serial.println("Initializing Bluetooth...");
    bleKeyboard.begin();
    connected = bleKeyboard.isConnected();
    Serial.println(connected ? "Bluetooth is connected." : "Bluetooth not connected.");
}

bool BluetoothManager::isConnected() {
    connected = bleKeyboard.isConnected();
    return connected;
}

BluetoothManager& BluetoothManager::getInstance() {
    static BluetoothManager instance("M5Stack", "WM", 51); // Local static variable
    return instance;
}

void BluetoothManager::waitForConnection(DisplayManager &displayManager) {
    while (!isConnected()) {
        M5.update();
        for (int i = 1; i <= 3; ++i) {
            Serial.println("Bluetooth disconnected!");
            displayManager.clearScreen();
            displayManager.showMessage("Waiting", -60);
            std::string dots(i, '.');
            displayManager.showMessage("For Bluetooth" + dots, -40);
            delay(500);
        }
    }
    displayManager.animateOpening(120, 120, 140);
}

// Send a keypress sequence
void BluetoothManager::sendKeyPress(const std::vector<unsigned int> &keys) {
    if (!isConnected()) {
        Serial.println("Bluetooth not connected. Cannot send key press.");
        return;
    }

    // Press and release each key in the sequence
    for (auto key : keys) {
        bleKeyboard.press(key); // Press the key
        Serial.println("Key pressed");
    }
    
    delay(100);//  delay to ensure key is registered
    bleKeyboard.releaseAll();
}

BleKeyboard &BluetoothManager::getBleKeyboard() {
        return bleKeyboard;
}

void BluetoothManager::changeVolume(int volumeDelta) {
    if (volumeDelta > 0) {
        for (int i = 0; i < volumeDelta; ++i) {
            bleKeyboard.press(KEY_MEDIA_VOLUME_UP);
            bleKeyboard.releaseAll();
            delay(50);
        }
    } else if (volumeDelta < 0) {
        for (int i = 0; i < -volumeDelta; ++i) {
            bleKeyboard.press(KEY_MEDIA_VOLUME_DOWN);
            bleKeyboard.releaseAll();
            delay(50);
        }
    }
}