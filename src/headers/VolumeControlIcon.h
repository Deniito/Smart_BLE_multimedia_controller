#pragma once
#include "BluetoothManager.h"
#include "RenderObject.h"
#include <string>
#include <vector>

class BluetoothManager;

class VolumeControlIcon : public RenderObject {
private:
    std::string imagePath;  // Path to the image or icon file
    int radius;  // Radius of the circle
    BluetoothManager& bluetoothManager;
public:
    VolumeControlIcon(int x, int y, int radius, uint16_t color, const std::string& imagePath);

    void render() override;

    void use(DisplayManager& displayManager) override;

    void increaseSize(int amount) override;

    int getRadius() const;

    void setRadius(int newRadius);
};