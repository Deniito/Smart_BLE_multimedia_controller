#pragma once

#include "TextCircle.h"
#include "headers/TemperatureSensorManager.h"
#include <string>
#include <sstream>

// Declaration of TempTextCircle class
class TempTextCircle : public TextCircle {
private:
    float temp;                // To store the current temperature
    bool isCelsius;            // Temperature unit (Celsius or Fahrenheit)
    TemperatureSensorManager sensor; // Sensor instance for fetching temperature data

public:
    // Constructor
    TempTextCircle(int x, int y, int radius, const std::string& text = "", bool isCelsius = true);

    // Override the `use` function for toggling temperature unit
    void use(DisplayManager& displayManager) override;

    // Override the `render` function to display temperature
    void render() override;
};
