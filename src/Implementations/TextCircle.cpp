#include "headers/TextCircle.h"

// Constructor implementation
TextCircle::TextCircle(int x, int y, int radius, const std::string& text)
    : RenderObject(x, y, radius), text(text) {}

// Render method implementation
void TextCircle::render() {
    if (isSelected()) 
        M5.Lcd.fillCircle(x, y, radius + 5, iconBackgroundColor);
    else 
        M5.Lcd.fillCircle(x, y, radius, iconBackgroundColor);

    M5.Lcd.setTextSize(2);
    M5.Lcd.setTextColor(iconBackgroundColor, mainColor);
    M5.Lcd.setTextDatum(CC_DATUM);
    M5.Lcd.drawString(text.c_str(), x, y);
}

// Use method implementation
void TextCircle::use(DisplayManager& displayManager) {
    // Implementation specific to your use case
}

