#ifndef REPORT_MODULE_H
#define REPORT_MODULE_H

#include <string>
#include <vector>
#include "WeatherData.h"

// Displays the current weather report on the terminal.
class ReportModule {
public:
    void display(const WeatherData& data, const std::vector<std::string>& alerts) const;
};

#endif
