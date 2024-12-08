#include "headers/MotionSensorManager.h"
#include "M5Dial.h"

MotionSensorManager::MotionSensorManager(int pin)
    : pirSensorPin(pin), lastMotionTime(0), motionDetected(false) {}

void MotionSensorManager::initialize() {
    pinMode(pirSensorPin, INPUT);
}

bool MotionSensorManager::read() {
    motionDetected = digitalRead(pirSensorPin);
    if (motionDetected) {
        lastMotionTime = millis();
    }
    return motionDetected;
}

bool MotionSensorManager::detectMotion() {
    return motionDetected;
}

bool MotionSensorManager::detectMotionInLastMinute() {
    bool currentMotion = digitalRead(pirSensorPin);
    if (currentMotion) {
        lastMotionTime = millis();
    }

    unsigned long currentTime = millis();
    if (currentTime - lastMotionTime <= 60000) {
        return true;
    }
    return false;
}
void IRAM_ATTR MotionSensorManager::motionDetectedISR() {
    // Motion detected, wake up the device
    // Use the ESP32 deep sleep wakeup feature to wake up from deep sleep
    esp_sleep_enable_ext0_wakeup((gpio_num_t)GPIO_NUM_1, HIGH); // G1 as the wake-up pin
    esp_deep_sleep_start();
}

void MotionSensorManager::setupInterrupt() {
    // Set up the interrupt on the pirSensorPin for motion detection (RISING edge)
    attachInterrupt(digitalPinToInterrupt(pirSensorPin), motionDetectedISR, RISING); 
}