#ifndef HWTRAINCONTROLLERPI_H
#define HWTRAINCONTROLLERPI_H

#include <string>
#include <pigpio.h>
#include <unistd.h>
#include "ExternalInputs.hpp"

#define READ_LENGTH 	15
#define WRITE_LENGTH 	16
#define MAX_POWER 		120000
#define T 				1

class HWTrainControllerPi {
	private:
		int temperature;
		double commandedPower, setpointSpeed, ek, ekminus1, uk, ukminus1;
		bool EBrakes, SBrakes, lights, leftDoors, rightDoors, signalReceived;
		char commandArr[WRITE_LENGTH], trackSignal[READ_LENGTH], setpointSpeedTmp[5];
		int fd, kp, ki;
		std::string command;
		ExternalInputs *exInputs;

	public:
		HWTrainControllerPi(int, ExternalInputs *);
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

#include "HWTrainControllerPi.cpp"
#endif
