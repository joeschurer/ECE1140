/********************************************************************************
** Form generated from reading UI file 'swtcui.ui'
**
** Created by: Qt User Interface Compiler version 6.2.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SWTCUI_H
#define UI_SWTCUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SWTCUI
{
public:
    QWidget *centralwidget;
    QPushButton *PlusSpeedButton;
    QLineEdit *SpeedLimitBox;
    QLabel *ClockLabel;
    QPushButton *EBrakeButton;
    QLabel *SpeedControlLabel;
    QLabel *TempLabel;
    QLabel *DegreesFLabel;
    QLabel *EStopState;
    QPushButton *AutomaticModeButton;
    QLabel *TimeDistanceLabel;
    QLabel *CurrentSpeedLabel;
    QLabel *SetSpeedMPH;
    QLabel *CommandedSpeedLabel;
    QLineEdit *EBrakeBox;
    QPushButton *OperateLeftDoorsButton;
    QPushButton *MinusACButton;
    QLabel *SpeedLimitMPH;
    QLineEdit *SetSpeedBox;
    QLineEdit *DestinationDisplay;
    QLineEdit *CommandedSpeedBox;
    QLineEdit *CurrentSpeedBox;
    QLabel *FailureLabel;
    QLabel *SpeedLimitLabel;
    QTextEdit *TimeDistanceBox;
    QPushButton *OperateLightsButton;
    QLabel *CommandedSpeedMPH;
    QLabel *CurrentSpeedMPH;
    QLineEdit *CurrentTempBox;
    QPushButton *MinusSpeedButton;
    QPushButton *PlusACButton;
    QLineEdit *ClockDisplay;
    QLabel *DestLabel;
    QPushButton *OperateRightDoorsButton;
    QPushButton *BrakeButton;
    QLabel *SetSpeedLabel;
    QLineEdit *FailureBox;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *SWTCUI)
    {
        if (SWTCUI->objectName().isEmpty())
            SWTCUI->setObjectName(QString::fromUtf8("SWTCUI"));
        SWTCUI->resize(1105, 651);
        centralwidget = new QWidget(SWTCUI);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        PlusSpeedButton = new QPushButton(centralwidget);
        PlusSpeedButton->setObjectName(QString::fromUtf8("PlusSpeedButton"));
        PlusSpeedButton->setGeometry(QRect(120, 330, 131, 51));
        QFont font;
        font.setPointSize(35);
        PlusSpeedButton->setFont(font);
        PlusSpeedButton->setStyleSheet(QString::fromUtf8("background-color: rgb(8, 185, 8);"));
        SpeedLimitBox = new QLineEdit(centralwidget);
        SpeedLimitBox->setObjectName(QString::fromUtf8("SpeedLimitBox"));
        SpeedLimitBox->setGeometry(QRect(580, 200, 113, 61));
        QFont font1;
        font1.setPointSize(25);
        SpeedLimitBox->setFont(font1);
        SpeedLimitBox->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        SpeedLimitBox->setReadOnly(true);
        ClockLabel = new QLabel(centralwidget);
        ClockLabel->setObjectName(QString::fromUtf8("ClockLabel"));
        ClockLabel->setGeometry(QRect(530, 60, 61, 31));
        QFont font2;
        font2.setPointSize(10);
        ClockLabel->setFont(font2);
        EBrakeButton = new QPushButton(centralwidget);
        EBrakeButton->setObjectName(QString::fromUtf8("EBrakeButton"));
        EBrakeButton->setGeometry(QRect(840, 10, 151, 51));
        QFont font3;
        font3.setPointSize(14);
        EBrakeButton->setFont(font3);
        EBrakeButton->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 0, 0);"));
        SpeedControlLabel = new QLabel(centralwidget);
        SpeedControlLabel->setObjectName(QString::fromUtf8("SpeedControlLabel"));
        SpeedControlLabel->setGeometry(QRect(130, 380, 141, 51));
        SpeedControlLabel->setFont(font3);
        TempLabel = new QLabel(centralwidget);
        TempLabel->setObjectName(QString::fromUtf8("TempLabel"));
        TempLabel->setGeometry(QRect(460, 520, 181, 41));
        TempLabel->setFont(font3);
        DegreesFLabel = new QLabel(centralwidget);
        DegreesFLabel->setObjectName(QString::fromUtf8("DegreesFLabel"));
        DegreesFLabel->setGeometry(QRect(590, 580, 55, 31));
        DegreesFLabel->setFont(font1);
        EStopState = new QLabel(centralwidget);
        EStopState->setObjectName(QString::fromUtf8("EStopState"));
        EStopState->setGeometry(QRect(730, 50, 91, 31));
        QFont font4;
        font4.setPointSize(13);
        EStopState->setFont(font4);
        AutomaticModeButton = new QPushButton(centralwidget);
        AutomaticModeButton->setObjectName(QString::fromUtf8("AutomaticModeButton"));
        AutomaticModeButton->setGeometry(QRect(110, 530, 151, 51));
        AutomaticModeButton->setFont(font3);
        AutomaticModeButton->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        TimeDistanceLabel = new QLabel(centralwidget);
        TimeDistanceLabel->setObjectName(QString::fromUtf8("TimeDistanceLabel"));
        TimeDistanceLabel->setGeometry(QRect(400, 370, 321, 31));
        TimeDistanceLabel->setFont(font3);
        CurrentSpeedLabel = new QLabel(centralwidget);
        CurrentSpeedLabel->setObjectName(QString::fromUtf8("CurrentSpeedLabel"));
        CurrentSpeedLabel->setGeometry(QRect(330, 260, 181, 31));
        QFont font5;
        font5.setPointSize(16);
        CurrentSpeedLabel->setFont(font5);
        SetSpeedMPH = new QLabel(centralwidget);
        SetSpeedMPH->setObjectName(QString::fromUtf8("SetSpeedMPH"));
        SetSpeedMPH->setGeometry(QRect(230, 220, 61, 31));
        QFont font6;
        font6.setPointSize(18);
        SetSpeedMPH->setFont(font6);
        CommandedSpeedLabel = new QLabel(centralwidget);
        CommandedSpeedLabel->setObjectName(QString::fromUtf8("CommandedSpeedLabel"));
        CommandedSpeedLabel->setGeometry(QRect(790, 260, 171, 31));
        CommandedSpeedLabel->setFont(font5);
        EBrakeBox = new QLineEdit(centralwidget);
        EBrakeBox->setObjectName(QString::fromUtf8("EBrakeBox"));
        EBrakeBox->setGeometry(QRect(740, 10, 71, 41));
        EBrakeBox->setFont(font3);
        EBrakeBox->setReadOnly(true);
        OperateLeftDoorsButton = new QPushButton(centralwidget);
        OperateLeftDoorsButton->setObjectName(QString::fromUtf8("OperateLeftDoorsButton"));
        OperateLeftDoorsButton->setGeometry(QRect(720, 410, 161, 51));
        OperateLeftDoorsButton->setFont(font4);
        OperateLeftDoorsButton->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);\n"
"color: rgb(255, 255, 255);"));
        MinusACButton = new QPushButton(centralwidget);
        MinusACButton->setObjectName(QString::fromUtf8("MinusACButton"));
        MinusACButton->setGeometry(QRect(390, 570, 81, 51));
        QFont font7;
        font7.setPointSize(37);
        MinusACButton->setFont(font7);
        MinusACButton->setStyleSheet(QString::fromUtf8("background-color: rgb(11, 15, 255);"));
        SpeedLimitMPH = new QLabel(centralwidget);
        SpeedLimitMPH->setObjectName(QString::fromUtf8("SpeedLimitMPH"));
        SpeedLimitMPH->setGeometry(QRect(700, 220, 61, 31));
        SpeedLimitMPH->setFont(font6);
        SetSpeedBox = new QLineEdit(centralwidget);
        SetSpeedBox->setObjectName(QString::fromUtf8("SetSpeedBox"));
        SetSpeedBox->setGeometry(QRect(110, 200, 113, 61));
        SetSpeedBox->setFont(font1);
        SetSpeedBox->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        SetSpeedBox->setReadOnly(true);
        DestinationDisplay = new QLineEdit(centralwidget);
        DestinationDisplay->setObjectName(QString::fromUtf8("DestinationDisplay"));
        DestinationDisplay->setGeometry(QRect(20, 10, 231, 51));
        QFont font8;
        font8.setPointSize(19);
        DestinationDisplay->setFont(font8);
        DestinationDisplay->setReadOnly(true);
        CommandedSpeedBox = new QLineEdit(centralwidget);
        CommandedSpeedBox->setObjectName(QString::fromUtf8("CommandedSpeedBox"));
        CommandedSpeedBox->setGeometry(QRect(810, 200, 113, 61));
        CommandedSpeedBox->setFont(font1);
        CommandedSpeedBox->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        CommandedSpeedBox->setReadOnly(true);
        CurrentSpeedBox = new QLineEdit(centralwidget);
        CurrentSpeedBox->setObjectName(QString::fromUtf8("CurrentSpeedBox"));
        CurrentSpeedBox->setGeometry(QRect(340, 200, 113, 61));
        CurrentSpeedBox->setFont(font1);
        CurrentSpeedBox->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        CurrentSpeedBox->setReadOnly(true);
        FailureLabel = new QLabel(centralwidget);
        FailureLabel->setObjectName(QString::fromUtf8("FailureLabel"));
        FailureLabel->setGeometry(QRect(320, 50, 91, 31));
        FailureLabel->setFont(font5);
        SpeedLimitLabel = new QLabel(centralwidget);
        SpeedLimitLabel->setObjectName(QString::fromUtf8("SpeedLimitLabel"));
        SpeedLimitLabel->setGeometry(QRect(580, 260, 151, 31));
        SpeedLimitLabel->setFont(font5);
        TimeDistanceBox = new QTextEdit(centralwidget);
        TimeDistanceBox->setObjectName(QString::fromUtf8("TimeDistanceBox"));
        TimeDistanceBox->setGeometry(QRect(440, 410, 241, 101));
        QFont font9;
        font9.setPointSize(20);
        TimeDistanceBox->setFont(font9);
        TimeDistanceBox->setReadOnly(true);
        OperateLightsButton = new QPushButton(centralwidget);
        OperateLightsButton->setObjectName(QString::fromUtf8("OperateLightsButton"));
        OperateLightsButton->setGeometry(QRect(810, 500, 151, 51));
        QFont font10;
        font10.setPointSize(15);
        OperateLightsButton->setFont(font10);
        OperateLightsButton->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 0);"));
        CommandedSpeedMPH = new QLabel(centralwidget);
        CommandedSpeedMPH->setObjectName(QString::fromUtf8("CommandedSpeedMPH"));
        CommandedSpeedMPH->setGeometry(QRect(930, 220, 61, 31));
        CommandedSpeedMPH->setFont(font6);
        CurrentSpeedMPH = new QLabel(centralwidget);
        CurrentSpeedMPH->setObjectName(QString::fromUtf8("CurrentSpeedMPH"));
        CurrentSpeedMPH->setGeometry(QRect(460, 220, 61, 31));
        CurrentSpeedMPH->setFont(font6);
        CurrentTempBox = new QLineEdit(centralwidget);
        CurrentTempBox->setObjectName(QString::fromUtf8("CurrentTempBox"));
        CurrentTempBox->setGeometry(QRect(510, 570, 71, 51));
        CurrentTempBox->setFont(font9);
        CurrentTempBox->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        CurrentTempBox->setReadOnly(true);
        MinusSpeedButton = new QPushButton(centralwidget);
        MinusSpeedButton->setObjectName(QString::fromUtf8("MinusSpeedButton"));
        MinusSpeedButton->setGeometry(QRect(120, 430, 131, 51));
        QFont font11;
        font11.setPointSize(51);
        MinusSpeedButton->setFont(font11);
        MinusSpeedButton->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 17, 17);"));
        PlusACButton = new QPushButton(centralwidget);
        PlusACButton->setObjectName(QString::fromUtf8("PlusACButton"));
        PlusACButton->setGeometry(QRect(650, 570, 81, 51));
        QFont font12;
        font12.setPointSize(27);
        PlusACButton->setFont(font12);
        PlusACButton->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 168, 17);"));
        ClockDisplay = new QLineEdit(centralwidget);
        ClockDisplay->setObjectName(QString::fromUtf8("ClockDisplay"));
        ClockDisplay->setGeometry(QRect(500, 10, 101, 51));
        ClockDisplay->setFont(font9);
        ClockDisplay->setAlignment(Qt::AlignCenter);
        ClockDisplay->setReadOnly(true);
        DestLabel = new QLabel(centralwidget);
        DestLabel->setObjectName(QString::fromUtf8("DestLabel"));
        DestLabel->setGeometry(QRect(30, 60, 241, 31));
        DestLabel->setFont(font10);
        OperateRightDoorsButton = new QPushButton(centralwidget);
        OperateRightDoorsButton->setObjectName(QString::fromUtf8("OperateRightDoorsButton"));
        OperateRightDoorsButton->setGeometry(QRect(900, 410, 161, 51));
        OperateRightDoorsButton->setFont(font4);
        OperateRightDoorsButton->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);\n"
"color: rgb(255, 255, 255);"));
        BrakeButton = new QPushButton(centralwidget);
        BrakeButton->setObjectName(QString::fromUtf8("BrakeButton"));
        BrakeButton->setGeometry(QRect(490, 300, 131, 51));
        BrakeButton->setFont(font1);
        BrakeButton->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 31, 11);"));
        SetSpeedLabel = new QLabel(centralwidget);
        SetSpeedLabel->setObjectName(QString::fromUtf8("SetSpeedLabel"));
        SetSpeedLabel->setGeometry(QRect(120, 260, 131, 31));
        SetSpeedLabel->setFont(font5);
        FailureBox = new QLineEdit(centralwidget);
        FailureBox->setObjectName(QString::fromUtf8("FailureBox"));
        FailureBox->setGeometry(QRect(300, 10, 113, 41));
        FailureBox->setFont(font10);
        FailureBox->setReadOnly(true);
        SWTCUI->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(SWTCUI);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        SWTCUI->setStatusBar(statusbar);

        retranslateUi(SWTCUI);

        QMetaObject::connectSlotsByName(SWTCUI);
    } // setupUi

    void retranslateUi(QMainWindow *SWTCUI)
    {
        SWTCUI->setWindowTitle(QCoreApplication::translate("SWTCUI", "MainWindow", nullptr));
        PlusSpeedButton->setText(QCoreApplication::translate("SWTCUI", "+", nullptr));
        ClockLabel->setText(QCoreApplication::translate("SWTCUI", "<html><head/><body><p><span style=\" font-size:16pt;\">Clock</span></p></body></html>", nullptr));
        EBrakeButton->setText(QCoreApplication::translate("SWTCUI", "Emergency Brake", nullptr));
        SpeedControlLabel->setText(QCoreApplication::translate("SWTCUI", "Speed Control", nullptr));
        TempLabel->setText(QCoreApplication::translate("SWTCUI", "Current Temperature", nullptr));
        DegreesFLabel->setText(QCoreApplication::translate("SWTCUI", "\302\260F", nullptr));
        EStopState->setText(QCoreApplication::translate("SWTCUI", "Emergency Brake", nullptr));
        AutomaticModeButton->setText(QCoreApplication::translate("SWTCUI", "Automatic Mode", nullptr));
        TimeDistanceLabel->setText(QCoreApplication::translate("SWTCUI", "Time and Distance Required To Stop", nullptr));
        CurrentSpeedLabel->setText(QCoreApplication::translate("SWTCUI", "Current Speed", nullptr));
        SetSpeedMPH->setText(QCoreApplication::translate("SWTCUI", "MPH", nullptr));
        CommandedSpeedLabel->setText(QCoreApplication::translate("SWTCUI", "Commanded Speed", nullptr));
        OperateLeftDoorsButton->setText(QCoreApplication::translate("SWTCUI", "Operate Left Doors", nullptr));
        MinusACButton->setText(QCoreApplication::translate("SWTCUI", "-", nullptr));
        SpeedLimitMPH->setText(QCoreApplication::translate("SWTCUI", "MPH", nullptr));
        FailureLabel->setText(QCoreApplication::translate("SWTCUI", "Failure", nullptr));
        SpeedLimitLabel->setText(QCoreApplication::translate("SWTCUI", "Speed Limit", nullptr));
        OperateLightsButton->setText(QCoreApplication::translate("SWTCUI", "Operate Lights", nullptr));
        CommandedSpeedMPH->setText(QCoreApplication::translate("SWTCUI", "MPH", nullptr));
        CurrentSpeedMPH->setText(QCoreApplication::translate("SWTCUI", "MPH", nullptr));
        MinusSpeedButton->setText(QCoreApplication::translate("SWTCUI", "-", nullptr));
        PlusACButton->setText(QCoreApplication::translate("SWTCUI", "+", nullptr));
        DestLabel->setText(QCoreApplication::translate("SWTCUI", "Upcoming Destination", nullptr));
        OperateRightDoorsButton->setText(QCoreApplication::translate("SWTCUI", "Operate Right Doors", nullptr));
        BrakeButton->setText(QCoreApplication::translate("SWTCUI", "Brake", nullptr));
        SetSpeedLabel->setText(QCoreApplication::translate("SWTCUI", "Set Speed", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SWTCUI: public Ui_SWTCUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SWTCUI_H
