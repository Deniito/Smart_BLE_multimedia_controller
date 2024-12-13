#pragma once

#include "FS.h"
#include "SPIFFS.h"
#include <SD.h>
#include <M5Dial.h>

class DisplayManager;

class RenderObject {
protected:
    const int x, y;
    uint16_t mainColor = M5.Lcd.color565(187, 72, 10);
    uint16_t iconBackgroundColor = M5.Lcd.color565(55, 55, 55); 

    std::string imagePath;
    std::string selectedImagePath;

    bool selected;
    int radius = 15;

public:
    // Default constructor
    RenderObject()
        : x(0), y(0), selected(false) {}

    // Constructor with x and y coordinates
    RenderObject(int x, int y, int radius)
        : x(x), y(y), radius(radius), selected(false) {}
    
    RenderObject(int x, int y, int radius, const std::string& imagePath, const std::string& selectedImagePath)
        : x(x), y(y), radius(radius), selected(false), imagePath(imagePath), selectedImagePath(selectedImagePath) {}
    
    RenderObject(int x, int y, int radius, uint16_t mainColor)
        : x(x), y(y), radius(radius), mainColor(mainColor), selected(false) {}
    
    RenderObject(int x, int y, int radius, uint16_t mainColor, uint16_t backgroundColor)
        : x(x), y(y), radius(radius), mainColor(mainColor), iconBackgroundColor(backgroundColor), selected(false) {}

    // Constructor with x, y coordinates and two colors (main and background)
    RenderObject(int x, int y, int radius, uint16_t mainColor, uint16_t backgroundColor, const std::string& imagePath, const std::string& selectedImagePath)
        : x(x), y(y), radius(radius), mainColor(mainColor), iconBackgroundColor(backgroundColor), selected(false), imagePath(imagePath), selectedImagePath(selectedImagePath) {}

    virtual ~RenderObject() = default;

    // Pure virtual render method
    virtual void render() {
    if (isSelected()) {
        M5.Lcd.fillCircle(x, y, radius+5, this->iconBackgroundColor);
        M5Dial.Lcd.drawPngFile(SPIFFS, selectedImagePath.c_str(), x-radius, y-radius);
    } else {
        M5.Lcd.fillCircle(x, y, radius, this->iconBackgroundColor);
        M5Dial.Lcd.drawPngFile(SPIFFS, imagePath.c_str(), x-radius, y-radius);
    }
    }

    virtual void use(DisplayManager& displayManager) = 0;

    // Accessors
    const bool& isSelected() const { return selected; }
    const int& getX() const { return x; }
    const int& getY() const { return y; }
    const uint16_t& getMainColor() const { return mainColor; }
    const uint16_t& getIconBackgroundColor() const { return iconBackgroundColor; }


    // Mutators
    void setMainColor(uint16_t color) { this->mainColor = color; }
    void setIconBackgroundColor(uint16_t backgroundColor) { this->iconBackgroundColor = backgroundColor; }
    void setSelected(bool isSelected) { this->selected = isSelected; }
};
