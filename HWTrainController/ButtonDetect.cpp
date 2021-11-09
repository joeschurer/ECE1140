#include <iostream>
#include <cstring>
#include <wiringPi.h>
#include "HWTrainController.hpp"

#define E_BRAKE 2			// GPIO 2
#define SERVICE_BRAKE 3		// GPIO 3
#define SPEED_UP 4			// GPIO 4
#define SPEED_DOWN 5		// GPIO 5
#define TEMP_UP 6			// GPIO 6
#define TEMP_DOWN 7			// GPIO 7
#define LIGHTS 8			// GPIO 8
#define LEFT_DOORS 9		// GPIO 9
#define RIGHT_DOORS 10		// GPIO 10
#define S 11				// GPIO 11

void pinSetup();

int main() {

	//char command[LENGTH];	// LENGTH is inherited from HWTrainController.hpp
	int serialPort;
	if ((serialPort = serialOpen("/dev/ttyS0", 9600)) < 0) {
		printf("Unable to open serial device\n");
		return 1;
	}
	
	HWTrainController tc(serialPort);

	pinSetup();
	
	while(1) {
		// read emergency brake [0]
		if (!digitalRead(E_BRAKE)) {		// this must be true until train comes to complete stop
			tc.initiateEBrake();
		}
			
		// read service brakes [2]
		if (!digitalRead(SERVICE_BRAKE) && !tc.brakePressed()) {
			tc.initiateSBrake();
		}
		
		// read lights [4]
		if (digitalRead(LIGHTS)) {
			if (!tc.lightStatus()) {
				tc.turnLightsOn();
			}
		} else {
			if (tc.lightStatus()) {
				tc.turnLightsOff();
			}
		}
		
		// read increase temp [4]
		if (!digitalRead(TEMP_UP)) {
			tc.increaseTemp();
		}
				
		// read decrease temp [5]
		if (!digitalRead(TEMP_DOWN)) {
			tc.decreaseTemp();
		}
			
		// read increase speed [2]
		if (!digitalRead(SPEED_UP) && !tc.brakePressed() && !tc.leftDoorStatus() && !tc.rightDoorStatus()) {
			tc.increaseSpeed();
		}
			
		// read decrease speed [3]
		if (!digitalRead(SPEED_DOWN) && !tc.brakePressed() && !tc.leftDoorStatus() && !tc.rightDoorStatus() && (tc.getCurrentSpeed() != 0)) {
			tc.decreaseSpeed();
		}
		
		delay(200);
		//strncpy(command, tc.createCommandStr(), sizeof(tc.createCommandStr()));
		tc.sendCommandStr();
	}
	
	return 0;
}

void pinSetup() {
	wiringPiSetupGpio();
	
	pinMode(E_BRAKE, INPUT);
	pinMode(SERVICE_BRAKE, INPUT);
	pinMode(SPEED_UP, INPUT);
	pinMode(SPEED_DOWN, INPUT);
	pinMode(TEMP_UP, INPUT);
	pinMode(TEMP_DOWN, INPUT);
	pinMode(LEFT_DOORS, INPUT);
	pinMode(RIGHT_DOORS, INPUT);
	pinMode(LIGHTS, INPUT);
	pinMode(S, INPUT);
	
	pullUpDnControl(E_BRAKE, PUD_UP);
	pullUpDnControl(SERVICE_BRAKE, PUD_UP);
	pullUpDnControl(SPEED_UP, PUD_UP);
	pullUpDnControl(SPEED_DOWN, PUD_UP);
	pullUpDnControl(TEMP_UP, PUD_UP);
	pullUpDnControl(TEMP_DOWN, PUD_UP);
	pullUpDnControl(LEFT_DOORS, PUD_UP);
	pullUpDnControl(RIGHT_DOORS, PUD_UP);
	pullUpDnControl(LIGHTS, PUD_UP);
	pullUpDnControl(S, PUD_UP);
}




















