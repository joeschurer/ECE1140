#include "ExternalInputs.hpp"

ExternalInputs::ExternalInputs() {
    trainWeight = 0;
    speedLimit = 0;
    currentSpeed = 0.0;
    commandedSpeed = 0.0;
    failure = false;
    for (int i = 0; i < 5; i++)
        tmpArr[i] = '0';
}

void ExternalInputs::setTrainWeight(int i) {
    trainWeight = i;
}

void ExternalInputs::setSpeedLimit(int i) {
    speedLimit = i;
}

void ExternalInputs::setCommandedSpeed(double d) {
    commandedSpeed = d;
}

void ExternalInputs::setCurrentSpeed(double d) {
    currentSpeed = d;
}

void ExternalInputs::setFailure(bool b) {
    failure = b;
}

int ExternalInputs::getTrainWeight() const {
    return trainWeight;
}

int ExternalInputs::getSpeedLimit() const {
    return speedLimit;
}

double ExternalInputs::getCurrentSpeed() const {
    return currentSpeed;
}

double ExternalInputs::getCommandedSpeed() const {
    return commandedSpeed;
}

bool ExternalInputs::getFailure() const {
    return failure;
}

char *ExternalInputs::getCurrentSpeedStr() {
	sprintf(tmpArr, "%.1f", currentSpeed);
	return tmpArr;
}

char *ExternalInputs::getCommandedSpeedStr() {
	sprintf(tmpArr, "%.1f", commandedSpeed);
	return tmpArr;
}

char *ExternalInputs::getSpeedLimitStr() {
	sprintf(tmpArr, "%i", speedLimit);
	return tmpArr;
}