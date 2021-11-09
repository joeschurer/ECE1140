#include "HWTrainController.hpp"

#include <iostream>

HWTrainController::HWTrainController(int port) {
	currentSpeed = 0.0;
	commandedSpeed = 0.0;
	setpointSpeed = 0.0;
	temperature = 70;
	passengerCount = 0;
	failure = false;
	EBrakes = false;
	SBrakes = false;
	lights = false;
	leftDoors = false;
	rightDoors = false;
	// EBrake, SBrake, Lights, Left Doors, Right Doors, Temp, Power
	command = "";
	serialPort = port;
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

	command += std::to_string(temperature) + std::to_string(PID.getPower());

	for(int i = 0; i < command.length(); i++) {
		commandArr[i] = command.at(i);
	}

	std::cout << command << std::endl;
	serialPuts(serialPort, commandArr);
}

void HWTrainController::increaseSpeed() {
	setpointSpeed += 1;
	PID.calculatePower(setpointSpeed);
}

void HWTrainController::decreaseSpeed() {
	setpointSpeed -= 1;
	PID.calculatePower(setpointSpeed);
}

void HWTrainController::initiateEBrake() {
	EBrakes = true;
	setpointSpeed = 0.0;
	//PID.calculatePower(setpointSpeed);
}

void HWTrainController::initiateSBrake() {
	SBrakes = true;
	setpointSpeed = 0.0;
	//PID.calculatePower(setpointSpeed);
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

void HWTrainController::setCurrentSpeed(double s) {
	currentSpeed = s;
}

void HWTrainController::setCommandedSpeed(double s) {
	commandedSpeed = s;
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

double HWTrainController::getCurrentSpeed() const {
	return currentSpeed;
}

double HWTrainController::getSetpointSpeed() const {
	return setpointSpeed;
}

double HWTrainController::getCommandedSpeed() const {
	return commandedSpeed;
}

int HWTrainController::getTemperature() const {
	return temperature;
}

int HWTrainController::getSpeedLimit() const {
	return speedLimit;
}

int HWTrainController::getPassengerCount() const {
	return passengerCount;
}
