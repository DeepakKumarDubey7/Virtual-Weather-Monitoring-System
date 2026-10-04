#ifndef LOGGER_H
#define LOGGER_H

#include <string>
#include <vector>
#include "WeatherData.h"

// Saves weather data to a text file (append mode).
class Logger {
public:
    explicit Logger(const std::string& filePath = "logs/weather_log.txt");
    // Throws std::runtime_error if the file cannot be written.
    void save(const WeatherData& data, const std::vector<std::string>& alerts) const;
private:
    std::string filePath_;
    void ensureLogDirectory() const;
};

#endif
