#include "headers/TemperatureSensorManager.h"
#include "headers/DisplayManager.h"

TemperatureSensorManager::TemperatureSensorManager() 
            : temperature(0), humidity(0), initialized(false), id(0) {}


bool TemperatureSensorManager::isInitialized() {
    return initialized;
}

// Initialize the sensor
bool TemperatureSensorManager::initialize() {
    SHTC3.begin();

    SHTC3.wakeup();  // Wake up the sensor

    // Retrieve the sensor ID
    id = SHTC3.getDeviceID();
    if (id == 0) {
        Serial.println("ID retrieval error, please check whether the device is connected correctly!");
        return false;
    }

    Serial.printf("Sensor ID: 0x%X\n", id);
    initialized = true;
    return true;
}

// Read temperature and humidity
void TemperatureSensorManager::read() {
    if (!initialized) {
        Serial.println("Sensor not initialized. Cannot read data.");
        return;
    }
    SHTC3.wakeup();

    // Get temperature and humidity
    temperature = SHTC3.getTemperature(PRECISION_HIGH_CLKSTRETCH_ON);
    humidity = SHTC3.getHumidity(PRECISION_HIGH_CLKSTRETCH_OFF);

    if (temperature == MODE_ERR) {
        Serial.println("Error reading temperature.");
        temperature = -273.15;
    }

    if (humidity == MODE_ERR) {
        Serial.println("Error reading humidity.");
        humidity = 200;
    }
    SHTC3.sleep();
}

const float TemperatureSensorManager::getTemp() {
    this->read();
    return temperature;
}

const float TemperatureSensorManager::getHumid() {
    this->read();
    return humidity;
}

void TemperatureSensorManager::displayTempMessage(DisplayManager& displayManager) {
    displayManager.showMessage(std::to_string(temperature), -40);  // Display the temperature
}

void TemperatureSensorManager::displayHumidMessage(DisplayManager& displayManager) {
    displayManager.showMessage(std::to_string(humidity), -20);  // Display the humidity
}

TemperatureSensorManager::~TemperatureSensorManager() {
    Serial.println("TempSensorManager destroyed.");
}
