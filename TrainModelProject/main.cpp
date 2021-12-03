#include "trainmodelui.h"
#include <cstdint>
#include <iostream>
#include <QApplication>
#include "traincalculate.h"
#include "mytimer.h"

int main(int argc, char *argv[])
{
       QApplication a(argc, argv);
       TrainModelUI w;
       trainCalculate m;
       w.makeTrain(m);
       w.show();
       w.updateUI();

       return a.exec();

}
