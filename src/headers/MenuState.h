#pragma once
#include <string>
#include <vector>
#include <memory> 


#include "RenderObject.h"

class DisplayManager; // Forward declaration to avoid cyclic dependency

class MenuState {
private:
    size_t selectedOption = 0;
    uint16_t BackgndColor = M5.Lcd.color565(0,0,0);
    bool initialized = 0;
protected:
    std::vector<std::shared_ptr<RenderObject>> renderObjects;
public:
    void render(DisplayManager& displayManager);
    virtual void initialize(DisplayManager& displayManager) = 0;
    virtual ~MenuState() = default;

    uint16_t getBackgndColor();
    void setSelectedOption(const size_t& selectedOption);

    virtual bool update() { return false; }

    const bool& isInitialized();
    const size_t& getSelectedOption();
    std::shared_ptr<RenderObject> getSelectedObject();

    void setIsInitialized(const bool& initialized);
    void setSelectedOption(const int& selectedOption);
    size_t getRenderObjectCount();
};
