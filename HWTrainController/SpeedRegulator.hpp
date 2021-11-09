#ifndef SPEEDREGULATOR_H
#define SPEEDREGULATOR_H

class SpeedRegulator {
    private:
        double commandedPower;
    public:
        SpeedRegulator();
        double calculatePower(double);
        double getPower() const;
};

#include "SpeedRegulator.cpp"
#endif