#include "trainsimwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    trainsimwindow w;
    w.show();
    return a.exec();
}
