#pragma once
#include "RenderObject.h"
#include <string>
#include <vector>

class DisplayManager;

class MenuChangeIcon : public RenderObject {
private:
    std::string newMenuName;
    std::string imagePath;
    int radius;
public:
    MenuChangeIcon(int x, int y, int radius, uint16_t color, const std::string& imagePath, const std::string newMenuName);

    void render() override;

    void use(DisplayManager& displayManager) override;

    void increaseSize(int amount) override;

    int getRadius() const;

    void setRadius(int newRadius);
};
