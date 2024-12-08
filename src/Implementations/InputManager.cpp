#include "headers/InputManager.h"
#include "headers/MenuState.h"
#include "headers/DisplayManager.h"

InputManager::InputManager()
{
    M5Dial.Encoder.write(0);
}
void InputManager::resetEncoder()
{
    M5Dial.Encoder.write(0);
}
bool InputManager::handleInput(DisplayManager& displayManager){
    if(!displayManager.getCurrentMenuState())
        return false;
    bool encoderActionRegistered = handleEncoder(displayManager);
    bool buttonActionRegistered = handleButton(displayManager);
    if(encoderActionRegistered || buttonActionRegistered)
        return true;
    return false;
}
bool InputManager::handleEncoder(DisplayManager& displayManager) {
    long newPosition = M5Dial.Encoder.read();
    long delta = newPosition - oldPosition;

    // Get the number of render objects in the current menu
    size_t numOptions = displayManager.getCurrentMenuState()->getRenderObjectCount();

    // Only adjust if the delta is large enough
    if (delta > 3) {
        // Move up in the menu, with wrap-around logic
        int newSelection = displayManager.getCurrentMenuState()->getSelectedOption() - 1;
        if (newSelection < 0) {
            newSelection = numOptions - 1; // Wrap around to the last option
        }
        displayManager.getCurrentMenuState()->setSelectedOption(newSelection);
        oldPosition = newPosition; 
    } else if (delta < -3) {
        // Move down in the menu, with wrap-around logic
        int newSelection = displayManager.getCurrentMenuState()->getSelectedOption() + 1;
        if (newSelection >= numOptions) {
            newSelection = 0; // Wrap around to the first option
        }
        displayManager.getCurrentMenuState()->setSelectedOption(newSelection);
        oldPosition = newPosition; 
    } else {
        return false; 
    }

    return true;
}

bool InputManager::handleButton(DisplayManager& displayManager) {
    // Check the button state
    if (M5.BtnA.isPressed()) {
        delay(200);
        displayManager.getCurrentMenuState()->getSelectedObject()->use(displayManager);
        // int x = MenuState->getSelectedObject()->getX();
        // int y = MenuState->getSelectedObject()->getY();
        // displayManager.animateOpening(x,y,9000, 240);
        return true;
    }
  return false;
}

bool InputManager::isHolding()
{
    return M5.BtnA.isHolding();
}

long InputManager::getOldPosition(){
    return this->oldPosition;
}

void InputManager::setOldPosition(long newPosition){
    this->oldPosition = newPosition;
}

int InputManager::getStep(){
    long newPosition = M5Dial.Encoder.read();
    long delta = newPosition - oldPosition;

    if (delta > 3) {
        oldPosition = newPosition; 
        return 1;
    } else if (delta < -3) {
        oldPosition = newPosition; 
        return -1;
    } else {
        return 0;
    }
}
long InputManager::readEncoder() {
    return M5Dial.Encoder.read();
}