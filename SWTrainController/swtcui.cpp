#include "swtcui.h"
#include "ui_swtcui.h"
#include <vector>
#include <QApplication>

SWTCUI::SWTCUI(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SWTCUI)
{
    ui->setupUi(this);

    //Set the initial text when the UI first comes up
    ui->SetSpeedBox->setText(QString::number(train.SetSpeed));
    ui->CurrentSpeedBox->setText(QString::number(train.CurrentSpeed));
    ui->SpeedLimitBox->setText(QString::number(train.SpeedLimit));
    ui->CommandedSpeedBox->setText(QString::number(train.CommandedSpeed));
    ui->CurrentTempValue->setText(QString::number(train.CurrentTemp));
    ui->SetTempBox->setText(QString::number(train.SetTemp));
    ui->StationDisplay->setText(QString::fromStdString(train.Destination));
    ui->ClockDisplay->setText(QString::fromStdString("12:00"));
    ui->EBrakeBox->setText(QString::fromStdString("Off"));
    ui->FailureBox->setText(QString::fromStdString("None"));
    //ui->TimeDistanceBox->setText(QString::fromStdString("30 Seconds and 0.15mi"));

    //This connects all of the buttons to each corresponding function
    QPushButton *numButtons[10];
    for(int i = 0; i < 10; i++)
    {
        switch (i)
        {
            case 0:
                numButtons[i] = SWTCUI::findChild<QPushButton *>("PlusSpeedButton");
                connect(numButtons[i], SIGNAL(released()), this, SLOT(PlusSpeedPressed()));
                break;
            case 1:
                numButtons[i] = SWTCUI::findChild<QPushButton *>("MinusSpeedButton");
                connect(numButtons[i], SIGNAL(released()), this, SLOT(MinusSpeedPressed()));
                break;
            case 2:
                numButtons[i] = SWTCUI::findChild<QPushButton *>("BrakeButton");
                connect(numButtons[i], SIGNAL(released()), this, SLOT(BrakePressed()));
                break;
            case 3:
                numButtons[i] = SWTCUI::findChild<QPushButton *>("MinusACButton");
                connect(numButtons[i], SIGNAL(released()), this, SLOT(MinusTempPressed()));
                break;
            case 4:
                numButtons[i] = SWTCUI::findChild<QPushButton *>("PlusACButton");
                connect(numButtons[i], SIGNAL(released()), this, SLOT(PlusTempPressed()));
                break;
            case 5:
                numButtons[i] = SWTCUI::findChild<QPushButton *>("OperateLeftDoorsButton");
                connect(numButtons[i], SIGNAL(released()), this, SLOT(OperateLeftDoorsPressed()));
                break;
            case 6:
                numButtons[i] = SWTCUI::findChild<QPushButton *>("OperateRightDoorsButton");
                connect(numButtons[i], SIGNAL(released()), this, SLOT(OperateRightDoorsPressed()));
                break;
            case 7:
                numButtons[i] = SWTCUI::findChild<QPushButton *>("OperateLightsButton");
                connect(numButtons[i], SIGNAL(released()), this, SLOT(LightsButtonPressed()));
                break;
            case 8:
                numButtons[i] = SWTCUI::findChild<QPushButton *>("AutomaticModeButton");
                connect(numButtons[i], SIGNAL(released()), this, SLOT(AutomaticModeButtonPressed()));
                break;
            case 9:
                numButtons[i] = SWTCUI::findChild<QPushButton *>("EBrakeButton");
                connect(numButtons[i], SIGNAL(released()), this, SLOT(EBrakePressed()));
                break;
        }
    }
}

SWTCUI::~SWTCUI()
{
    delete ui;
}

