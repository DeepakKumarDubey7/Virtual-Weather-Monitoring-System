#include "ReportModule.h"
#include <iostream>
#include <iomanip>

void ReportModule::display(const WeatherData& data,
                           const std::vector<std::string>& alerts) const {
    const std::string line(36, '=');

    std::cout << "\n" << line << "\n"
              << "   Virtual Weather Monitoring System\n"
              << line << "\n\n"
              << std::left
              << std::setw(12) << "Temperature" << ": " << data.temperature << " \u00B0C\n"
              << std::setw(12) << "Humidity"    << ": " << data.humidity    << " %\n"
              << std::setw(12) << "Pressure"    << ": " << data.pressure    << " hPa\n\n";

    std::cout << "Alerts:\n";
    if (alerts.empty()) {
        std::cout << "  No alerts. Conditions are normal.\n";
    } else {
        for (std::size_t i = 0; i < alerts.size(); ++i)
            std::cout << "\u2713 " << alerts[i] << "\n";
    }

    std::cout << "\nData Saved Successfully.\n\n" << line << "\n";
}
