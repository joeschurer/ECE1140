/********************************************************************************
** Form generated from reading UI file 'swtraincontrollerui.ui'
**
** Created by: Qt User Interface Compiler version 6.2.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SWTRAINCONTROLLERUI_H
#define UI_SWTRAINCONTROLLERUI_H

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

class Ui_SWTrainControllerUI
{
public:
    QWidget *centralwidget;
    QPushButton *PlusSpeedButton;
    QLabel *SpeedControlLabel;
    QPushButton *OperateLightsButton;
    QLabel *CurrentSpeedMPH;
    QLabel *DegreesFLabel;
    QLabel *EStopState;
    QLabel *CommandedSpeedLabel;
    QLineEdit *CurrentSpeedBox;
    QLineEdit *SpeedLimitBox;
    QLineEdit *ClockDisplay;
    QLabel *SetSpeedLabel;
    QLabel *CommandedSpeedMPH;
    QLineEdit *CurrentTempBox;
    QLineEdit *CommandedSpeedBox;
    QPushButton *OperateRightDoorsButton;
    QLabel *SpeedLimitMPH;
    QLabel *DestLabel;
    QTextEdit *TimeDistanceBox;
    QPushButton *MinusACButton;
    QPushButton *PlusACButton;
    QPushButton *EBrakeButton;
    QLabel *FailureLabel;
    QPushButton *MinusSpeedButton;
    QLineEdit *SetSpeedBox;
    QLabel *SpeedLimitLabel;
    QPushButton *OperateLeftDoorsButton;
    QLineEdit *FailureBox;
    QPushButton *AutomaticModeButton;
    QLabel *CurrentSpeedLabel;
    QLabel *TimeDistanceLabel;
    QLabel *ClockLabel;
    QLineEdit *EBrakeBox;
    QLabel *SetSpeedMPH;
    QLineEdit *DestinationDisplay;
    QLabel *TempLabel;
    QPushButton *BrakeButton;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *SWTrainControllerUI)
    {
        if (SWTrainControllerUI->objectName().isEmpty())
            SWTrainControllerUI->setObjectName(QString::fromUtf8("SWTrainControllerUI"));
        SWTrainControllerUI->resize(1058, 636);
        centralwidget = new QWidget(SWTrainControllerUI);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        PlusSpeedButton = new QPushButton(centralwidget);
        PlusSpeedButton->setObjectName(QString::fromUtf8("PlusSpeedButton"));
        PlusSpeedButton->setGeometry(QRect(110, 330, 131, 51));
        QFont font;
        font.setPointSize(35);
        PlusSpeedButton->setFont(font);
        PlusSpeedButton->setStyleSheet(QString::fromUtf8("background-color: rgb(8, 185, 8);"));
        SpeedControlLabel = new QLabel(centralwidget);
        SpeedControlLabel->setObjectName(QString::fromUtf8("SpeedControlLabel"));
        SpeedControlLabel->setGeometry(QRect(120, 380, 141, 51));
        QFont font1;
        font1.setPointSize(14);
        SpeedControlLabel->setFont(font1);
        OperateLightsButton = new QPushButton(centralwidget);
        OperateLightsButton->setObjectName(QString::fromUtf8("OperateLightsButton"));
        OperateLightsButton->setGeometry(QRect(800, 500, 151, 51));
        QFont font2;
        font2.setPointSize(15);
        OperateLightsButton->setFont(font2);
        OperateLightsButton->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 0);"));
        CurrentSpeedMPH = new QLabel(centralwidget);
        CurrentSpeedMPH->setObjectName(QString::fromUtf8("CurrentSpeedMPH"));
        CurrentSpeedMPH->setGeometry(QRect(450, 220, 61, 31));
        QFont font3;
        font3.setPointSize(18);
        CurrentSpeedMPH->setFont(font3);
        DegreesFLabel = new QLabel(centralwidget);
        DegreesFLabel->setObjectName(QString::fromUtf8("DegreesFLabel"));
        DegreesFLabel->setGeometry(QRect(580, 580, 55, 31));
        QFont font4;
        font4.setPointSize(25);
        DegreesFLabel->setFont(font4);
        EStopState = new QLabel(centralwidget);
        EStopState->setObjectName(QString::fromUtf8("EStopState"));
        EStopState->setGeometry(QRect(720, 50, 91, 31));
        QFont font5;
        font5.setPointSize(13);
        EStopState->setFont(font5);
        CommandedSpeedLabel = new QLabel(centralwidget);
        CommandedSpeedLabel->setObjectName(QString::fromUtf8("CommandedSpeedLabel"));
        CommandedSpeedLabel->setGeometry(QRect(780, 260, 171, 31));
        QFont font6;
        font6.setPointSize(16);
        CommandedSpeedLabel->setFont(font6);
        CurrentSpeedBox = new QLineEdit(centralwidget);
        CurrentSpeedBox->setObjectName(QString::fromUtf8("CurrentSpeedBox"));
        CurrentSpeedBox->setGeometry(QRect(330, 200, 113, 61));
        CurrentSpeedBox->setFont(font4);
        CurrentSpeedBox->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        CurrentSpeedBox->setReadOnly(true);
        SpeedLimitBox = new QLineEdit(centralwidget);
        SpeedLimitBox->setObjectName(QString::fromUtf8("SpeedLimitBox"));
        SpeedLimitBox->setGeometry(QRect(570, 200, 113, 61));
        SpeedLimitBox->setFont(font4);
        SpeedLimitBox->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        SpeedLimitBox->setReadOnly(true);
        ClockDisplay = new QLineEdit(centralwidget);
        ClockDisplay->setObjectName(QString::fromUtf8("ClockDisplay"));
        ClockDisplay->setGeometry(QRect(490, 10, 101, 51));
        QFont font7;
        font7.setPointSize(20);
        ClockDisplay->setFont(font7);
        ClockDisplay->setAlignment(Qt::AlignCenter);
        ClockDisplay->setReadOnly(true);
        SetSpeedLabel = new QLabel(centralwidget);
        SetSpeedLabel->setObjectName(QString::fromUtf8("SetSpeedLabel"));
        SetSpeedLabel->setGeometry(QRect(110, 260, 131, 31));
        SetSpeedLabel->setFont(font6);
        CommandedSpeedMPH = new QLabel(centralwidget);
        CommandedSpeedMPH->setObjectName(QString::fromUtf8("CommandedSpeedMPH"));
        CommandedSpeedMPH->setGeometry(QRect(920, 220, 61, 31));
        CommandedSpeedMPH->setFont(font3);
        CurrentTempBox = new QLineEdit(centralwidget);
        CurrentTempBox->setObjectName(QString::fromUtf8("CurrentTempBox"));
        CurrentTempBox->setGeometry(QRect(500, 570, 71, 51));
        CurrentTempBox->setFont(font7);
        CurrentTempBox->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        CurrentTempBox->setReadOnly(true);
        CommandedSpeedBox = new QLineEdit(centralwidget);
        CommandedSpeedBox->setObjectName(QString::fromUtf8("CommandedSpeedBox"));
        CommandedSpeedBox->setGeometry(QRect(800, 200, 113, 61));
        CommandedSpeedBox->setFont(font4);
        CommandedSpeedBox->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        CommandedSpeedBox->setReadOnly(true);
        OperateRightDoorsButton = new QPushButton(centralwidget);
        OperateRightDoorsButton->setObjectName(QString::fromUtf8("OperateRightDoorsButton"));
        OperateRightDoorsButton->setGeometry(QRect(890, 410, 161, 51));
        OperateRightDoorsButton->setFont(font5);
        OperateRightDoorsButton->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);\n"
"color: rgb(255, 255, 255);"));
        SpeedLimitMPH = new QLabel(centralwidget);
        SpeedLimitMPH->setObjectName(QString::fromUtf8("SpeedLimitMPH"));
        SpeedLimitMPH->setGeometry(QRect(690, 220, 61, 31));
        SpeedLimitMPH->setFont(font3);
        DestLabel = new QLabel(centralwidget);
        DestLabel->setObjectName(QString::fromUtf8("DestLabel"));
        DestLabel->setGeometry(QRect(20, 60, 241, 31));
        DestLabel->setFont(font2);
        TimeDistanceBox = new QTextEdit(centralwidget);
        TimeDistanceBox->setObjectName(QString::fromUtf8("TimeDistanceBox"));
        TimeDistanceBox->setGeometry(QRect(430, 410, 241, 101));
        TimeDistanceBox->setFont(font7);
        TimeDistanceBox->setReadOnly(true);
        MinusACButton = new QPushButton(centralwidget);
        MinusACButton->setObjectName(QString::fromUtf8("MinusACButton"));
        MinusACButton->setGeometry(QRect(380, 570, 81, 51));
        QFont font8;
        font8.setPointSize(37);
        MinusACButton->setFont(font8);
        MinusACButton->setStyleSheet(QString::fromUtf8("background-color: rgb(11, 15, 255);"));
        PlusACButton = new QPushButton(centralwidget);
        PlusACButton->setObjectName(QString::fromUtf8("PlusACButton"));
        PlusACButton->setGeometry(QRect(640, 570, 81, 51));
        QFont font9;
        font9.setPointSize(27);
        PlusACButton->setFont(font9);
        PlusACButton->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 168, 17);"));
        EBrakeButton = new QPushButton(centralwidget);
        EBrakeButton->setObjectName(QString::fromUtf8("EBrakeButton"));
        EBrakeButton->setGeometry(QRect(830, 10, 151, 51));
        EBrakeButton->setFont(font1);
        EBrakeButton->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 0, 0);"));
        FailureLabel = new QLabel(centralwidget);
        FailureLabel->setObjectName(QString::fromUtf8("FailureLabel"));
        FailureLabel->setGeometry(QRect(310, 50, 91, 31));
        FailureLabel->setFont(font6);
        MinusSpeedButton = new QPushButton(centralwidget);
        MinusSpeedButton->setObjectName(QString::fromUtf8("MinusSpeedButton"));
        MinusSpeedButton->setGeometry(QRect(110, 430, 131, 51));
        QFont font10;
        font10.setPointSize(51);
        MinusSpeedButton->setFont(font10);
        MinusSpeedButton->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 17, 17);"));
        SetSpeedBox = new QLineEdit(centralwidget);
        SetSpeedBox->setObjectName(QString::fromUtf8("SetSpeedBox"));
        SetSpeedBox->setGeometry(QRect(100, 200, 113, 61));
        SetSpeedBox->setFont(font4);
        SetSpeedBox->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        SetSpeedBox->setReadOnly(true);
        SpeedLimitLabel = new QLabel(centralwidget);
        SpeedLimitLabel->setObjectName(QString::fromUtf8("SpeedLimitLabel"));
        SpeedLimitLabel->setGeometry(QRect(570, 260, 151, 31));
        SpeedLimitLabel->setFont(font6);
        OperateLeftDoorsButton = new QPushButton(centralwidget);
        OperateLeftDoorsButton->setObjectName(QString::fromUtf8("OperateLeftDoorsButton"));
        OperateLeftDoorsButton->setGeometry(QRect(710, 410, 161, 51));
        OperateLeftDoorsButton->setFont(font5);
        OperateLeftDoorsButton->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);\n"
"color: rgb(255, 255, 255);"));
        FailureBox = new QLineEdit(centralwidget);
        FailureBox->setObjectName(QString::fromUtf8("FailureBox"));
        FailureBox->setGeometry(QRect(290, 10, 113, 41));
        FailureBox->setFont(font2);
        FailureBox->setReadOnly(true);
        AutomaticModeButton = new QPushButton(centralwidget);
        AutomaticModeButton->setObjectName(QString::fromUtf8("AutomaticModeButton"));
        AutomaticModeButton->setGeometry(QRect(100, 530, 151, 51));
        AutomaticModeButton->setFont(font1);
        AutomaticModeButton->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        CurrentSpeedLabel = new QLabel(centralwidget);
        CurrentSpeedLabel->setObjectName(QString::fromUtf8("CurrentSpeedLabel"));
        CurrentSpeedLabel->setGeometry(QRect(320, 260, 181, 31));
        CurrentSpeedLabel->setFont(font6);
        TimeDistanceLabel = new QLabel(centralwidget);
        TimeDistanceLabel->setObjectName(QString::fromUtf8("TimeDistanceLabel"));
        TimeDistanceLabel->setGeometry(QRect(390, 370, 321, 31));
        TimeDistanceLabel->setFont(font1);
        ClockLabel = new QLabel(centralwidget);
        ClockLabel->setObjectName(QString::fromUtf8("ClockLabel"));
        ClockLabel->setGeometry(QRect(520, 60, 61, 31));
        QFont font11;
        font11.setPointSize(10);
        ClockLabel->setFont(font11);
        EBrakeBox = new QLineEdit(centralwidget);
        EBrakeBox->setObjectName(QString::fromUtf8("EBrakeBox"));
        EBrakeBox->setGeometry(QRect(730, 10, 71, 41));
        EBrakeBox->setFont(font1);
        EBrakeBox->setReadOnly(true);
        SetSpeedMPH = new QLabel(centralwidget);
        SetSpeedMPH->setObjectName(QString::fromUtf8("SetSpeedMPH"));
        SetSpeedMPH->setGeometry(QRect(220, 220, 61, 31));
        SetSpeedMPH->setFont(font3);
        DestinationDisplay = new QLineEdit(centralwidget);
        DestinationDisplay->setObjectName(QString::fromUtf8("DestinationDisplay"));
        DestinationDisplay->setGeometry(QRect(10, 10, 231, 51));
        QFont font12;
        font12.setPointSize(19);
        DestinationDisplay->setFont(font12);
        DestinationDisplay->setReadOnly(true);
        TempLabel = new QLabel(centralwidget);
        TempLabel->setObjectName(QString::fromUtf8("TempLabel"));
        TempLabel->setGeometry(QRect(450, 520, 181, 41));
        TempLabel->setFont(font1);
        BrakeButton = new QPushButton(centralwidget);
        BrakeButton->setObjectName(QString::fromUtf8("BrakeButton"));
        BrakeButton->setGeometry(QRect(480, 300, 131, 51));
        BrakeButton->setFont(font4);
        BrakeButton->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 31, 11);"));
        SWTrainControllerUI->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(SWTrainControllerUI);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        SWTrainControllerUI->setStatusBar(statusbar);

        retranslateUi(SWTrainControllerUI);

        QMetaObject::connectSlotsByName(SWTrainControllerUI);
    } // setupUi

    void retranslateUi(QMainWindow *SWTrainControllerUI)
    {
        SWTrainControllerUI->setWindowTitle(QCoreApplication::translate("SWTrainControllerUI", "SWTrainControllerUI", nullptr));
        PlusSpeedButton->setText(QCoreApplication::translate("SWTrainControllerUI", "+", nullptr));
        SpeedControlLabel->setText(QCoreApplication::translate("SWTrainControllerUI", "Speed Control", nullptr));
        OperateLightsButton->setText(QCoreApplication::translate("SWTrainControllerUI", "Operate Lights", nullptr));
        CurrentSpeedMPH->setText(QCoreApplication::translate("SWTrainControllerUI", "MPH", nullptr));
        DegreesFLabel->setText(QCoreApplication::translate("SWTrainControllerUI", "\302\260F", nullptr));
        EStopState->setText(QCoreApplication::translate("SWTrainControllerUI", "Emergency Brake", nullptr));
        CommandedSpeedLabel->setText(QCoreApplication::translate("SWTrainControllerUI", "Commanded Speed", nullptr));
        SetSpeedLabel->setText(QCoreApplication::translate("SWTrainControllerUI", "Set Speed", nullptr));
        CommandedSpeedMPH->setText(QCoreApplication::translate("SWTrainControllerUI", "MPH", nullptr));
        OperateRightDoorsButton->setText(QCoreApplication::translate("SWTrainControllerUI", "Operate Right Doors", nullptr));
        SpeedLimitMPH->setText(QCoreApplication::translate("SWTrainControllerUI", "MPH", nullptr));
        DestLabel->setText(QCoreApplication::translate("SWTrainControllerUI", "Upcoming Destination", nullptr));
        MinusACButton->setText(QCoreApplication::translate("SWTrainControllerUI", "-", nullptr));
        PlusACButton->setText(QCoreApplication::translate("SWTrainControllerUI", "+", nullptr));
        EBrakeButton->setText(QCoreApplication::translate("SWTrainControllerUI", "Emergency Brake", nullptr));
        FailureLabel->setText(QCoreApplication::translate("SWTrainControllerUI", "Failure", nullptr));
        MinusSpeedButton->setText(QCoreApplication::translate("SWTrainControllerUI", "-", nullptr));
        SpeedLimitLabel->setText(QCoreApplication::translate("SWTrainControllerUI", "Speed Limit", nullptr));
        OperateLeftDoorsButton->setText(QCoreApplication::translate("SWTrainControllerUI", "Operate Left Doors", nullptr));
        AutomaticModeButton->setText(QCoreApplication::translate("SWTrainControllerUI", "Automatic Mode", nullptr));
        CurrentSpeedLabel->setText(QCoreApplication::translate("SWTrainControllerUI", "Current Speed", nullptr));
        TimeDistanceLabel->setText(QCoreApplication::translate("SWTrainControllerUI", "Time and Distance Required To Stop", nullptr));
        ClockLabel->setText(QCoreApplication::translate("SWTrainControllerUI", "<html><head/><body><p><span style=\" font-size:16pt;\">Clock</span></p></body></html>", nullptr));
        SetSpeedMPH->setText(QCoreApplication::translate("SWTrainControllerUI", "MPH", nullptr));
        TempLabel->setText(QCoreApplication::translate("SWTrainControllerUI", "Current Temperature", nullptr));
        BrakeButton->setText(QCoreApplication::translate("SWTrainControllerUI", "Brake", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SWTrainControllerUI: public Ui_SWTrainControllerUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SWTRAINCONTROLLERUI_H
