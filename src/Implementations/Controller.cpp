#include "headers/Controller.h"

Controller::Controller()
    : bluetoothManager(BluetoothManager::getInstance()), // Initialize reference to singleton
      motionSensor(1), lightSensor(LightSensorManager()) // Pass pin to MotionSensorManager constructor
{}
void Controller::initialize() {

    M5Dial.Lcd.setBrightness(64);
    Serial.begin(115200);
    M5.begin();
    M5Dial.Display.begin();
    auto cfg = M5.config();
    cfg.serial_baudrate = 115200;
    M5Dial.begin(cfg, true, true);

    motionSensor.initialize();  // Initialize the motion sensor
    bluetoothManager.initialize();
    M5Dial.Lcd.setTextSize(5);
    M5Dial.Lcd.setTextColor(BLACK);
    M5Dial.Lcd.fillScreen(WHITE);
    M5Dial.Lcd.setCursor(10, 120);
    M5Dial.Lcd.print("SMIW <3");
    lightSensor.begin();
    delay(1000);

    esp_sleep_enable_ext0_wakeup((gpio_num_t)GPIO_NUM_1, HIGH);
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
