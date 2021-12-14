#ifndef TRAINMODELUI_H
#define TRAINMODELUI_H

#include <QWidget>
#include "traincalculate.h"
QT_BEGIN_NAMESPACE
namespace Ui { class TrainModelUI; }
QT_END_NAMESPACE

class TrainModelUI : public QWidget
{
    Q_OBJECT

public:
    TrainModelUI(QWidget *parent = nullptr);
    ~TrainModelUI();
    void makeTrain(trainCalculate);
    void updateUI();
    void setUI();
    void setLength(double);
    void setMass(double);
    void getPower(int);
    void getVelocity(float);
    void getAcceleration(float);
    void getBlock();
    void getLightState(bool);
    void getLeftDoorState(bool);
    void getRightDoorState(bool);
    void getMode(int);
    void getPassengers(int);
    void getTemp(int);
    void selectTrain(int);
    void updateALL();
    trainCalculate train;

private slots:
    void on_toggleLights_clicked();
    void on_inputPowerConfirm_clicked();
    void on_emergencyBrake_clicked();
    void on_pushButton_3_clicked();
    void on_toggleDoorRight_clicked();
    void on_toggleDoorLeft_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_clicked();
    void on_serviceBrakeButton_clicked();
    void on_standardModeButton_clicked();
    void on_pushButton_5_clicked();

private:
    Ui::TrainModelUI *ui;

public slots:
    //TC slots
    void receivePower(int power);
    void DestinationDifferent(std::string destination);
    void DistanceDifferent(std::string distance); //the size of the block
    void TimeDifferent(std::string time); //take in current time?
    void SpeedLimitDifferent(int speed); //tkae in speed limit, emit it to TC
    void CommandedSpeedDifferent(int speed); //take in commanded speed, emit to TC
    void CurrentSpeedDifferent(int power); //receive power, call setPower
    void FailureDifferent(std::string state);

    //Jake put these in
    void LightsChanged(bool state);
    void LeftDoorsChanged(bool state);
    void RightDoorsChanged(bool state);
    void TempChanged(int temp);
    void PowerChanged(int power);
    void EmergencyBrakeChanged(bool state);
    //End of Jakes slots

    //TM slots
    void boardingPassengersFromTM(int numPassengers);
    void trackSignalFromTM(int meters, int grade, int limit, int comm);

    //length of blokc
    //grade
    //speedlimit
    //commanded speed
    //passengers
signals:
    //to train controller
    void currSpeedTC(int);
    void speedLimitTC(int speedL);
    void commandedSpeedTC(int cSpeed);
    void distLeftTC(int dist);
    void eBrakeSetTC(bool state);
    void failureState(int mode);

    //to track model
    void currSpeed(int currSpeed);
    void currentPassengers(int passengers);
};
#endif // TRAINMODELUI_H