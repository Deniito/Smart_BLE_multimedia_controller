#pragma once
#include "BluetoothManager.h"
#include "RenderObject.h"
#include <string>
#include <vector>
#include "DisplayManager.h"

class BluetoothManager;

class ShortcutIcon : public RenderObject {
private:
    std::vector<unsigned int> keys;
    std::string imagePath;  // Path to the image or icon file
    int radius;  // Radius of the circle
    BluetoothManager& bluetoothManager;
public:
    // Constructor to initialize position, radius, color, and image path
    ShortcutIcon(int x, int y, int radius, uint16_t color, const std::string& imagePath, const std::vector<unsigned int>& customKeys);
    // Override render method to draw the circle border and the image
    void render() override;

    void use(DisplayManager& displayManager) override;

    // Increase the radius of the circle and adjust the image size accordingly
    void increaseSize(int amount) override;

    // Getter for radius
    int getRadius() const;

    // Setter for radius
    void setRadius(int newRadius);
};
