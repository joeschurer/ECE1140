#include "trainmodelui.h"
#include "ui_trainmodelui.h"
#include "traincalculate.h"
TrainModelUI::TrainModelUI(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::TrainModelUI)
{
    ui->setupUi(this);
}

TrainModelUI::~TrainModelUI()
{
    delete ui;
}


void TrainModelUI::setLength(double length){
    ui->trainLengthValue->setText(QString::number(length));

}

void TrainModelUI::setMass(double weight){
    ui->trainWeightV->setText(QString::number(weight));
}


void TrainModelUI::getPower(int power){
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
int getPassengers();
float getTemp();
int selectTrain();



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


}





void TrainModelUI::on_emergencyBrake_clicked()
{
    ui->currentModeValue->setText("Emergency Brake Pulled");
}


void TrainModelUI::on_pushButton_3_clicked()
{
    ui->currentModeValue->setText("POWER FAILURE");
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
}


void TrainModelUI::on_pushButton_4_clicked()
{
    ui->currentModeValue->setText("TRAIN ENGINE FAILURE");
}

