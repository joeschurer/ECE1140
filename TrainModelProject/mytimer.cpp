#include "mytimer.h"
#include <QDebug>
#include "trainmodelui.h"
MyTimer::MyTimer()
{
    // create a timer
    time = 0.0;
    timer = new QTimer(this);

    // setup signal and slot
    connect(timer, SIGNAL(timeout()),
          this, SLOT(MyTimerSlot()));

    // msec
    timer->start(1000);
}

void MyTimer::MyTimerSlot()
{
    time = time+1;
    emit newTime(time);

}
