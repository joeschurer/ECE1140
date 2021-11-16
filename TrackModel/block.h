#ifndef BLOCK_H
#define BLOCK_H

#include "switch.h"
#include "station.h"
#include "beacons.h"
#include <string>

class Block
{
public:
    int blockNum;
    double length;
    double lengthFeet;
    int speedLimit;
    double grade;
    double elevation;
    bool heatersOn;
    bool presenceDetected;
    bool hasCrossing;
    bool crossingLights;
    bool underground;
    bool hasStation;
    bool hasBeacon = false;
    bool hasSwitch;
    bool trackBroken = false;
    bool circuitBroken = false;
    bool powerBroken = false;
    string section;
    Beacons beacon;
    Station station;
    Switch swtch;

    Block();
    Block(int blockNum, string section, double lenght, int speedLimit, double grade, double elevation);
    Block(int blockNum, string section, double length, int speedLimit, double grade, double elevation, bool hasCrossing, bool underground);
    Block(int blockNum, string section, double length, int speedLimit, double grade, double elevation, bool hasCrossing, bool underground, Station stat);
    Block(int blockNum, string section, double length, int speedLimit, double grade, double elevation, bool hasCrossing, bool underground, Switch swi);
};

#endif // BLOCK_H
