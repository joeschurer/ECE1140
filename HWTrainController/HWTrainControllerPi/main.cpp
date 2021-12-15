#include <iostream>
#include <pigpio.h>
#include <unistd.h>
#include <fcntl.h>
#include <termios.h>
#include "HWTrainControllerPi.hpp"
#include "ExternalInputs.hpp"
#include "i2cControl.hpp"
#include "lcdDriver.hpp"

#define E_BRAKE 		20
#define SERVICE_BRAKE 	21
#define SPEED_UP 		4
#define SPEED_DOWN 		5
#define TEMP_UP 		6
#define TEMP_DOWN 		7
#define LIGHTS 			12
#define RIGHT_DOORS 	13
#define LEFT_DOORS 		16
#define POWER_FAIL 		26
#define SIGNAL_FAIL 	19
#define BRAKE_FAIL 		17
#define AUTHORITY 		27
#define TERMINATE 		22
#define lcdAddr 		0x27

void pinSetup();
void displayValues(ExternalInputs, HWTrainControllerPi);
int connect(int);
void setBlocking(int);

I2cControl *i2c = new I2cControl(1);
LcdDriver lcd(lcdAddr, i2c);

int main() {

	pinSetup();
	char portname[] = "/dev/ttyS0";

	int fd = open(portname, O_RDWR | O_NOCTTY | O_SYNC);
	if (fd < 0) {
		std::cout << "Error opening port\n";
		return 1;
	}

	if (connect(fd) < 0) {
		std::cout << "Error connecting to port\n";
		return 1;
	}
	setBlocking(fd);

	char command[READ_LENGTH];	// LENGTH is inherited from HWTrainController.hpp

	int kp, ki;
	ExternalInputs exInputs;
	HWTrainControllerPi tc(fd, &exInputs);

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
		if (exInputs.getPowerFailure()) {
			gpioWrite(POWER_FAIL, 1);
		} else {
			gpioWrite(POWER_FAIL, 0);
		}

		// check brake failure
		if (exInputs.getBrakeFailure()) {
			gpioWrite(BRAKE_FAIL, 1);
		} else {
			gpioWrite(BRAKE_FAIL, 0);
		}

		// check signal failure
		if (exInputs.getSignalFailure()) {
			gpioWrite(SIGNAL_FAIL, 1);
		} else {
			gpioWrite(SIGNAL_FAIL, 0);
		}

		// check authority
		if (exInputs.getAuthoriy()) {
			gpioWrite(AUTHORITY, 0);
		} else {
			gpioWrite(AUTHORITY, 1);
		}

		// break from loop
		if (!gpioRead(TERMINATE)) {
			break;
		}

		tc.readTrackSignal();			// reads track signal from PC
		displayValues(exInputs, tc);	// displays values to LCD screen
		tc.sendCommandStr();			// sends signal back to PC to send to train model
		gpioDelay(500);					// delay for 500 us
	}

	close(fd);		// close serial port
	delete i2c;		// delete object from dynamic memory
	
	return 0;
}

// function to display values to LCD screen
void displayValues(ExternalInputs e, HWTrainControllerPi tc) {

	// outputs current speed to LCD screen
	lcd.lcdSendCommand(LCD_BEG_LINE_1);
	lcd.lcdString("Current:");
	lcd.setCursorPositionRowCol(1, 9);
	lcd.lcdString(e.getCurrentSpeedStr());

	// outptuts setpoint speed to LCD screen
	lcd.lcdSendCommand(LCD_BEG_LINE_2);
	lcd.lcdString("Setpoint:");
	lcd.setCursorPositionRowCol(2, 10);
	lcd.lcdString(tc.getSetpointSpeedStr());

	// outputs suggested speed to LCD screen
	lcd.lcdSendCommand(LCD_BEG_LINE_3);
	lcd.lcdString("Suggested:");
	lcd.setCursorPositionRowCol(3, 11);
	lcd.lcdString(e.getSuggestedSpeedStr());

	// outputs speed limit to LCD screen
	lcd.lcdSendCommand(LCD_BEG_LINE_4);
	lcd.lcdString("Speed Limit:");
	lcd.setCursorPositionRowCol(4, 13);
	lcd.lcdString(e.getSpeedLimitStr());
}

// function to initialize GPIO pins
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

int connect(int fd) {

	struct termios tty;
	if (tcgetattr(fd, &tty) != 0) {
		std::cout << "tcgetattr error\n";
		return -1;
	}

	cfsetospeed(&tty, B9600);		// write baud rate set to 9600
	cfsetispeed(&tty, B9600);		// read baud rate set to 9600

	tty.c_cflag = (tty.c_cflag & ~CSIZE) | CS8;		// 8-bit chars

	// disable IGNBRK for mismatched speed tests; otherwise receive break as \000 chars
	tty.c_iflag &= ~IGNBRK;		// disable break processing
	tty.c_lflag = 0;			// no signaling chars, no echo, no canonical processing
	tty.c_oflag = 0;            // no remapping, no delays
	tty.c_cc[VMIN]  = 0;        // read doesn't block
	tty.c_cc[VTIME] = 5;        // 0.5 seconds read timeout

    	tty.c_iflag &= ~(IXON | IXOFF | IXANY); // shut off xon/xoff ctrl

    	tty.c_cflag |= (CLOCAL | CREAD);		// ignore modem controls, enable reading
        
    	tty.c_cflag &= ~PARENB;     // shut off parity
    	tty.c_cflag |= 0;			// no parity
    	tty.c_cflag &= ~CSTOPB;
    	tty.c_cflag &= ~CRTSCTS;

    	if (tcsetattr (fd, TCSANOW, &tty) != 0) {
		std::cout << "Error from tcssetarr\n";
        	return -1;
    	}
    	return 0;
}

void setBlocking (int fd) {
        struct termios tty;
        memset (&tty, 0, sizeof tty);
        if (tcgetattr (fd, &tty) != 0) {
        	std::cout << "Error from tggetattr\n";
            return;
        }

        tty.c_cc[VMIN]  = 0;	// no blocking
        tty.c_cc[VTIME] = 1;    // 0.5 seconds read timeout

        if (tcsetattr (fd, TCSANOW, &tty) != 0)
    		std::cout << "Error setting term attributes\n";
}


