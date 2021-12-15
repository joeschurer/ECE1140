#ifndef TRAINFACTORY_H
#define TRAINFACTORY_H
#include <vector>
#include <QMainWindow>
#include "trainmodelui.h"
#include "traincalculate.h"
#include <QTimer>
using namespace std;
QT_BEGIN_NAMESPACE
namespace Ui { class TrainFactory; }
QT_END_NAMESPACE

class TrainFactory : public QMainWindow
{
    Q_OBJECT

public:
    TrainFactory(QWidget *parent = nullptr);
    ~TrainFactory();

    void makeTrain(trainCalculate, int, int);
    void receiveSignal(vector<int>);
    vector<TrainModelUI*> trains;
    int globalTemp;
    QTimer *timer;

signals:
    void commandedSpeedTC(int id, int cSpeed);
    void passOffTrain(vector<int>);
    void beaconToTC(int, string, int);
    void createTC(int id, int comm);
public slots:
        //on train creation
        void dispatchTrain(vector<int>);


        //timeslot
        void timeSlot();

        //slots from TM

        void boardingPassengers(vector<int>);
        void receiveBeacon(vector<string>);
        void temperatureChange(double);


private:
    Ui::TrainFactory *ui;


};
#endif // TRAINFACTORY_H
