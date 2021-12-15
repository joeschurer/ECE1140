#include "trainmodelui.h"
#include <cstdint>
#include <iostream>
#include <QApplication>
#include "traincalculate.h"
#include "mytimer.h"
#include "trainfactory.h"
#include <vector>
#include <QDebug>
#include <QTimer>
int main(int argc, char *argv[])
{
       QApplication a(argc, argv);

       TrainFactory f = new TrainFactory();
       TrainModelUI w;
       trainCalculate m;
       QTimer *timer = new QTimer();
       timer->start(1000);
       vector<int> ggg;
       ggg.push_back(0);
       ggg.push_back(70);
       f.dispatchTrain(ggg);
       vector<int> gggg;
       gggg.push_back(1);
       gggg.push_back(50);
       f.dispatchTrain(gggg);

       f.trains[0]->updateUI();
       qDebug() << "timer started";

           QObject::connect(timer, &QTimer::timeout, &f, &TrainFactory::timeSlot);


       return a.exec();

}
