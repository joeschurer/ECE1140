#ifndef SWTCCALCULATIONS_H
#define SWTCCALCULATIONS_H
#include <vector>
#include <cstdlib>
#include <iostream>
#include <QWidget>
#include <QApplication>

using namespace std;

class SWTCCalculations
{

public:
    SWTCCalculations();
    void CalculatePower();
    int SetSpeed = 0;
    int CurrentSpeed = 0;
    int SpeedLimit = 0;
    int CommandedSpeed = 0;
    double SpeedPower;
    double CurrentKPH;
    int SetTemp = 70;
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
    int id;
    int Authority;

public slots:
    void KpKiChanged(double Kp, double Ki);

signals:
    void PowerCalculation(int power);

};

#endif // SWTCCALCULATIONS_H
