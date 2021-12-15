/********************************************************************************
** Form generated from reading UI file 'beacon.ui'
**
** Created by: Qt User Interface Compiler version 6.2.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BEACON_H
#define UI_BEACON_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Beacon
{
public:
    QWidget *centralwidget;
    QLabel *beaconData;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Beacon)
    {
        if (Beacon->objectName().isEmpty())
            Beacon->setObjectName(QString::fromUtf8("Beacon"));
        Beacon->resize(232, 156);
        centralwidget = new QWidget(Beacon);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        beaconData = new QLabel(centralwidget);
        beaconData->setObjectName(QString::fromUtf8("beaconData"));
        beaconData->setGeometry(QRect(10, 20, 211, 91));
        beaconData->setAlignment(Qt::AlignCenter);
        Beacon->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Beacon);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 232, 21));
        Beacon->setMenuBar(menubar);
        statusbar = new QStatusBar(Beacon);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        Beacon->setStatusBar(statusbar);

        retranslateUi(Beacon);

        QMetaObject::connectSlotsByName(Beacon);
    } // setupUi

    void retranslateUi(QMainWindow *Beacon)
    {
        Beacon->setWindowTitle(QCoreApplication::translate("Beacon", "MainWindow", nullptr));
        beaconData->setText(QCoreApplication::translate("Beacon", "Waiting for Input", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Beacon: public Ui_Beacon {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BEACON_H
