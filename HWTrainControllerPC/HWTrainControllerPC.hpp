#ifndef HWTRAINCONTROLLERPC_H
#define HWTRAINCONTROLLERPC_H

#include <cstring>

class HWTrainControllerPC {
	private:
		bool lightStatus, leftDoorStatus, rightDoorStatus, EBrakes, SBrakes;
		int temperature;
		double power;
		char tempStr[3], powerStr[9];
	public:
		HWTrainControllerPC();
		void parseReadString(char *);
		void setLightStatus(bool);
		void setLeftDoorStatus(bool);
		void setRightDoorStatus(bool);
		void setTemperature(int);
		void setPower(double);
		bool getLightStatus() const;
		bool getLeftDoorStatus() const;
		bool getRightDoorStatus() const;
		int getTemperature() const;
		double getPower() const;
};

#include "HWTrainControllerPC.cpp"
#endif
