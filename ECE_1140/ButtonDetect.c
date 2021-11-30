#include <stdio.h>
#include <string.h>
#include <wiringPi.h>
#include <wiringSerial.h>

#define E_BRAKE 2		// GPIO 2
#define BRAKE 3			// GPIO 3
#define SPEED_UP 4		// GPIO 4
#define SPEED_DOWN 5	// GPIO 5
#define TEMP_UP 6		// GPIO 6
#define TEMP_DOWN 7		// GPIO 7
#define LIGHTS 8		// GPIO 8
#define LEFT_DOORS 9	// GPIO 9
#define RIGHT_DOORS 10	// GPIO 10
#define S 11		// GPIO 11

void pinSetup();

int main() {
	int serialPort;
	std::string = "0,0,0,0,0,0,0.0000000000";

	pinSetup();
	
	if ((serialPort = serialOpen("/dev/ttyS0", 9600)) < 0) {
		printf("Unable to open serial device\n");
		return 1;
	}
	
	while(1) {
		// read emergency brake [0]
		if (!digitalRead(E_BRAKE)) 
			command[0] = '1';
			
		// read brakes [1]
		if (!digitalRead(BRAKE))
			command[2] = '1';
			
		// read increase speed [2]
		if (!digitalRead(SPEED_UP))
			command[2] = '1';
			
		// read decrease speed [3]
		if (!digitalRead(SPEED_DOWN))
			command[3] = '1';
		
		// read increase temp [4]
		if (!digitalRead(TEMP_UP))
			command[4] = '1';
		
		// read decrease temp [5]
		if (!digitalRead(TEMP_DOWN))
			command[5] = '1';
			
		// read lights [6]
		if (digitalRead(LIGHTS))
			command[6] = '1';
		
		delay(100);
		printf("%s\n", command);
		serialPuts(serialPort, command);
		strncpy(command, "000000000", sizeof(command));
//		if (!digitalRead(S))
//			break;
	}
	
	return 0;
}

void pinSetup() {
	wiringPiSetupGpio();
	
	pinMode(E_BRAKE, INPUT);
	pinMode(BRAKE, INPUT);
	pinMode(SPEED_UP, INPUT);
	pinMode(SPEED_DOWN, INPUT);
	pinMode(TEMP_UP, INPUT);
	pinMode(TEMP_DOWN, INPUT);
	pinMode(LEFT_DOORS, INPUT);
	pinMode(RIGHT_DOORS, INPUT);
	pinMode(LIGHTS, INPUT);
	pinMode(S, INPUT);
	
	pullUpDnControl(E_BRAKE, PUD_UP);
	pullUpDnControl(BRAKE, PUD_UP);
	pullUpDnControl(SPEED_UP, PUD_UP);
	pullUpDnControl(SPEED_DOWN, PUD_UP);
	pullUpDnControl(TEMP_UP, PUD_UP);
	pullUpDnControl(TEMP_DOWN, PUD_UP);
	pullUpDnControl(LEFT_DOORS, PUD_UP);
	pullUpDnControl(RIGHT_DOORS, PUD_UP);
	pullUpDnControl(LIGHTS, PUD_UP);
	pullUpDnControl(S, PUD_UP);
}
