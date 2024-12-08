#include "headers/VolumeControlIcon.h"
#include "headers/DisplayManager.h"

VolumeControlIcon::VolumeControlIcon(int x, int y, int radius, uint16_t color, const std::string& imagePath)
    : RenderObject(x, y, color), radius(radius), imagePath(imagePath),
      bluetoothManager(BluetoothManager::getInstance())
{
}
void VolumeControlIcon::render() {
    if (isSelected()) {
        M5.Lcd.fillCircle(x, y, radius+5, M5Dial.Lcd.color565(100, 100, 100));
    } else {
        M5.Lcd.fillCircle(x, y, radius, M5Dial.Lcd.color565(100, 100, 100));
    }

    M5.Lcd.fillRect(x-(radius/2), y-(radius/2), radius, radius, this->color);  // Placeholder for the image
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

void VolumeControlIcon::increaseSize(int amount)
{
    this->radius += amount;
}

int VolumeControlIcon::getRadius() const
{
    return this->radius;
}

void VolumeControlIcon::setRadius(int newRadius)
{
    this->radius = newRadius;
}

