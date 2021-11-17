#include "testui.h"
#include "ui_testui.h"
#include <sstream>
#include <string>


TestUI::TestUI(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::TestUI)
{
    ui->setupUi(this);


}

TestUI::~TestUI()
{
    delete ui;
}

void TestUI::SetSpeedChanged(int SetSpeed)
{
    ui->SetSpeedBox->setText(QString::number(SetSpeed));
}

void TestUI::LightsChanged(bool state)
{
    if(state)
    {
        ui->LightsBox->setText("On");
    }
    else
    {
        ui->LightsBox->setText("Off");
    }
}

void TestUI::LeftDoorsChanged(bool state)
{
    if(state)
    {
        ui->LeftDoorsBox->setText("Open");
    }
    else
    {
        ui->LeftDoorsBox->setText("Closed");
    }
}

void TestUI::RightDoorsChanged(bool state)
{
    if(state)
    {
        ui->RightDoorsBox->setText("Open");
    }
    else
    {
        ui->RightDoorsBox->setText("Closed");
    }
}

void TestUI::TempChanged(int temp)
{
    ui->TempBox->setText(QString::number(temp));
}

void TestUI::EmergencyBrakeChanged(bool state)
{
    if(state)
    {
        ui->EBrakeOutBox->setText(QString::fromStdString("On"));
    }
    else
    {
        ui->EBrakeOutBox->setText(QString::fromStdString("Off"));
    }
}

void TestUI::AutomaticModeChanged(bool state)
{
    if(state)
    {
        ui->AutomaticModeBox->setText(QString::fromStdString("On"));
    }
    else
    {
        ui->AutomaticModeBox->setText(QString::fromStdString("Off"));
    }
}

void TestUI::PowerChanged(double power)
{
    Power = power;
    ui->PowerBox->setText(QString::number(Power));
}

void TestUI::on_DestinationBox_textChanged(const QString &arg1)
{

    std::string Destination = arg1.toUtf8().constData();
    emit DestinationDifferent(Destination);
}


void TestUI::on_DistanceBox_textChanged(const QString &arg1)
{
    std::string Distance = arg1.toUtf8().constData();
    emit DistanceDifferent(Distance);
}


void TestUI::on_TimeBox_textChanged(const QString &arg1)
{
    std::string Time = arg1.toUtf8().constData();
    emit TimeDifferent(Time);
}


void TestUI::on_SpeedLimitBox_textChanged(const QString &arg1)
{
    std::string SpeedString = arg1.toUtf8().constData();
    int SpeedInt = 0;
    SpeedInt = stoi(SpeedString);
    emit SpeedLimitDifferent(SpeedInt);
}

void TestUI::on_SuggestedSpeedBox_textChanged(const QString &arg1)
{
    std::string SpeedString = arg1.toUtf8().constData();
    int SpeedInt = 0;
    SpeedInt = stoi(SpeedString);
    emit CommandedSpeedDifferent(SpeedInt);
}

void TestUI::on_EBrakeInBox_textChanged(const QString &arg1)
{
    std::string State = arg1.toUtf8().constData();
    emit EmergencyBrakeDifferent(State);
}


void TestUI::on_FailureBox_textChanged(const QString &arg1)
{
    std::string State = arg1.toUtf8().constData();
    emit FailureDifferent(State);
}


void TestUI::on_CurrentSpeedBox_returnPressed()
{
    QString Speed = ui->CurrentSpeedBox->text();
    int SpeedInt = Speed.toInt();
    emit CurrentSpeedDifferent(SpeedInt);
}

