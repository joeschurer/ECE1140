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
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Engineer
{
public:
    QLabel *label;
    QLabel *label_2;
    QLineEdit *KiBox;
    QPushButton *SubmitButton;
    QLineEdit *KpBox;

    void setupUi(QWidget *Engineer)
    {
        if (Engineer->objectName().isEmpty())
            Engineer->setObjectName(QString::fromUtf8("Engineer"));
        Engineer->resize(815, 476);
        label = new QLabel(Engineer);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(300, 200, 91, 41));
        QFont font;
        font.setPointSize(14);
        label->setFont(font);
        label_2 = new QLabel(Engineer);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(540, 200, 71, 31));
        label_2->setFont(font);
        KiBox = new QLineEdit(Engineer);
        KiBox->setObjectName(QString::fromUtf8("KiBox"));
        KiBox->setGeometry(QRect(460, 140, 181, 61));
        KiBox->setFont(font);
        SubmitButton = new QPushButton(Engineer);
        SubmitButton->setObjectName(QString::fromUtf8("SubmitButton"));
        SubmitButton->setGeometry(QRect(340, 280, 161, 71));
        QFont font1;
        font1.setPointSize(13);
        SubmitButton->setFont(font1);
        KpBox = new QLineEdit(Engineer);
        KpBox->setObjectName(QString::fromUtf8("KpBox"));
        KpBox->setGeometry(QRect(230, 140, 181, 61));
        KpBox->setFont(font);

        retranslateUi(Engineer);

        QMetaObject::connectSlotsByName(Engineer);
    } // setupUi

    void retranslateUi(QWidget *Engineer)
    {
        Engineer->setWindowTitle(QCoreApplication::translate("Engineer", "Form", nullptr));
        label->setText(QCoreApplication::translate("Engineer", "Kp", nullptr));
        label_2->setText(QCoreApplication::translate("Engineer", "Ki", nullptr));
        SubmitButton->setText(QCoreApplication::translate("Engineer", "Submit Values", nullptr));
        KpBox->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Engineer: public Ui_Engineer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ENGINEER_H
