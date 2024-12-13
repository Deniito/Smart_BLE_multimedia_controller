#pragma once


#include <string>
#include <vector>

#include "BluetoothManager.h"
#include "RenderObject.h"
#include "DisplayManager.h"

class BluetoothManager;

class ShortcutIcon : public RenderObject {
private:
    std::vector<unsigned int> keys;
    
    BluetoothManager& bluetoothManager;
public:
    ShortcutIcon(int x, int y, int radius, uint16_t mainColor, uint16_t backgroundColor,
                const std::string& imagePath, const std::string& selectedImagePath, 
                const std::vector<unsigned int>& customKeys);
                
    ShortcutIcon(int x, int y, int radius,const std::string& imagePath, 
                const std::string& selectedImagePath, 
                const std::vector<unsigned int>& customKeys);

    void use(DisplayManager& displayManager) override;

    // Getter for radius
    int getRadius() const;

    // Setter for radius
    void setRadius(int newRadius);
};
