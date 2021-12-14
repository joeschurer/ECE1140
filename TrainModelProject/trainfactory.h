#ifndef TRAINFACTORY_H
#define TRAINFACTORY_H
#include <vector>
#include "traincalculate.h"
#include "trainmodelui.h"
using namespace std;

class TrainFactory
{
public:
    TrainFactory();
    void makeTrain(trainCalculate, int, int);
    vector<TrainModelUI*> trains;
    int globalTemp;

signals:
    void commandedSpeedTC(int id, int cSpeed);
    void passOffTrain(vector<int>);
    void beaconToTC(vector<string>);

public slots:
        //on train creation
        void dispatchTrain(vector<int>);

        //slots from TM
        void receiveSignal(vector<int>);
        void boardingPassengers(vector<int>);
        void receiveBeacon(vector<string>);
        void temperatureChange(double);

        //slots from TC
        void receiveStationInfo(int, string, string);

};



#endif // TRAINFACTORY_H
