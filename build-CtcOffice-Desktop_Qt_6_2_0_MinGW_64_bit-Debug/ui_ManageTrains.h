/********************************************************************************
** Form generated from reading UI file 'ManageTrains.ui'
**
** Created by: Qt User Interface Compiler version 6.2.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MANAGETRAINS_H
#define UI_MANAGETRAINS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_ManageTrains
{
public:
    QFrame *seperator_3;
    QLabel *homepageLink;
    QFrame *seperator;
    QLabel *testInterfaceLink;
    QFrame *seperator_2;
    QLabel *manageTracksLink;

    void setupUi(QDialog *ManageTrains)
    {
        if (ManageTrains->objectName().isEmpty())
            ManageTrains->setObjectName(QString::fromUtf8("ManageTrains"));
        ManageTrains->resize(400, 300);
        seperator_3 = new QFrame(ManageTrains);
        seperator_3->setObjectName(QString::fromUtf8("seperator_3"));
        seperator_3->setGeometry(QRect(290, 20, 20, 21));
        seperator_3->setFrameShape(QFrame::VLine);
        seperator_3->setFrameShadow(QFrame::Sunken);
        homepageLink = new QLabel(ManageTrains);
        homepageLink->setObjectName(QString::fromUtf8("homepageLink"));
        homepageLink->setGeometry(QRect(10, 16, 71, 20));
        seperator = new QFrame(ManageTrains);
        seperator->setObjectName(QString::fromUtf8("seperator"));
        seperator->setGeometry(QRect(80, 20, 20, 21));
        seperator->setFrameShape(QFrame::VLine);
        seperator->setFrameShadow(QFrame::Sunken);
        testInterfaceLink = new QLabel(ManageTrains);
        testInterfaceLink->setObjectName(QString::fromUtf8("testInterfaceLink"));
        testInterfaceLink->setGeometry(QRect(330, 20, 71, 16));
        seperator_2 = new QFrame(ManageTrains);
        seperator_2->setObjectName(QString::fromUtf8("seperator_2"));
        seperator_2->setGeometry(QRect(190, 20, 20, 21));
        seperator_2->setFrameShape(QFrame::VLine);
        seperator_2->setFrameShadow(QFrame::Sunken);
        manageTracksLink = new QLabel(ManageTrains);
        manageTracksLink->setObjectName(QString::fromUtf8("manageTracksLink"));
        manageTracksLink->setGeometry(QRect(210, 20, 101, 16));

        retranslateUi(ManageTrains);

        QMetaObject::connectSlotsByName(ManageTrains);
    } // setupUi

    void retranslateUi(QDialog *ManageTrains)
    {
        ManageTrains->setWindowTitle(QCoreApplication::translate("ManageTrains", "Dialog", nullptr));
        homepageLink->setText(QCoreApplication::translate("ManageTrains", "Homepage", nullptr));
        testInterfaceLink->setText(QCoreApplication::translate("ManageTrains", "Test Interface", nullptr));
        manageTracksLink->setText(QCoreApplication::translate("ManageTrains", "Manage Tracks", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ManageTrains: public Ui_ManageTrains {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MANAGETRAINS_H