void SWTCUI::PlusSpeedPressed() {
    //Change set speed and make sure it does not go over 43 (Max in MPH)
    ++train.SetSpeed;
    if(train.SetSpeed > 43)
    {
        train.SetSpeed = 43;
    }
    ui->SetSpeedBox->setText(QString::number(train.SetSpeed, 'g', 3));
    //Calculate Power each time set speed is changed
    train.CalculatePower();
    emit PowerCalculated(train.id, train.Power);
    emit SetSpeedDifferent(train.id, train.SetSpeed);
}

void SWTCUI::MinusSpeedPressed() {
    //Change set speed and make sure it does not go under 0
    --train.SetSpeed;
    if(train.SetSpeed <= 0)
    {
        train.SetSpeed = 0;
        ui->SetSpeedBox->setText(QString::number(train.SetSpeed, 'g', 3));
    }
    else
    {
        ui->SetSpeedBox->setText(QString::number(train.SetSpeed, 'g', 3));
    }
    //Calculate Power each time set speed is changed
    train.CalculatePower();
    emit PowerCalculated(train.id, train.Power);
    emit SetSpeedDifferent(train.id, train.SetSpeed);
}

void SWTCUI::PlusTempPressed() {
    //Change current temperature
    ++train.CurrentTemp;
    ui->SetTempBox->setText(QString::number(train.CurrentTemp, 'g', 3));
    emit TempDifferent(train.id, train.SetTemp);
}

void SWTCUI::MinusTempPressed() {
    //Change current temperature
    --train.CurrentTemp;
    ui->SetTempBox->setText(QString::number(train.CurrentTemp, 'g', 3));
    emit TempDifferent(train.id, train.SetTemp);
}

void SWTCUI::BrakePressed() {
    //Set speed, brake state, and power appropriately
    train.SetSpeed = 0;
    train.BrakeState = true;
    train.Power = 0;
    train.Ukminus1 = 0;
    ui->SetSpeedBox->setText(QString::number(train.SetSpeed, 'g', 3));
    emit SetSpeedDifferent(train.id, train.SetSpeed);
    emit PowerCalculated(train.id, train.Power);
    emit ServiceBrakeDifferent(train.id, train.BrakeState);
}

void SWTCUI::OperateLeftDoorsPressed() {
    //Change left door state based on the current state
    if(train.LeftDoorsOpen)
    {
        train.LeftDoorsOpen = false;
    }
    else
    {
        train.LeftDoorsOpen = true;
    }
    emit LeftDoorsDifferent(train.id, train.LeftDoorsOpen);

}

void SWTCUI::OperateRightDoorsPressed() {
    //Change right door state based on the current state
    if(train.RightDoorsOpen)
    {
        train.RightDoorsOpen = false;
    }
    else
    {
        train.RightDoorsOpen = true;
    }
    emit RightDoorsDifferent(train.id, train.RightDoorsOpen);
}

void SWTCUI::LightsButtonPressed() {
    //Change light state based on the current state
    if(train.LightsOn)
    {
        train.LightsOn = false;
    }
    else
    {
        train.LightsOn = true;
    }
    emit LightsDifferent(train.id, train.LightsOn);
}

void SWTCUI::AutomaticModeButtonPressed() {
    //If current state is true then disengage automatic mode
    //If current state is false then engage automatic mode and update values accordingly
    if(train.AutomaticModeState)
    {
        train.AutomaticModeState = false;
    }
    else
    {
        train.AutomaticModeState = true;
        train.SetSpeed = train.CommandedSpeed;
        emit SetSpeedDifferent(train.id, train.SetSpeed);
        train.CalculatePower();
    }
    ui->CurrentSpeedBox->setText(QString::number(train.SetSpeed));
    emit AutomaticModeDifferent(train.id, train.AutomaticModeState);
}

