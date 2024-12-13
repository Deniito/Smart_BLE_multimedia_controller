#include "headers/Controller.h"

Controller::Controller()
    : bluetoothManager(BluetoothManager::getInstance()), // Initialize reference to singleton
      motionSensor(1), lightSensor(LightSensorManager()) // Pass pin to MotionSensorManager constructor
{}
void Controller::initialize() {
    if (!SPIFFS.begin(true)) {
        Serial.println("SPIFFS initialization failed!");
    }

    Serial.begin(115200);

    auto cfg = M5.config();
    cfg.serial_baudrate = 115200;
    M5Dial.begin(cfg, true, true);

    lightSensor.begin();

    motionSensor.initialize(); 

    bluetoothManager.initialize();

    esp_sleep_enable_ext0_wakeup((gpio_num_t)GPIO_NUM_1, HIGH);

    displayManager.setBrightness(lightSensor.scaleBrightness());

    M5Dial.Lcd.setTextSize(5);
    M5Dial.Lcd.setTextColor(BLACK);
    M5Dial.Lcd.fillScreen(WHITE);
    M5Dial.Lcd.setCursor(10, 120);
    M5Dial.Lcd.print("SMIW <3");

    delay(1000);
}

void Controller::run() { 
    M5Dial.update();
    if (!bluetoothManager.isConnected()) {
        bluetoothManager.waitForConnection(displayManager);
        return;
    }
    
    bool updateResult = displayManager.update(); // Check update result
    bool motionResult = motionSensor.read();    // Check motion sensor result

    if (updateResult || motionResult) {
        lastTrueTimestamp = millis(); // Update the last true timestamp
    }

    unsigned long currentTime = millis();
    if (currentTime - lastTrueTimestamp > timeout) {
        // Set display brightness to 0 (turn off) before deep sleep
        displayManager.setBrightness(0);

        esp_deep_sleep_start(); // Put the device into deep sleep mode
    } else {
        displayManager.setBrightness(lightSensor.scaleBrightness());
    }   

}
