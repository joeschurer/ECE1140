#include "trainfactory.h"
#include <vector>
#include "trainmodelui.h"
#include "ui_trainmodelui.h"
#include "traincalculate.h"
TrainFactory::TrainFactory()
{
//    vector<TrainModelUI> temp(0,0);
//    trains = temp;
    globalTemp = 72;
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
    trane->calcs.outsideTemp = globalTemp;
    emit trane->createTC(id, comm);//should be a different method to initialize train controller


}

//from Track Model
void TrainFactory::receiveSignal(vector<int> data){
    int id = data[0];
    int loc = data[1];
    int blockLength = data[2];
    int grade = data[3];
    int speedLimit = data[4];
    int comm = data[5];

    trains[id]->trackSignal(id, loc, blockLength, grade, speedLimit, comm);

}

void TrainFactory::boardingPassengers(vector<int> data){
    int id = data[0];
    int newPass = data[1];
    trains[id]->calcs.calcCapacity(newPass);
    trains[id]->updateUI();
}


void TrainFactory::receiveBeacon(vector<string> data){
    vector<string> aaaha = data;
    //emit beaconToTC(aaaha);
    //    string stringID = data[0];
//    int id = stoi(stringID);
//    string stationName = data[1];
//    string side = data[2];
//    bool stop = true;
}


void TrainFactory::temperatureChange(double temp){
    globalTemp = temp;
    for(int i = 0; i < trains.size(); i++){
        trains[i]->outsideTemperature(temp);
        trains[i]->calcs.setTemp;
        trains[i]->calcTemp();
        trains[i]->updateUI();
    }
}




//from Train Controller
void TrainFactory::receiveStationInfo(int id, string stationName, string side){
    trains[id]->stationValues(stationName, side);
    trains[id]->updateUI();
}

