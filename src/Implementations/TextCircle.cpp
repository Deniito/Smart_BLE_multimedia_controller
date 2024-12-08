#include "headers/TextCircle.h"

// Constructor implementation
TextCircle::TextCircle(int x, int y, int radius, const std::string& text)
    : RenderObject(x, y), text(text), radius(radius) {}

// Render method implementation
void TextCircle::render() {
    if (isSelected()) 
        M5.Lcd.fillCircle(x, y, radius + 5, color);
    else 
        M5.Lcd.fillCircle(x, y, radius, color);

    M5.Lcd.setTextSize(2);
    M5.Lcd.setTextColor(M5.Lcd.color565(100, 95, 92), color);
    M5.Lcd.setTextDatum(CC_DATUM);
    M5.Lcd.drawString(text.c_str(), x, y);
}

// Use method implementation
void TextCircle::use(DisplayManager& displayManager) {
    // Implementation specific to your use case
}

// Increase size method implementation
void TextCircle::increaseSize(int amount) {
    radius += amount;
    if (radius < 0) radius = 0;
}
