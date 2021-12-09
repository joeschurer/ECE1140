#include "swtcui.h"
#include "engineer.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Engineer EngineerUI;
    SWTCUI DriverUI;
    DriverUI.show();
    EngineerUI.show();

    QObject::connect(&EngineerUI, SIGNAL(SubmitKpKi(double,double)), &DriverUI, SLOT(KpKiChanged(double,double)));

    return a.exec();
}
