#include "trainfactory.h"
#include <vector>
#include "trainmodelui.h"
#include "ui_trainmodelui.h"
#include "traincalculate.h"
TrainFactory::TrainFactory()
{
//    vector<TrainModelUI> temp(0,0);
//    trains = temp;
}

void TrainFactory::dispatchTrain(vector<int> trainData){
    int id = trainData[0];
    int comm = trainData[1];
    trainCalculate calcs;
    makeTrain(calcs, id, comm);
}

void TrainFactory::makeTrain(trainCalculate calcs, int id, int comm){

    TrainModelUI* trane = new TrainModelUI();
    trains.push_back(trane); //is spot in the vector its id number
    trane->calcs = calcs;
    trane->calcs.id = id;
    trane->show();
    trane->updateUI();
    emit trane->commandedSpeedTC(id, comm); //should be a different method to initialize train controller
}
