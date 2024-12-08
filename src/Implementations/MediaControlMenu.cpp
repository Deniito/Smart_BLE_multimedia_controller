#include "headers/MediaControlMenu.h"

MediaControlMenu::MediaControlMenu(DisplayManager& displayManager)
    : displayManager(&displayManager) {}

void MediaControlMenu::initialize(DisplayManager &displayManager)
{
        if (!isInitialized()) {  // Check if the menu is already initialized
        const auto& iconCords = displayManager.getItemsCords();  // Access the icon coordinates

        renderObjects.push_back(std::make_shared<ShortcutIcon>(
                220, 120, 15,
                M5.Lcd.color565(255, 0, 0), 
                "/icons/icon" + std::to_string(2 + 1) + ".bmp",
                std::vector<unsigned int>{'N'}));
        
        renderObjects.push_back(std::make_shared<ShortcutIcon>(
                120, 120, 45, 
                M5.Lcd.color565(255, 0, 0), 
                "/icons/icon" + std::to_string(2 + 1) + ".bmp",
                std::vector<unsigned int>{KEY_MEDIA_STOP[1]}));
        
        renderObjects.push_back(std::make_shared<MenuChangeIcon>(
                120, 20, 15,
                M5.Lcd.color565(0, 255, 0), 
                "/icons/icon" + std::to_string(2 + 1) + ".bmp",
                "MainMenu"));

        renderObjects.push_back(std::make_shared<ShortcutIcon>(
                20, 120, 15,
                M5.Lcd.color565(255, 0, 0), 
                "/icons/icon" + std::to_string(2 + 1) + ".bmp",
                std::vector<unsigned int>{'N'}));
                
        renderObjects.push_back(std::make_shared<VolumeControlIcon>(
                120, 220, 15,
                M5.Lcd.color565(0, 0, 255), 
                "path/to/image.png"));

        setIsInitialized(true);  // Mark the menu as initialized
    }
}

