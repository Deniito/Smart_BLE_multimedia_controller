#include "headers/MenuChangeIcon.h"
#include "headers/DisplayManager.h"


MenuChangeIcon::MenuChangeIcon(int x, int y, int radius, uint16_t color, const std::string& imagePath, const std::string newMenuName)
    : RenderObject(x, y, color), radius(radius), imagePath(imagePath), newMenuName(newMenuName)
{
}
void MenuChangeIcon::render() {
    if (isSelected()) {
        M5.Lcd.fillCircle(x, y, radius+5, M5Dial.Lcd.color565(100, 100, 100));
    } else {
        M5.Lcd.fillCircle(x, y, radius, M5Dial.Lcd.color565(100, 100, 100));
    }

    M5.Lcd.fillRect(x-(radius/2), y-(radius/2), radius, radius, this->color);  // Placeholder for the image
}

void MenuChangeIcon::use(DisplayManager &displayManager) {
    displayManager.setMenuState(this->newMenuName);
}

void MenuChangeIcon::increaseSize(int amount)
{
    this->radius += amount;
}

int MenuChangeIcon::getRadius() const
{
    return this->radius;
}

void MenuChangeIcon::setRadius(int newRadius)
{
    this->radius = newRadius;
}
