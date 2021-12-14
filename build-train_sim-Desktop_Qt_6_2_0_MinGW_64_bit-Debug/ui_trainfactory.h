/********************************************************************************
** Form generated from reading UI file 'trainfactory.ui'
**
** Created by: Qt User Interface Compiler version 6.2.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TRAINFACTORY_H
#define UI_TRAINFACTORY_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TrainFactory
{
public:
    QWidget *centralwidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *TrainFactory)
    {
        if (TrainFactory->objectName().isEmpty())
            TrainFactory->setObjectName(QString::fromUtf8("TrainFactory"));
        TrainFactory->resize(800, 600);
        centralwidget = new QWidget(TrainFactory);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        TrainFactory->setCentralWidget(centralwidget);
        menubar = new QMenuBar(TrainFactory);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        TrainFactory->setMenuBar(menubar);
        statusbar = new QStatusBar(TrainFactory);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        TrainFactory->setStatusBar(statusbar);

        retranslateUi(TrainFactory);

        QMetaObject::connectSlotsByName(TrainFactory);
    } // setupUi

    void retranslateUi(QMainWindow *TrainFactory)
    {
        TrainFactory->setWindowTitle(QCoreApplication::translate("TrainFactory", "TrainFactory", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TrainFactory: public Ui_TrainFactory {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRAINFACTORY_H
