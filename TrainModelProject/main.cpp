#include "trainmodelui.h"
#include <cstdint>
#include <iostream>
#include <QApplication>
#include "traincalculate.h"
#include "mytimer.h"
#include "trainfactory.h"
#include <vector>
#include <QDebug>
int main(int argc, char *argv[])
{
       QApplication a(argc, argv);
       TrainFactory f;
       TrainModelUI w;
       trainCalculate m;

       vector<int> ggg;
       ggg.push_back(0);
       ggg.push_back(70);
       f.dispatchTrain(ggg);
       vector<int> gggg;
       gggg.push_back(1);
       gggg.push_back(50);
       f.dispatchTrain(gggg);
       QTimer timer;
       QObject::connect(&timer, &QTimer::timeout, &w, &TrainModelUI::dormammu);
       timer.start(1000);
       qDebug() << "timer started";

       return a.exec();

}
