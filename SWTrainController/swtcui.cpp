#include "swtcui.h"
#include "ui_swtcui.h"
#include <vector>
#include <QApplication>

SWTCUI::SWTCUI(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SWTCUI)
{
    ui->setupUi(this);

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
    ui->TimeDistanceBox->setText(QString::fromStdString("30 Seconds and 0.15mi"));

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
    emit PowerCalculated(train.Power);
    emit SetSpeedDifferent(train.SetSpeed);
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
    emit PowerCalculated(train.Power);
    emit SetSpeedDifferent(train.SetSpeed);
}

void SWTCUI::PlusTempPressed() {
    //Change current temperature
    ++train.CurrentTemp;
    ui->SetTempBox->setText(QString::number(train.CurrentTemp, 'g', 3));
    emit TempDifferent(train.SetTemp);
}

void SWTCUI::MinusTempPressed() {
    //Change current temperature
    --train.CurrentTemp;
    ui->SetTempBox->setText(QString::number(train.CurrentTemp, 'g', 3));
    emit TempDifferent(train.SetTemp);
}

void SWTCUI::BrakePressed() {
    //Set speed, brake state, and power appropriately
    train.SetSpeed = 0;
    train.BrakeState = true;
    train.Power = 0;
    train.Ukminus1 = 0;
    ui->SetSpeedBox->setText(QString::number(train.SetSpeed, 'g', 3));
    emit SetSpeedDifferent(train.SetSpeed);
    emit PowerCalculated(train.Power);
    emit ServiceBrakeDifferent(train.BrakeState);
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
    emit LeftDoorsDifferent(train.LeftDoorsOpen);

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
    emit RightDoorsDifferent(train.RightDoorsOpen);
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
    emit LightsDifferent(train.LightsOn);
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
        emit SetSpeedDifferent(train.SetSpeed);
        train.CalculatePower();
    }
    ui->CurrentSpeedBox->setText(QString::number(train.SetSpeed));
    emit AutomaticModeDifferent(train.AutomaticModeState);
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
        emit SetSpeedDifferent(train.SetSpeed);
        emit PowerCalculated(train.Power);
    }
    ui->SetSpeedBox->setText(QString::number(train.SetSpeed, 'g', 3));
    emit EmergencyBrakeDifferent(train.EmergencyBrakeState);
}

void SWTCUI::DestinationChanged(std::string destination)
{
    ui->StationDisplay->setText(QString::fromStdString(destination));
}

void SWTCUI::DistanceChanged(std::string distance)
{
    ui->TimeDistanceBox->setText(QString::fromStdString(distance));
}

void SWTCUI::TimeChanged(std::string time)
{
    ui->ClockDisplay->setText(QString::fromStdString(time));
}

void SWTCUI::SpeedLimitChanged(int speed)
{
    ui->SpeedLimitBox->setText(QString::number(speed));
    train.SpeedLimit = speed;
}

void SWTCUI::CommandedSpeedChanged(int speed)
{
    ui->CommandedSpeedBox->setText(QString::number(speed));
    train.CommandedSpeed = speed;
}

void SWTCUI::CurrentSpeedChanged(int speed)
{
    ui->CurrentSpeedBox->setText(QString::number(speed));
    train.CurrentSpeed = speed;
    train.CalculatePower();
}

void SWTCUI::EmergencyBrakeChanged(std::string state)
{
    ui->EBrakeBox->setText(QString::fromStdString(state));
}

void SWTCUI::FailureChanged(std::string state)
{
    ui->FailureBox->setText(QString::fromStdString(state));
}

void SWTCUI::ReadBeacon(vector<string> data)
{
    string IDstring = data[0];
    int ID = stoi(IDstring);
    string StationName = data[1];
    string DoorSide = data[2];
    if(train.id == ID)
    {
        train.Destination = StationName;
        DestinationChanged(StationName);
        EngageBrake();
        ArrivedAtStation();
    }
}

void SWTCUI::ReadTrackSignal(int id, int SpeedLimit, int CSpeed)
{
    if(train.id == id)
    {
        train.SpeedLimit = SpeedLimit;
        train.CommandedSpeed = CSpeed;
        SpeedLimitChanged(SpeedLimit);
        CommandedSpeedChanged(CSpeed);
    }
}

void SWTCUI::EngageBrake()
{
    train.BrakeState = true;
}

void SWTCUI::ArrivedAtStation()
{

}



