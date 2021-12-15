/********************************************************************************
** Form generated from reading UI file 'trainsimwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TRAINSIMWINDOW_H
#define UI_TRAINSIMWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_trainsimwindow
{
public:
    QWidget *centralwidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *trainsimwindow)
    {
        if (trainsimwindow->objectName().isEmpty())
            trainsimwindow->setObjectName(QString::fromUtf8("trainsimwindow"));
        trainsimwindow->resize(800, 600);
        centralwidget = new QWidget(trainsimwindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        trainsimwindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(trainsimwindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        trainsimwindow->setMenuBar(menubar);
        statusbar = new QStatusBar(trainsimwindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        trainsimwindow->setStatusBar(statusbar);

        retranslateUi(trainsimwindow);

        QMetaObject::connectSlotsByName(trainsimwindow);
    } // setupUi

    void retranslateUi(QMainWindow *trainsimwindow)
    {
        trainsimwindow->setWindowTitle(QCoreApplication::translate("trainsimwindow", "trainsimwindow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class trainsimwindow: public Ui_trainsimwindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRAINSIMWINDOW_H
