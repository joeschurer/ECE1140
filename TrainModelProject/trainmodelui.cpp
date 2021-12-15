#include "trainmodelui.h"
#include "ui_trainmodelui.h"
#include "traincalculate.h"
#include <QApplication>
#include <QDebug>
TrainModelUI::TrainModelUI(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::TrainModelUI)
{
    ui->setupUi(this);
    trainCalculate calcs;
    double covered;
}

TrainModelUI::~TrainModelUI()
{
    delete ui;
}






void TrainModelUI::setLength(){
    ui->trainLengthValue->setText(QString::number(calcs.trainLength));

}

void TrainModelUI::setWeight(){

    ui->trainWeightV->setText(QString::number(calcs.currentWeight));
}

void TrainModelUI::setHeight(){

    ui->trainHeightVal->setText(QString::number(calcs.trainHeight));
}

void TrainModelUI::setWidth(){

    ui->trainWidthVal->setText(QString::number(calcs.trainWidth));
}

//void TrainModelUI::getPower(int power){
//    calcs.setPower(power);
//    ui->currentPowerValue->setText(QString::number((power)));

//}

void TrainModelUI::getVelocity(float speed){

    ui->currentSpeedValue->setText(QString::number((speed)));

}


void TrainModelUI::getAcceleration(float acc){
    ui->currentAccelerationValue->setText(QString::number((acc)));

}
void TrainModelUI::getLightState(bool val){
    if(val == false){
        ui->lightStateValue->setText("CLOSED");
    }else{
        ui->lightStateValue->setText("OPEN");
    }
}

void TrainModelUI::getLeftDoorState(bool val){
    if(val == false){
        ui->leftDoorStateValue->setText("CLOSED");
    }else{
        ui->leftDoorStateValue->setText("OPEN");
    }
}
void TrainModelUI::getRightDoorState(bool val){
    if(val == false){
        ui->rightDoorStateValue->setText("CLOSED");
    }else{
        ui->rightDoorStateValue->setText("OPEN");
    }
}
void TrainModelUI::getMode(int val){
    if(val == 0){
        ui->currentModeValue->setText("FUNCTIONAL MODE");
    }else if(val == 1){
        ui->currentModeValue->setText("SIGNAL PICKUP FAILURE");
    }else if (val == 2){
        ui->currentModeValue->setText("BRAKE FAILURE MODE");
    }else if (val == 3){
        ui->currentModeValue->setText("ENGINE FAILURE MODE");
    }
}
void TrainModelUI::getPassengers(int passengers){
    ui->passengersOnTrainValue->setText(QString::number(passengers));
}


void TrainModelUI::on_toggleLights_clicked()
{
    if(ui->lightStateValue->text() == "OFF" ){
        ui->lightStateValue->setText("ON");
    } else{
        ui->lightStateValue->setText("OFF");
    }
}

void TrainModelUI::outsideTemperature(int tt){
    calcs.outsideTemp = tt;
    return;
}
void TrainModelUI::internalTemperature(int sett){
    calcs.setTemp = sett;
}


void TrainModelUI::on_inputPowerConfirm_clicked()
{
    QString x = ui->inputPowerResult->text();
    double powerval = x.toDouble();
    calcs.setPower(powerval);

}



void TrainModelUI::on_emergencyBrake_clicked()
{
    if(calcs.emergencyBrake == false){
        ui->currentModeValue->setText("Emergency Brake Pulled");
        calcs.setPower(0);
        calcs.emergencyBrake = true;
        emit eBrakeSetTC(calcs.id, true);
    }else{
        ui->currentModeValue->setText("Standard Mode");
        calcs.emergencyBrake = false;
        calcs.resetValues();
    }



}

void TrainModelUI::dormammu(){ //my clock
    calcs.lastTime = calcs.currentTime;
    calcs.currentTime += 1;
    qDebug() << calcs.currentTime;
    updateUI();
    qDebug() << "finished updateUI";
}

void TrainModelUI::stationValues(string stationName, string side){
    std::string station = stationName;
    QString qstr = QString::fromStdString(station);

    std::string doorSide = side;
    QString doorname = QString::fromStdString(doorSide);
    ui->nextStationValue->setText(qstr);
    if(side == "left"){
        on_toggleDoorLeft_clicked();
    }else{
        on_toggleDoorRight_clicked();
    }
    vector byebye = calcs.passengersLeavingTrain();
    emit offPassengers(byebye);
}

void TrainModelUI::on_pushButton_3_clicked()
{
    ui->currentModeValue->setText("BRAKE FAILURE");
    int i = 2;
    calcs.currentMode = 2;
    emit failureState(calcs.id, i);
}


void TrainModelUI::on_toggleDoorRight_clicked()
{
    if(calcs.currentVelocity == 0){
        if(ui->rightDoorStateValue->text() == "OPEN" ){
            ui->rightDoorStateValue->setText("CLOSED");
        } else{
            ui->rightDoorStateValue->setText("OPEN");
        }
    }

}



void TrainModelUI::on_toggleDoorLeft_clicked()
{
    if(calcs.currentVelocity == 0){
        if(ui->leftDoorStateValue->text() == "OPEN" ){
            ui->leftDoorStateValue->setText("CLOSED");
        } else{
            ui->leftDoorStateValue->setText("OPEN");
        }
    }

}


void TrainModelUI::on_pushButton_2_clicked()
{
    ui->currentModeValue->setText("SIGNAL PICKUP FAILURE");
    int i = 1;
    calcs.currentMode = 1;
    emit failureState(calcs.id, i);
}


