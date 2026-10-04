#ifndef ALERT_MODULE_H
#define ALERT_MODULE_H

#include <string>
#include <vector>
#include "WeatherData.h"

// Compares readings against predefined safe limits.
class AlertModule {
public:
    static const int MAX_SAFE_TEMP     = 35;   // above -> High Temperature
    static const int MAX_SAFE_HUMIDITY = 80;   // above -> High Humidity
    static const int MIN_SAFE_PRESSURE = 990;  // below -> Low Pressure

    std::vector<std::string> check(const WeatherData& data) const;
};

#endif