void SWTCUI::EBrakePressed() {
    //If current state is true then disengage Emergency Brake and update text
    //If current state is false then engage Emergency Brake and update values accordingly
    if(train.EmergencyBrakeState)
    {
        train.EmergencyBrakeState = false;
        ui->EBrakeBox->setText(QString::fromStdString("Off"));
    }
    else
    {
        train.EmergencyBrakeState = true;
        ui->EBrakeBox->setText(QString::fromStdString("On"));
        train.SetSpeed = 0;
        train.Power = 0;
        train.Ukminus1 = 0;
        emit SetSpeedDifferent(train.id, train.SetSpeed);
        emit PowerCalculated(train.id, train.Power);
    }
    ui->SetSpeedBox->setText(QString::number(train.SetSpeed, 'g', 3));
    emit EmergencyBrakeDifferent(train.id, train.EmergencyBrakeState);
}

//Functions below are simple changing of UI elements
void SWTCUI::DestinationChanged(int id, std::string destination)
{
    //Check to make sure id is correct and update destination on ui
    if(train.id == id)
    {
        ui->StationDisplay->setText(QString::fromStdString(destination));
    }
}

/*
void SWTCUI::DistanceChanged(std::string distance)
{
    ui->TimeDistanceBox->setText(QString::fromStdString(distance));
}

void SWTCUI::TimeChanged(std::string time)
{
    ui->ClockDisplay->setText(QString::fromStdString(time));
}
*/

void SWTCUI::SpeedLimitChanged(int id, int speed)
{
    //Check to make sure id is correct and update speed limit
    if(train.id == id)
    {
        ui->SpeedLimitBox->setText(QString::number(speed));
        train.SpeedLimit = speed;
    }
}

void SWTCUI::CommandedSpeedChanged(int id, int speed)
{
    //Check to make sure id is correct and update commanded speed
    if(train.id == id)
    {
        ui->CommandedSpeedBox->setText(QString::number(speed));
        train.CommandedSpeed = speed;
    }
}

void SWTCUI::CurrentSpeedChanged(int id, int speed)
{
    //Check to make sure id is correct and update current speed and calculate new power
    if(train.id == id)
    {
        ui->CurrentSpeedBox->setText(QString::number(speed));
        train.CurrentSpeed = speed;
        train.CalculatePower();
    }
}

void SWTCUI::EmergencyBrakeChanged(int id, bool state)
{
    //Check to make sure id is correct and update Emergency Brake state and set power correctly
    if(train.id == id)
    {
        if(state)
        {
            ui->EBrakeBox->setText(QString::fromStdString("On"));
            train.EmergencyBrakeState = state;
            train.Power = 0;
            train.Ukminus1 = 0;
        }
        else
        {
            ui->EBrakeBox->setText(QString::fromStdString("Off"));
            train.EmergencyBrakeState = state;
        }
    }
}

void SWTCUI::FailureChanged(int id, int mode)
{
    //Make sure it is the correct train and then update the UI based on the current failure
    if(train.id == id)
    {
        if(mode == 0)
        {
            ui->FailureBox->setText(QString::fromStdString("None"));
        }
        else if(mode == 1)
        {
            ui->FailureBox->setText(QString::fromStdString("Signal"));

        }
        else if(mode == 2)
        {
            ui->FailureBox->setText(QString::fromStdString("Brake"));
        }
        else if(mode == 3)
        {
            ui->FailureBox->setText(QString::fromStdString("Power"));
        }
    }
}

//Read Beacon to update train
void SWTCUI::ReadBeacon(int id, string Station, int DoorSide)
{
    if(train.id == id)
    {
        train.Destination = Station;
        train.DoorToOpen = DoorSide;
        DestinationChanged(id, Station);
        BrakePressed();
        train.StopAtStation = true;
    }
}

//Read track signal, update train and ensure it goes to right train
void SWTCUI::ReadTrackSignal(int id, int SpeedLimit, int CSpeed, int authority)
{
    if(train.id == id)
    {
        train.SpeedLimit = SpeedLimit;
        train.CommandedSpeed = CSpeed;
        train.Authority = authority;
        SpeedLimitChanged(id, SpeedLimit);
        CommandedSpeedChanged(id, CSpeed);
    }
}




