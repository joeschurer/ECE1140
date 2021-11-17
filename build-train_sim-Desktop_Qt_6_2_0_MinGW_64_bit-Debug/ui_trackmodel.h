/********************************************************************************
** Form generated from reading UI file 'trackmodel.ui'
**
** Created by: Qt User Interface Compiler version 6.2.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TRACKMODEL_H
#define UI_TRACKMODEL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TrackModel
{
public:
    QWidget *centralwidget;
    QLineEdit *breakCircuit;
    QLineEdit *breakTrack;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *breakPower;
    QLabel *label_3;
    QLabel *faultList;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *TrackModel)
    {
        if (TrackModel->objectName().isEmpty())
            TrackModel->setObjectName(QString::fromUtf8("TrackModel"));
        TrackModel->resize(800, 600);
        centralwidget = new QWidget(TrackModel);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        breakCircuit = new QLineEdit(centralwidget);
        breakCircuit->setObjectName(QString::fromUtf8("breakCircuit"));
        breakCircuit->setGeometry(QRect(670, 480, 113, 21));
        breakTrack = new QLineEdit(centralwidget);
        breakTrack->setObjectName(QString::fromUtf8("breakTrack"));
        breakTrack->setGeometry(QRect(550, 480, 113, 21));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(670, 500, 111, 16));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(550, 500, 111, 16));
        breakPower = new QLineEdit(centralwidget);
        breakPower->setObjectName(QString::fromUtf8("breakPower"));
        breakPower->setGeometry(QRect(430, 480, 113, 21));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(430, 500, 111, 16));
        faultList = new QLabel(centralwidget);
        faultList->setObjectName(QString::fromUtf8("faultList"));
        faultList->setGeometry(QRect(470, 450, 251, 16));
        TrackModel->setCentralWidget(centralwidget);
        menubar = new QMenuBar(TrackModel);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 21));
        TrackModel->setMenuBar(menubar);
        statusbar = new QStatusBar(TrackModel);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        TrackModel->setStatusBar(statusbar);

        retranslateUi(TrackModel);

        QMetaObject::connectSlotsByName(TrackModel);
    } // setupUi

    void retranslateUi(QMainWindow *TrackModel)
    {
        TrackModel->setWindowTitle(QCoreApplication::translate("TrackModel", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("TrackModel", "Break Circuit At Block", nullptr));
        label_2->setText(QCoreApplication::translate("TrackModel", "Break Track At Block", nullptr));
        label_3->setText(QCoreApplication::translate("TrackModel", "Drain Power At Block", nullptr));
        faultList->setText(QCoreApplication::translate("TrackModel", "There are no faults", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TrackModel: public Ui_TrackModel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRACKMODEL_H
