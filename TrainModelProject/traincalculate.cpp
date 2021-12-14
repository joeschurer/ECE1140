#include "traincalculate.h"
#include <cstdlib>
#include <iostream>
trainCalculate::trainCalculate()
{
    numCars = 2;
    numPassengers = 0;
    passengersOff = 0;
    currentPower = 0;
    currentVelocity = 0;
    lastAcc = 0;
    currentAcc = 0;
    trainLength = 105.6;
    maxCapacity = 222;
    currentMode = 0;
    lastVelocity = 0;
    currentForce = 0;
    currentWeight = 40900;
    trainWeight = 40900;
    lastTime = 0;
    currentTime = 1;
    lastPosition = 0;
    currentPosition = 0;
    blockSize = 50;
    setTemp = 0;
    outsideTemp = 0;
    currentTemp = 70;
}


//modes:
//mode 1: standard mode
//mode 2: signal pickup failure
//mode 3 brake failure
//mode 4: train engine failure (power failure)
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

double trainCalculate::distTraveled(){
    if(lastTime == 0){
        lastPosition = 0;
    }
    double timeDiff = currentTime-lastTime;
    double avgVelocity = (currentVelocity+lastVelocity)/2;
    double distanceCovered = avgVelocity * (currentTime - lastTime);
    return distanceCovered;
}

void trainCalculate:: calcTime(){

}

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

double trainCalculate::calculateVelocity(){
    if(currentVelocity == 0 && atStation == true){
        resetValues();
    }
    lastVelocity = currentVelocity;
    lastAcc = currentAcc;

    if(lastVelocity != 0){
        currentForce = (currentPower / lastVelocity)-(40*lastVelocity*lastVelocity);
    }
    currentAcc = currentForce/currentWeight;
    if(serviceBrake == true){ //service brake
        lastAcc = -1.2;
        currentAcc = -1.2;
    }else if (emergencyBrake == true){ //emergency brake
        lastAcc = -2.73;
        currentAcc = -2.73;
    }
    if(currentAcc > .5){
        currentAcc = .5;
    }
    currentVelocity = currentVelocity + ((currentTime-lastTime)*(currentAcc+lastAcc))/2;
    if(currentVelocity < 0){
        currentVelocity = 0;
    }
    currentKPH = currentVelocity*3.6; //convert to Kilometers per hour
    if(currentKPH > 70){
        currentKPH = 70;
    }

    return currentKPH;
}

double trainCalculate::getLength(){
    return trainLength;
}
int trainCalculate::calcWeight(int numPassengers){
    int passWeight = 150*numPassengers;
    currentWeight = trainWeight + passWeight;
    return currentWeight;
}
int trainCalculate::calcCapacity(int newPassengers){
    if(numPassengers > 0){
        //passengersOff = rand() % numPassengers;
    }
        numPassengers = numPassengers-passengersOff;
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


