#ifndef MYTIMER_H
#define MYTIMER_H

#include <QTimer>
#include "trainmodelui.h"
class MyTimer : public QObject
{
    Q_OBJECT
public:
    MyTimer();
    QTimer *timer;
    float time;
public slots:
    void MyTimerSlot();

signals:
    void newTime(float);
};

#endif // MYTIMER_H
