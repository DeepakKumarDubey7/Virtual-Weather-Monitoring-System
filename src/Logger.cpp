#include "Logger.h"
#include <fstream>
#include <stdexcept>
#include <sys/stat.h>   // mkdir (system programming)
#include <cerrno>

Logger::Logger(const std::string& filePath) : filePath_(filePath) {}

void Logger::ensureLogDirectory() const {
    std::string::size_type pos = filePath_.find_last_of('/');
    if (pos == std::string::npos) return;
    std::string dir = filePath_.substr(0, pos);
    if (mkdir(dir.c_str(), 0755) != 0 && errno != EEXIST)
        throw std::runtime_error("Cannot create log directory: " + dir);
}

void Logger::save(const WeatherData& data, const std::vector<std::string>& alerts) const {
    ensureLogDirectory();

    std::ofstream file(filePath_.c_str(), std::ios::app);
    if (!file.is_open())
        throw std::runtime_error("Cannot open log file: " + filePath_);

    file << "[" << data.timestamp << "] "
         << "Temp=" << data.temperature << "C, "
         << "Humidity=" << data.humidity << "%, "
         << "Pressure=" << data.pressure << "hPa, "
         << "Alerts=";

    if (alerts.empty()) {
        file << "None";
    } else {
        for (std::size_t i = 0; i < alerts.size(); ++i) {
            if (i > 0) file << "; ";
            file << alerts[i];
        }
    }
    file << "\n";

    if (!file.good())
        throw std::runtime_error("Error while writing to log file: " + filePath_);
}
