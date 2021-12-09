#include "mainwindow.h"
#include "engineer.h"
#include "swtcui.h"
#include "traincalculate.h"
#include "trainmodelui.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Engineer e;
    SWTCUI s;
    TrainModelUI w;
    trainCalculate m;
    w.makeTrain(m);
    w.show();
    w.updateUI();
    s.show();
    e.show();
    QObject::connect(&e, SIGNAL(SubmitKpKi(double,double)), &s, SLOT(KpKiChanged(double,double)));
    QObject::connect(&s, SIGNAL(TempDifferent(int)), &w, SLOT(TempChanged(int)));
    QObject::connect(&s, SIGNAL(LeftDoorsDifferent(bool)), &w, SLOT(LeftDoorsChanged(bool)));
    QObject::connect(&s, SIGNAL(RightDoorsDifferent(bool)), &w, SLOT(RightDoorsChanged(bool)));
    QObject::connect(&s, SIGNAL(LightsDifferent(bool)), &w, SLOT(LightsChanged(bool)));
    QObject::connect(&s, SIGNAL(PowerCalculated(int)), &w, SLOT(PowerChanged(int)));
    QObject::connect(&s, SIGNAL(EmergencyBrakeDifferent(bool)), &w, SLOT(EmergencyBrakeChanged(bool)));

    return a.exec();
}
