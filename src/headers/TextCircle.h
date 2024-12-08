#pragma once

#include "headers/RenderObject.h"
#include <M5Dial.h>
#include <string>

// Declaration of TextCircle class
class TextCircle : public RenderObject {
protected:
    std::string text;
    int radius;

public:
    // Constructor
    TextCircle(int x, int y, int radius, const std::string& text = "Default");

    // Override render method
    void render() override;

    // Override use method
    void use(DisplayManager& displayManager) override;

    // Override increaseSize method
    void increaseSize(int amount) override;
};
