#include "headers/MainMenu.h"
#include "headers/DisplayManager.h"
#include "headers/ShortcutIcon.h"

MainMenu::MainMenu(DisplayManager& displayManager)
    : displayManager(&displayManager) {}

void MainMenu::initialize(DisplayManager& displayManager) {
    if (!isInitialized()) {
        const auto& iconCords = displayManager.getItemsCords();

    renderObjects.push_back(std::make_shared<MenuChangeIcon>(
        iconCords[0][0], iconCords[0][1], 15,        // x, y, radius
        "",                                          // imagePath (empty string)
        "",                                          // selectedImagePath (valid name)
        "MediaControlMenu"                          // newMenuName (empty string)
    ));

    renderObjects.push_back(std::make_shared<MenuChangeIcon>(
        iconCords[1][0], iconCords[1][1], 15,        // x, y, radius
        "",                                          // imagePath (empty string)
        "",                                         // selectedImagePath (valid name)
        "TempHumidMenu"                              // newMenuName (empty string)
    ));

    // For ShortcutIcon objects
    renderObjects.push_back(std::make_shared<ShortcutIcon>(
        iconCords[2][0], iconCords[2][1], 15,                           // x, y, radius
        "",                                                         // imagePath (empty string)
        "",                                                         // selectedImagePath (empty string)
        std::vector<unsigned int>{KEY_LEFT_CTRL, KEY_LEFT_GUI, 'n'}  // key combination
    ));

    renderObjects.push_back(std::make_shared<ShortcutIcon>(
        iconCords[3][0], iconCords[3][1], 15,                       // x, y, radius
        "",                                                         // imagePath (empty string)
        "",                                                         // selectedImagePath (empty string)
        std::vector<unsigned int>{KEY_LEFT_GUI, KEY_LEFT_SHIFT, 'n'}  // key combination
    ));


        setIsInitialized(true);
    }
}
