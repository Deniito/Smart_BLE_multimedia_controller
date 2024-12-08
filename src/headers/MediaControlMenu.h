#pragma once
#include "headers/ShortcutIcon.h"
#include "headers/MenuState.h"
#include "headers/DisplayManager.h"
#include "headers/VolumeControlIcon.h"
#include "headers/MenuChangeIcon.h"

class MediaControlMenu : public MenuState {
private:
    DisplayManager* displayManager;
public:
    MediaControlMenu(DisplayManager& displayManager);
    void initialize(DisplayManager& displayManager) override;
};
