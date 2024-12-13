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
            "/Back_not_selected.png",
            "/Back_selected.png",
            "MainMenu"));

    renderObjects.push_back(std::make_shared<TempTextCircle>(
        120, 100, 70,  // x, y, radius
        "C",           // text
        -273.15        // isCelsius (this should be a temperature value, not a boolean)
    ));

    setIsInitialized(true);
        
    delay(1000);
}