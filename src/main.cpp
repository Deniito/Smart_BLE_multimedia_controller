#include "FS.h"
#include "SPIFFS.h"
#include <SD.h>
#include <M5Dial.h>
#include "headers/Controller.h"

Controller divice;

void setup() {
    divice.initialize();
}

void loop() {
    divice.run();
}
