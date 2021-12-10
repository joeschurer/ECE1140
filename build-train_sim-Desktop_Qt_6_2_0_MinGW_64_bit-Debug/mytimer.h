#ifndef MYTIMER_H
#define MYTIMER_H

#include <QTimer>
#include "trainmodelui.h"
class MyTimer : public QObject
{
    Q_OBJECT
public:
    MyTimer();
    void setTrain(TrainModelUI maitrain);
    QTimer *timer;
    TrainModelUI train;
public slots:
    void MyTimerSlot();
};

#endif // MYTIMER_H
