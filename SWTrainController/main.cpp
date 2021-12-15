#include "swtcui.h"
#include "engineer.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SWTCUI traincontrollerui;
    Engineer engineerui;
    traincontrollerui.show();
    engineerui.show();
    return a.exec();
}
