#ifndef TEMPERATURE_MODULE_H
#define TEMPERATURE_MODULE_H

// Generates random temperature values (degrees Celsius).
class TemperatureModule {
public:
    TemperatureModule(int minVal = 15, int maxVal = 45);
    int generate() const;
private:
    int minVal_;
    int maxVal_;
};

#endif
