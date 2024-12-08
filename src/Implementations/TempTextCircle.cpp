#include "headers/TempTextCircle.h"

// Constructor implementation
TempTextCircle::TempTextCircle(int x, int y, int radius, const std::string& text, bool isCelsius)
    : TextCircle(x, y, radius, text), temp(0.0f), isCelsius(isCelsius) {
    sensor.initialize();
}

// Override `use` function implementation
void TempTextCircle::use(DisplayManager& displayManager) {
    isCelsius = !isCelsius; 
}

// Override `render` function implementation
void TempTextCircle::render() {
    sensor.read();
    temp = sensor.getTemp();

    float displayTemp = isCelsius ? temp : (temp * 9 / 5) + 32;
    std::string unit = isCelsius ? "C" : "F";

    if (isSelected())
        M5.Lcd.fillCircle(x, y, radius + 5, color);
    else
        M5.Lcd.fillCircle(x, y, radius, color);

    M5.Lcd.setTextSize(2);
    M5.Lcd.setTextColor(M5.Lcd.color565(100, 95, 92), color);
    M5.Lcd.setTextDatum(CC_DATUM);

    std::ostringstream tempText;
    tempText.precision(2);
    tempText << std::fixed << displayTemp << "o" << unit;

    M5.Lcd.drawString(tempText.str().c_str(), x, y);
}