void TrainModelUI::on_pushButton_4_clicked()
{
    ui->currentModeValue->setText("TRAIN ENGINE FAILURE");
    int i = 3;
    calcs.setPower(0);
    emit failureState(calcs.id, i);
}

void TrainModelUI::updateUI(){
    qDebug() << calcs.currentPower;
    qDebug() << "input power result:";
    qDebug() << ui->inputPowerResult->text();
    double speed = calcs.calculateVelocity();
    ui->currentSpeedValue->setText(QString::number(speed));
    emit currSpeedTC(calcs.id, (speed*0.621371));
    QString speedToTM = QString::number(speed);
    emit currSpeedTM(speedToTM);
    ui->currentAccelerationValue->setText(QString::number(calcs.currentAcc));
    ui->currentPowerValue->setText(QString::number(calcs.currentPower));
    ui->passengersOnTrainValue->setText(QString::number(calcs.numPassengers));
    setLength();
    setWeight();
    setHeight();
    setWidth();
    calcTemp();
    covered += calcs.distTraveled(blockLength);
    if(covered >= blockLength){
        emit moveBlock(calcs.id);
    }
    ui->crewMembersValue->setText(QString::number(calcs.crewMembers));
    //testmodule vals
    calcs.testDist();
    QString dist = QString::number(calcs.distToDest);
    ui->distToDestVal->setText(dist);


    qDebug() << "end updateUI";
}


void TrainModelUI::CurrentSpeedDifferent(int power){
    calcs.setPower(power);
    int speed = calcs.calculateVelocity();
    emit currSpeedTC(calcs.id, speed);
    QString speedToTM = QString::number(speed);
    emit currSpeedTM(speedToTM);
}

void TrainModelUI::boardingPassengersFromTM(int numPassengers){
    int newtotal = calcs.calcCapacity(numPassengers);
    ui->passengersOnTrainValue->setText(QString::number(newtotal));
    ui->percentCapacityValue->setText(QString::number(calcs.percentCapacity));
}
void TrainModelUI::trackSignal(int i, int l, int bL, int g, int sL, int c, int au){
    int id = i;
    int loc = l;
    blockLength = bL;
    int grade = g;
    int speedLimit = sL;
    int comm = c;
    int auth = au;

    covered = calcs.distTraveled(blockLength);

    if(calcs.currentMode == 2){
        emit trackSignalTC(id, 0, 0, auth);
    }else{
        emit trackSignalTC(id, speedLimit, comm, auth);
    }


}

void FailureDifferent(std::string state);
void distLeftTC(int dist);
void eBrakeSetTC(bool state);
void failureState(int mode);

//to track model
void currSpeed(int currSpeed);
void currentPassengers(int passengers);


//length of block
//grade
//speedlimit
//commanded speed
//passengers

void TrainModelUI::on_pushButton_clicked()
{
    updateUI();
}


void TrainModelUI::on_serviceBrakeButton_clicked()
{
    if(calcs.currentMode != 2){
        ui->currentModeValue->setText("Service Brake Pulled");
        calcs.serviceBrake = true;
        calcs.currentPower = 0;
    }

}


void TrainModelUI::on_standardModeButton_clicked()
{
    ui->currentModeValue->setText("Standard");
    calcs.currentMode = 0;
    calcs.emergencyBrake = false;
    calcs.serviceBrake = false;
    calcs.resetValues();

}

void TrainModelUI::TempChanged(int temp)
{
    ui->currentTempValue->setText(QString::number(temp));
}

void TrainModelUI::LeftDoorsChanged(bool state)
{
    if(calcs.currentVelocity == 0){
        if(state)
        {
            ui->leftDoorStateValue->setText("Open");
        }
        else
        {
            ui->leftDoorStateValue->setText("Closed");
        }
    }
}

void TrainModelUI::RightDoorsChanged(bool state)
{
    if(calcs.currentVelocity == 0){
        if(state)
        {
            ui->rightDoorStateValue->setText("Open");
        }
        else
        {
            ui->rightDoorStateValue->setText("Closed");
        }
    }
}

void TrainModelUI::LightsChanged(bool state)
{
    if(state)
    {
        ui->lightStateValue->setText("On");
    }
    else
    {
        ui->lightStateValue->setText("Off");
    }
}
void TrainModelUI::PowerChanged(int power)
{
    calcs.setPower(power);
    updateUI();
}

void  TrainModelUI::calcTemp(){
    if(calcs.currentTemp > calcs.outsideTemp){
        ui->tempControlValue->setText("AC on");
    }else{
        ui->tempControlValue->setText("Heater on");
    }
}

void TrainModelUI::on_inputTempConfirm_clicked()
{
    QString x = ui->inputCurrentTempValue->text();
    double tempval = x.toDouble();
    ui->currentTempValue->setText(QString::number(tempval));

}


void TrainModelUI::on_passengersConfirm_clicked()
{
    int input = ui->inputPassengersOnBoard->text().toInt();
    calcs.passengersLeavingTrain();
    boardingPassengersFromTM(input);

}


void TrainModelUI::on_stationMetersButton_clicked()
{
    QString x = ui->stationMetersVal->text();
    double tempval = x.toDouble();
    ui->distToDestVal->setText(x);
    calcs.distToDest = tempval;
    calcs.testDist();
}


void TrainModelUI::on_moveNextBlock_clicked()
{
    emit moveBlock(calcs.id);
}

