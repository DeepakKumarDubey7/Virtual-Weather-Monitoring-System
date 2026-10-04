#ifndef HUMIDITY_MODULE_H
#define HUMIDITY_MODULE_H

// Generates random humidity values (percent).
class HumidityModule {
public:
    HumidityModule(int minVal = 20, int maxVal = 100);
    int generate() const;
private:
    int minVal_;
    int maxVal_;
};

#endif
