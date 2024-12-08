#include "headers/MainMenu.h"
#include "headers/DisplayManager.h"
#include "headers/ShortcutIcon.h"

MainMenu::MainMenu(DisplayManager& displayManager)
    : displayManager(&displayManager) {}

void MainMenu::initialize(DisplayManager& displayManager) {
    if (!isInitialized()) {
        const auto& iconCords = displayManager.getItemsCords();

        renderObjects.push_back(std::make_shared<MenuChangeIcon>(
                iconCords[0][0], iconCords[0][1], 15,
                M5.Lcd.color565(0, 255, 0), 
                "/icons/icon" + std::to_string(2 + 1) + ".bmp",
                "MediaControlMenu"));

        renderObjects.push_back(std::make_shared<MenuChangeIcon>(
                iconCords[1][0], iconCords[1][1], 15,
                M5.Lcd.color565(0, 255, 0), 
                "/icons/icon" + std::to_string(2 + 1) + ".bmp",
                "TempHumidMenu"));
        
        renderObjects.push_back(std::make_shared<ShortcutIcon>(
                iconCords[2][0], iconCords[2][1], 15, 
                M5.Lcd.color565(255, 0, 0), 
                "/icons/icon" + std::to_string(2 + 1) + ".bmp",
                std::vector<unsigned int>{KEY_LEFT_CTRL, KEY_LEFT_GUI, 'n'}));
        
        renderObjects.push_back(std::make_shared<ShortcutIcon>(
                iconCords[3][0], iconCords[3][1], 15, 
                M5.Lcd.color565(255, 0, 0), 
                "/icons/icon" + std::to_string(2 + 1) + ".bmp",
                std::vector<unsigned int>{KEY_LEFT_GUI, KEY_LEFT_SHIFT, 'n'}));

        setIsInitialized(true);
    }
}
