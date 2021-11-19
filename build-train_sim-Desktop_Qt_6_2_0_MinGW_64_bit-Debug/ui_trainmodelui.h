/********************************************************************************
** Form generated from reading UI file 'trainmodelui.ui'
**
** Created by: Qt User Interface Compiler version 6.2.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TRAINMODELUI_H
#define UI_TRAINMODELUI_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TrainModelUI
{
public:
    QAction *actiontrainWeight;
    QLabel *trainWeightButton;
    QListView *listView;
    QLabel *trainLengthButton;
    QLabel *passengersOnTrain;
    QLabel *percentCapacity;
    QLabel *currentTemp;
    QLabel *currentMode;
    QFrame *line;
    QLabel *trainWeightV;
    QLabel *trainLengthValue;
    QLabel *passengersOnTrainValue;
    QLabel *percentCapacityValue;
    QLabel *currentTempValue;
    QLabel *currentModeValue;
    QTableWidget *tableWidget;
    QLabel *currentSpeedLabel;
    QLabel *currentAccelerationLabel;
    QLabel *currentPowerLabel;
    QLabel *currentSpeedValue;
    QLabel *currentAccelerationValue;
    QLabel *currentPowerValue;
    QFrame *line_2;
    QPushButton *toggleLights;
    QPushButton *inputPowerConfirm;
    QPushButton *toggleDoorLeft;
    QLineEdit *inputPowerResult;
    QLabel *currentVelocityLabel;
    QLabel *label;
    QLabel *lightStateLabel;
    QLabel *leftDoorStateLabel;
    QLabel *lightStateValue;
    QLabel *leftDoorStateValue;
    QLabel *crewMembers;
    QLabel *crewMembersValue;
    QPushButton *emergencyBrake;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QLabel *label_2;
    QLabel *rightDoorStateLabel;
    QLabel *rightDoorStateValue;
    QPushButton *toggleDoorRight;

    void setupUi(QWidget *TrainModelUI)
    {
        if (TrainModelUI->objectName().isEmpty())
            TrainModelUI->setObjectName(QString::fromUtf8("TrainModelUI"));
        TrainModelUI->resize(800, 600);
        actiontrainWeight = new QAction(TrainModelUI);
        actiontrainWeight->setObjectName(QString::fromUtf8("actiontrainWeight"));
        trainWeightButton = new QLabel(TrainModelUI);
        trainWeightButton->setObjectName(QString::fromUtf8("trainWeightButton"));
        trainWeightButton->setGeometry(QRect(20, 90, 71, 16));
        listView = new QListView(TrainModelUI);
        listView->setObjectName(QString::fromUtf8("listView"));
        listView->setGeometry(QRect(10, 80, 341, 211));
        trainLengthButton = new QLabel(TrainModelUI);
        trainLengthButton->setObjectName(QString::fromUtf8("trainLengthButton"));
        trainLengthButton->setGeometry(QRect(20, 110, 71, 16));
        passengersOnTrain = new QLabel(TrainModelUI);
        passengersOnTrain->setObjectName(QString::fromUtf8("passengersOnTrain"));
        passengersOnTrain->setGeometry(QRect(20, 150, 81, 16));
        percentCapacity = new QLabel(TrainModelUI);
        percentCapacity->setObjectName(QString::fromUtf8("percentCapacity"));
        percentCapacity->setGeometry(QRect(20, 170, 71, 16));
        currentTemp = new QLabel(TrainModelUI);
        currentTemp->setObjectName(QString::fromUtf8("currentTemp"));
        currentTemp->setGeometry(QRect(20, 190, 121, 16));
        currentMode = new QLabel(TrainModelUI);
        currentMode->setObjectName(QString::fromUtf8("currentMode"));
        currentMode->setGeometry(QRect(20, 210, 71, 16));
        line = new QFrame(TrainModelUI);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(140, 80, 21, 191));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);
        trainWeightV = new QLabel(TrainModelUI);
        trainWeightV->setObjectName(QString::fromUtf8("trainWeightV"));
        trainWeightV->setGeometry(QRect(170, 90, 71, 16));
        trainLengthValue = new QLabel(TrainModelUI);
        trainLengthValue->setObjectName(QString::fromUtf8("trainLengthValue"));
        trainLengthValue->setGeometry(QRect(170, 110, 71, 16));
        passengersOnTrainValue = new QLabel(TrainModelUI);
        passengersOnTrainValue->setObjectName(QString::fromUtf8("passengersOnTrainValue"));
        passengersOnTrainValue->setGeometry(QRect(170, 150, 81, 16));
        percentCapacityValue = new QLabel(TrainModelUI);
        percentCapacityValue->setObjectName(QString::fromUtf8("percentCapacityValue"));
        percentCapacityValue->setGeometry(QRect(170, 170, 71, 16));
        currentTempValue = new QLabel(TrainModelUI);
        currentTempValue->setObjectName(QString::fromUtf8("currentTempValue"));
        currentTempValue->setGeometry(QRect(170, 190, 51, 16));
        currentModeValue = new QLabel(TrainModelUI);
        currentModeValue->setObjectName(QString::fromUtf8("currentModeValue"));
        currentModeValue->setGeometry(QRect(170, 210, 171, 16));
        tableWidget = new QTableWidget(TrainModelUI);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(10, 330, 256, 192));
        currentSpeedLabel = new QLabel(TrainModelUI);
        currentSpeedLabel->setObjectName(QString::fromUtf8("currentSpeedLabel"));
        currentSpeedLabel->setGeometry(QRect(20, 330, 81, 16));
        currentAccelerationLabel = new QLabel(TrainModelUI);
        currentAccelerationLabel->setObjectName(QString::fromUtf8("currentAccelerationLabel"));
        currentAccelerationLabel->setGeometry(QRect(20, 360, 101, 16));
        currentPowerLabel = new QLabel(TrainModelUI);
        currentPowerLabel->setObjectName(QString::fromUtf8("currentPowerLabel"));
        currentPowerLabel->setGeometry(QRect(20, 390, 101, 16));
        currentSpeedValue = new QLabel(TrainModelUI);
        currentSpeedValue->setObjectName(QString::fromUtf8("currentSpeedValue"));
        currentSpeedValue->setGeometry(QRect(160, 330, 81, 16));
        currentAccelerationValue = new QLabel(TrainModelUI);
        currentAccelerationValue->setObjectName(QString::fromUtf8("currentAccelerationValue"));
        currentAccelerationValue->setGeometry(QRect(160, 360, 101, 16));
        currentPowerValue = new QLabel(TrainModelUI);
        currentPowerValue->setObjectName(QString::fromUtf8("currentPowerValue"));
        currentPowerValue->setGeometry(QRect(160, 390, 101, 16));
        line_2 = new QFrame(TrainModelUI);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setGeometry(QRect(140, 330, 21, 191));
        line_2->setFrameShape(QFrame::VLine);
        line_2->setFrameShadow(QFrame::Sunken);
        toggleLights = new QPushButton(TrainModelUI);
        toggleLights->setObjectName(QString::fromUtf8("toggleLights"));
        toggleLights->setGeometry(QRect(630, 110, 141, 22));
        inputPowerConfirm = new QPushButton(TrainModelUI);
        inputPowerConfirm->setObjectName(QString::fromUtf8("inputPowerConfirm"));
        inputPowerConfirm->setGeometry(QRect(630, 140, 80, 22));
        toggleDoorLeft = new QPushButton(TrainModelUI);
        toggleDoorLeft->setObjectName(QString::fromUtf8("toggleDoorLeft"));
        toggleDoorLeft->setGeometry(QRect(630, 50, 141, 22));
        inputPowerResult = new QLineEdit(TrainModelUI);
        inputPowerResult->setObjectName(QString::fromUtf8("inputPowerResult"));
        inputPowerResult->setGeometry(QRect(500, 140, 113, 21));
        currentVelocityLabel = new QLabel(TrainModelUI);
        currentVelocityLabel->setObjectName(QString::fromUtf8("currentVelocityLabel"));
        currentVelocityLabel->setGeometry(QRect(430, 140, 81, 16));
        label = new QLabel(TrainModelUI);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(570, 20, 71, 16));
        lightStateLabel = new QLabel(TrainModelUI);
        lightStateLabel->setObjectName(QString::fromUtf8("lightStateLabel"));
        lightStateLabel->setGeometry(QRect(20, 230, 71, 16));
        leftDoorStateLabel = new QLabel(TrainModelUI);
        leftDoorStateLabel->setObjectName(QString::fromUtf8("leftDoorStateLabel"));
        leftDoorStateLabel->setGeometry(QRect(20, 250, 91, 16));
        lightStateValue = new QLabel(TrainModelUI);
        lightStateValue->setObjectName(QString::fromUtf8("lightStateValue"));
        lightStateValue->setGeometry(QRect(170, 230, 71, 16));
        leftDoorStateValue = new QLabel(TrainModelUI);
        leftDoorStateValue->setObjectName(QString::fromUtf8("leftDoorStateValue"));
        leftDoorStateValue->setGeometry(QRect(170, 250, 71, 16));
        crewMembers = new QLabel(TrainModelUI);
        crewMembers->setObjectName(QString::fromUtf8("crewMembers"));
        crewMembers->setGeometry(QRect(20, 130, 101, 16));
        crewMembersValue = new QLabel(TrainModelUI);
        crewMembersValue->setObjectName(QString::fromUtf8("crewMembersValue"));
        crewMembersValue->setGeometry(QRect(170, 130, 81, 16));
        emergencyBrake = new QPushButton(TrainModelUI);
        emergencyBrake->setObjectName(QString::fromUtf8("emergencyBrake"));
        emergencyBrake->setGeometry(QRect(520, 340, 111, 22));
        pushButton_2 = new QPushButton(TrainModelUI);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(370, 500, 131, 22));
        pushButton_2->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 0)"));
        pushButton_3 = new QPushButton(TrainModelUI);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(520, 500, 111, 22));
        pushButton_3->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 85, 0)"));
        pushButton_4 = new QPushButton(TrainModelUI);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(650, 500, 111, 22));
        pushButton_4->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 0, 0)"));
        label_2 = new QLabel(TrainModelUI);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(540, 450, 81, 16));
        rightDoorStateLabel = new QLabel(TrainModelUI);
        rightDoorStateLabel->setObjectName(QString::fromUtf8("rightDoorStateLabel"));
        rightDoorStateLabel->setGeometry(QRect(20, 270, 101, 16));
        rightDoorStateValue = new QLabel(TrainModelUI);
        rightDoorStateValue->setObjectName(QString::fromUtf8("rightDoorStateValue"));
        rightDoorStateValue->setGeometry(QRect(170, 270, 71, 16));
        toggleDoorRight = new QPushButton(TrainModelUI);
        toggleDoorRight->setObjectName(QString::fromUtf8("toggleDoorRight"));
        toggleDoorRight->setGeometry(QRect(630, 80, 141, 22));
        listView->raise();
        trainWeightButton->raise();
        trainLengthButton->raise();
        passengersOnTrain->raise();
        percentCapacity->raise();
        currentTemp->raise();
        currentMode->raise();
        line->raise();
        trainWeightV->raise();
        trainLengthValue->raise();
        passengersOnTrainValue->raise();
        percentCapacityValue->raise();
        currentTempValue->raise();
        currentModeValue->raise();
        tableWidget->raise();
        currentSpeedLabel->raise();
        currentAccelerationLabel->raise();
        currentPowerLabel->raise();
        currentSpeedValue->raise();
        currentAccelerationValue->raise();
        currentPowerValue->raise();
        line_2->raise();
        toggleLights->raise();
        inputPowerConfirm->raise();
        toggleDoorLeft->raise();
        inputPowerResult->raise();
        currentVelocityLabel->raise();
        label->raise();
        lightStateLabel->raise();
        leftDoorStateLabel->raise();
        lightStateValue->raise();
        leftDoorStateValue->raise();
        crewMembers->raise();
        crewMembersValue->raise();
        emergencyBrake->raise();
        pushButton_2->raise();
        pushButton_3->raise();
        pushButton_4->raise();
        label_2->raise();
        rightDoorStateLabel->raise();
        rightDoorStateValue->raise();
        toggleDoorRight->raise();

        retranslateUi(TrainModelUI);

        QMetaObject::connectSlotsByName(TrainModelUI);
    } // setupUi

    void retranslateUi(QWidget *TrainModelUI)
    {
        TrainModelUI->setWindowTitle(QCoreApplication::translate("TrainModelUI", "TrainModelUI", nullptr));
        actiontrainWeight->setText(QCoreApplication::translate("TrainModelUI", "trainWeight", nullptr));
        trainWeightButton->setText(QCoreApplication::translate("TrainModelUI", "Train Weight", nullptr));
        trainLengthButton->setText(QCoreApplication::translate("TrainModelUI", "Train Length", nullptr));
        passengersOnTrain->setText(QCoreApplication::translate("TrainModelUI", "# of Passengers", nullptr));
        percentCapacity->setText(QCoreApplication::translate("TrainModelUI", "% Capacity", nullptr));
        currentTemp->setText(QCoreApplication::translate("TrainModelUI", "Current Temperature (F)", nullptr));
        currentMode->setText(QCoreApplication::translate("TrainModelUI", "Current Mode", nullptr));
        trainWeightV->setText(QCoreApplication::translate("TrainModelUI", "0", nullptr));
        trainLengthValue->setText(QCoreApplication::translate("TrainModelUI", "0", nullptr));
        passengersOnTrainValue->setText(QCoreApplication::translate("TrainModelUI", "0", nullptr));
        percentCapacityValue->setText(QCoreApplication::translate("TrainModelUI", "0", nullptr));
        currentTempValue->setText(QCoreApplication::translate("TrainModelUI", "75F", nullptr));
        currentModeValue->setText(QCoreApplication::translate("TrainModelUI", "Standard", nullptr));
        currentSpeedLabel->setText(QCoreApplication::translate("TrainModelUI", "Current Speed", nullptr));
        currentAccelerationLabel->setText(QCoreApplication::translate("TrainModelUI", "Current Acceleration", nullptr));
        currentPowerLabel->setText(QCoreApplication::translate("TrainModelUI", "Current Power Draw", nullptr));
        currentSpeedValue->setText(QCoreApplication::translate("TrainModelUI", "0 m/s", nullptr));
        currentAccelerationValue->setText(QCoreApplication::translate("TrainModelUI", "0 m/s/s", nullptr));
        currentPowerValue->setText(QCoreApplication::translate("TrainModelUI", "0V", nullptr));
        toggleLights->setText(QCoreApplication::translate("TrainModelUI", "Turn On/Off Train Lights", nullptr));
        inputPowerConfirm->setText(QCoreApplication::translate("TrainModelUI", "Confirm", nullptr));
        toggleDoorLeft->setText(QCoreApplication::translate("TrainModelUI", "Open/Close Left Doors", nullptr));
        currentVelocityLabel->setText(QCoreApplication::translate("TrainModelUI", "Input Power", nullptr));
        label->setText(QCoreApplication::translate("TrainModelUI", "Test Module", nullptr));
        lightStateLabel->setText(QCoreApplication::translate("TrainModelUI", "Light State", nullptr));
        leftDoorStateLabel->setText(QCoreApplication::translate("TrainModelUI", "Left Door State", nullptr));
        lightStateValue->setText(QCoreApplication::translate("TrainModelUI", "OFF", nullptr));
        leftDoorStateValue->setText(QCoreApplication::translate("TrainModelUI", "CLOSED", nullptr));
        crewMembers->setText(QCoreApplication::translate("TrainModelUI", "# of Crew Members", nullptr));
        crewMembersValue->setText(QCoreApplication::translate("TrainModelUI", "0", nullptr));
        emergencyBrake->setText(QCoreApplication::translate("TrainModelUI", "Emergency Brake", nullptr));
        pushButton_2->setText(QCoreApplication::translate("TrainModelUI", "Signal Pickup Failure", nullptr));
        pushButton_3->setText(QCoreApplication::translate("TrainModelUI", "Power Failure", nullptr));
        pushButton_4->setText(QCoreApplication::translate("TrainModelUI", "Train Engine Failure", nullptr));
        label_2->setText(QCoreApplication::translate("TrainModelUI", "Failure Modes", nullptr));
        rightDoorStateLabel->setText(QCoreApplication::translate("TrainModelUI", "Right Door State", nullptr));
        rightDoorStateValue->setText(QCoreApplication::translate("TrainModelUI", "CLOSED", nullptr));
        toggleDoorRight->setText(QCoreApplication::translate("TrainModelUI", "Open/Close Right Doors", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TrainModelUI: public Ui_TrainModelUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRAINMODELUI_H
