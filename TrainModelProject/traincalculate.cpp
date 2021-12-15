#include "traincalculate.h"
#include <cstdlib>
#include <iostream>
#include <vector>
#include <QDebug>
trainCalculate::trainCalculate()
{
    numCars = 2;
    numPassengers = 0.00;
    passengersOff = 0.00;
    currentPower = 0;
    currentVelocity = 0;
    lastAcc = 0;
    currentAcc = 0;
    trainLength = 105.6;
    maxCapacity = 222.00;
    currentMode = 0;
    lastVelocity = 0;
    currentForce = 0;
    currentWeight = 41050;
    trainWeight = 40900;
    lastTime = 0;
    currentTime = 1;
    lastPosition = 0;
    currentPosition = 0;
    blockSize = 50;
    setTemp = 0;
    outsideTemp = 72;
    currentTemp = 70;
    distToDest = 0;
}


//modes:
//mode 0: standard mode
//mode 1: signal pickup failure
//mode 2 brake failure
//mode 3: train engine failure (power failure)
void trainCalculate::setPower(double power){
    if(currentMode == 4 || emergencyBrake == true || serviceBrake == true){
        currentPower = 0; //if service brake is pulled, TC sends 0 power.
    }else{
        currentPower = power;
    }
    if(currentForce > (.5*currentWeight)){
        currentForce = .5*currentWeight;
    } else if((lastVelocity && currentPower == 0) || emergencyBrake == true){
        currentForce = 0;
    }else if(lastVelocity == 0){
        currentForce = currentPower;
    }else{
        currentForce = currentPower / lastVelocity;
    }


    return;
}

//calculate distance traveled since the last clock tick
double trainCalculate::distTraveled(int blockLength){
    if(lastTime == 0){
        lastPosition = 0;
    }

    double timeDiff = currentTime-lastTime;
    double avgVelocity = (currentVelocity+lastVelocity)/2;
    double distanceCovered = avgVelocity * (currentTime - lastTime);
    return distanceCovered;
}

//reset values once the train has come to a stop from either of the brakes
void trainCalculate:: resetValues(){
    passengersOff = 0;
    lastAcc = 0;
    currentAcc = 0;
    currentMode = 0;
    currentForce = 0;
}

void trainCalculate::trainAtStation(){
    if(currentVelocity == 0 && serviceBrake == true){
        atStation = true;
    }
}

//velocity calculations
//was having connectivity issues with the whole project so I was going
//to wait to implement grade and elevation.
//ran out of time so there is no grade/elevation in the calculations of speed
double trainCalculate::calculateVelocity(){
    qDebug() << "starting calcvelocity";
    if(currentVelocity == 0 && atStation == true){
        resetValues();
    }
    lastVelocity = currentVelocity;
    lastAcc = currentAcc;

    if(lastVelocity != 0){
        currentForce = (currentPower / lastVelocity)/*-(40*lastVelocity*lastVelocity)*/;
    }
    currentAcc = currentForce/currentWeight;
    if(currentMode != 2){
        if(serviceBrake == true){ //service brake
            lastAcc = -1.2;
            currentAcc = -1.2;
        }
    }else if (emergencyBrake == true){ //emergency brake
        lastAcc = -2.73;
        currentAcc = -2.73;
    }
    if(currentAcc > 1.2){
        currentAcc = 1.2;
    }
    currentVelocity = currentVelocity + ((currentTime-lastTime)*(currentAcc+lastAcc))/2;
    if(currentVelocity < 0){
        currentVelocity = 0;
    }
    currentKPH = currentVelocity*3.6; //convert to Kilometers per hour
    if(currentKPH > 70){
        currentKPH = 70;
    }
    qDebug() << currentKPH;
    return currentKPH;
}

double trainCalculate::getLength(){
    return trainLength;
}

//weight is calculated with 150 avg weight for a person + the train weight
int trainCalculate::calcWeight(int numPassengers){
    int passWeight = 150*numPassengers;
    int crewWeight = 150*crewMembers;
    currentWeight = trainWeight + passWeight + crewWeight;
    return currentWeight;
}


//randomly assigns a % of total passengers to leave the train.
vector<int> trainCalculate::passengersLeavingTrain(){
    if(numPassengers > 0){
        int aaah = rand() % (int)numPassengers;
        passengersOff = aaah;
    }
        numPassengers = numPassengers-passengersOff;
    vector<int> result;
    result[0] = id;
    result[1] = passengersOff;
    return result;
}

//brings in new passengers and calculates total and percent capacity
int trainCalculate::calcCapacity(int newPassengers){
        numPassengers += newPassengers;
        if(numPassengers > maxCapacity){
            numPassengers = maxCapacity;
        }
        percentCapacity = (numPassengers/maxCapacity) * 100;
        calcWeight(numPassengers);

        serviceBrake = false; //not sure if this is the right place to put this
    return numPassengers;
}
void trainCalculate::leftDoors(){
    if(leftDoorsVal == true && currentVelocity == 0){
        leftDoorsVal = false;
    }else if(currentVelocity == 0){
        leftDoorsVal = true;
    }
    return;
}
void trainCalculate::rightDoors(){
    if(rightDoorsVal == true && currentVelocity == 0){
        rightDoorsVal = false;
    }else if(currentVelocity == 0){
        rightDoorsVal = true;
    }
    return;
}

//test function for distance in the test module for automatic stopping
//without help from the beacons.

void trainCalculate::testDist(){
    //current speed in kph * 1000 / 60 / 60 * (velocity / acceleration kph / 2)
    double avgVelocity = (currentVelocity+lastVelocity)/2;
    if(avgVelocity > 19.444){
        avgVelocity = 19.444;
    }
    double distanceCovered = avgVelocity;
    distToDest = distToDest - distanceCovered;
    float distToStop = (((currentKPH * 1000) / 60) / 60);
    distToStop = distToStop * ((currentKPH/4.32)/2);
    if(distToDest <= distToStop){
        if(currentMode != 2){
            currentKPH = 70;
            serviceBrake = true;
            currentPower = 0;
        }

    }


}
