#include "headers/MediaControlMenu.h"

MediaControlMenu::MediaControlMenu(DisplayManager& displayManager)
    : displayManager(&displayManager) {}

void MediaControlMenu::initialize(DisplayManager &displayManager)
{
        if (!isInitialized()) {  // Check if the menu is already initialized
        const auto& iconCords = displayManager.getItemsCords();  // Access the icon coordinates

        // For MediaControlIcon objects
        renderObjects.push_back(std::make_shared<MediaControlIcon>(
            220, 120, 15,                                // x, y, radius
            "",                                          // imagePath (empty string)
            "",                                          // selectedImagePath (empty string)
            KEY_MEDIA_NEXT_TRACK                          // key (e.g., 'N')
        ));

        renderObjects.push_back(std::make_shared<MediaControlIcon>(
            120, 120, 45,                                // x, y, radius
            "",                                          // imagePath (empty string)
            "",                                          // selectedImagePath (empty string)
            KEY_MEDIA_PLAY_PAUSE                        // key (e.g., stop key)
        ));

        // For MenuChangeIcon
        renderObjects.push_back(std::make_shared<MenuChangeIcon>(
            120, 20, 15,                                 // x, y, radius
            "/Back_not_selected.png",                    // imagePath (image path)
            "/Back_selected.png",                        // selectedImagePath (selected menu name)
            "MainMenu"                                   // newMenuName (new menu name)
        ));

        // For another MediaControlIcon
        renderObjects.push_back(std::make_shared<MediaControlIcon>(
            20, 120, 15,                                 // x, y, radius
            "",                                          // imagePath (empty string)
            "",                                          // selectedImagePath (empty string)
            KEY_MEDIA_PREVIOUS_TRACK                     // key (e.g., 'N')
        ));

        // For VolumeControlIcon objects
        renderObjects.push_back(std::make_shared<VolumeControlIcon>(
            120, 220, 15,                                // x, y, radius
            ""                                           // imagePath (empty string)
        ));


        setIsInitialized(true);  // Mark the menu as initialized
    }
}

