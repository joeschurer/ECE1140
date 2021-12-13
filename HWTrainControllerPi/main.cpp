#include <iostream>
#include <pigpio.h>
#include "HWTrainControllerPi.hpp"
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
#define POWER_FAIL 26
#define SIGNAL_FAIL 19
#define BRAKE_FAIL 17
#define AUTHORITY 27
#define TERMINATE 22				// GPIO 11
#define lcdAddr 0x27

void pinSetup();
void displayValues(ExternalInputs, HWTrainControllerPi);

I2cControl *i2c = new I2cControl(1);
LcdDriver lcd(lcdAddr, i2c);

int main() {

	pinSetup();

	char command[LENGTH];	// LENGTH is inherited from HWTrainController.hpp
	int serialPort;
	if ((serialPort = serOpen("/dev/ttyS0", 9600, 0)) < 0) {
		std::cout << "Unable to open serial device\n";
		return 1;
	}

	int kp, ki;
	ExternalInputs exInputs;
	HWTrainControllerPi tc(serialPort, &exInputs);

	std::cout << "Enter Kp value: ";
	std::cin >> kp;
	std::cout << "Enter Ki value: ";
	std::cin >> ki;

	tc.setKp(kp);
	tc.setKi(ki);
	
	while(1) {
		// read emergency brake
		if (!gpioRead(E_BRAKE) && !tc.brakePressed()) {		// this must be true until train comes to complete stop
			tc.initiateEBrake();
		}
			
		// read service brakes
		if (!gpioRead(SERVICE_BRAKE) && !tc.brakePressed()) {
			tc.initiateSBrake();
		}
		
		// read lights
		if (gpioRead(LIGHTS)) {
			if (!tc.lightStatus()) {
				tc.turnLightsOn();
			}
		} else {
			if (tc.lightStatus()) {
				tc.turnLightsOff();
			}
		}
		
		// read increase temp
		if (!gpioRead(TEMP_UP)) {
			tc.increaseTemp();
		}
				
		// read decrease temp
		if (!gpioRead(TEMP_DOWN)) {
			tc.decreaseTemp();
		}
			
		// read increase speed
		if (!gpioRead(SPEED_UP) && !tc.brakePressed() && !tc.leftDoorStatus() && !tc.rightDoorStatus()) {
			tc.increaseSpeed();
		}
			
		// read decrease speed
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

		// check power failure

		// break from loop
		if (!gpioRead(TERMINATE)) {
			break;
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

void displayValues(ExternalInputs e, HWTrainControllerPi tc) {
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
	lcd.lcdString(e.getSuggestedSpeedStr());

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
	gpioSetMode(TERMINATE, PI_INPUT);
	gpioSetMode(POWER_FAIL, PI_OUTPUT);
	gpioSetMode(SIGNAL_FAIL, PI_OUTPUT);
	gpioSetMode(BRAKE_FAIL, PI_OUTPUT);
	gpioSetMode(AUTHORITY, PI_OUTPUT);

	gpioSetPullUpDown(E_BRAKE, PI_PUD_UP);
	gpioSetPullUpDown(SERVICE_BRAKE, PI_PUD_UP);
	gpioSetPullUpDown(SPEED_UP, PI_PUD_UP);
	gpioSetPullUpDown(SPEED_DOWN, PI_PUD_UP);
	gpioSetPullUpDown(TEMP_UP, PI_PUD_UP);
	gpioSetPullUpDown(TEMP_DOWN, PI_PUD_UP);
	gpioSetPullUpDown(LEFT_DOORS, PI_PUD_UP);
	gpioSetPullUpDown(RIGHT_DOORS, PI_PUD_UP);
	gpioSetPullUpDown(LIGHTS, PI_PUD_UP);
	gpioSetPullUpDown(TERMINATE, PI_PUD_UP);
}


