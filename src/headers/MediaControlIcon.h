#pragma once

#include "mediaKeyReport.h"

#include <string>
#include <vector>

#include "DisplayManager.h"
#include "RenderObject.h"
#include "BluetoothManager.h"



class BluetoothManager;

class MediaControlIcon : public RenderObject {
private:  
    const MediaKeyReport key; 
    BluetoothManager& bluetoothManager;
public:
    MediaControlIcon(int x, int y, int radius, const std::string& imagePath, 
                        const std::string& selectedImagePath, const MediaKeyReport key);

    MediaControlIcon(int x, int y, int radius, uint16_t mainColor, uint16_t backgroundColor, const std::string& imagePath, 
                        const std::string& selectedImagePath, const MediaKeyReport key);

    void use(DisplayManager& displayManager) override;
};
