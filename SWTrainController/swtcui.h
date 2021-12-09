#ifndef SWTCUI_H
#define SWTCUI_H

#include <QMainWindow>

namespace Ui {
class SWTCUI;
}

class SWTCUI : public QMainWindow
{
    Q_OBJECT

public:
    explicit SWTCUI(QWidget *parent = nullptr);
    ~SWTCUI();

public slots:
    void DestinationChanged(std::string destination);
    void DistanceChanged(std::string distance);
    void TimeChanged(std::string time);
    void SpeedLimitChanged(int speed);
    void CommandedSpeedChanged(int speed);
    void CurrentSpeedChanged(int speed);
    void EmergencyBrakeChanged(std::string state);
    void FailureChanged(std::string state);
    void KpKiChanged(double Kp, double Ki);

signals:
    void SetSpeedDifferent(int speed);
    void LightsDifferent(bool state);
    void LeftDoorsDifferent(bool state);
    void RightDoorsDifferent(bool state);
    void TempDifferent(int temp);
    void EmergencyBrakeDifferent(bool state);
    void AutomaticModeDifferent(bool state);
    void PowerCalculated(int power);

private:
    Ui::SWTCUI *ui;
    void CalculatePower();
    int SetSpeed = 0;
    int CurrentSpeed = 0;
    int SpeedLimit = 0;
    int CommandedSpeed = 0;
    double SpeedPower;
    double CurrentKPH;
    int CurrentTemp = 70;
    bool LeftDoorsOpen = false;
    bool RightDoorsOpen = false;
    bool LightsOn = false;
    bool EmergencyBrakeState = false;
    bool BrakeState = false;
    bool AutomaticModeState = false;
    std::string Destination = "Heinz Field 0.5mi";
    int Power;
    double KpValue;
    double KiValue;
    double Uk;
    double Ukminus1 = 0;
    double T = 1;
    double Ek;
    double Ekminus1 = 0;

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
