#pragma once

#include "headers/MenuState.h"
#include "headers/DisplayManager.h"
#include "headers/MenuChangeIcon.h"

#include <memory>
#include <vector>
#include <string>

class MainMenu : public MenuState {
private:
    DisplayManager* displayManager;
public:
    MainMenu(DisplayManager& displayManager);
    void initialize(DisplayManager& displayManager) override;
};
