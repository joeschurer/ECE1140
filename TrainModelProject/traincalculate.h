#ifndef TRAINCALCULATE_H
#define TRAINCALCULATE_H
#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;
class trainCalculate
{

public:
    trainCalculate();
    //trainCalculate();
    void setPower(double);
    double calculateVelocity();
    double distTraveled(int);
    int calcWeight(int);
    double getLength();
    int calcCapacity(int);
    void leftDoors();
    void rightDoors();
    void calcTime();
    void resetValues();
    void trainAtStation();
    vector<int> passengersLeavingTrain();
    void testDist();

//acceleration and deceleration set values
    double accelLimit = 0.5;
    double serviceDecel = -1.2;
    double emergencyDecel = -2.73;

//variables
    float distToDest;
    int id;
    double trainLength = 0;
    double percentCapacity = 0.0;
    int numCars;
    double numPassengers = 0;
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
    int crewMembers = 1;
    bool atStation = false;
    double maxCapacity = 222;
    double newPassengers = 0;
    double passengersOff = 0;
    bool leftDoorsVal = false;
    bool rightDoorsVal = false;
    int currentMode = 0;
    bool emergencyBrake = false;
    int currentWeight;
    int timespan = 5;
    int trainWeight;
    int blockSize;
    bool serviceBrake = false;
    int setTemp;
    int outsideTemp;
    int currentTemp;
    float setDist;

};

#endif // TRAINCALCULATE_H
