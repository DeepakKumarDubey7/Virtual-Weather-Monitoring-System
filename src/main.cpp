// Virtual Weather Monitoring & Alert System
// Usage: ./weather_monitor [number_of_readings] [interval_seconds]

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <vector>
#include <stdexcept>
#include <unistd.h>      // sleep, getpid (system programming)

#include "WeatherData.h"
#include "TemperatureModule.h"
#include "HumidityModule.h"
#include "PressureModule.h"
#include "AlertModule.h"
#include "Logger.h"
#include "ReportModule.h"

static std::string currentTimestamp() {
    std::time_t now = std::time(NULL);
    char buf[32];
    std::strftime(buf, sizeof(buf), "%Y-%m-%d %H:%M:%S", std::localtime(&now));
    return std::string(buf);
}

int main(int argc, char* argv[]) {
    int readings = 5;
    int interval = 1;

    try {
        if (argc > 1) readings = std::stoi(argv[1]);
        if (argc > 2) interval = std::stoi(argv[2]);
        if (readings <= 0 || interval < 0)
            throw std::invalid_argument("values must be positive");
    } catch (const std::exception&) {
        std::cerr << "Usage: " << argv[0]
                  << " [number_of_readings] [interval_seconds]\n";
        return 1;
    }

    std::srand(static_cast<unsigned>(std::time(NULL)) ^ static_cast<unsigned>(getpid()));

    TemperatureModule tempModule;
    HumidityModule    humModule;
    PressureModule    presModule;
    AlertModule       alertModule;
    Logger            logger;
    ReportModule      report;

    try {
        for (int i = 0; i < readings; ++i) {
            WeatherData data;
            data.temperature = tempModule.generate();
            data.humidity    = humModule.generate();
            data.pressure    = presModule.generate();
            data.timestamp   = currentTimestamp();

            std::vector<std::string> alerts = alertModule.check(data);

            logger.save(data, alerts);
            report.display(data, alerts);

            if (i < readings - 1) sleep(interval);
        }
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 2;
    }

    return 0;
}
