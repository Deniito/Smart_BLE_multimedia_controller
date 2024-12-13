#pragma once

#include <string>
#include <vector>

#include "RenderObject.h"


class DisplayManager;

class MenuChangeIcon : public RenderObject {
private:
    std::string newMenuName;
public:
    MenuChangeIcon(int x, int y, int radius, uint16_t color, uint16_t backgroundColor, 
                   const std::string& imagePath, const std::string& selectedImagePath, 
                   const std::string& newMenuName);
                   
    MenuChangeIcon(int x, int y, int radius, const std::string& imagePath, 
                   const std::string& selectedImagePath, const std::string& newMenuName);

    void use(DisplayManager& displayManager) override;

    int getRadius() const;

    void setRadius(int newRadius);
};
