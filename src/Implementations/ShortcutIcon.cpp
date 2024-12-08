#include "headers/ShortcutIcon.h"

ShortcutIcon::ShortcutIcon(int x, int y, int radius, uint16_t color, const std::string& imagePath, const std::vector<unsigned int>& customKeys)
    : RenderObject(x, y, color), radius(radius), imagePath(imagePath), keys(customKeys), bluetoothManager(BluetoothManager::getInstance()) {
}

void ShortcutIcon::render() {
    if (isSelected()) {
        M5.Lcd.fillCircle(x, y, radius+5, M5Dial.Lcd.color565(100, 100, 100));
    } else {
        M5.Lcd.fillCircle(x, y, radius, M5Dial.Lcd.color565(100, 100, 100));

    }

    // Draw the image inside the circle (Placeholder: using fillRect for now)
    // Center the image within the circle using radius
    M5.Lcd.fillRect(x-(radius/2), y-(radius/2), radius, radius, M5.Lcd.color565(255, 0, 0));  // Placeholder for the image
}

void ShortcutIcon::use(DisplayManager& displayManager) {
    bluetoothManager.sendKeyPress(keys);
}
void ShortcutIcon::increaseSize(int amount) {
    radius += amount;
}

int ShortcutIcon::getRadius() const {
    return radius;
}

void ShortcutIcon::setRadius(int newRadius) {
    radius = newRadius;
}
