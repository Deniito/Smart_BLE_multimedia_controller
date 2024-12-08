#include "headers/MenuState.h"
#include "headers/MenuState.h"

uint16_t MenuState::getBackgndColor(){
    return BackgndColor;
}
void MenuState::render(DisplayManager& displayManager) {
    int index = 0;
    M5Dial.Lcd.clear();
    for (const auto& record : renderObjects) {
        // Highlight the selected option based on the index and selected option
        if (index == this->getSelectedOption()) {
            record->setSelected(true);  // Set the selected status
        } else {
            record->setSelected(false);  // Set the unselected status
        }
        // Render the current object (RenderIcon in this case)
        record->render();
        index++;
    }
}
void MenuState::setSelectedOption(const size_t& selectedOption)
{
    this->selectedOption = selectedOption;
}
const bool& MenuState::isInitialized()
{
    return initialized;
}
const size_t &MenuState::getSelectedOption()
{
    return this->selectedOption; 
}
std::shared_ptr<RenderObject>  MenuState::getSelectedObject()
{
    return renderObjects.at(getSelectedOption()%renderObjects.size());
}
void MenuState::setIsInitialized(const bool& initialized)
{
    this->initialized = initialized;
}
void MenuState::setSelectedOption(const int& selectedOption)
{
    int numOptions = renderObjects.size();

    // Wrap around negative selectedOption
    if (selectedOption < 0)
        this->selectedOption = (selectedOption % numOptions + numOptions) % numOptions;
    // Wrap around values greater than the last index
    else
        this->selectedOption = selectedOption % numOptions;
}

size_t MenuState::getRenderObjectCount()
{
    return this->renderObjects.size();
}
