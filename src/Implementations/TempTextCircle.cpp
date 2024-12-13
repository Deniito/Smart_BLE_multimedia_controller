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
        M5.Lcd.fillCircle(x, y, radius + 5, mainColor);
    else
        M5.Lcd.fillCircle(x, y, radius, mainColor);

    M5.Lcd.setTextSize(1.3);
    M5.Lcd.setTextColor(iconBackgroundColor, mainColor);
    M5.Lcd.setTextDatum(CC_DATUM);

    M5.Lcd.setFont(&Orbitron_Light_24);

    std::ostringstream tempText;
    tempText.precision(1);
    tempText << std::fixed << displayTemp << "o" << unit;

    M5.Lcd.drawString(tempText.str().c_str(), x, y);
}
