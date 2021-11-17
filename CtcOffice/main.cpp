#include "HomepageWindow.h"
#include "CtcOffice.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    CtcOffice ctcOffice;
    QApplication a(argc, argv);
    HomepageWindow w(nullptr, &ctcOffice);

    w.show();
    return a.exec();
}
