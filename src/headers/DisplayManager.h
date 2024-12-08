#pragma once

#include "headers/MainMenu.h"
#include "headers/MenuState.h"
#include "headers/InputManager.h"
#include "headers/MediaControlMenu.h"
#include "headers/TempHumidMenu.h"

#include <M5Dial.h>
#include <unordered_map>
#include <memory>
#include <string>

class DisplayManager {
private:
    std::shared_ptr<MenuState> currentMenuState; // Pointer to the currently active menu
    std::unordered_map<std::string, std::shared_ptr<MenuState>> menuRegistry; // Registry of menu states
    std::shared_ptr<InputManager> inputManager;
    
    std::array<std::array<int, 2>, 12> itemsCords = {{
        {{120, 20}}, {{70, 33}}, {{33, 70}},
        {{20, 120}}, {{33, 170}}, {{70, 207}},
        {{120, 220}}, {{170, 207}}, {{207, 170}},
        {{220, 120}}, {{206, 70}}, {{170, 33}}
    }};
    int brightness;
public:
    DisplayManager();
    const std::array<std::array<int, 2>, 12>& getItemsCords();
    bool setMenuState(const std::string& name);
    void setBrightness(int newBrightness);

    void registerMenuState(const std::string& name, std::shared_ptr<MenuState> menuState);

    bool update();

    std::shared_ptr<InputManager> getInputManager();
    std::shared_ptr<MenuState> getCurrentMenuState();

    void clearScreen();
    void showMessage(const std::string& message, int y_offset = 0);
    void animateOpening(int origin_x = 0, int origin_y = 0, int speed = 1, int rad = 120, uint16_t color = M5.Lcd.color565(100, 47, 18));
};
