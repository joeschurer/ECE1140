#include "HomepageWindow.h"
#include "CtcOffice.h"
#include <QTimer>

#include <QApplication>

int main(int argc, char *argv[])
{
    CtcOffice ctcOffice;
    QApplication a(argc, argv);
    HomepageWindow w(nullptr, &ctcOffice);
    QTimer timer;
    QObject::connect(&timer, &QTimer::timeout, &w, &HomepageWindow::timerSlot);
    timer.start(1000/simulationSpeed);

    w.show();
    return a.exec();
}
