#include "swtraincontrollerui.h"
#include "ui_swtraincontrollerui.h"

SWTrainControllerUI::SWTrainControllerUI(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::SWTrainControllerUI)
{
    ui->setupUi(this);

    ui->SetSpeedBox->setText(QString::number(SetSpeed));
    ui->CurrentSpeedBox->setText(QString::number(CurrentSpeed));
    ui->SpeedLimitBox->setText(QString::number(SpeedLimit));
    ui->CommandedSpeedBox->setText(QString::number(CommandedSpeed));
    ui->CurrentTempBox->setText(QString::number(CurrentTemp));
    ui->DestinationDisplay->setText(QString::fromStdString(Destination));
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
                numButtons[i] = SWTrainControllerUI::findChild<QPushButton *>("PlusSpeedButton");
                connect(numButtons[i], SIGNAL(released()), this, SLOT(PlusSpeedPressed()));
                break;
            case 1:
                numButtons[i] = SWTrainControllerUI::findChild<QPushButton *>("MinusSpeedButton");
                connect(numButtons[i], SIGNAL(released()), this, SLOT(MinusSpeedPressed()));
                break;
            case 2:
                numButtons[i] = SWTrainControllerUI::findChild<QPushButton *>("BrakeButton");
                connect(numButtons[i], SIGNAL(released()), this, SLOT(BrakePressed()));
                break;
            case 3:
                numButtons[i] = SWTrainControllerUI::findChild<QPushButton *>("MinusACButton");
                connect(numButtons[i], SIGNAL(released()), this, SLOT(MinusTempPressed()));
                break;
            case 4:
                numButtons[i] = SWTrainControllerUI::findChild<QPushButton *>("PlusACButton");
                connect(numButtons[i], SIGNAL(released()), this, SLOT(PlusTempPressed()));
                break;
            case 5:
                numButtons[i] = SWTrainControllerUI::findChild<QPushButton *>("OperateLeftDoorsButton");
                connect(numButtons[i], SIGNAL(released()), this, SLOT(OperateLeftDoorsPressed()));
                break;
            case 6:
                numButtons[i] = SWTrainControllerUI::findChild<QPushButton *>("OperateRightDoorsButton");
                connect(numButtons[i], SIGNAL(released()), this, SLOT(OperateRightDoorsPressed()));
                break;
            case 7:
                numButtons[i] = SWTrainControllerUI::findChild<QPushButton *>("OperateLightsButton");
                connect(numButtons[i], SIGNAL(released()), this, SLOT(LightsButtonPressed()));
                break;
            case 8:
                numButtons[i] = SWTrainControllerUI::findChild<QPushButton *>("AutomaticModeButton");
                connect(numButtons[i], SIGNAL(released()), this, SLOT(AutomaticModeButtonPressed()));
                break;
            case 9:
                numButtons[i] = SWTrainControllerUI::findChild<QPushButton *>("EBrakeButton");
                connect(numButtons[i], SIGNAL(released()), this, SLOT(EBrakePressed()));
                break;
        }
    }
}

SWTrainControllerUI::~SWTrainControllerUI()
{
    delete ui;
}


void SWTrainControllerUI::PlusSpeedPressed() {
    int newSpeed = ++SetSpeed;
    if(SetSpeed > 43)
    {
        SetSpeed = 43;
        newSpeed = 43;
    }
    ui->SetSpeedBox->setText(QString::number(newSpeed, 'g', 3));
    CalculatePower();
    emit SetSpeedDifferent(SetSpeed);
}

void SWTrainControllerUI::MinusSpeedPressed() {
    int newSpeed = --SetSpeed;
    if(SetSpeed <= 0)
    {
        newSpeed = 0;
        SetSpeed = 0;
        ui->SetSpeedBox->setText(QString::number(newSpeed, 'g', 3));
    }
    else
    {
        ui->SetSpeedBox->setText(QString::number(newSpeed, 'g', 3));
    }
    CalculatePower();
    emit SetSpeedDifferent(SetSpeed);
}

void SWTrainControllerUI::PlusTempPressed() {
    int newTemp = ++CurrentTemp;
    ui->CurrentTempBox->setText(QString::number(newTemp, 'g', 3));
    emit TempDifferent(newTemp);
}

