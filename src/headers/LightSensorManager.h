#pragma once

#include "Adafruit_VEML7700.h"

class LightSensorManager
{
private:
    Adafruit_VEML7700 veml;
    unsigned long lastReadTime = 0;
    float cachedLux = 0.0;
    const unsigned long luxReadInterval = 30000; // Read lux every 30 second
    const float luxMin = 1.0;
    const float luxMax = 400.0;
    const int minBrightness = 10;
    const int maxBrightness = 255;
    const float gamma = 0.8;

public:
    // Constructor
    LightSensorManager();

    // Initialize the sensor
    bool begin();

    // Read and cache the current lux value
    void updateLux();

    // Get the cached lux value
    float getLux();

    // Scale lux value to brightness using default parameters
    int scaleBrightness();

    // Get the current gain setting as a string
    String getGain();

    // Get the current integration time as a string
    String getIntegrationTime();
};
