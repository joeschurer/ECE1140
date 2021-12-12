#include "HWTrainController.hpp"

#include <iostream>

HWTrainController::HWTrainController(int port, ExternalInputs *e) {
	exInputs = e;
	setpointSpeed = 0;
	temperature = 70;
	commandedPower = 0.0;
	kp = 0;
	ki = 0;
	ek = 0.0;
	ekminus1 = 0.0;
	uk = 0.0;
	ukminus1 = 0.0;
	EBrakes = false;
	SBrakes = false;
	lights = false;
	leftDoors = false;
	rightDoors = false;
	command = "";
	trackSignal = "";
	fd = port;
	for (int i = 0; i < 5; i++)
		setpointSpeedTmp[i] = '0';
}

void HWTrainController::sendCommandStr() {
	// changes the values to true if they are set
	command = "00000";
	if (EBrakes)
		command.at(0) = '1';
	if (SBrakes)
		command.at(1) = '1';
	if (lights)
		command.at(2) = '1';
	if (leftDoors)
		command.at(3) = '1';
	if (rightDoors)
		command.at(4) = '1';
	
	char power[9];
	if (commandedPower < 10)
		sprintf(power, "%.6f", commandedPower);
	else if (commandedPower < 100)
		sprintf(power, "%.5f", commandedPower);
	else if (commandedPower < 1000)
		sprintf(power, "%.4f", commandedPower);
	else if (commandedPower < 10000)
		sprintf(power, "%.3f", commandedPower);
	else if (commandedPower < 100000)
		sprintf(power, "%.2f", commandedPower);
	else
		sprintf(power, "%.1f", commandedPower);
	std::string tmp = power;
	command += std::to_string(temperature) + tmp;

	for(int i = 0; i < LENGTH; i++) {
		commandArr[i] = command.at(i);
	}

	for (int i = 0; i < LENGTH; i++) {
		std::cout << commandArr[i];
	}
	std::cout << std::endl;
	serWrite(fd, commandArr, command.length());
}

void HWTrainController::readTrackSignal() {
	int count = 0;
	char tmp[14];
	trackSignal = "";
	if ((count = serRead(fd, tmp, 14)) == 14) {
		std::cout << count << std::endl;
		std::cout << tmp << std::endl;
	}
}

void HWTrainController::setKp(int i) {
	kp = i;
}

void HWTrainController::setKi(int i) {
	ki = i;
}

void HWTrainController::increaseSpeed() {
	//if (setpointSpeed+1 <= exInputs->getCommandedSpeed()) {
		setpointSpeed += 1;
		calculatePower();
	//}
}

void HWTrainController::decreaseSpeed() {
	if (setpointSpeed != 0) {
		setpointSpeed -= 1;
		calculatePower();
	}
}

void HWTrainController::initiateEBrake() {
	EBrakes = true;
	setpointSpeed = 0;
	calculatePower();
}

void HWTrainController::initiateSBrake() {
	SBrakes = true;
	setpointSpeed = 0.0;
	calculatePower();
}

void HWTrainController::increaseTemp() {
	temperature += 1;
}

void HWTrainController::decreaseTemp() {
	temperature -= 1;
}

void HWTrainController::openLeftDoors() {
	leftDoors = true;
}

void HWTrainController::closeLeftDoors() {
	leftDoors = false;
}

void HWTrainController::openRightDoors() {
	rightDoors = true;
}

void HWTrainController::closeRightDoors() {
	rightDoors = false;
}

void HWTrainController::turnLightsOn() {
	lights = true;
}

void HWTrainController::turnLightsOff() {
	lights = false;
}

void HWTrainController::calculatePower() {
	double setpointSpeedKPH = setpointSpeed * 1.60934;
	double currentSpeedKPH = exInputs->getCurrentSpeed() * 1.60934;
	ek = setpointSpeedKPH - currentSpeedKPH;
	uk = ukminus1 + ((T/2) * (ek + ekminus1));
	ekminus1 = ek;
	ukminus1 = uk;

	commandedPower = (kp*ek) + (ki*uk);

	if (commandedPower > MAX_POWER) {
		commandedPower = MAX_POWER;
		uk = ukminus1;
	}
}

bool HWTrainController::lightStatus() const {
	return lights;
}

bool HWTrainController::leftDoorStatus() const {
	return leftDoors;
}

bool HWTrainController::rightDoorStatus() const {
	return rightDoors;
}

bool HWTrainController::brakePressed() const {
	return EBrakes && SBrakes;
}

int HWTrainController::getSetpointSpeed() const {
	return setpointSpeed;
}

int HWTrainController::getTemperature() const {
	return temperature;
}

char *HWTrainController::getSetpointSpeedStr() {
	sprintf(setpointSpeedTmp, "%.1f", setpointSpeed);
	return setpointSpeedTmp;
}