void SWTrainControllerUI::MinusTempPressed() {
    int newTemp = --CurrentTemp;
    ui->CurrentTempBox->setText(QString::number(newTemp, 'g', 3));
    emit TempDifferent(newTemp);
}

void SWTrainControllerUI::BrakePressed() {
    int newSpeed = 0;
    CurrentSpeed = 0;
    BrakeState = true;
    Power = 0;
    ui->SetSpeedBox->setText(QString::number(newSpeed, 'g', 3));
    emit SetSpeedDifferent(CurrentSpeed);
}

void SWTrainControllerUI::OperateLeftDoorsPressed() {
    if(LeftDoorsOpen)
    {
        LeftDoorsOpen = false;
    }
    else
    {
        LeftDoorsOpen = true;
    }
    emit LeftDoorsDifferent(LeftDoorsOpen);

}

void SWTrainControllerUI::OperateRightDoorsPressed() {
    if(RightDoorsOpen)
    {
        RightDoorsOpen = false;
    }
    else
    {
        RightDoorsOpen = true;
    }
    emit RightDoorsDifferent(RightDoorsOpen);
}

void SWTrainControllerUI::LightsButtonPressed() {
    if(LightsOn)
    {
        LightsOn = false;
    }
    else
    {
        LightsOn = true;
    }
    emit LightsDifferent(LightsOn);
}

void SWTrainControllerUI::AutomaticModeButtonPressed() {
    if(AutomaticModeState)
    {
        AutomaticModeState = false;
    }
    else
    {
        AutomaticModeState = true;
        SetSpeed = CommandedSpeed;
    }
    emit SetSpeedDifferent(SetSpeed);
    emit AutomaticModeDifferent(AutomaticModeState);
}

void SWTrainControllerUI::EBrakePressed() {
    int newSpeed = 0;
    CurrentSpeed = 0;
    if(EmergencyBrakeState)
    {
        EmergencyBrakeState = false;
        ui->EBrakeBox->setText(QString::fromStdString("Off"));
    }
    else
    {
        EmergencyBrakeState = true;
        ui->EBrakeBox->setText(QString::fromStdString("On"));
    }
    ui->SetSpeedBox->setText(QString::number(newSpeed, 'g', 3));
    emit EmergencyBrakeDifferent(EmergencyBrakeState);
    emit SetSpeedDifferent(CurrentSpeed);
}

void SWTrainControllerUI::DestinationChanged(std::string destination)
{
    ui->DestinationDisplay->setText(QString::fromStdString(destination));
}

void SWTrainControllerUI::DistanceChanged(std::string distance)
{
    ui->TimeDistanceBox->setText(QString::fromStdString(distance));
}

void SWTrainControllerUI::TimeChanged(std::string time)
{
    ui->ClockDisplay->setText(QString::fromStdString(time));
}

void SWTrainControllerUI::SpeedLimitChanged(int speed)
{
    ui->SpeedLimitBox->setText(QString::number(speed));
    SpeedLimit = speed;
}

void SWTrainControllerUI::CommandedSpeedChanged(int speed)
{
    ui->CommandedSpeedBox->setText(QString::number(speed));
    CommandedSpeed = speed;
}

void SWTrainControllerUI::CurrentSpeedChanged(int speed)
{
    ui->CurrentSpeedBox->setText(QString::number(speed));
    CurrentSpeed = speed;
    CalculatePower();
}

void SWTrainControllerUI::EmergencyBrakeChanged(std::string state)
{
    ui->EBrakeBox->setText(QString::fromStdString(state));
}

void SWTrainControllerUI::KpKiChanged(int Kp, int Ki)
{
    KpValue = Kp;
    KiValue = Ki;
}

void SWTrainControllerUI::CalculatePower()
{
    SpeedPower = SetSpeed * 1.60934;
    CurrentKPH = CurrentSpeed * 1.60934;

    Ek = SpeedPower - CurrentKPH;
    Uk = Ukminus1 + ((T/2) * (Ek + Ekminus1));
    Ekminus1 = Ek;
    Ukminus1 = Uk;

    Power = (KpValue*Ek) + (KiValue*Uk);

    if(Power > 120000)
    {
        Power = 120000;
        Ukminus1 = Power;
    }
    emit PowerCalculated(Power);
}




