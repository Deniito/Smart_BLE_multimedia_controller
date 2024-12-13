#include "headers/LightSensorManager.h"

// Constructor
LightSensorManager::LightSensorManager() {}

// Initialize the sensor
bool LightSensorManager::begin()
{
    if (!veml.begin())
    {
        return false; // Return false if the sensor is not found
    }
    lastReadTime = 30000;
    return true; // Return true if initialization is successful
}

// Read and cache the current lux value
void LightSensorManager::updateLux()
{
    unsigned long currentTime = millis();
    if (currentTime - lastReadTime >= luxReadInterval) 
    {
        cachedLux = veml.readLux(VEML_LUX_AUTO);
        lastReadTime = currentTime;
    }
}

// Get the cached lux value
float LightSensorManager::getLux()
{
    return cachedLux;
}

// Scale lux value to brightness using default parameters
int LightSensorManager::scaleBrightness()
{
    updateLux(); // Ensure the lux value is up to date

    // Read the cached lux value
    float lux = getLux();

    // Clamp lux value to range
    if (lux < luxMin) lux = luxMin;
    if (lux > luxMax) lux = luxMax;

    // Normalize lux and apply gamma correction
    float normalized = (lux - luxMin) / (luxMax - luxMin);
    return minBrightness + pow(normalized, gamma) * (maxBrightness - minBrightness);
}

// Get the current gain setting as a string
String LightSensorManager::getGain()
{
    switch (veml.getGain())
    {
    case VEML7700_GAIN_1:
        return "1";
    case VEML7700_GAIN_2:
        return "2";
    case VEML7700_GAIN_1_4:
        return "1/4";
    case VEML7700_GAIN_1_8:
        return "1/8";
    default:
        return "Unknown";
    }
}

// Get the current integration time as a string
String LightSensorManager::getIntegrationTime()
{
    switch (veml.getIntegrationTime())
    {
    case VEML7700_IT_25MS:
        return "25";
    case VEML7700_IT_50MS:
        return "50";
    case VEML7700_IT_100MS:
        return "100";
    case VEML7700_IT_200MS:
        return "200";
    case VEML7700_IT_400MS:
        return "400";
    case VEML7700_IT_800MS:
        return "800";
    default:
        return "Unknown";
    }
}
