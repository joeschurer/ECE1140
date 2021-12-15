#include "swtccreator.h"
#include "ui_swtccreator.h"

SWTCCreator::SWTCCreator(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::SWTCCreator)
{
    ui->setupUi(this);
}

SWTCCreator::~SWTCCreator()
{
    delete ui;
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
