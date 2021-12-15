#include "swtccreator.h"
#include "swtcui.h"
#include "ui_swtcui.h"
#include <vector>

SWTCCreator::SWTCCreator()
{

}

void SWTCCreator::DispatchTrain(int ID, int CommandedSpeed)
{
    //Receive info about new train to dispatch
    SWTCCalculations train;
    MakeTrain(train, ID, CommandedSpeed);
}

void SWTCCreator::MakeTrain(SWTCCalculations train, int ID, int CommandedSpeedForTrain)
{
    //Create a new UI and specify ID and Commanded Speed
    SWTCUI* NewTrain = new SWTCUI();
    AllTrains.push_back(NewTrain);
    NewTrain->train = train;
    NewTrain->train.id = ID;
    NewTrain->train.CommandedSpeed = CommandedSpeedForTrain;
    NewTrain->show();
}
