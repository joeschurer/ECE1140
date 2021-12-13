#ifndef TRAINMODELTEST_H
#define TRAINMODELTEST_H

class TrainModelTest {
	private:
		bool powerFailure, signalFailure, brakeFailure, authority;
		int speedLimit;
		double suggestedSpeed, currentSpeed;
		char trackSignal[14];
		
	public:
		TrainModelTest();
		char *createWriteString();
		void setPowerFailure(bool b);
		void setSignalFailure(bool b);
		void setBrakeFailure(bool b);
		void setAuthority(bool b);
		void setSpeedLimit(int i);
		void setSuggestedSpeed(double d);
		void setCurrentSpeed(double d);
		bool getPowerFailure() const;
		bool getSignalFailure() const;
		bool getBrakeFailure() const;
		bool getAuthority() const;
		int getSpeedLimit() const;
		double getSuggestedSpeed() const;
		double getCurrentSpeed() const;
};

#include "TrainModelTest.cpp"
#endif
