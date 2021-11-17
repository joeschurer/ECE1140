#include "trainmodelui.h"
#include <cstdint>
#include <iostream>
#include <QApplication>
#include "traincalculate.h"

int main(int argc, char *argv[])
{
       QApplication a(argc, argv);
       TrainModelUI w;
       trainCalculate m;
       w.show();
       return a.exec();

}
