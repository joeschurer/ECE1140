#include <iostream>
#include <pigpio.h>
#include "HWTrainController.hpp"
#include "ExternalInputs.hpp"
#include "i2cControl.hpp"
#include "lcdDriver.hpp"

#define E_BRAKE 20			// GPIO 2
#define SERVICE_BRAKE 21	// GPIO 3
#define SPEED_UP 4			// GPIO 4
#define SPEED_DOWN 5		// GPIO 5
#define TEMP_UP 6			// GPIO 6
#define TEMP_DOWN 7			// GPIO 7
#define LIGHTS 12			// GPIO 8
#define RIGHT_DOORS 13		// GPIO 9
#define LEFT_DOORS 16		// GPIO 10
#define S 11				// GPIO 11
#define lcdAddr 0x27

void pinSetup();
void displayValues(ExternalInputs, HWTrainController);

I2cControl *i2c = new I2cControl(1);
LcdDriver lcd(lcdAddr, i2c);

int main() {

	pinSetup();

	char command[LENGTH];	// LENGTH is inherited from HWTrainController.hpp
	int serialPort;
	if ((serialPort = serOpen("/dev/ttyAMA0", 9600, 0)) < 0) {
		std::cout << "Unable to open serial device\n";
		return 1;
	}

	int kp, ki;
	ExternalInputs exInputs;
	HWTrainController tc(serialPort, &exInputs);

	std::cout << "Enter Kp value: ";
	std::cin >> kp;
	std::cout << "Enter Ki value: ";
	std::cin >> ki;

	tc.setKp(kp);
	tc.setKi(ki);
	
	while(1) {
		// read emergency brake [0]
		if (!gpioRead(E_BRAKE) && !tc.brakePressed()) {		// this must be true until train comes to complete stop
			tc.initiateEBrake();
		}
			
		// read service brakes [2]
		if (!gpioRead(SERVICE_BRAKE) && !tc.brakePressed()) {
			tc.initiateSBrake();
		}
		
		// read lights [4]
		if (gpioRead(LIGHTS)) {
			if (!tc.lightStatus()) {
				tc.turnLightsOn();
			}
		} else {
			if (tc.lightStatus()) {
				tc.turnLightsOff();
			}
		}
		
		// read increase temp [4]
		if (!gpioRead(TEMP_UP)) {
			tc.increaseTemp();
		}
				
		// read decrease temp [5]
		if (!gpioRead(TEMP_DOWN)) {
			tc.decreaseTemp();
		}
			
		// read increase speed [2]
		if (!gpioRead(SPEED_UP) && !tc.brakePressed() && !tc.leftDoorStatus() && !tc.rightDoorStatus()) {
			tc.increaseSpeed();
		}
			
		// read decrease speed [3]
		if (!gpioRead(SPEED_DOWN) && !tc.brakePressed() && !tc.leftDoorStatus() && !tc.rightDoorStatus() && (tc.getSetpointSpeed() != 0)) {
			tc.decreaseSpeed();
		}

		// read left doors
		if (gpioRead(LEFT_DOORS) && tc.getSetpointSpeed() == 0 && exInputs.getCurrentSpeed() == 0) {
			if (!tc.leftDoorStatus()) {
				tc.openLeftDoors();
			}
		} else {
			if (tc.leftDoorStatus()) {
				tc.closeLeftDoors();
			}
		}

		// read right doors
		if (gpioRead(RIGHT_DOORS) && tc.getSetpointSpeed() == 0 && exInputs.getCurrentSpeed() == 0) {
			if (!tc.rightDoorStatus()) {
				tc.openRightDoors();
			}
		} else {
			if (tc.rightDoorStatus()) {
				tc.closeRightDoors();
			}
		}
		
		gpioDelay(500);
		tc.sendCommandStr();
		displayValues(exInputs, tc);
		tc.readTrackSignal();
	}

	delete i2c;
	serClose(serialPort);
	
	return 0;
}

void displayValues(ExternalInputs e, HWTrainController tc) {
	char *tmp;

	lcd.lcdSendCommand(LCD_BEG_LINE_1);
	lcd.lcdString("Current:");
	lcd.setCursorPositionRowCol(1, 9);
	tmp = e.getCurrentSpeedStr();
	lcd.lcdString(tmp);

	lcd.lcdSendCommand(LCD_BEG_LINE_2);
	lcd.lcdString("Setpoint:");
	lcd.setCursorPositionRowCol(2, 10);
	lcd.lcdString(tc.getSetpointSpeedStr());

	lcd.lcdSendCommand(LCD_BEG_LINE_3);
	lcd.lcdString("Commanded:");
	lcd.setCursorPositionRowCol(3, 11);
	lcd.lcdString(e.getCommandedSpeedStr());

	lcd.lcdSendCommand(LCD_BEG_LINE_4);
	lcd.lcdString("Speed Limit:");
	lcd.setCursorPositionRowCol(4, 13);
	lcd.lcdString(e.getSpeedLimitStr());
}

void pinSetup() {
	gpioInitialise();

	gpioSetMode(E_BRAKE, PI_INPUT);
	gpioSetMode(SERVICE_BRAKE, PI_INPUT);
	gpioSetMode(SPEED_UP, PI_INPUT);
	gpioSetMode(SPEED_DOWN, PI_INPUT);
	gpioSetMode(TEMP_UP, PI_INPUT);
	gpioSetMode(TEMP_DOWN, PI_INPUT);
	gpioSetMode(LEFT_DOORS, PI_INPUT);
	gpioSetMode(RIGHT_DOORS, PI_INPUT);
	gpioSetMode(LIGHTS, PI_INPUT);

	gpioSetPullUpDown(E_BRAKE, PI_PUD_UP);
	gpioSetPullUpDown(SERVICE_BRAKE, PI_PUD_UP);
	gpioSetPullUpDown(SPEED_UP, PI_PUD_UP);
	gpioSetPullUpDown(SPEED_DOWN, PI_PUD_UP);
	gpioSetPullUpDown(TEMP_UP, PI_PUD_UP);
	gpioSetPullUpDown(TEMP_DOWN, PI_PUD_UP);
	gpioSetPullUpDown(LEFT_DOORS, PI_PUD_UP);
	gpioSetPullUpDown(RIGHT_DOORS, PI_PUD_UP);
	gpioSetPullUpDown(LIGHTS, PI_PUD_UP);

	/*
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
	
	pullUpDnControl(E_BRAKE, PUD_DOWN);
	pullUpDnControl(SERVICE_BRAKE, PUD_DOWN);
	pullUpDnControl(SPEED_UP, PUD_UP);
	pullUpDnControl(SPEED_DOWN, PUD_UP);
	pullUpDnControl(TEMP_UP, PUD_UP);
	pullUpDnControl(TEMP_DOWN, PUD_UP);
	pullUpDnControl(LEFT_DOORS, PUD_UP);
	pullUpDnControl(RIGHT_DOORS, PUD_UP);
	pullUpDnControl(LIGHTS, PUD_UP);
	pullUpDnControl(S, PUD_UP);
	*/
}


