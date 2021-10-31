/********************************************************************************
** Form generated from reading UI file 'HomepageWindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HOMEPAGEWINDOW_H
#define UI_HOMEPAGEWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_HomepageWindow
{
public:
    QWidget *centralwidget;
    QFrame *separator;
    QFrame *separator_2;
    QFrame *separator_3;
    QStackedWidget *stackedWidget;
    QWidget *homepage;
    QLabel *systemThroughput;
    QTextEdit *throughputTextEdit;
    QComboBox *selectTrainComboBox;
    QPushButton *getStatusButton;
    QLabel *speedLabel;
    QLabel *authorityLabel;
    QLabel *locationLabel;
    QLabel *destinationLabel;
    QLabel *selectTrainLabel;
    QLineEdit *speedLineEdit;
    QLineEdit *authorityLineEdit;
    QLineEdit *locationLineEdit;
    QLineEdit *destinationLineEdit;
    QWidget *mangeTrainsPage;
    QPushButton *uploadScheduleButton;
    QTableWidget *trainTableWidget;
    QPushButton *plusButton;
    QPushButton *minusButton;
    QLineEdit *scheduleTrainLineEdit;
    QLineEdit *scheduleRouteLineEdit;
    QLineEdit *scheduleArrivalLineEdit;
    QCheckBox *autoDispatchCheckBox;
    QPushButton *dispatchButton;
    QWidget *manageTracksPage;
    QTableWidget *trackSectionTable;
    QTableWidget *switchTableWidget;
    QPushButton *addTrackSectionButton;
    QPushButton *removeTrackButton;
    QLabel *label;
    QLineEdit *trackLineEdit;
    QCheckBox *maintenanceModeCheckBox;
    QPushButton *addSwitchButton;
    QPushButton *removeSwitchButton;
    QLineEdit *switchLineEdit;
    QWidget *testInterfacePage;
    QComboBox *testTrackComboBox;
    QLabel *trackInputLabel;
    QComboBox *testTrackConditionComboBox;
    QLabel *trackInputLabel_2;
    QComboBox *testLocationComboBox;
    QComboBox *testTrainComboBox;
    QLineEdit *testSpeedLineEdit;
    QLineEdit *testAuthorityLineEdit;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QPushButton *submitTestTrackInputButton;
    QPushButton *submitTestTrainInputButton;
    QLabel *label_8;
    QLabel *label_9;
    QLineEdit *testDestinationLineEdit;
    QLabel *label_10;
    QPushButton *homepageButton;
    QPushButton *manageTrainsButton;
    QPushButton *manageTracksButton;
    QFrame *separator_4;
    QPushButton *testInterfaceButton;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *HomepageWindow)
    {
        if (HomepageWindow->objectName().isEmpty())
            HomepageWindow->setObjectName(QString::fromUtf8("HomepageWindow"));
        HomepageWindow->resize(943, 654);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(HomepageWindow->sizePolicy().hasHeightForWidth());
        HomepageWindow->setSizePolicy(sizePolicy);
        centralwidget = new QWidget(HomepageWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        separator = new QFrame(centralwidget);
        separator->setObjectName(QString::fromUtf8("separator"));
        separator->setGeometry(QRect(240, 0, 20, 21));
        separator->setFrameShape(QFrame::VLine);
        separator->setFrameShadow(QFrame::Sunken);
        separator_2 = new QFrame(centralwidget);
        separator_2->setObjectName(QString::fromUtf8("separator_2"));
        separator_2->setGeometry(QRect(350, 0, 20, 21));
        separator_2->setFrameShape(QFrame::VLine);
        separator_2->setFrameShadow(QFrame::Sunken);
        separator_3 = new QFrame(centralwidget);
        separator_3->setObjectName(QString::fromUtf8("separator_3"));
        separator_3->setGeometry(QRect(450, 0, 20, 21));
        separator_3->setFrameShape(QFrame::VLine);
        separator_3->setFrameShadow(QFrame::Sunken);
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setGeometry(QRect(-10, 70, 951, 611));
        homepage = new QWidget();
        homepage->setObjectName(QString::fromUtf8("homepage"));
        systemThroughput = new QLabel(homepage);
        systemThroughput->setObjectName(QString::fromUtf8("systemThroughput"));
        systemThroughput->setGeometry(QRect(40, 390, 231, 20));
        throughputTextEdit = new QTextEdit(homepage);
        throughputTextEdit->setObjectName(QString::fromUtf8("throughputTextEdit"));
        throughputTextEdit->setGeometry(QRect(230, 380, 41, 41));
        selectTrainComboBox = new QComboBox(homepage);
        selectTrainComboBox->setObjectName(QString::fromUtf8("selectTrainComboBox"));
        selectTrainComboBox->setGeometry(QRect(200, 20, 281, 22));
        getStatusButton = new QPushButton(homepage);
        getStatusButton->setObjectName(QString::fromUtf8("getStatusButton"));
        getStatusButton->setGeometry(QRect(510, 20, 80, 22));
        speedLabel = new QLabel(homepage);
        speedLabel->setObjectName(QString::fromUtf8("speedLabel"));
        speedLabel->setGeometry(QRect(120, 90, 47, 14));
        authorityLabel = new QLabel(homepage);
        authorityLabel->setObjectName(QString::fromUtf8("authorityLabel"));
        authorityLabel->setGeometry(QRect(120, 150, 61, 20));
        locationLabel = new QLabel(homepage);
        locationLabel->setObjectName(QString::fromUtf8("locationLabel"));
        locationLabel->setGeometry(QRect(120, 200, 47, 14));
        destinationLabel = new QLabel(homepage);
        destinationLabel->setObjectName(QString::fromUtf8("destinationLabel"));
        destinationLabel->setGeometry(QRect(120, 240, 61, 16));
        selectTrainLabel = new QLabel(homepage);
        selectTrainLabel->setObjectName(QString::fromUtf8("selectTrainLabel"));
        selectTrainLabel->setGeometry(QRect(130, 20, 61, 16));
        speedLineEdit = new QLineEdit(homepage);
        speedLineEdit->setObjectName(QString::fromUtf8("speedLineEdit"));
        speedLineEdit->setGeometry(QRect(210, 90, 231, 21));
        authorityLineEdit = new QLineEdit(homepage);
        authorityLineEdit->setObjectName(QString::fromUtf8("authorityLineEdit"));
        authorityLineEdit->setGeometry(QRect(210, 150, 231, 21));
        locationLineEdit = new QLineEdit(homepage);
        locationLineEdit->setObjectName(QString::fromUtf8("locationLineEdit"));
        locationLineEdit->setGeometry(QRect(210, 200, 231, 21));
        destinationLineEdit = new QLineEdit(homepage);
        destinationLineEdit->setObjectName(QString::fromUtf8("destinationLineEdit"));
        destinationLineEdit->setGeometry(QRect(210, 240, 231, 21));
        stackedWidget->addWidget(homepage);
        mangeTrainsPage = new QWidget();
        mangeTrainsPage->setObjectName(QString::fromUtf8("mangeTrainsPage"));
        uploadScheduleButton = new QPushButton(mangeTrainsPage);
        uploadScheduleButton->setObjectName(QString::fromUtf8("uploadScheduleButton"));
        uploadScheduleButton->setGeometry(QRect(170, 330, 121, 20));
        trainTableWidget = new QTableWidget(mangeTrainsPage);
        if (trainTableWidget->columnCount() < 5)
            trainTableWidget->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        trainTableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        trainTableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        trainTableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        trainTableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        trainTableWidget->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        trainTableWidget->setObjectName(QString::fromUtf8("trainTableWidget"));
        trainTableWidget->setGeometry(QRect(150, 30, 511, 241));
        plusButton = new QPushButton(mangeTrainsPage);
        plusButton->setObjectName(QString::fromUtf8("plusButton"));
        plusButton->setGeometry(QRect(40, 330, 41, 22));
        minusButton = new QPushButton(mangeTrainsPage);
        minusButton->setObjectName(QString::fromUtf8("minusButton"));
        minusButton->setGeometry(QRect(90, 330, 41, 22));
        scheduleTrainLineEdit = new QLineEdit(mangeTrainsPage);
        scheduleTrainLineEdit->setObjectName(QString::fromUtf8("scheduleTrainLineEdit"));
        scheduleTrainLineEdit->setGeometry(QRect(150, 290, 91, 21));
        scheduleRouteLineEdit = new QLineEdit(mangeTrainsPage);
        scheduleRouteLineEdit->setObjectName(QString::fromUtf8("scheduleRouteLineEdit"));
        scheduleRouteLineEdit->setGeometry(QRect(250, 290, 91, 21));
        scheduleArrivalLineEdit = new QLineEdit(mangeTrainsPage);
        scheduleArrivalLineEdit->setObjectName(QString::fromUtf8("scheduleArrivalLineEdit"));
        scheduleArrivalLineEdit->setGeometry(QRect(350, 290, 91, 21));
        autoDispatchCheckBox = new QCheckBox(mangeTrainsPage);
        autoDispatchCheckBox->setObjectName(QString::fromUtf8("autoDispatchCheckBox"));
        autoDispatchCheckBox->setGeometry(QRect(40, 0, 111, 20));
        dispatchButton = new QPushButton(mangeTrainsPage);
        dispatchButton->setObjectName(QString::fromUtf8("dispatchButton"));
        dispatchButton->setGeometry(QRect(360, 390, 121, 20));
        stackedWidget->addWidget(mangeTrainsPage);
        manageTracksPage = new QWidget();
        manageTracksPage->setObjectName(QString::fromUtf8("manageTracksPage"));
        trackSectionTable = new QTableWidget(manageTracksPage);
        if (trackSectionTable->columnCount() < 1)
            trackSectionTable->setColumnCount(1);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        trackSectionTable->setHorizontalHeaderItem(0, __qtablewidgetitem5);
        trackSectionTable->setObjectName(QString::fromUtf8("trackSectionTable"));
        trackSectionTable->setGeometry(QRect(70, 50, 101, 192));
        switchTableWidget = new QTableWidget(manageTracksPage);
        if (switchTableWidget->columnCount() < 1)
            switchTableWidget->setColumnCount(1);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        switchTableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem6);
        switchTableWidget->setObjectName(QString::fromUtf8("switchTableWidget"));
        switchTableWidget->setGeometry(QRect(210, 50, 91, 192));
        addTrackSectionButton = new QPushButton(manageTracksPage);
        addTrackSectionButton->setObjectName(QString::fromUtf8("addTrackSectionButton"));
        addTrackSectionButton->setGeometry(QRect(70, 280, 41, 22));
        removeTrackButton = new QPushButton(manageTracksPage);
        removeTrackButton->setObjectName(QString::fromUtf8("removeTrackButton"));
        removeTrackButton->setGeometry(QRect(130, 280, 41, 22));
        label = new QLabel(manageTracksPage);
        label->setObjectName(QString::fromUtf8("label"));
        label->setEnabled(false);
        label->setGeometry(QRect(330, -30, 851, 391));
        label->setPixmap(QPixmap(QString::fromUtf8("../../../OneDrive - University of Pittsburgh/PITT/PITT Senior Year/Semester 1/ECE 1140-Systems and Project Engineering/blue_line_small.png")));
        trackLineEdit = new QLineEdit(manageTracksPage);
        trackLineEdit->setObjectName(QString::fromUtf8("trackLineEdit"));
        trackLineEdit->setGeometry(QRect(70, 250, 101, 21));
        maintenanceModeCheckBox = new QCheckBox(manageTracksPage);
        maintenanceModeCheckBox->setObjectName(QString::fromUtf8("maintenanceModeCheckBox"));
        maintenanceModeCheckBox->setGeometry(QRect(40, 10, 121, 20));
        addSwitchButton = new QPushButton(manageTracksPage);
        addSwitchButton->setObjectName(QString::fromUtf8("addSwitchButton"));
        addSwitchButton->setEnabled(false);
        addSwitchButton->setGeometry(QRect(210, 280, 41, 22));
        removeSwitchButton = new QPushButton(manageTracksPage);
        removeSwitchButton->setObjectName(QString::fromUtf8("removeSwitchButton"));
        removeSwitchButton->setEnabled(false);
        removeSwitchButton->setGeometry(QRect(270, 280, 41, 22));
        switchLineEdit = new QLineEdit(manageTracksPage);
        switchLineEdit->setObjectName(QString::fromUtf8("switchLineEdit"));
        switchLineEdit->setEnabled(false);
        switchLineEdit->setGeometry(QRect(210, 250, 101, 21));
        stackedWidget->addWidget(manageTracksPage);
        testInterfacePage = new QWidget();
        testInterfacePage->setObjectName(QString::fromUtf8("testInterfacePage"));
        testTrackComboBox = new QComboBox(testInterfacePage);
        testTrackComboBox->setObjectName(QString::fromUtf8("testTrackComboBox"));
        testTrackComboBox->setGeometry(QRect(190, 80, 191, 22));
        trackInputLabel = new QLabel(testInterfacePage);
        trackInputLabel->setObjectName(QString::fromUtf8("trackInputLabel"));
        trackInputLabel->setGeometry(QRect(190, 40, 101, 16));
        testTrackConditionComboBox = new QComboBox(testInterfacePage);
        testTrackConditionComboBox->setObjectName(QString::fromUtf8("testTrackConditionComboBox"));
        testTrackConditionComboBox->setGeometry(QRect(190, 120, 191, 22));
        trackInputLabel_2 = new QLabel(testInterfacePage);
        trackInputLabel_2->setObjectName(QString::fromUtf8("trackInputLabel_2"));
        trackInputLabel_2->setGeometry(QRect(560, 30, 101, 16));
        testLocationComboBox = new QComboBox(testInterfacePage);
        testLocationComboBox->setObjectName(QString::fromUtf8("testLocationComboBox"));
        testLocationComboBox->setGeometry(QRect(560, 100, 191, 22));
        testTrainComboBox = new QComboBox(testInterfacePage);
        testTrainComboBox->setObjectName(QString::fromUtf8("testTrainComboBox"));
        testTrainComboBox->setGeometry(QRect(560, 60, 191, 22));
        testSpeedLineEdit = new QLineEdit(testInterfacePage);
        testSpeedLineEdit->setObjectName(QString::fromUtf8("testSpeedLineEdit"));
        testSpeedLineEdit->setGeometry(QRect(560, 140, 113, 21));
        testAuthorityLineEdit = new QLineEdit(testInterfacePage);
        testAuthorityLineEdit->setObjectName(QString::fromUtf8("testAuthorityLineEdit"));
        testAuthorityLineEdit->setGeometry(QRect(560, 180, 113, 21));
        label_4 = new QLabel(testInterfacePage);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(500, 60, 47, 14));
        label_5 = new QLabel(testInterfacePage);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(490, 110, 47, 14));
        label_6 = new QLabel(testInterfacePage);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(490, 150, 47, 14));
        label_7 = new QLabel(testInterfacePage);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(480, 180, 61, 20));
        submitTestTrackInputButton = new QPushButton(testInterfacePage);
        submitTestTrackInputButton->setObjectName(QString::fromUtf8("submitTestTrackInputButton"));
        submitTestTrackInputButton->setGeometry(QRect(240, 180, 80, 22));
        submitTestTrainInputButton = new QPushButton(testInterfacePage);
        submitTestTrainInputButton->setObjectName(QString::fromUtf8("submitTestTrainInputButton"));
        submitTestTrainInputButton->setGeometry(QRect(620, 250, 80, 22));
        label_8 = new QLabel(testInterfacePage);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(100, 80, 47, 14));
        label_9 = new QLabel(testInterfacePage);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(100, 120, 101, 20));
        testDestinationLineEdit = new QLineEdit(testInterfacePage);
        testDestinationLineEdit->setObjectName(QString::fromUtf8("testDestinationLineEdit"));
        testDestinationLineEdit->setGeometry(QRect(560, 210, 113, 21));
        label_10 = new QLabel(testInterfacePage);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(480, 210, 81, 20));
        stackedWidget->addWidget(testInterfacePage);
        homepageButton = new QPushButton(centralwidget);
        homepageButton->setObjectName(QString::fromUtf8("homepageButton"));
        homepageButton->setGeometry(QRect(150, 0, 80, 22));
        manageTrainsButton = new QPushButton(centralwidget);
        manageTrainsButton->setObjectName(QString::fromUtf8("manageTrainsButton"));
        manageTrainsButton->setGeometry(QRect(260, 0, 91, 22));
        manageTracksButton = new QPushButton(centralwidget);
        manageTracksButton->setObjectName(QString::fromUtf8("manageTracksButton"));
        manageTracksButton->setGeometry(QRect(370, 0, 101, 22));
        separator_4 = new QFrame(centralwidget);
        separator_4->setObjectName(QString::fromUtf8("separator_4"));
        separator_4->setGeometry(QRect(470, 0, 20, 21));
        separator_4->setFrameShape(QFrame::VLine);
        separator_4->setFrameShadow(QFrame::Sunken);
        testInterfaceButton = new QPushButton(centralwidget);
        testInterfaceButton->setObjectName(QString::fromUtf8("testInterfaceButton"));
        testInterfaceButton->setGeometry(QRect(490, 0, 80, 22));
        HomepageWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(HomepageWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        HomepageWindow->setStatusBar(statusbar);

        retranslateUi(HomepageWindow);

        stackedWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(HomepageWindow);
    } // setupUi

    void retranslateUi(QMainWindow *HomepageWindow)
    {
        HomepageWindow->setWindowTitle(QCoreApplication::translate("HomepageWindow", "HomepageWindow", nullptr));
        systemThroughput->setText(QCoreApplication::translate("HomepageWindow", "Throughput Blue (tickets/hour)", nullptr));
        selectTrainComboBox->setPlaceholderText(QCoreApplication::translate("HomepageWindow", "Select Train", nullptr));
        getStatusButton->setText(QCoreApplication::translate("HomepageWindow", "Go", nullptr));
        speedLabel->setText(QCoreApplication::translate("HomepageWindow", "Speed", nullptr));
        authorityLabel->setText(QCoreApplication::translate("HomepageWindow", "Authority", nullptr));
        locationLabel->setText(QCoreApplication::translate("HomepageWindow", "Location", nullptr));
        destinationLabel->setText(QCoreApplication::translate("HomepageWindow", "Destination", nullptr));
        selectTrainLabel->setText(QCoreApplication::translate("HomepageWindow", "Select Train", nullptr));
        uploadScheduleButton->setText(QCoreApplication::translate("HomepageWindow", "Upload", nullptr));
        QTableWidgetItem *___qtablewidgetitem = trainTableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("HomepageWindow", "Train", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = trainTableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("HomepageWindow", "Route", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = trainTableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("HomepageWindow", "Arrival", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = trainTableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("HomepageWindow", "Suggested Speed (km/hr)", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = trainTableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("HomepageWindow", "Authority (Blocks)", nullptr));
        plusButton->setText(QCoreApplication::translate("HomepageWindow", "+", nullptr));
        minusButton->setText(QCoreApplication::translate("HomepageWindow", "-", nullptr));
        autoDispatchCheckBox->setText(QCoreApplication::translate("HomepageWindow", "Auto-dispatch", nullptr));
        dispatchButton->setText(QCoreApplication::translate("HomepageWindow", "Dispatch", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = trackSectionTable->horizontalHeaderItem(0);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("HomepageWindow", "Closed Tracks", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = switchTableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("HomepageWindow", "Switches", nullptr));
        addTrackSectionButton->setText(QCoreApplication::translate("HomepageWindow", "+", nullptr));
        removeTrackButton->setText(QCoreApplication::translate("HomepageWindow", "-", nullptr));
        label->setText(QString());
        maintenanceModeCheckBox->setText(QCoreApplication::translate("HomepageWindow", "Maintenance Mode", nullptr));
        addSwitchButton->setText(QCoreApplication::translate("HomepageWindow", "+", nullptr));
        removeSwitchButton->setText(QCoreApplication::translate("HomepageWindow", "-", nullptr));
        testTrackComboBox->setPlaceholderText(QCoreApplication::translate("HomepageWindow", "Select Track", nullptr));
        trackInputLabel->setText(QCoreApplication::translate("HomepageWindow", "Enter Track Input", nullptr));
        testTrackConditionComboBox->setPlaceholderText(QCoreApplication::translate("HomepageWindow", "Select Track", nullptr));
        trackInputLabel_2->setText(QCoreApplication::translate("HomepageWindow", "Enter Train Input", nullptr));
        testLocationComboBox->setPlaceholderText(QCoreApplication::translate("HomepageWindow", "Select Location", nullptr));
        testTrainComboBox->setPlaceholderText(QCoreApplication::translate("HomepageWindow", "Select Train", nullptr));
        testSpeedLineEdit->setPlaceholderText(QCoreApplication::translate("HomepageWindow", "Enter Current Speed", nullptr));
        testAuthorityLineEdit->setPlaceholderText(QCoreApplication::translate("HomepageWindow", "Enter Authority", nullptr));
        label_4->setText(QCoreApplication::translate("HomepageWindow", "Train:", nullptr));
        label_5->setText(QCoreApplication::translate("HomepageWindow", "Location:", nullptr));
        label_6->setText(QCoreApplication::translate("HomepageWindow", "Speed:", nullptr));
        label_7->setText(QCoreApplication::translate("HomepageWindow", "Authority:", nullptr));
        submitTestTrackInputButton->setText(QCoreApplication::translate("HomepageWindow", "Submit", nullptr));
        submitTestTrainInputButton->setText(QCoreApplication::translate("HomepageWindow", "Submit", nullptr));
        label_8->setText(QCoreApplication::translate("HomepageWindow", "Track:", nullptr));
        label_9->setText(QCoreApplication::translate("HomepageWindow", "Condition:", nullptr));
        testDestinationLineEdit->setPlaceholderText(QCoreApplication::translate("HomepageWindow", "Enter Destination", nullptr));
        label_10->setText(QCoreApplication::translate("HomepageWindow", "Destination:", nullptr));
        homepageButton->setText(QCoreApplication::translate("HomepageWindow", "Homepage", nullptr));
        manageTrainsButton->setText(QCoreApplication::translate("HomepageWindow", "Manage Trains", nullptr));
        manageTracksButton->setText(QCoreApplication::translate("HomepageWindow", "Manage Tracks", nullptr));
        testInterfaceButton->setText(QCoreApplication::translate("HomepageWindow", "Test Interface", nullptr));
    } // retranslateUi

};

namespace Ui {
    class HomepageWindow: public Ui_HomepageWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HOMEPAGEWINDOW_H
