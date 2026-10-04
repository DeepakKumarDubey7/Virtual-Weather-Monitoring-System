#ifndef PRESSURE_MODULE_H
#define PRESSURE_MODULE_H

// Generates random air pressure values (hPa).
class PressureModule {
public:
    PressureModule(int minVal = 960, int maxVal = 1040);
    int generate() const;
private:
    int minVal_;
    int maxVal_;
};

#endif
