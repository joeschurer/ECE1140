/********************************************************************************
** Form generated from reading UI file 'wayside.ui'
**
** Created by: Qt User Interface Compiler version 6.2.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WAYSIDE_H
#define UI_WAYSIDE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Wayside
{
public:
    QPushButton *test1;
    QPushButton *cont1_1;
    QLineEdit *toggleSwitch;
    QLabel *label;
    QPushButton *cont1_2;
    QPushButton *cont1_3;
    QPushButton *testYard;
    QLineEdit *toggleCrossing;
    QLabel *label_2;

    void setupUi(QDialog *Wayside)
    {
        if (Wayside->objectName().isEmpty())
            Wayside->setObjectName(QString::fromUtf8("Wayside"));
        Wayside->resize(209, 298);
        test1 = new QPushButton(Wayside);
        test1->setObjectName(QString::fromUtf8("test1"));
        test1->setGeometry(QRect(40, 20, 121, 22));
        cont1_1 = new QPushButton(Wayside);
        cont1_1->setObjectName(QString::fromUtf8("cont1_1"));
        cont1_1->setGeometry(QRect(40, 50, 121, 22));
        toggleSwitch = new QLineEdit(Wayside);
        toggleSwitch->setObjectName(QString::fromUtf8("toggleSwitch"));
        toggleSwitch->setGeometry(QRect(40, 230, 121, 21));
        label = new QLabel(Wayside);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(50, 250, 101, 20));
        cont1_2 = new QPushButton(Wayside);
        cont1_2->setObjectName(QString::fromUtf8("cont1_2"));
        cont1_2->setGeometry(QRect(40, 80, 121, 22));
        cont1_3 = new QPushButton(Wayside);
        cont1_3->setObjectName(QString::fromUtf8("cont1_3"));
        cont1_3->setGeometry(QRect(40, 110, 121, 22));
        testYard = new QPushButton(Wayside);
        testYard->setObjectName(QString::fromUtf8("testYard"));
        testYard->setGeometry(QRect(40, 140, 121, 22));
        toggleCrossing = new QLineEdit(Wayside);
        toggleCrossing->setObjectName(QString::fromUtf8("toggleCrossing"));
        toggleCrossing->setGeometry(QRect(40, 180, 121, 21));
        label_2 = new QLabel(Wayside);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(40, 200, 121, 20));
        label_2->setAlignment(Qt::AlignCenter);

        retranslateUi(Wayside);

        QMetaObject::connectSlotsByName(Wayside);
    } // setupUi

    void retranslateUi(QDialog *Wayside)
    {
        Wayside->setWindowTitle(QCoreApplication::translate("Wayside", "Dialog", nullptr));
        test1->setText(QCoreApplication::translate("Wayside", "Add Test Train", nullptr));
        cont1_1->setText(QCoreApplication::translate("Wayside", "Continue Test Train 1", nullptr));
        label->setText(QCoreApplication::translate("Wayside", "Toggle Switch #", nullptr));
        cont1_2->setText(QCoreApplication::translate("Wayside", "Continue Test Train 2", nullptr));
        cont1_3->setText(QCoreApplication::translate("Wayside", "Continue Test Train 3", nullptr));
        testYard->setText(QCoreApplication::translate("Wayside", "Test Yard", nullptr));
        label_2->setText(QCoreApplication::translate("Wayside", "Toggle Crossing #", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Wayside: public Ui_Wayside {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WAYSIDE_H
