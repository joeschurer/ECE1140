#include "swtraincontrollerui.h"
#include "engineer.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SWTrainControllerUI w;
    Engineer e;
    w.show();
    e.show();
    return a.exec();
}
