#ifndef TRAINCALCULATE_H
#define TRAINCALCULATE_H
#include <cstdlib>
#include <iostream>

class trainCalculate
{

public:
    trainCalculate();
    //trainCalculate();
    void setPower(double);
    double calculateVelocity();
    double distTraveled();
    int calcWeight(int);
    double getLength();
    int calcCapacity(int);
    void leftDoors();
    void rightDoors();
    void calcTime();
    void resetValues();


//acceleration and deceleration set values
    double accelLimit = 0.5;
    double serviceDecel = -1.2;
    double emergencyDecel = -2.73;

//variables
    double trainLength = 0;
    int numCars;
    int numPassengers = 0;
    int currentPower;
    double currentVelocity;
    double currentMPH;
    double currentKPH;
    double currentAcc;
    double currentForce;
    double lastVelocity;
    double lastAcc;
    int lastPosition;
    int currentPosition;
    double currentTime;
    double lastTime;
    int maxCapacity = 222;
    int newPassengers = 0;
    int passengersOff = 0;
    bool leftDoorsVal = false;
    bool rightDoorsVal = false;
    int currentMode = 0;
    bool emergencyBrake = false;
    int currentWeight;
    int timespan = 5;
    int trainWeight;
    int blockSize;

};

#endif // TRAINCALCULATE_H
