#include <M5Unified.h>
#include "headers/Controller.h"

Controller divice;

void setup() {
    divice.initialize();
}

void loop() {
    divice.run();
}
