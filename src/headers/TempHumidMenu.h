#pragma once
#include "headers/MenuState.h"
#include "headers/MenuChangeIcon.h"
#include "headers/TemperatureSensorManager.h"

// Forward declare TemperatureSensorManager

class TempHumidMenu : public MenuState {
private:
    DisplayManager* displayManager;
public:
    TempHumidMenu(DisplayManager& displayManager);
    void initialize(DisplayManager& displayManager) override;
};
