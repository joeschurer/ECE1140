#include "trainsimwindow.h"
#include "mainwindow.h"
#include "lineselect.h"
#include "trackmodel.h"
#include "beacon.h"
#include "trainmodel.h"
#include "wayside.h"

#include <QApplication>

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

    //Beacon Test UI
    Beacon beacon;
    beacon.show();

    //Wayside UI
    MainWindow wui;
    wui.show();

    Wayside wayTest;
    wayTest.show();

    //Train Model Test UI
    TrainModel trainUI;
    trainUI.setGeometry(860, 350, 300, 300);
    trainUI.show();

    QObject::connect(&trainUI, SIGNAL(trainMoved(int)), &window, SLOT(trainMoved(int)));
    QObject::connect(&trainUI, SIGNAL(trainSpeedUpdated(QString)), &window, SLOT(actualSpeedChanged(QString)));
    QObject::connect(&wui, &MainWindow::sendTrainDispatch, &window, &TrackModel::trainUpdated);
    QObject::connect(&wui, &MainWindow::sendTrackModelSwitches, &window, &TrackModel::toggleSwitch);
    QObject::connect(&window, SIGNAL(beaconData(string)), &beacon, SLOT(transmitting(string)));
    QObject::connect(&trainUI, SIGNAL(doorsOpen(int)), &window, SLOT(doorsOpen(int)));
    QObject::connect(&window, &TrackModel::occupancyChanged, &wui, &MainWindow::receiveOcc);

    QObject::connect(&wayTest, SIGNAL(trainChanged(vector<string>)), &window, SLOT(trainUpdated(vector<string>)));
    QObject::connect(&wayTest, SIGNAL(toggleSwitch(vector<int>)), &window, SLOT(toggleSwitch(vector<int>)));
    QObject::connect(&wayTest, SIGNAL(toggleCrossing(int)), &window, SLOT(toggleCrossing(int)));
    QObject::connect(&wui, &MainWindow::activateCrossing, &window, &TrackModel::toggleCrossings);
    QObject::connect(&window, &TrackModel::heatersOn, &wui, &MainWindow::receiveHeater);
    return a.exec();
}
