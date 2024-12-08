#include "headers/TempHumidMenu.h"
#include "headers/TempHumidMenu.h"
#include "headers/TempTextCircle.h"


TempHumidMenu::TempHumidMenu(DisplayManager& displayManager) 
    : displayManager(&displayManager)
    {}

void TempHumidMenu::initialize(DisplayManager &displayManager)
{
    if (isInitialized()) return;

    renderObjects.push_back(std::make_shared<MenuChangeIcon>(
            120, 220, 15,
            M5.Lcd.color565(0, 255, 0), 
            "/icons/icon" + std::to_string(2 + 1) + ".bmp",
            "MainMenu"));

    renderObjects.push_back(std::make_shared<TempTextCircle>(
            120, 120, 55, 
            "C", -273.15));

    setIsInitialized(true);
        
    delay(1000);
}