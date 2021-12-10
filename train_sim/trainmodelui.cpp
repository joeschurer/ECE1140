#include "trainmodelui.h"
#include "ui_trainmodelui.h"
#include "traincalculate.h"
#include <QApplication>
TrainModelUI::TrainModelUI(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::TrainModelUI)
{
    ui->setupUi(this);
    trainCalculate hah;
}

TrainModelUI::~TrainModelUI()
{
    delete ui;
}

void TrainModelUI::makeTrain(trainCalculate calcs){
    train = calcs;
}

void TrainModelUI::setLength(double length){
    ui->trainLengthValue->setText(QString::number(length));

}

void TrainModelUI::setMass(double weight){
    ui->trainWeightV->setText(QString::number(weight));
}


void TrainModelUI::getPower(int power){
    train.setPower(power);
    ui->currentPowerValue->setText(QString::number((power)));

}

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
        ui->currentModeValue->setText("POWER FAILURE MODE");
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


void TrainModelUI::on_inputPowerConfirm_clicked()
{
    QString x = ui->inputPowerResult->text();
    double powerval = x.toDouble();
    train.setPower(powerval);

}





void TrainModelUI::on_emergencyBrake_clicked()
{
    ui->currentModeValue->setText("Emergency Brake Pulled");
    train.emergencyBrake = true;
    emit eBrakeSetTC(true);
}


void TrainModelUI::on_pushButton_3_clicked()
{
    ui->currentModeValue->setText("POWER FAILURE");
    int i = 2;
    emit failureState(i);
}


void TrainModelUI::on_toggleDoorRight_clicked()
{
    if(ui->rightDoorStateValue->text() == "OPEN" ){
        ui->rightDoorStateValue->setText("CLOSED");
    } else{
        ui->rightDoorStateValue->setText("OPEN");
    }
}



void TrainModelUI::on_toggleDoorLeft_clicked()
{
    if(ui->leftDoorStateValue->text() == "OPEN" ){
        ui->leftDoorStateValue->setText("CLOSED");
    } else{
        ui->leftDoorStateValue->setText("OPEN");
    }
}


void TrainModelUI::on_pushButton_2_clicked()
{
    ui->currentModeValue->setText("SIGNAL PICKUP FAILURE");
    int i = 1;
    emit failureState(i);
}


void TrainModelUI::on_pushButton_4_clicked()
{
    ui->currentModeValue->setText("TRAIN ENGINE FAILURE");
    int i = 3;
    emit failureState(i);
}

void TrainModelUI::updateUI(){
    ui->currentSpeedValue->setText(QString::number(train.calculateVelocity()));
    ui->currentAccelerationValue->setText(QString::number(train.currentAcc));
    ui->currentPowerValue->setText(QString::number(train.currentPower));
    //train.lastTime = train.currentTime;
    //train.currentTime = train.clockTime;
}


void TrainModelUI::CurrentSpeedDifferent(int power){
    train.setPower(power);
    int speed = train.calculateVelocity();
    emit currSpeedTC(speed);
}

void TrainModelUI::boardingPassengersFromTM(int numPassengers){
   int newtotal = train.calcCapacity(numPassengers);
    ui->passengersOnTrainValue->setText(QString::number(newtotal));
}
void TrainModelUI::trackSignalFromTM(int meters, int grade, int limit, int comm){
    emit speedLimitTC(limit);
    emit commandedSpeedTC(comm);


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
    ui->currentModeValue->setText("Service Brake Pulled");
    train.serviceBrake = true;

}


void TrainModelUI::on_standardModeButton_clicked()
{
    ui->currentModeValue->setText("Standard");
    train.currentMode = 0;
    train.resetValues();
}


void TrainModelUI::on_pushButton_5_clicked()
{
    int i = 1;
}

void TrainModelUI::TempChanged(int temp)
{
    ui->currentTempValue->setText(QString::number(temp));
}

void TrainModelUI::LeftDoorsChanged(bool state)
{
    if(state)
    {
        ui->leftDoorStateValue->setText("Open");
    }
    else
    {
        ui->leftDoorStateValue->setText("Closed");
    }
}

void TrainModelUI::RightDoorsChanged(bool state)
{
    if(state)
    {
        ui->rightDoorStateValue->setText("Open");
    }
    else
    {
        ui->rightDoorStateValue->setText("Closed");
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
    train.setPower(power);
    updateUI();
}

void TrainModelUI::on_pushme_clicked()
{
    int i = 0;
}

