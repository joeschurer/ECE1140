#ifndef SWTCCREATOR_H
#define SWTCCREATOR_H

#include "swtccalculations.h"
#include "swtcui.h"


class SWTCCreator
{
public:
    SWTCCreator();
    void MakeTrain(SWTCCalculations train, int ID, int CommandedSpeedForTrain);
    vector<SWTCUI*> AllTrains;

public slots:
    void DispatchTrain(int ID, int CommandedSpeed);  

};

#endif // SWTCCREATOR_H
