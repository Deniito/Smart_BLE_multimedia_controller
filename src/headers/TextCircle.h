#pragma once


#include "FS.h"
#include "SPIFFS.h"
#include <SD.h>
#include <M5Dial.h>
#include <string>

#include "headers/RenderObject.h"


class TextCircle : public RenderObject {
protected:
    std::string text;

public:
    TextCircle(int x, int y, int radius, const std::string& text = "Default");

    void render() override;

    void use(DisplayManager& displayManager) override;
};
