#include "headers/MediaControlIcon.h"
MediaControlIcon::MediaControlIcon(int x, int y, int radius, const std::string& imagePath, 
                                   const std::string& selectedImagePath, const MediaKeyReport key)
    : RenderObject(x, y, radius, imagePath, selectedImagePath), // Initialize base class with x, y, and image paths
      bluetoothManager(BluetoothManager::getInstance()), // Initialize BluetoothManager instance
      key{key[0], key[1]} // Initialize const member `key` in initializer list
{}

MediaControlIcon::MediaControlIcon(int x, int y, int radius, uint16_t mainColor, uint16_t backgroundColor, 
                                   const std::string& imagePath, const std::string& selectedImagePath, 
                                   const MediaKeyReport key)
    : RenderObject(x, y, radius, mainColor, backgroundColor, imagePath, selectedImagePath), // Initialize base class
      bluetoothManager(BluetoothManager::getInstance()), // Initialize BluetoothManager instance
      key{key[0], key[1]} // Initialize const member `key` in initializer list
{}


void MediaControlIcon::use(DisplayManager& displayManager) {

}

