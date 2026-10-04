#ifndef WEATHER_DATA_H
#define WEATHER_DATA_H

#include <string>

// Holds one complete weather reading.
struct WeatherData {
    int temperature;      // degrees Celsius
    int humidity;         // percent
    int pressure;         // hPa
    std::string timestamp;
};

#endif
