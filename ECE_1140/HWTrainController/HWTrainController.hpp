#ifndef HWTRAINCONTROLLER_H
#define HWTRAINCONTROLLER_H

#include <string>
#include <wiringSerial.h>
#include <unistd.h>
#include "ExternalInputs.hpp"

#define LENGTH 15
#define MAX_POWER 120000
#define TRAIN_MASS 1
#define T 1

class HWTrainController {
	private:
		int temperature;
		double commandedPower, setpointSpeed, ek, ekminus1, uk, ukminus1;
		bool EBrakes, SBrakes, lights, leftDoors, rightDoors;
		char commandArr[LENGTH], setpointSpeedTmp[5];
		int fd, kp, ki;
		std::string command, trackSignal;
		ExternalInputs *exInputs;

	public:
		HWTrainController(int, ExternalInputs *);
		void sendCommandStr();
		void readTrackSignal();
		void setKp(int);
		void setKi(int);
		void increaseSpeed();
		void decreaseSpeed();
		void initiateEBrake();
		void initiateSBrake();
		void increaseTemp();
		void decreaseTemp();
		void openLeftDoors();
		void closeLeftDoors();
		void openRightDoors();
		void closeRightDoors();
		void turnLightsOn();
		void turnLightsOff();
		void calculatePower();
		bool lightStatus() const;
		bool leftDoorStatus() const;
		bool rightDoorStatus() const;
		bool brakePressed() const;
		int getSetpointSpeed() const;
		int getTemperature() const;
		char *getSetpointSpeedStr();

};

#include "HWTrainController.cpp"
#endif
