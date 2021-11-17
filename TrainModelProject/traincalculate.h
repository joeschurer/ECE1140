#ifndef TRAINCALCULATE_H
#define TRAINCALCULATE_H
#include <cstdlib>
#include <iostream>

class trainCalculate
{

public:
    trainCalculate();
    //trainCalculate();
    void getPower(double);
    float calculateVelocity();
    float distTraveled();
    int calcWeight(int);
    float getLength();
    int calcCapacity(int, int);
    void leftDoors();
    void rightDoors();
    void calcTime();


//acceleration and deceleration set values
    double accelLimit = 0.5;
    double serviceDecel = -1.2;
    double emergencyDecel = -2.73;

//variables
    float trainLength = 0;
    int numCars;
    int numPassengers = 0;
    int currentPower;
    float currentVelocity;
    float currentAcc;
    float currentForce;
    float lastVelocity;
    float lastAcc;
    int lastPosition;
    int currentPosition;
    int maxCapacity = 222;
    int newPassengers = 0;
    int passengersOff = 0;
    bool leftDoorsVal = false;
    bool rightDoorsVal = false;
    int currentMode = 0;
    bool emergencyBrake = false;
    int currentWeight;
    int timespan = 5;


};

#endif // TRAINCALCULATE_H
