#pragma once


#include <string>
#include <sstream>

#include "TextCircle.h"
#include "headers/TemperatureSensorManager.h"

class TempTextCircle : public TextCircle {
private:
    float temp;
    bool isCelsius;
    TemperatureSensorManager sensor;

public:
    TempTextCircle(int x, int y, int radius, const std::string& text = "", bool isCelsius = true);

    void use(DisplayManager& displayManager) override;

    void render() override;
};
