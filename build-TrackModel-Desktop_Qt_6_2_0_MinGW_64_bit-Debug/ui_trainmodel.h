/********************************************************************************
** Form generated from reading UI file 'trainmodel.ui'
**
** Created by: Qt User Interface Compiler version 6.2.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TRAINMODEL_H
#define UI_TRAINMODEL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TrainModel
{
public:
    QWidget *centralwidget;
    QGroupBox *moveTrain;
    QLabel *moveLabel;
    QLineEdit *moveEdit;
    QGroupBox *updateSpeed;
    QLabel *speedLabel;
    QLineEdit *speedEdit;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *TrainModel)
    {
        if (TrainModel->objectName().isEmpty())
            TrainModel->setObjectName(QString::fromUtf8("TrainModel"));
        TrainModel->resize(151, 249);
        centralwidget = new QWidget(TrainModel);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        moveTrain = new QGroupBox(centralwidget);
        moveTrain->setObjectName(QString::fromUtf8("moveTrain"));
        moveTrain->setGeometry(QRect(10, 10, 120, 80));
        moveLabel = new QLabel(moveTrain);
        moveLabel->setObjectName(QString::fromUtf8("moveLabel"));
        moveLabel->setGeometry(QRect(20, 50, 81, 16));
        moveEdit = new QLineEdit(moveTrain);
        moveEdit->setObjectName(QString::fromUtf8("moveEdit"));
        moveEdit->setGeometry(QRect(10, 30, 101, 21));
        updateSpeed = new QGroupBox(centralwidget);
        updateSpeed->setObjectName(QString::fromUtf8("updateSpeed"));
        updateSpeed->setGeometry(QRect(10, 100, 121, 91));
        speedLabel = new QLabel(updateSpeed);
        speedLabel->setObjectName(QString::fromUtf8("speedLabel"));
        speedLabel->setGeometry(QRect(10, 50, 111, 41));
        speedLabel->setWordWrap(true);
        speedEdit = new QLineEdit(updateSpeed);
        speedEdit->setObjectName(QString::fromUtf8("speedEdit"));
        speedEdit->setGeometry(QRect(10, 30, 101, 21));
        TrainModel->setCentralWidget(centralwidget);
        menubar = new QMenuBar(TrainModel);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 151, 21));
        TrainModel->setMenuBar(menubar);
        statusbar = new QStatusBar(TrainModel);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        TrainModel->setStatusBar(statusbar);

        retranslateUi(TrainModel);

        QMetaObject::connectSlotsByName(TrainModel);
    } // setupUi

    void retranslateUi(QMainWindow *TrainModel)
    {
        TrainModel->setWindowTitle(QCoreApplication::translate("TrainModel", "MainWindow", nullptr));
        moveTrain->setTitle(QCoreApplication::translate("TrainModel", "Move to Next Block", nullptr));
        moveLabel->setText(QCoreApplication::translate("TrainModel", "Enter Train ID", nullptr));
        updateSpeed->setTitle(QCoreApplication::translate("TrainModel", "Update Speed", nullptr));
        speedLabel->setText(QCoreApplication::translate("TrainModel", "Enter Train ID, New Speed with no spaces", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TrainModel: public Ui_TrainModel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRAINMODEL_H
