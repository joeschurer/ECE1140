#include "swtcui.h"
#include "ui_swtcui.h"

SWTCUI::SWTCUI(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SWTCUI)
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

void SWTCUI::MinusSpeedPressed() {
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

void SWTCUI::PlusTempPressed() {
    int newTemp = ++CurrentTemp;
    ui->CurrentTempBox->setText(QString::number(newTemp, 'g', 3));
    emit TempDifferent(newTemp);
}

void SWTCUI::MinusTempPressed() {
    int newTemp = --CurrentTemp;
    ui->CurrentTempBox->setText(QString::number(newTemp, 'g', 3));
    emit TempDifferent(newTemp);
}

void SWTCUI::BrakePressed() {
    int newSpeed = 0;
    SetSpeed = 0;
    BrakeState = true;
    Power = 0;
    ui->SetSpeedBox->setText(QString::number(newSpeed, 'g', 3));
    CalculatePower();
    emit SetSpeedDifferent(SetSpeed);
}

void SWTCUI::OperateLeftDoorsPressed() {
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

void SWTCUI::OperateRightDoorsPressed() {
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

void SWTCUI::LightsButtonPressed() {
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

void SWTCUI::AutomaticModeButtonPressed() {
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

void SWTCUI::EBrakePressed() {
    int newSpeed = 0;
    SetSpeed = 0;
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
    emit SetSpeedDifferent(SetSpeed);
    CalculatePower();
}

void SWTCUI::DestinationChanged(std::string destination)
{
    ui->DestinationDisplay->setText(QString::fromStdString(destination));
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
    SpeedLimit = speed;
}

void SWTCUI::CommandedSpeedChanged(int speed)
{
    ui->CommandedSpeedBox->setText(QString::number(speed));
    CommandedSpeed = speed;
}

void SWTCUI::CurrentSpeedChanged(int speed)
{
    ui->CurrentSpeedBox->setText(QString::number(speed));
    CurrentSpeed = speed;
    CalculatePower();
}

void SWTCUI::EmergencyBrakeChanged(std::string state)
{
    ui->EBrakeBox->setText(QString::fromStdString(state));
}

void SWTCUI::FailureChanged(std::string state)
{
    ui->FailureBox->setText(QString::fromStdString(state));
}

void SWTCUI::KpKiChanged(double Kp, double Ki)
{
    KpValue = Kp;
    KiValue = Ki;
}

void SWTCUI::CalculatePower()
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

    if(Power < 0)
    {
        Power = 0;
        Ukminus1 = Power;
    }

    emit PowerCalculated(Power);
}

