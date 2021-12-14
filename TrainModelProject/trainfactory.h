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

signals:
    void commandedSpeedTC(int id, int cSpeed);

public slots:
        void dispatchTrain(vector<int>);
};



#endif // TRAINFACTORY_H
