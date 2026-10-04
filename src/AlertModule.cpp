#include "AlertModule.h"

std::vector<std::string> AlertModule::check(const WeatherData& data) const {
    std::vector<std::string> alerts;

    if (data.temperature > MAX_SAFE_TEMP)
        alerts.push_back("High Temperature Warning");

    if (data.humidity > MAX_SAFE_HUMIDITY)
        alerts.push_back("High Humidity Warning");

    if (data.pressure < MIN_SAFE_PRESSURE)
        alerts.push_back("Low Pressure Warning");

    // Combined condition: humid air and falling pressure suggest rain.
    if (data.humidity > MAX_SAFE_HUMIDITY && data.pressure < MIN_SAFE_PRESSURE)
        alerts.push_back("Heavy Rain Possibility");

    return alerts;
}
