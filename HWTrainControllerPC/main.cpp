#include <iostream>
#include <string>
#include <stdlib.h>
#include <unistd.h>
#include <windows.h>
#include "HWTrainControllerPC.hpp"
#include "TrainModelTest.hpp"

#define READ_LENGTH 15
#define WRITE_LENGTH 14

// Open serial port
HANDLE serialHandle;
char port[] = "\\\\.\\COM8";
char readData[READ_LENGTH];
//char writeData[WRITE_LENGTH] = { '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0' };
char *writeData;
								
// power failure, track signal failure, brake failure, authority, current speed, commanded speed, speed limit (13)

void connect();
void createTestValues();

int main(void) {
	
	connect();
	HWTrainControllerPC tc;
	TrainModelTest tm;
	LPDWORD bytesSent, bytesReceived;
	
	while(1) {
		bool signalReceived = false;
		bool signalSent = false;
		writeData = tm.createWriteString();
		std::cout << "write: " << writeData << std::endl;
		while (*bytesSent != WRITE_LENGTH && !signalSent) {
			if (WriteFile(serialHandle, writeData, WRITE_LENGTH, bytesSent, NULL)) {
				signalSent = true;
			}
		}
		
		while (*bytesReceived != READ_LENGTH && !signalReceived) {
			if (ReadFile(serialHandle, readData, READ_LENGTH, bytesReceived, NULL)) {
				signalReceived = true;
			}
		}
		std::cout << "read: " << readData << std::endl;
		tc.parseReadString(readData);
		usleep(500);
	}
	
	CloseHandle(serialHandle);
	
	return 0;
}

void connect() {
	
	serialHandle = CreateFileA(port, GENERIC_READ | GENERIC_WRITE, 0, 0, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0);

	// Do some basic settings
	DCB serialParams = { 0 };
	serialParams.DCBlength = sizeof(serialParams);

	GetCommState(serialHandle, &serialParams);
	serialParams.BaudRate = CBR_9600;	
	serialParams.ByteSize = 8;
	serialParams.StopBits = ONESTOPBIT;
	serialParams.Parity = NOPARITY;
	SetCommState(serialHandle, &serialParams);

	// Set timeouts, all time in ms
	COMMTIMEOUTS timeout = { 0 };
	timeout.ReadIntervalTimeout = 50;			// 50, maximum time allowed to elapse before the arrival of the next byte on the communications line
	timeout.ReadTotalTimeoutConstant = 50;		// 50, constant used to calculate the total time-out period for read operations
	timeout.ReadTotalTimeoutMultiplier = 50;	// 50, multiplier used to calculate the total time-out period for read operations
	timeout.WriteTotalTimeoutConstant = 50;		// 50, constant used to calculate the total time-out period for write operations
	timeout.WriteTotalTimeoutMultiplier = 50;	// 10, multiplier used to calculate the total time-out period for write operations

	SetCommTimeouts(serialHandle, &timeout);
}
