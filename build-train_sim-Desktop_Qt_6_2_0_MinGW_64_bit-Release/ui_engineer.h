/********************************************************************************
** Form generated from reading UI file 'engineer.ui'
**
** Created by: Qt User Interface Compiler version 6.2.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ENGINEER_H
#define UI_ENGINEER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Engineer
{
public:
    QWidget *centralwidget;
    QLineEdit *KpBox;
    QLineEdit *KiBox;
    QLabel *label_2;
    QLabel *label;
    QPushButton *SubmitButton;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Engineer)
    {
        if (Engineer->objectName().isEmpty())
            Engineer->setObjectName(QString::fromUtf8("Engineer"));
        Engineer->resize(538, 320);
        centralwidget = new QWidget(Engineer);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        KpBox = new QLineEdit(centralwidget);
        KpBox->setObjectName(QString::fromUtf8("KpBox"));
        KpBox->setGeometry(QRect(60, 50, 181, 61));
        QFont font;
        font.setPointSize(14);
        KpBox->setFont(font);
        KiBox = new QLineEdit(centralwidget);
        KiBox->setObjectName(QString::fromUtf8("KiBox"));
        KiBox->setGeometry(QRect(290, 50, 181, 61));
        KiBox->setFont(font);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(370, 110, 71, 31));
        label_2->setFont(font);
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(130, 110, 91, 41));
        label->setFont(font);
        SubmitButton = new QPushButton(centralwidget);
        SubmitButton->setObjectName(QString::fromUtf8("SubmitButton"));
        SubmitButton->setGeometry(QRect(170, 190, 161, 71));
        QFont font1;
        font1.setPointSize(13);
        SubmitButton->setFont(font1);
        Engineer->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(Engineer);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        Engineer->setStatusBar(statusbar);

        retranslateUi(Engineer);

        QMetaObject::connectSlotsByName(Engineer);
    } // setupUi

    void retranslateUi(QMainWindow *Engineer)
    {
        Engineer->setWindowTitle(QCoreApplication::translate("Engineer", "MainWindow", nullptr));
        KpBox->setText(QString());
        label_2->setText(QCoreApplication::translate("Engineer", "Ki", nullptr));
        label->setText(QCoreApplication::translate("Engineer", "Kp", nullptr));
        SubmitButton->setText(QCoreApplication::translate("Engineer", "Submit Values", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Engineer: public Ui_Engineer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ENGINEER_H
