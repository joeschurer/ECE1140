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
    void ReadBeacon(int id, string Station, int DoorSide);
    void ReadTrackSignal(int id, int SpeedLimit, int CSpeed, int authority);
    void EngageBrake();
    void ArrivedAtStation();

public slots:
    void DestinationChanged(int id, std::string destination);
    void DistanceChanged(std::string distance);
    void TimeChanged(std::string time);
    void SpeedLimitChanged(int id, int speed);
    void CommandedSpeedChanged(int id, int speed);
    void CurrentSpeedChanged(int id, int speed);
    void EmergencyBrakeChanged(int id, bool state);
    void FailureChanged(int id, int mode);

signals:
    void SetSpeedDifferent(int id, int speed);
    void LightsDifferent(int id, bool state);
    void LeftDoorsDifferent(int id, bool state);
    void RightDoorsDifferent(int id, bool state);
    void TempDifferent(int id, int temp);
    void EmergencyBrakeDifferent(int id, bool state);
    void ServiceBrakeDifferent(int id, bool state);
    void AutomaticModeDifferent(int id, bool state);
    void PowerCalculated(int id, int power);

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
