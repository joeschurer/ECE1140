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
    currentAcc = 0;
    trainLength = 105.6;
    maxCapacity = 222;
    currentMode = 0;
    lastVelocity = 0;
    currentForce = 0;
    currentWeight = 40800;
}
void trainCalculate::getPower(double power){
    if(currentMode == 2){
        power = 0;
    }else{
        currentPower = power;
    }
    currentForce = currentPower / lastVelocity;
    if(currentForce > (.5*currentWeight)){
        currentForce = .5*currentWeight;
    } else if((lastVelocity && currentPower == 0) || emergencyBrake == true){
        currentForce = 0;
    }else if(lastVelocity == 0){
        currentForce = .5*currentWeight;
    }
    currentAcc = currentForce/currentWeight;
    if(currentAcc > .5){
        currentAcc = .5;
    }
    return;
}

float trainCalculate::distTraveled(){

}

void trainCalculate:: calcTime(){

}

float trainCalculate::calculateVelocity(){
    currentVelocity = currentVelocity + (currentAcc*timespan);
    if(currentVelocity < 0){
        currentVelocity = 0;
    }
    return currentVelocity;
}

float trainCalculate::getLength(){
    return trainLength;
}
int trainCalculate::calcWeight(int numPassengers){
    int weight = 2*40800;
    int passWeight = 150*numPassengers;
    currentWeight = weight + passWeight;
    return currentWeight;
}
int trainCalculate::calcCapacity(int numPassengers, int newPassengers){

    if(numPassengers > 0){
        passengersOff = rand() % numPassengers;
    }
        numPassengers = numPassengers-passengersOff;
        numPassengers += newPassengers;
        if(numPassengers > maxCapacity){
            numPassengers = maxCapacity;
        }
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

//length of blokc
//grade
//speedlimit
//commanded speed
//passengers
