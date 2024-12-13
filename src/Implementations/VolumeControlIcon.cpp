#include "headers/VolumeControlIcon.h"
#include "headers/DisplayManager.h"

VolumeControlIcon::VolumeControlIcon(int x, int y, int radius, uint16_t mainColor, uint16_t backgroundColor, 
                                           const std::string& imagePath)
    : RenderObject(x, y, radius, mainColor, backgroundColor, imagePath, ""), // Initialize base class with main and background colors
      bluetoothManager(BluetoothManager::getInstance()) // Initialize BluetoothManager instance
{
}

VolumeControlIcon::VolumeControlIcon(int x, int y, int radius, const std::string& imagePath)
    : RenderObject(x, y, radius, imagePath, ""), // Initialize base class with image path
      bluetoothManager(BluetoothManager::getInstance()) // Initialize BluetoothManager instance
{
}

void VolumeControlIcon::use(DisplayManager &displayManager) {
    while (!displayManager.getInputManager()->isHolding()) {
        int step = displayManager.getInputManager()->getStep();

        M5Dial.Lcd.setTextSize(1.25);

        M5.Lcd.setCursor(90, 35);
        M5.Lcd.setTextColor(M5.Lcd.color565(255, 255, 255), M5.Lcd.color565(0, 0, 0));
        M5.Lcd.print(("step: " + std::to_string(step)).c_str());

        if (step > 0)
            bluetoothManager.changeVolume(1);
        else if (step < 0)
            bluetoothManager.changeVolume(-1);
        M5Dial.update();
    }
    delay(1000);
}


int VolumeControlIcon::getRadius() const
{
    return this->radius;
}

void VolumeControlIcon::setRadius(int newRadius)
{
    this->radius = newRadius;
}

