#include "block.h"

Block::Block() {
    blockNum = -1;
    length = 0;
    lengthFeet = 0;
    speedLimit = 0;
    grade = 100;
    elevation = 0;
    heatersOn = false;
    presenceDetected = false;
    hasCrossing = false;
    crossingLights = false;
    underground = false;
    hasStation = false;
    hasSwitch = false;
    section = "";
    trackBroken = false;
    circuitBroken = false;
    powerBroken = false;
}

Block::Block(int blockNum, string section, double lenght, int speedLimit, double grade, double elevation) {
    this->blockNum = blockNum;
    this->section = section;
    this->length = lenght;
    lengthFeet = length*3.28;
    this->speedLimit = speedLimit;
    this->grade = grade;
    this->elevation = elevation;
    heatersOn = false;
    presenceDetected = false;
    hasCrossing = false;
    crossingLights = false;
    underground = false;
    hasStation = false;
    hasSwitch = false;
}

Block::Block(int blockNum, string section, double length, int speedLimit, double grade, double elevation, bool hasCrossing, bool underground) {
    this->blockNum = blockNum;
    this->section = section;
    this->length = length;
    lengthFeet = length*3.28;
    this->speedLimit = speedLimit;
    this->grade = grade;
    this->elevation = elevation;
    heatersOn = false;
    presenceDetected = false;
    this->hasCrossing = hasCrossing;
    crossingLights = false;
    this->underground = underground;
    hasStation = false;
    hasSwitch = false;
    trackBroken = false;
    circuitBroken = false;
    powerBroken = false;
}

Block::Block(int blockNum, string section, double length, int speedLimit, double grade, double elevation, bool hasCrossing, bool underground, Station stat) {
    this->blockNum = blockNum;
    this->section = section;
    this->length = length;
    lengthFeet = length*3.28;
    this->speedLimit = speedLimit;
    this->grade = grade;
    this->elevation = elevation;
    heatersOn = false;
    presenceDetected = false;
    this->hasCrossing = hasCrossing;
    crossingLights = false;
    this->underground = underground;
    hasStation = true;
    station.name = stat.name;
    hasSwitch = false;
    trackBroken = false;
    circuitBroken = false;
    powerBroken = false;
}

Block::Block(int blockNum, string section, double length, int speedLimit, double grade, double elevation, bool hasCrossing, bool underground, Switch swi) {
    this->blockNum = blockNum;
    this->section = section;
    this->length = length;
    lengthFeet = length*3.28;
    this->speedLimit = speedLimit;
    this->grade = grade;
    this->elevation = elevation;
    heatersOn = false;
    presenceDetected = false;
    this->hasCrossing = hasCrossing;
    crossingLights = false;
    this->underground = underground;
    hasStation = false;
    hasSwitch = true;
    swtch = swi;
    trackBroken = false;
    circuitBroken = false;
    powerBroken = false;
}
