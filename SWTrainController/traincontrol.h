#ifndef TRAINCONTROL_H
#define TRAINCONTROL_H

#include <string>


class traincontrol
{

private:

public:
    int getCurrentSpeed();
    bool getEmergencyBrakeState();
    std::string getDestination();
    void CurrentSpeedChanged(int speed);
    void EmergencyBrakeChanged(bool state);
    void DestinationChanged(std::string destination);
    traincontrol();
    int SetSpeed;
    int CurrentSpeed;
    int SpeedLimit;
    int CommandedSpeed;
    double SpeedPower;
    double CurrentKPH;
    int CurrentTemp;
    bool LeftDoorsOpen;
    bool RightDoorsOpen;
    bool LightsOn;
    bool EmergencyBrakeState = false;
    bool BrakeState;
    bool AutomaticModeState;
    std::string Destination;
    double Power;
    double KpValue;
    double KiValue;
    double Uk;
    double Ukminus1 = 0;
    double T = 1;
    double Ek;
    double Ekminus1 = 0;
};

#endif // TRAINCONTROL_H
