#include "topwindow.h"
#include "homepagewindow.h"
#include "mainwindow.h"
#include "CtcOffice.h"
#include "lineselect.h"
#include "trackmodel.h"
#include "lineselect.h"
#include "beacon.h"
#include "trainmodel.h"
#include "layout.h"
#include "QTableWidget"
#include "QTableWidgetItem"
#include <QWidget>
#include <QWidgetItem>
#include <QPushButton>
#include <QApplication>
#include <QTimer>
#include <QLocale>
#include <QTranslator>
#include <QObject>
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/stat.h>
#include "wayside.h"
#include <unistd.h>
#include <QApplication>
#include "swtraincontrollerui.h"
#include "engineer.h"
#include "trainmodelui.h"
#include "traincalculate.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "TrackModel_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            a.installTranslator(&translator);
            break;
        }
    }
    //Line selection popup
        LineSelect lineselect;
        lineselect.setGeometry(10, 10, 400, 400);
        lineselect.show();
        a.exec();

        //Open the window and put the layout into it
        TrackModel window;
        window.setGeometry(0, 20, 850, 1000);
        window.setWindowTitle("Track Model");
        window.show();

        //Beacon Test UI
        //Beacon beacon;
        //beacon.show();
        //QObject::connect(&window, SIGNAL(beaconData(string)), &beacon, SLOT(transmitting(string)));

        MainWindow wui;
        wui.show();

        CtcOffice ctcOffice;
        HomepageWindow ctc(nullptr, &ctcOffice);
        ctc.show();

        SWTrainControllerUI swt;
        swt.show();

        Engineer eng;
        eng.show();

        TrainModelUI aaah;
        trainCalculate wwwww;
        aaah.makeTrain(wwwww);
        aaah.show();
      //  TestUI t;
        //t.show();

        //TrainTimer ttime(1000);
        QTimer timer;
        //QObject::connect(&timer, &QTimer::timeout, &aaah, &TrainModelUI::updateTime);
        //QObject::connect(&timer, &QTimer::timeout,&window, &TrackModel::timeout);
        QObject::connect(&timer, &QTimer::timeout, &ctc, &HomepageWindow::timerSlot);
        timer.start(1000/simulationSpeed);
        QObject::connect(&wui, &MainWindow::sendCTCOcc,&ctc, &HomepageWindow::receiveOccupancy);
        QObject::connect(&ctc, &HomepageWindow::sendClosedBlocks,&wui, &MainWindow::getMaintenaceMode);
        QObject::connect(&ctc, &HomepageWindow::sendSwitchPosition,&wui, &MainWindow::changeSwitch);
        QObject::connect(&wui, &MainWindow::sendTrainDispatch,&window, &TrackModel::trainUpdated);
        QObject::connect(&window, &TrackModel::occupancyChanged,&wui, &MainWindow::receiveOcc);
        QObject::connect(&wui, &MainWindow::sendTrackModelSwitches,&window, &TrackModel::toggleSwitch);

        //Train Controller
        /* QObject::connect(&swt, SIGNAL(SetSpeedDifferent(int)), &t, SLOT(SetSpeedChanged(int)));
         QObject::connect(&swt, SIGNAL(LightsDifferent(bool)), &t, SLOT(LightsChanged(bool)));
         QObject::connect(&swt, SIGNAL(LeftDoorsDifferent(bool)), &t, SLOT(LeftDoorsChanged(bool)));
         QObject::connect(&swt, SIGNAL(RightDoorsDifferent(bool)), &t, SLOT(RightDoorsChanged(bool)));
         QObject::connect(&swt, SIGNAL(TempDifferent(int)), &t, SLOT(TempChanged(int)));
         QObject::connect(&swt, SIGNAL(EmergencyBrakeDifferent(bool)), &t, SLOT(EmergencyBrakeChanged(bool)));
         QObject::connect(&swt, SIGNAL(AutomaticModeDifferent(bool)), &t, SLOT(AutomaticModeChanged(bool)));
         QObject::connect(&t, SIGNAL(DestinationD   ifferent(std::string)), &w, SLOT(DestinationChanged(std::string)));
         QObject::connect(&t, SIGNAL(DistanceDifferent(std::string)), &w, SLOT(DistanceChanged(std::string)));
         QObject::connect(&t, SIGNAL(TimeDifferent(std::string)), &w, SLOT(TimeChanged(std::string)));
         QObject::connect(&t, SIGNAL(SpeedLimitDifferent(int)), &w, SLOT(SpeedLimitChanged(int)));
         QObject::connect(&t, SIGNAL(CommandedSpeedDifferent(int)), &w, SLOT(CommandedSpeedChanged(int)));
         QObject::connect(&t, SIGNAL(CurrentSpeedDifferent(int)), &w, SLOT(CurrentSpeedChanged(int)));
         QObject::connect(&t, SIGNAL(EmergencyBrakeDifferent(std::string)), &w, SLOT(EmergencyBrakeChanged(std::string)));
        */
         QObject::connect(&eng, SIGNAL(SubmitKpKi(int,int)), &swt, SLOT(KpKiChanged(int,int)));
        // QObject::connect(&swt, SIGNAL(PowerCalculated(double)), &t, SLOT(PowerChanged(double)));

        return a.exec();
}

