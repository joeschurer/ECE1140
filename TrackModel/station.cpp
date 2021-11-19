#include "station.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>

using namespace std;

Station::Station()
{
    passengers = -1;
    rightBoarding = true;
    leftBoarding = false;
}

Station::Station(string name) {
    this->name = name;
    passengers = 0;
    rightBoarding = true;
    leftBoarding = true;
}

Station::Station(string name, int pass, bool left, bool right) {
    this->name = name;
    passengers = pass;
    leftBoarding = left;
    rightBoarding = right;
}

void Station::addPassengers() {
    passengers += rand() % 10 + 1;
}


