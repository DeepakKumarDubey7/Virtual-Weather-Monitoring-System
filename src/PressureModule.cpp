#include "PressureModule.h"
#include <cstdlib>

PressureModule::PressureModule(int minVal, int maxVal)
    : minVal_(minVal), maxVal_(maxVal) {}

int PressureModule::generate() const {
    return minVal_ + std::rand() % (maxVal_ - minVal_ + 1);
}
