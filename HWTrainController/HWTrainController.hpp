#ifndef HWTRAINCONTROLLER_H
#define HWTRAINCONTROLLER_H

#include <string>
#include <wiringSerial.h>
#include "SpeedRegulator.hpp"

#define LENGTH 20

class HWTrainController {
	private:
		double currentSpeed, setpointSpeed, commandedSpeed;
		int temperature, speedLimit, passengerCount;
		bool EBrakes, SBrakes, lights, leftDoors, rightDoors, failure;
		char commandArr[LENGTH];
		int serialPort;
		std::string command;
		SpeedRegulator PID;
		
	public:
		HWTrainController(int);
		void parseTrainModelStr();
		void sendCommandStr();
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
		void setCurrentSpeed(double);
		void setCommandedSpeed(double);
		bool lightStatus() const;
		bool leftDoorStatus() const;
		bool rightDoorStatus() const;
		bool brakePressed() const;
		double getCurrentSpeed() const;
		double getSetpointSpeed() const;
		double getCommandedSpeed() const;
		int getTemperature() const;
		int getSpeedLimit() const;
		int getPassengerCount() const;

};

#include "HWTrainController.cpp"
#endif
