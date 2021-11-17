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
using namespace std;

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

    //Wayside Test UI
    Wayside waysideUI;
    waysideUI.setGeometry(860, 20, 300, 300);
    waysideUI.show();

    //Beacon Test UI
    Beacon beacon;
    beacon.show();

    //Train Model Test UI
    TrainModel trainUI;
    trainUI.setGeometry(860, 350, 300, 300);
    trainUI.show();

    QObject::connect(&waysideUI, SIGNAL(timeChanged()), &window, SLOT(timeout()));
    QObject::connect(&trainUI, SIGNAL(trainMoved(int)), &window, SLOT(trainMoved(int)));
    QObject::connect(&trainUI, SIGNAL(trainSpeedUpdated(QString)), &window, SLOT(actualSpeedChanged(QString)));
    QObject::connect(&waysideUI, SIGNAL(trainChanged(vector<string>)), &window, SLOT(trainUpdated(vector<string>)));
    QObject::connect(&waysideUI, SIGNAL(toggleSwitch(vector<int>)), &window, SLOT(toggleSwitch(vector<int>)));
    QObject::connect(&window, SIGNAL(beaconData(string)), &beacon, SLOT(transmitting(string)));

    return a.exec();
}
