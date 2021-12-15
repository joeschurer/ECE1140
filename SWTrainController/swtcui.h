#ifndef SWTCUI_H
#define SWTCUI_H

#include <QWidget>
#include <vector>
#include "swtccalculations.h"

using namespace std;

namespace Ui {
class SWTCUI;
}

class SWTCUI : public QWidget
{
    Q_OBJECT

public:
    SWTCUI(QWidget *parent = nullptr);
    ~SWTCUI();
    SWTCCalculations train;
    void DispatchTrain(vector<int> traindata);
    void ReadBeacon(int id, string Station, int DoorSide);
    void ReadTrackSignal(int id, int SpeedLimit, int CSpeed, int authority);
    void EngageBrake();
    void ArrivedAtStation();

public slots:
    void DestinationChanged(std::string destination);
    void DistanceChanged(std::string distance);
    void TimeChanged(std::string time);
    void SpeedLimitChanged(int speed);
    void CommandedSpeedChanged(int speed);
    void CurrentSpeedChanged(int speed);
    void EmergencyBrakeChanged(std::string state);
    void FailureChanged(std::string state);

signals:
    void SetSpeedDifferent(int speed);
    void LightsDifferent(bool state);
    void LeftDoorsDifferent(bool state);
    void RightDoorsDifferent(bool state);
    void TempDifferent(int temp);
    void EmergencyBrakeDifferent(bool state);
    void ServiceBrakeDifferent(bool state);
    void AutomaticModeDifferent(bool state);
    void PowerCalculated(int power);

private:
    Ui::SWTCUI *ui;

private slots:
    void PlusSpeedPressed();
    void MinusSpeedPressed();
    void PlusTempPressed();
    void MinusTempPressed();
    void OperateRightDoorsPressed();
    void OperateLeftDoorsPressed();
    void LightsButtonPressed();
    void AutomaticModeButtonPressed();
    void BrakePressed();
    void EBrakePressed();
};

#endif // SWTCUI_H
