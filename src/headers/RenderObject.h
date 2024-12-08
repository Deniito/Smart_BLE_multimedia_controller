#pragma once
#include <M5Dial.h>

class DisplayManager;

class RenderObject {
protected:
    int x, y;  // Position of the object
    uint16_t color = M5.Lcd.color565(100, 47, 18);
    bool selected;  // Whether the object is selected
public:
    RenderObject()
        : x(0), y(0), color(M5.Lcd.color565(100, 47, 18)), selected(false) {}
    RenderObject(int x, int y)
        : x(x), y(y), color(M5.Lcd.color565(100, 47, 18)), selected(false) {}
    RenderObject(int x, int y, uint16_t color)
        : x(x), y(y), color(color), selected(false) {}

    virtual ~RenderObject() = default;

    // Pure virtual render method
    virtual void render() = 0;

    virtual void use(DisplayManager& displayManager) = 0;

    // Accessors
    const bool& isSelected() const { return selected; }
    const int& getX() const { return x; }
    const int& getY() const { return y; }
    const uint16_t& getColor() const { return color; }

    // Mutators
    virtual void increaseSize(int amount);
    void setPosition(int x, int y) { this->x = x; this->y = y; }
    void setColor(uint16_t color) { this->color = color; }
    void setSelected(bool isSelected) { this->selected = isSelected; }
};
