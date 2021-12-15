#ifndef TRAINMODELUI_H
#define TRAINMODELUI_H
#include <vector>
#include <QWidget>
#include "traincalculate.h"
using namespace std;
QT_BEGIN_NAMESPACE
namespace Ui { class TrainModelUI; }
QT_END_NAMESPACE

class TrainModelUI : public QWidget
{
    Q_OBJECT

public:
    TrainModelUI(QWidget *parent = nullptr);
    ~TrainModelUI();
    trainCalculate calcs;
    double covered;
    double blockLength;
    void updateUI();
    void setUI();
    void setLength();
    void setWeight();
    //void getPower(int);
    void getVelocity(float);
    void getAcceleration(float);
    void getBlock();
    void getLightState(bool);
    void getLeftDoorState(bool);
    void boardingPassengersFromTM(int numPassengers);

    void getRightDoorState(bool);
    void getMode(int);
    void getPassengers(int);
    void getTemp(int);
    void selectTrain(int);
    void updateALL();
    void stationValues(string, string);
    void calcTemp();
    void setHeight();
    void setWidth();
    void dormammu(); //the time slot
    void trackSignal(int, int, int, int, int, int, int);

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

    void on_inputTempConfirm_clicked();

    void on_passengersConfirm_clicked();

    void on_stationMetersButton_clicked();

    void on_moveNextBlock_clicked();

private:
    Ui::TrainModelUI *ui;


public slots:
    //void updateUI();
    //void dormammu(); //the time slot
    void LightsChanged(bool state);
    void LeftDoorsChanged(bool state);
    void RightDoorsChanged(bool state);
    void TempChanged(int temp);

    void PowerChanged(int power);

    //TC slots

    void CurrentSpeedDifferent(int power); //receive power, call setPower
//    void EmergencyBrakeDifferent(std::string state); //receive
//    void FailureDifferent(std::string state);

//    //TM slots


    void outsideTemperature(int tt);
    void internalTemperature(int sett);


    //length of blokc
    //grade
    //speedlimit
    //commanded speed
    //passengers
signals:
    //to train controller
    void currSpeedTC(int id,int);
    void eBrakeSetTC(int id,bool state);
    void failureState(int id, int mode);
    void trackSignalTC(int id, int speedLimit, int cSpeed, int auth);

    //to track model
    void currSpeedTM(QString currSpeed);
    void offPassengers(vector<int>);
    void moveBlock(int);

};
#endif // TRAINMODELUI_H
