#include <iostream>
#include <unordered_map>
#include <memory>

#include "headers/DisplayManager.h"

DisplayManager::DisplayManager() {
    
    inputManager = std::make_shared<InputManager>();  // Example of proper initialization

    registerMenuState("MainMenu", std::move(std::make_shared<MainMenu>(*this)));
    registerMenuState("MediaControlMenu", std::move(std::make_shared<MediaControlMenu>(*this)));
    registerMenuState("TempHumidMenu", std::move(std::make_shared<TempHumidMenu>(*this)));

    setMenuState("MediaControlMenu");
}

void DisplayManager::setBrightness(int newBrightness)
{
    this->brightness = newBrightness;
    M5Dial.Display.setBrightness(brightness);
}
const std::array<std::array<int, 2>, 12>& DisplayManager::getItemsCords() {
    return this->itemsCords;
}

bool DisplayManager::setMenuState(const std::string& name) {
    auto it = menuRegistry.find(name);
    if (it != menuRegistry.end()) {
        currentMenuState = it->second; // Share ownership
        currentMenuState->render(*this);
        return true;
    }
    return false;
}
void DisplayManager::registerMenuState(const std::string& name, std::shared_ptr<MenuState> menuState) {
    menuRegistry[name] = menuState;
}

bool DisplayManager::update() {
    if (currentMenuState && !currentMenuState->isInitialized()) {
        currentMenuState->initialize(*this);  // Initialize the menu if it wasn't done before
        return true;
    }

    else if (currentMenuState && currentMenuState->isInitialized()) {
        bool wasUpdated = currentMenuState->update();
        bool inputDetected = inputManager->handleInput(*this);
        if ((inputManager && inputDetected) || wasUpdated) 
        {
            currentMenuState->render(*this);
            return true;
        }

    }
    return false;
}

std::shared_ptr<InputManager> DisplayManager::getInputManager()
{
    return this->inputManager;
}
std::shared_ptr<MenuState> DisplayManager::getCurrentMenuState()
{
    return this->currentMenuState;
}
void DisplayManager::clearScreen() {
       M5Dial.Display.clear();
}

void DisplayManager::showMessage(const std::string& message, int y_offset) {
    int x = 120, y = 160 + y_offset, height = 20, radius = 8;
    uint16_t rectColor = M5.Lcd.color565(187, 72, 10);
    uint16_t textColor = M5.Lcd.color565(55, 55, 55);

    M5Dial.Lcd.setTextSize(2);
    M5Dial.Lcd.setTextColor(textColor);
    M5.Lcd.setTextDatum(CC_DATUM);

    int text_width = message.length() * 12 + 20;

    M5Dial.Lcd.fillRoundRect(x - text_width / 2, y, text_width, height, radius, rectColor);
    M5Dial.Lcd.drawCentreString(message.c_str(), x, y + 2);
}

void DisplayManager::animateOpening(int origin_x, int origin_y, int speed, int rad, uint16_t color) {
    for (int i = 0; i < std::abs(rad); i++) {
        M5.Lcd.fillCircle(origin_x, origin_y, i, color);
        if(speed != 0)
            delay(i / (10 * std::abs(speed)));
    }
    this->currentMenuState->render(*this);
}
