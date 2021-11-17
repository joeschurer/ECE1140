#ifndef TESTUI_H
#define TESTUI_H

#include <QMainWindow>

namespace Ui {
class TestUI;
}

class TestUI : public QMainWindow
{
    Q_OBJECT

public:
    explicit TestUI(QWidget *parent = nullptr);
    ~TestUI();

public slots:
    void SetSpeedChanged(int SetSpeed);
    void LightsChanged(bool state);
    void LeftDoorsChanged(bool state);
    void RightDoorsChanged(bool state);
    void TempChanged(int temp);
    void EmergencyBrakeChanged(bool state);
    void AutomaticModeChanged(bool state);
    void PowerChanged(double power);

signals:
    void DestinationDifferent(std::string destination);
    void DistanceDifferent(std::string distance);
    void TimeDifferent(std::string time);
    void SpeedLimitDifferent(int speed);
    void CommandedSpeedDifferent(int speed);
    void CurrentSpeedDifferent(int speed);
    void EmergencyBrakeDifferent(std::string state);
    void FailureDifferent(std::string state);

private slots:
    void on_DestinationBox_textChanged(const QString &arg1);
    void on_DistanceBox_textChanged(const QString &arg1);
    void on_TimeBox_textChanged(const QString &arg1);
    void on_SpeedLimitBox_textChanged(const QString &arg1);
    void on_SuggestedSpeedBox_textChanged(const QString &arg1);
    void on_EBrakeInBox_textChanged(const QString &arg1);
    void on_FailureBox_textChanged(const QString &arg1);
    void on_CurrentSpeedBox_returnPressed();

private:
    Ui::TestUI *ui;
    double Power;
};

#endif // TESTUI_H
