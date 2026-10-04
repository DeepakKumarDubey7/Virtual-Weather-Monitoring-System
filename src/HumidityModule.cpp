#include "HumidityModule.h"
#include <cstdlib>

HumidityModule::HumidityModule(int minVal, int maxVal)
    : minVal_(minVal), maxVal_(maxVal) {}

int HumidityModule::generate() const {
    return minVal_ + std::rand() % (maxVal_ - minVal_ + 1);
}
