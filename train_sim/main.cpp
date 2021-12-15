#include "trainsimwindow.h"
#include "mainwindow.h"
#include "lineselect.h"
#include "trackmodel.h"
#include "beacon.h"
#include "trainmodel.h"
#include "wayside.h"
#include "homepagewindow.h"
#include <QTimer>
#include "trainmodelui.h"
#include "traincalculate.h"
#include "engineer.h"
#include "swtcui.h"
#include "models.h"
#include "trainfactory.h"

#include <QApplication>
int globalLine = 0;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //Launch Track Model
    //Line selection popup
    LineSelect lineselect;
    lineselect.setGeometry(10, 10, 400, 400);
    lineselect.show();
    a.exec();

    //Open the window and put the layout into it
    TrackModel window;
    window.setGeometry(0, 20, 850, 1400);
    window.setWindowTitle("Track Model");
    window.show();

    //globalLine = ts.selectedLine;
    //qDebug() << "line is" << globalLine;
    //Beacon Test UI
    Beacon beacon;
    beacon.show();

    //CTC office
    CtcOffice ctcOffice;
    HomepageWindow ctc(nullptr, &ctcOffice);
    ctc.show();

    //Wayside UI
    MainWindow wui;
    wui.show();

    Wayside wayTest;
    wayTest.show();

    Engineer e;
    SWTCUI s;
    TrainFactory f;
    TrainModelUI w;
    trainCalculate m;
    s.show();
    e.show();

    QObject::connect(&window, &TrackModel::trainData, &f, &TrainFactory::dispatchTrain);
   QObject::connect(&window, &TrackModel::tempChanged, &f, &TrainFactory::temperatureChange);
    QObject::connect(&window, &TrackModel::beaconData, &f, &TrainFactory::receiveBeacon);
   QObject::connect(&window, &TrackModel::passengersChanged, &f, &TrainFactory::boardingPassengers);
    QObject::connect(&w, &TrainModelUI::currSpeedTM, &window, &TrackModel::actualSpeedChanged);



    QObject::connect(&e, SIGNAL(SubmitKpKi(double,double)), &s, SLOT(KpKiChanged(double,double)));
    QObject::connect(&s, SIGNAL(TempDifferent(int)), &w, SLOT(TempChanged(int)));
    QObject::connect(&s, SIGNAL(LeftDoorsDifferent(bool)), &w, SLOT(LeftDoorsChanged(bool)));
    QObject::connect(&s, SIGNAL(RightDoorsDifferent(bool)), &w, SLOT(RightDoorsChanged(bool)));
    QObject::connect(&s, SIGNAL(LightsDifferent(bool)), &w, SLOT(LightsChanged(bool)));
    QObject::connect(&s, SIGNAL(PowerCalculated(int)), &w, SLOT(PowerChanged(int)));
    QObject::connect(&s, SIGNAL(EmergencyBrakeDifferent(bool)), &w, SLOT(EmergencyBrakeChanged(bool)));


    TrainModel trainUI;
    trainUI.setGeometry(860, 350, 300, 300);
    trainUI.show();

    QTimer timer;
    timer.start(1000/simulationSpeed);
    QObject::connect(&timer, &QTimer::timeout, &ctc, &HomepageWindow::timerSlot);
    QObject::connect(&timer, &QTimer::timeout, &w, &TrainModelUI::updateUI);
    QObject::connect(&wui, &MainWindow::sendThroughput, &ctc, &HomepageWindow::receiveTicketSales);
    QObject::connect(&wui, &MainWindow::sendCTCOcc,&ctc, &HomepageWindow::receiveOccupancy);
    QObject::connect(&ctc, &HomepageWindow::sendClosedBlocks,&wui, &MainWindow::getMaintenaceMode);
    QObject::connect(&ctc, &HomepageWindow::sendSwitchPosition,&wui, &MainWindow::changeSwitch);
    QObject::connect(&ctc, &HomepageWindow::sendDispatchInfo,&wui, &MainWindow::recieveAuth);
    QObject::connect(&wui, &MainWindow::sendFixed, &window,&TrackModel::fixBlock);
    QObject::connect(&wui, &MainWindow::sendTrainDispatch,&window, &TrackModel::trainUpdated);
    QObject::connect(&trainUI, SIGNAL(trainMoved(int)), &window, SLOT(trainMoved(int)));
    QObject::connect(&trainUI, SIGNAL(trainSpeedUpdated(QString)), &window, SLOT(actualSpeedChanged(QString)));
    QObject::connect(&wui, &MainWindow::sendTrainDispatch, &window, &TrackModel::trainUpdated);
    QObject::connect(&wui, &MainWindow::sendTrackModelSwitches, &window, &TrackModel::toggleSwitch);
    QObject::connect(&window, SIGNAL(beaconData(string)), &beacon, SLOT(transmitting(string)));
    QObject::connect(&trainUI, SIGNAL(doorsOpen(int)), &window, SLOT(doorsOpen(int)));
    QObject::connect(&window, &TrackModel::occupancyChanged, &wui, &MainWindow::receiveOcc);
    QObject::connect(&wui, &MainWindow::sendMaintenace, &window, &TrackModel::closeBlocks);

    QObject::connect(&wayTest, SIGNAL(trainChanged(vector<string>)), &window, SLOT(trainUpdated(vector<string>)));
    QObject::connect(&wayTest, SIGNAL(toggleSwitch(vector<int>)), &window, SLOT(toggleSwitch(vector<int>)));
    QObject::connect(&wayTest, SIGNAL(toggleCrossing(int)), &window, SLOT(toggleCrossing(int)));
    QObject::connect(&wui, &MainWindow::activateCrossing, &window, &TrackModel::toggleCrossings);
    QObject::connect(&window, &TrackModel::heatersOn, &wui, &MainWindow::receiveHeater);
    QObject::connect(&window, &TrackModel::throughput,&wui, &MainWindow::receiveThroughput);
    //QObject::connect(&ctc. &HomepageWindow:: , &wui, &MainWindow::sendThroughput);
    return a.exec();
}
