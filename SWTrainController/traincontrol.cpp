#include "traincontrol.h"
#include <QString>

traincontrol::traincontrol()
{

}

void traincontrol::CurrentSpeedChanged(int speed)
{
    CurrentSpeed = speed;
}

void traincontrol::EmergencyBrakeChanged(bool state)
{

    if(state)
    {
        EmergencyBrakeState = true;
    }
    else
    {
        EmergencyBrakeState = false;
    }
}

void traincontrol::DestinationChanged(std::string destination)
{
    Destination = destination;
}

int traincontrol::getCurrentSpeed()
{
    return CurrentSpeed;
}

bool traincontrol::getEmergencyBrakeState()
{
    return EmergencyBrakeState;
}

std::string traincontrol::getDestination()
{
    return Destination;
}
