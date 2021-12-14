#ifndef TRAINFACTORY_H
#define TRAINFACTORY_H
#include <vector>
#include <QMainWindow>
#include "trainmodelui.h"
#include "traincalculate.h"
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
    vector<TrainModelUI*> trains;
    int globalTemp;

signals:
    void commandedSpeedTC(int id, int cSpeed);
    void passOffTrain(vector<int>);
    void beaconToTC(vector<string>);

public slots:
        //on train creation
        void dispatchTrain(vector<int>);

        //slots from TM
        void receiveSignal(vector<int>);
        void boardingPassengers(vector<int>);
        void receiveBeacon(vector<string>);
        void temperatureChange(double);

        //slots from TC
        void receiveStationInfo(int, string, string);

private:
    Ui::TrainFactory *ui;


};
#endif // TRAINFACTORY_H
