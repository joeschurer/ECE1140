/********************************************************************************
** Form generated from reading UI file 'topwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TOPWINDOW_H
#define UI_TOPWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TopWindow
{
public:
    QWidget *centralwidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *TopWindow)
    {
        if (TopWindow->objectName().isEmpty())
            TopWindow->setObjectName(QString::fromUtf8("TopWindow"));
        TopWindow->resize(800, 600);
        centralwidget = new QWidget(TopWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        TopWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(TopWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        TopWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(TopWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        TopWindow->setStatusBar(statusbar);

        retranslateUi(TopWindow);

        QMetaObject::connectSlotsByName(TopWindow);
    } // setupUi

    void retranslateUi(QMainWindow *TopWindow)
    {
        TopWindow->setWindowTitle(QCoreApplication::translate("TopWindow", "TopWindow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TopWindow: public Ui_TopWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TOPWINDOW_H
