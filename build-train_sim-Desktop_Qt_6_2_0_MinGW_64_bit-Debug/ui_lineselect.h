/********************************************************************************
** Form generated from reading UI file 'lineselect.ui'
**
** Created by: Qt User Interface Compiler version 6.2.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LINESELECT_H
#define UI_LINESELECT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_LineSelect
{
public:
    QGroupBox *selectionbox;
    QPushButton *selectgreen;
    QPushButton *selectred;
    QPushButton *selectblue;

    void setupUi(QDialog *LineSelect)
    {
        if (LineSelect->objectName().isEmpty())
            LineSelect->setObjectName(QString::fromUtf8("LineSelect"));
        LineSelect->resize(400, 300);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(LineSelect->sizePolicy().hasHeightForWidth());
        LineSelect->setSizePolicy(sizePolicy);
        QFont font;
        font.setPointSize(12);
        LineSelect->setFont(font);
        selectionbox = new QGroupBox(LineSelect);
        selectionbox->setObjectName(QString::fromUtf8("selectionbox"));
        selectionbox->setGeometry(QRect(100, 50, 171, 211));
        QFont font1;
        font1.setPointSize(17);
        selectionbox->setFont(font1);
        selectionbox->setAlignment(Qt::AlignCenter);
        selectgreen = new QPushButton(selectionbox);
        selectgreen->setObjectName(QString::fromUtf8("selectgreen"));
        selectgreen->setGeometry(QRect(10, 50, 151, 41));
        selectred = new QPushButton(selectionbox);
        selectred->setObjectName(QString::fromUtf8("selectred"));
        selectred->setGeometry(QRect(10, 100, 151, 41));
        selectblue = new QPushButton(selectionbox);
        selectblue->setObjectName(QString::fromUtf8("selectblue"));
        selectblue->setGeometry(QRect(10, 151, 151, 41));

        retranslateUi(LineSelect);

        QMetaObject::connectSlotsByName(LineSelect);
    } // setupUi

    void retranslateUi(QDialog *LineSelect)
    {
        LineSelect->setWindowTitle(QCoreApplication::translate("LineSelect", "Dialog", nullptr));
        selectionbox->setTitle(QCoreApplication::translate("LineSelect", "Select A Line", nullptr));
        selectgreen->setText(QCoreApplication::translate("LineSelect", "Green Line", nullptr));
        selectred->setText(QCoreApplication::translate("LineSelect", "Red Line", nullptr));
        selectblue->setText(QCoreApplication::translate("LineSelect", "Blue Line", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LineSelect: public Ui_LineSelect {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LINESELECT_H
