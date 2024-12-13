#include "headers/MenuChangeIcon.h"
#include "headers/DisplayManager.h"

MenuChangeIcon::MenuChangeIcon(int x, int y, int radius, uint16_t color, uint16_t backgroundColor, 
                   const std::string& imagePath, const std::string& selectedImagePath, 
                   const std::string& newMenuName)
        : RenderObject(x, y, radius, color, backgroundColor, imagePath, selectedImagePath), 
          newMenuName(newMenuName) {}

    // Constructor without color parameters
MenuChangeIcon::MenuChangeIcon(int x, int y, int radius, const std::string& imagePath, 
                   const std::string& selectedImagePath, const std::string& newMenuName)
        : RenderObject(x, y, radius, imagePath, selectedImagePath), 
          newMenuName(newMenuName) {}
          
void MenuChangeIcon::use(DisplayManager &displayManager) {
    displayManager.setMenuState(this->newMenuName);
}

int MenuChangeIcon::getRadius() const
{
    return this->radius;
}

void MenuChangeIcon::setRadius(int newRadius)
{
    this->radius = newRadius;
}
