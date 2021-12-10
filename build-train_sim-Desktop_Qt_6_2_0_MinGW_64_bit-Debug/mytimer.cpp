#include "mytimer.h"
#include <QDebug>
#include "trainmodelui.h"
MyTimer::MyTimer()
{
    // create a timer

    timer = new QTimer(this);

    // setup signal and slot
    connect(timer, SIGNAL(timeout()),
          this, SLOT(MyTimerSlot()));

    // msec
    timer->start(1000);
}

void MyTimer::MyTimerSlot()
{
    qDebug() << "Timer...";
}

void MyTimer::setTrain(TrainModelUI maitrain){
    train = maitrain;
}
