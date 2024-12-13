#include "headers/ShortcutIcon.h"

ShortcutIcon::ShortcutIcon(int x, int y, int radius, uint16_t mainColor, uint16_t backgroundColor, 
                               const std::string& imagePath, const std::string& selectedImagePath, 
                               const std::vector<unsigned int>& customKeys)
    : RenderObject(x, y, radius, mainColor, backgroundColor, imagePath, selectedImagePath), // Initialize base class
      keys(customKeys), 
      bluetoothManager(BluetoothManager::getInstance()) // Initialize BluetoothManager instance
{
}

ShortcutIcon::ShortcutIcon(int x, int y, int radius, const std::string& imagePath, 
                           const std::string& selectedImagePath, 
                           const std::vector<unsigned int>& customKeys)
    : RenderObject(x, y, radius, imagePath, selectedImagePath), // Initialize base class with image paths
      keys(customKeys), 
      bluetoothManager(BluetoothManager::getInstance()) // Initialize BluetoothManager instance
{
}

void ShortcutIcon::use(DisplayManager& displayManager) {
    bluetoothManager.sendKeyPress(keys);
}

int ShortcutIcon::getRadius() const {
    return radius;
}

void ShortcutIcon::setRadius(int newRadius) {
    radius = newRadius;
}
