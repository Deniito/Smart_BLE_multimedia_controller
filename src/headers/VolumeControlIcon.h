#pragma once

#include "BluetoothManager.h"
#include "RenderObject.h"
#include <string>
#include <vector>

class BluetoothManager;

class VolumeControlIcon : public RenderObject {
private:
    BluetoothManager& bluetoothManager;
public:
    VolumeControlIcon(int x, int y, int radius, uint16_t mainColor, uint16_t backgroundColor, const std::string& imagePath);

    VolumeControlIcon(int x, int y, int radius, const std::string& imagePath);    

    void use(DisplayManager& displayManager) override;

    int getRadius() const;

    void setRadius(int newRadius);
};