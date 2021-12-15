#include "HWTrainControllerPC.hpp"

HWTrainControllerPC::HWTrainControllerPC() {
    EBrakes = false;
    SBrakes = false;
    lightStatus = false;
    leftDoorStatus = false;
    rightDoorStatus = false;
    temperature = 0;
    power = 0.0;
}

void HWTrainControllerPC::parseReadString(char *str) {
    EBrakes = (str[0] == '1' ? true : false);
    SBrakes = (str[1] == '1' ? true : false);
    lightStatus = (str[2] == '1' ? true : false);
    leftDoorStatus = (str[3] == '1' ? true : false);
    rightDoorStatus = (str[4] == '1' ? true : false);

    memcpy(tempStr, str+5, 2);
    temperature = atoi(tempStr);
    memcpy(powerStr, str+7, 8);
    power = std::atof(powerStr);

}

void HWTrainControllerPC::setLightStatus(bool b) {
    lightStatus = b;
}

void HWTrainControllerPC::setLeftDoorStatus(bool b) {
    leftDoorStatus = b;
}

void HWTrainControllerPC::setRightDoorStatus(bool b) {
    rightDoorStatus = b;
}

void HWTrainControllerPC::setTemperature(int i) {
    temperature = i;
}

void HWTrainControllerPC::setPower(double d) {
    power = d;
}

bool HWTrainControllerPC::getLightStatus() const {
    return lightStatus;
}

bool HWTrainControllerPC::getLeftDoorStatus() const {
    return leftDoorStatus;
}

bool HWTrainControllerPC::getRightDoorStatus() const {
    return rightDoorStatus;
}

int HWTrainControllerPC::getTemperature() const {
    return temperature;
}

double HWTrainControllerPC::getPower() const {
    return power;
}
