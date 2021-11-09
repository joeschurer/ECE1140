#include "SpeedRegulator.hpp"

SpeedRegulator::SpeedRegulator() {
    commandedPower = 0.0;
}

double SpeedRegulator::calculatePower(double v) {
    commandedPower += 1;
    return commandedPower;
}

double SpeedRegulator::getPower() const {
    return commandedPower;
}