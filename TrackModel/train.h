#ifndef TRAIN_H
#define TRAIN_H

#include <string>
#include <vector>
using namespace std;

class Train
{
public:
    int commandedSpeed;
    double actualSpeed;
    int capacity = 222; //Pulled from track/vehicle data excel sheet
    int passengers;
    bool emergencyStop;
    int id;
    int location;

    Train();
    Train(int id, int com, int loc);
    void setCommandedSpeed(int com);
    void setActualSpeed(double act);
    void addPassengers(int available);
    void removePassengers();
    void removePassengers(int rem);
    void moveTrain(int loc);
};

#endif // TRAIN_H
