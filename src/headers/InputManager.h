#pragma once
#include <M5Dial.h>
#include <M5Unified.h>
#include <memory>

class MenuState;  // Forward declaration to avoid cyclic dependency
class DisplayManager;  // Forward declaration

class InputManager {
private:
    long oldPosition;
    bool handleEncoder(DisplayManager& displayManager);
    bool handleButton(DisplayManager& displayManager);
public:
    bool isHolding();
    long readEncoder();
    bool handleInput(DisplayManager& displayManager);
    long getOldPosition();
    void setOldPosition(long newPosition);
    void resetEncoder();
    int getStep();
    InputManager();
    ~InputManager() = default;
};
