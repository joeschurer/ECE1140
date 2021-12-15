#include "swtccalculations.h"
#include <QApplication>

SWTCCalculations::SWTCCalculations()
{

}

void SWTCCalculations::CalculatePower()
{
    //This calculation was taken from the slides in Lecture 2
    //I convert the Set Speed and Current Speed to KPH for consistency
    SpeedPower = SetSpeed * 1.60934;
    CurrentKPH = CurrentSpeed * 1.60934;

    //Below is the formula from the slides
    Ek = SpeedPower - CurrentKPH;
    Uk = Ukminus1 + ((T/2) * (Ek + Ekminus1));
    Ekminus1 = Ek;
    Ukminus1 = Uk;

    Power = (KpValue*Ek) + (KiValue*Uk);

    CheckStationArrival();

    //The power cannot exceed 120KW
    if(Power > 120000)
    {
        Power = 120000;
        Ukminus1 = Power;
    }

    //Power cannot go below 0
    if(Power < 0)
    {
        Power = 0;
        Ukminus1 = Power;
    }

    //If authority is 0 then the train must stop
    if(Authority == 0)
    {
        Power = 0;
        Ukminus1 = Power;
    }
}

void SWTCCalculations::KpKiChanged(double Kp, double Ki)
{
    //Setting Kp and Ki values from Engineer
    KpValue = Kp;
    KiValue = Ki;
}

void SWTCCalculations::CheckStationArrival()
{
    //Check to see if you are approaching a station and the train is completely stopped
    //Open the correct doors depending on the beacon data
    if(CurrentSpeed == 0 && StopAtStation == true)
    {
        if(DoorToOpen == 1)
        {
            LeftDoorsOpen = true;
        }
        else if(DoorToOpen == 2)
        {
            RightDoorsOpen = true;
        }
        else if(DoorToOpen == 3)
        {
            RightDoorsOpen = true;
            LeftDoorsOpen = true;
        }
        StopAtStation = false;
    }

    //Keep doors closed until train is stopped
    if(CurrentSpeed != 0)
    {
        RightDoorsOpen = false;
        LeftDoorsOpen = false;
    }
}



