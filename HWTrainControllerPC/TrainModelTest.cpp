#include "TrainModelTest.hpp"

TrainModelTest::TrainModelTest() {
	powerFailure = false;
	signalFailure = false;
	brakeFailure = false;
	authority = true;
	speedLimit = 10;
	suggestedSpeed = 0.0;
	currentSpeed = 0.0;
	for (int i = 0; i < 14; i++) {
		trackSignal[i] = '0';
	}
}

char *TrainModelTest::createWriteString() {
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

void TrainModelTest::setPowerFailure(bool b) {
	powerFailure = b;
}

void TrainModelTest::setSignalFailure(bool b) {
	signalFailure = b;
}

void TrainModelTest::setBrakeFailure(bool b) {
	brakeFailure = b;
}

void TrainModelTest::setAuthority(bool b) {
	authority = b;
}

void TrainModelTest::setSpeedLimit(int i) {
	speedLimit = i;
}

void TrainModelTest::setSuggestedSpeed(double d) {
	suggestedSpeed = d;
}

void TrainModelTest::setCurrentSpeed(double d) {
	currentSpeed = d;
}

bool TrainModelTest::getPowerFailure() const {
	return powerFailure;
}

bool TrainModelTest::getSignalFailure() const {
	return signalFailure;
}

bool TrainModelTest::getBrakeFailure() const {
	return brakeFailure;
}

bool TrainModelTest::getAuthority() const {
	return authority;
}

int TrainModelTest::getSpeedLimit() const {
	return speedLimit;
}

double TrainModelTest::getSuggestedSpeed() const {
	return suggestedSpeed;
}

double TrainModelTest::getCurrentSpeed() const {
	return currentSpeed;
}






