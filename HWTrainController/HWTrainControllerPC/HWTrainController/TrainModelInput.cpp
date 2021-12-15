#include "TrainModelInput.hpp"

TrainModelInput::TrainModelInput() {
    powerFailure = false;
    signalFailure = false;
    brakeFailure = false;
    authority = true;
    speedLimit = 10;
    suggestedSpeed = 0.0;
    currentSpeed = 0.0;
    for (int i = 0; i < 16; i++) {
        trackSignal[i] = '0';
    }
}

char *TrainModelInput::createWriteString() {
    trackSignal[0] = (powerFailure == true ? '1' : '0');
    trackSignal[1] = (signalFailure == true ? '1' : '0');
    trackSignal[2] = (brakeFailure == true ? '1' : '0');
    trackSignal[3] = (authority == true ? '1' : '0');

    if (currentSpeed < 10)
        sprintf(trackSignal+4, "%.2f", currentSpeed);
    else
        sprintf(trackSignal+4, "%.1f", currentSpeed);

    if (suggestedSpeed < 10)
        sprintf(trackSignal+8, "%.2f", suggestedSpeed);
    else
        sprintf(trackSignal+8, "%.1f", suggestedSpeed);

    sprintf(trackSignal+12, "%i", speedLimit);

    return trackSignal;
}

void TrainModelInput::setPowerFailure(bool b) {
    powerFailure = b;
}

void TrainModelInput::setSignalFailure(bool b) {
    signalFailure = b;
}

void TrainModelInput::setBrakeFailure(bool b) {
    brakeFailure = b;
}

void TrainModelInput::setAuthority(bool b) {
    authority = b;
}

void TrainModelInput::setOpenLeftDoor(bool b) {
    openLeftDoor = b;
}

void TrainModelInput::setOpenRightDoor(bool b) {
    openRightDoor = b;
}

void TrainModelInput::setSpeedLimit(int i) {
    speedLimit = i;
}

void TrainModelInput::setSuggestedSpeed(double d) {
    suggestedSpeed = d;
}

void TrainModelInput::setCurrentSpeed(double d) {
    currentSpeed = d;
}

bool TrainModelInput::getPowerFailure() const {
    return powerFailure;
}

bool TrainModelInput::getSignalFailure() const {
    return signalFailure;
}

bool TrainModelInput::getBrakeFailure() const {
    return brakeFailure;
}

bool TrainModelInput::getAuthority() const {
    return authority;
}

bool TrainModelInput::getOpenLeftDoor() const {
    return openLeftDoor;
}

bool TrainModelInput::getOpenRightDoor() const {
    return openRightDoor;
}

int TrainModelInput::getSpeedLimit() const {
    return speedLimit;
}

double TrainModelInput::getSuggestedSpeed() const {
    return suggestedSpeed;
}

double TrainModelInput::getCurrentSpeed() const {
    return currentSpeed;
}
