#include "trainfactory.h"
#include "ui_trainfactory.h"
#include <vector>
#include "trainmodelui.h"
#include "ui_trainmodelui.h"
#include "traincalculate.h"
#include <QTimer>
TrainFactory::TrainFactory(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::TrainFactory)
{
    ui->setupUi(this);
    globalTemp = 72;
//    timer = new QTimer(this);
//    timer->start(1000);
}

TrainFactory::~TrainFactory()
{
    delete ui;
}






void TrainFactory::timeSlot(){
    for(int i = 0; i < trains.size(); i++){
        trains[i]->dormammu();
        qDebug() << "fuck";
    }
}

//slot to receive train and decode values
void TrainFactory::dispatchTrain(vector<int> trainData){
    int id = trainData[0];
    int comm = trainData[1];
    trainCalculate calcs;
    //TrackModel asked me to use same signal for the track signal and the creation signal so I had to
    //do some magic here with size of thet vector.
    if(trainData.size() == 2){
        makeTrain(calcs, id, comm);

    }else if(trainData.size() == 7){
        receiveSignal(trainData);
    }
}

//called after dispatchTrain decodes, creates the train.
void TrainFactory::makeTrain(trainCalculate calcs, int id, int comm){

    TrainModelUI* trane = new TrainModelUI();
    //timer had to be personalized inside each train otherwise it wouldn't update the ui on tick
    //and they would remain at 0 vals.


    //assign trane to the vector of trains and assign an individual train
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
    int auth = data[6];

    if(trains[id]->calcs.currentMode == 1){
        trains[id]->trackSignal(0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00);
    }else{
        trains[id]->trackSignal(id, loc, blockLength, grade, speedLimit, comm, auth);
    }

}

void TrainFactory::boardingPassengers(vector<int> data){
    int id = data[0];
    int newPass = data[1];
    trains[id]->calcs.calcCapacity(newPass);
    trains[id]->updateUI();
}


void TrainFactory::receiveBeacon(vector<string> data){
    string stringID = data[0];
    int id = stoi(stringID);
    string stationName = data[1];
    string side = data[2];
    int sideNum;
    if(side == "LEFT"){
        sideNum = 1;
    }else if(side == "RIGHT"){
        sideNum = 2;
    }else{
        sideNum = 3;
    }
    emit beaconToTC(id, stationName, sideNum);
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
