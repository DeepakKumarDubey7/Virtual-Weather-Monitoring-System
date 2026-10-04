#include "TemperatureModule.h"
#include <cstdlib>

TemperatureModule::TemperatureModule(int minVal, int maxVal)
    : minVal_(minVal), maxVal_(maxVal) {}

int TemperatureModule::generate() const {
    return minVal_ + std::rand() % (maxVal_ - minVal_ + 1);
}
