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
        Beacon beacon;
        beacon.show();
        QObject::connect(&window, SIGNAL(beaconData(string)), &beacon, SLOT(transmitting(string)));

        MainWindow wui;
        wui.show();

        HomepageWindow ctc;
        ctc.show();

        SWTrainControllerUI swt;
        swt.show();

        Engineer eng;
        eng.show();


        return a.exec();
}
