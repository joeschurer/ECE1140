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
    void updateUI();
    void setUI();
    void setTrain(trainCalculate);
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

private slots:
    void on_toggleDoor_clicked();

    void on_toggleLights_clicked();

    void on_inputPowerConfirm_clicked();

    void on_emergencyBrake_clicked();

    void on_pushButton_3_clicked();

    void on_toggleDoorRight_clicked();

    void on_toggleDoorLeft_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::TrainModelUI *ui;


public slots:
    void receivePower(int power);
signals:
    //to train controller
    void currSpeedTC(int currSpeed);
    void speedLimitTC(int speedL);
    void commandedSpeedTC(int cSpeed);
    void distLeftTC(int dist);
    void eBrakeSetTC(bool state);
    void failureState(int mode);

    //to track model
    void currSpeed(int currSpeed);
};
#endif // TRAINMODELUI_H
