#include "train.h"

Train::Train()
{
    passengers = 0;
    id = -1;
    commandedSpeed = -1;
    actualSpeed = -1;
    capacity = 222;
    emergencyStop = false;
    location = 0;
    authority.clear();
}

Train::Train(int id, int com, int loc, vector<bool> auth) {
    passengers = 0;
    this->id = id;
    commandedSpeed = com;
    actualSpeed = -1;
    capacity = 222;
    emergencyStop = false;
    location = loc;
    authority = auth;
}

void Train::setAuthority(vector<bool> auth) {
    authority.clear();
    authority = auth;
}

void Train::setCommandedSpeed(int com) {
    commandedSpeed = com;
}

void Train::setActualSpeed(double act) {
    actualSpeed = act;
}

//Add all possible passengers in a station.
void Train::addPassengers(int available) {
    int spots = capacity - passengers;
    if (available <= spots) passengers += available;
    else passengers = capacity;
}

//Remove all passengers at a station.
void Train::removePassengers() {
    passengers = 0;
}

//Remove a certain number of passengers at a station.
void Train::removePassengers(int rem) {
    passengers -= rem;
    if (passengers <0) passengers = 0;
}

void Train::moveTrain(int loc) {
    location = loc;
}
