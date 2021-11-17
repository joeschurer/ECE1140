#include "mainwindow.h"
#include "testui.h"
#include "engineer.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    TestUI t;
    Engineer e;
    w.show();
    t.show();
    e.show();
    QObject::connect(&w, SIGNAL(SetSpeedDifferent(int)), &t, SLOT(SetSpeedChanged(int)));
    QObject::connect(&w, SIGNAL(LightsDifferent(bool)), &t, SLOT(LightsChanged(bool)));
    QObject::connect(&w, SIGNAL(LeftDoorsDifferent(bool)), &t, SLOT(LeftDoorsChanged(bool)));
    QObject::connect(&w, SIGNAL(RightDoorsDifferent(bool)), &t, SLOT(RightDoorsChanged(bool)));
    QObject::connect(&w, SIGNAL(TempDifferent(int)), &t, SLOT(TempChanged(int)));
    QObject::connect(&w, SIGNAL(EmergencyBrakeDifferent(bool)), &t, SLOT(EmergencyBrakeChanged(bool)));
    QObject::connect(&w, SIGNAL(AutomaticModeDifferent(bool)), &t, SLOT(AutomaticModeChanged(bool)));
    QObject::connect(&t, SIGNAL(DestinationDifferent(std::string)), &w, SLOT(DestinationChanged(std::string)));
    QObject::connect(&t, SIGNAL(DistanceDifferent(std::string)), &w, SLOT(DistanceChanged(std::string)));
    QObject::connect(&t, SIGNAL(TimeDifferent(std::string)), &w, SLOT(TimeChanged(std::string)));
    QObject::connect(&t, SIGNAL(SpeedLimitDifferent(int)), &w, SLOT(SpeedLimitChanged(int)));
    QObject::connect(&t, SIGNAL(CommandedSpeedDifferent(int)), &w, SLOT(CommandedSpeedChanged(int)));
    QObject::connect(&t, SIGNAL(CurrentSpeedDifferent(int)), &w, SLOT(CurrentSpeedChanged(int)));
    QObject::connect(&t, SIGNAL(EmergencyBrakeDifferent(std::string)), &w, SLOT(EmergencyBrakeChanged(std::string)));
    QObject::connect(&e, SIGNAL(SubmitKpKi(int,int)), &w, SLOT(KpKiChanged(int,int)));
    QObject::connect(&w, SIGNAL(PowerCalculated(double)), &t, SLOT(PowerChanged(double)));

    return a.exec();
}
