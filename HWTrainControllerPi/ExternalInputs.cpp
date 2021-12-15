#include "ExternalInputs.hpp"

ExternalInputs::ExternalInputs() {
    speedLimit = 0;
    currentSpeed = 0.0;
    suggestedSpeed = 0.0;
    powerFailure = false;
    brakeFailure = false;
    signalFailure = false;
    authority = true;
    for (int i = 0; i < 5; i++)
        tmpArr[i] = '0';
}

void ExternalInputs::parseTrackSignal(char *signal) {
    powerFailure = (signal[0] == '1' ? true : false);
    signalFailure = (signal[1] == '1' ? true : false);
    brakeFailure = (signal[2] == '1' ? true : false);
    authority = (signal[3] == '0' ? true : false);

    memcpy(currentStr, signal+4, 4);
    currentSpeed = std::atof(currentStr);
    memcpy(suggestedStr, signal+8, 4);
    suggestedSpeed = std::atof(suggestedStr);
    memcpy(speedLimitStr, signal+12, 2);
    speedLimit = std::atoi(speedLimitStr);
}

void ExternalInputs::setSpeedLimit(int i) {
    speedLimit = i;
}

void ExternalInputs::setSuggestedSpeed(double d) {
    suggestedSpeed = d;
}

void ExternalInputs::setCurrentSpeed(double d) {
    currentSpeed = d;
}

void ExternalInputs::setPowerFailure(bool b) {
    powerFailure = b;
}

void ExternalInputs::setBrakeFailure(bool b) {
    brakeFailure = b;
}

void ExternalInputs::setSignalFailure(bool b) {
    signalFailure = b;
}

void ExternalInputs::setAuthority(bool b) {
    authority = b;
}

int ExternalInputs::getSpeedLimit() const {
    return speedLimit;
}

double ExternalInputs::getCurrentSpeed() const {
    return currentSpeed;
}

double ExternalInputs::getSuggestedSpeed() const {
    return suggestedSpeed;
}

bool ExternalInputs::getPowerFailure() const {
    return powerFailure;
}

bool ExternalInputs::getBrakeFailure() const {
    return brakeFailure;
}

bool ExternalInputs::getSignalFailure() const {
    return signalFailure;
}

bool ExternalInputs::getAuthoriy() const {
    return authority;
}

char *ExternalInputs::getCurrentSpeedStr() {
	sprintf(tmpArr, "%.1f", currentSpeed);
	return tmpArr;
}

char *ExternalInputs::getSuggestedSpeedStr() {
	sprintf(tmpArr, "%.1f", suggestedSpeed);
	return tmpArr;
}

char *ExternalInputs::getSpeedLimitStr() {
	sprintf(tmpArr, "%i", speedLimit);
	return tmpArr;
}