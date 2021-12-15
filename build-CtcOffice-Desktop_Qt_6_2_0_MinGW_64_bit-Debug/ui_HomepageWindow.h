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
    QLineEdit *greenThroughputLineEdit;
    QLabel *label_3;
    QLineEdit *redThroughputLineEdit;
    QTableWidget *occupancyTableWidget;
    QTextEdit *trackFailureAlertTextEdit;
    QLineEdit *totalOccupancyLineEdit;
    QLabel *label_11;
    QLabel *label_12;
    QLineEdit *dispatchedTrainsCountLineEdit;
    QLineEdit *timeHourLineEdit;
    QLineEdit *timeMinuteLineEdit;
    QLabel *label_13;
    QLabel *label_14;
    QLabel *label_19;
    QLineEdit *trackLineLineEdit;
    QPushButton *oneXButton;
    QPushButton *tenXButton;
    QPushButton *startSimulationButton;
    QWidget *mangeTrainsPage;
    QPushButton *uploadScheduleButton;
    QTableWidget *trainTableWidget;
    QPushButton *plusButton;
    QLineEdit *scheduleTrainLineEdit;
    QLineEdit *scheduleDestinationLineEdit;
    QLineEdit *scheduleArrivalLineEdit;
    QCheckBox *autoDispatchCheckBox;
    QLabel *label_2;
    QPushButton *dispatchButton;
    QLabel *label_17;
    QLabel *label_18;
    QLineEdit *timeMinuteLineEdit_3;
    QLineEdit *timeHourLineEdit_3;
    QWidget *manageTracksPage;
    QTableWidget *trackSectionTable;
    QTableWidget *switchTableWidget;
    QPushButton *addTrackSectionButton;
    QPushButton *removeTrackButton;
    QLabel *label;
    QLineEdit *trackLineEdit;
    QCheckBox *maintenanceModeCheckBox;
    QPushButton *addSwitchButton;
    QLineEdit *switchLineEdit;
    QLabel *label_15;
    QLabel *label_16;
    QLineEdit *timeMinuteLineEdit_2;
    QLineEdit *timeHourLineEdit_2;
    QWidget *testInterfacePage;
    QPushButton *submitBlockButton;
    QLineEdit *startBlockLineEdit;
    QLineEdit *destinationBlockLineEdit;
    QLineEdit *testOccupancyLineEdit;
    QLabel *label_4;
    QPushButton *submitTestOccupancyPushButton;
    QLabel *label_5;
    QLineEdit *testTicketsSoldLineEdit;
    QPushButton *SubmitTestTicketsSoldButton;
    QLabel *label_6;
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
        HomepageWindow->resize(943, 525);
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
        stackedWidget->setGeometry(QRect(-20, 50, 961, 631));
        homepage = new QWidget();
        homepage->setObjectName(QString::fromUtf8("homepage"));
        systemThroughput = new QLabel(homepage);
        systemThroughput->setObjectName(QString::fromUtf8("systemThroughput"));
        systemThroughput->setGeometry(QRect(30, 380, 231, 20));
        greenThroughputLineEdit = new QLineEdit(homepage);
        greenThroughputLineEdit->setObjectName(QString::fromUtf8("greenThroughputLineEdit"));
        greenThroughputLineEdit->setGeometry(QRect(290, 380, 113, 21));
        label_3 = new QLabel(homepage);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(30, 420, 241, 16));
        redThroughputLineEdit = new QLineEdit(homepage);
        redThroughputLineEdit->setObjectName(QString::fromUtf8("redThroughputLineEdit"));
        redThroughputLineEdit->setGeometry(QRect(290, 420, 113, 21));
        occupancyTableWidget = new QTableWidget(homepage);
        if (occupancyTableWidget->columnCount() < 2)
            occupancyTableWidget->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        occupancyTableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        occupancyTableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        occupancyTableWidget->setObjectName(QString::fromUtf8("occupancyTableWidget"));
        occupancyTableWidget->setGeometry(QRect(280, 20, 371, 201));
        trackFailureAlertTextEdit = new QTextEdit(homepage);
        trackFailureAlertTextEdit->setObjectName(QString::fromUtf8("trackFailureAlertTextEdit"));
        trackFailureAlertTextEdit->setGeometry(QRect(690, 20, 261, 71));
        totalOccupancyLineEdit = new QLineEdit(homepage);
        totalOccupancyLineEdit->setObjectName(QString::fromUtf8("totalOccupancyLineEdit"));
        totalOccupancyLineEdit->setGeometry(QRect(540, 230, 113, 21));
        label_11 = new QLabel(homepage);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(340, 230, 101, 20));
        label_12 = new QLabel(homepage);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(340, 260, 151, 16));
        dispatchedTrainsCountLineEdit = new QLineEdit(homepage);
        dispatchedTrainsCountLineEdit->setObjectName(QString::fromUtf8("dispatchedTrainsCountLineEdit"));
        dispatchedTrainsCountLineEdit->setGeometry(QRect(540, 260, 113, 21));
        timeHourLineEdit = new QLineEdit(homepage);
        timeHourLineEdit->setObjectName(QString::fromUtf8("timeHourLineEdit"));
        timeHourLineEdit->setGeometry(QRect(80, 30, 61, 21));
        timeMinuteLineEdit = new QLineEdit(homepage);
        timeMinuteLineEdit->setObjectName(QString::fromUtf8("timeMinuteLineEdit"));
        timeMinuteLineEdit->setGeometry(QRect(170, 30, 61, 21));
        label_13 = new QLabel(homepage);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(150, 20, 41, 41));
        QFont font;
        font.setPointSize(19);
        font.setBold(true);
        label_13->setFont(font);
        label_14 = new QLabel(homepage);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setGeometry(QRect(30, 30, 47, 14));
        label_19 = new QLabel(homepage);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        label_19->setGeometry(QRect(30, 80, 81, 16));
        trackLineLineEdit = new QLineEdit(homepage);
        trackLineLineEdit->setObjectName(QString::fromUtf8("trackLineLineEdit"));
        trackLineLineEdit->setGeometry(QRect(150, 80, 113, 21));
        trackLineLineEdit->setStyleSheet(QString::fromUtf8(""));
        oneXButton = new QPushButton(homepage);
        oneXButton->setObjectName(QString::fromUtf8("oneXButton"));
        oneXButton->setGeometry(QRect(30, 160, 101, 17));
        tenXButton = new QPushButton(homepage);
        tenXButton->setObjectName(QString::fromUtf8("tenXButton"));
        tenXButton->setGeometry(QRect(150, 160, 111, 17));
        startSimulationButton = new QPushButton(homepage);
        startSimulationButton->setObjectName(QString::fromUtf8("startSimulationButton"));
        startSimulationButton->setGeometry(QRect(80, 200, 121, 17));
        stackedWidget->addWidget(homepage);
        mangeTrainsPage = new QWidget();
        mangeTrainsPage->setObjectName(QString::fromUtf8("mangeTrainsPage"));
        uploadScheduleButton = new QPushButton(mangeTrainsPage);
        uploadScheduleButton->setObjectName(QString::fromUtf8("uploadScheduleButton"));
        uploadScheduleButton->setGeometry(QRect(510, 340, 121, 20));
        trainTableWidget = new QTableWidget(mangeTrainsPage);
        if (trainTableWidget->columnCount() < 5)
            trainTableWidget->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        trainTableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        trainTableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem3);
        QFont font1;
        font1.setPointSize(9);
        font1.setKerning(true);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        __qtablewidgetitem4->setFont(font1);
        trainTableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        trainTableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        trainTableWidget->setHorizontalHeaderItem(4, __qtablewidgetitem6);
        trainTableWidget->setObjectName(QString::fromUtf8("trainTableWidget"));
        trainTableWidget->setGeometry(QRect(290, 30, 501, 241));
        plusButton = new QPushButton(mangeTrainsPage);
        plusButton->setObjectName(QString::fromUtf8("plusButton"));
        plusButton->setGeometry(QRect(750, 280, 41, 22));
        scheduleTrainLineEdit = new QLineEdit(mangeTrainsPage);
        scheduleTrainLineEdit->setObjectName(QString::fromUtf8("scheduleTrainLineEdit"));
        scheduleTrainLineEdit->setGeometry(QRect(300, 280, 91, 21));
        scheduleDestinationLineEdit = new QLineEdit(mangeTrainsPage);
        scheduleDestinationLineEdit->setObjectName(QString::fromUtf8("scheduleDestinationLineEdit"));
        scheduleDestinationLineEdit->setGeometry(QRect(410, 280, 91, 21));
        scheduleArrivalLineEdit = new QLineEdit(mangeTrainsPage);
        scheduleArrivalLineEdit->setObjectName(QString::fromUtf8("scheduleArrivalLineEdit"));
        scheduleArrivalLineEdit->setGeometry(QRect(510, 280, 101, 21));
        autoDispatchCheckBox = new QCheckBox(mangeTrainsPage);
        autoDispatchCheckBox->setObjectName(QString::fromUtf8("autoDispatchCheckBox"));
        autoDispatchCheckBox->setGeometry(QRect(40, 0, 111, 20));
        label_2 = new QLabel(mangeTrainsPage);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(130, 290, 47, 14));
        dispatchButton = new QPushButton(mangeTrainsPage);
        dispatchButton->setObjectName(QString::fromUtf8("dispatchButton"));
        dispatchButton->setGeometry(QRect(300, 340, 80, 22));
        label_17 = new QLabel(mangeTrainsPage);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setGeometry(QRect(40, 50, 47, 14));
        label_18 = new QLabel(mangeTrainsPage);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setGeometry(QRect(160, 40, 41, 41));
        label_18->setFont(font);
        timeMinuteLineEdit_3 = new QLineEdit(mangeTrainsPage);
        timeMinuteLineEdit_3->setObjectName(QString::fromUtf8("timeMinuteLineEdit_3"));
        timeMinuteLineEdit_3->setGeometry(QRect(180, 50, 61, 21));
        timeHourLineEdit_3 = new QLineEdit(mangeTrainsPage);
        timeHourLineEdit_3->setObjectName(QString::fromUtf8("timeHourLineEdit_3"));
        timeHourLineEdit_3->setGeometry(QRect(90, 50, 61, 21));
        stackedWidget->addWidget(mangeTrainsPage);
        manageTracksPage = new QWidget();
        manageTracksPage->setObjectName(QString::fromUtf8("manageTracksPage"));
        trackSectionTable = new QTableWidget(manageTracksPage);
        if (trackSectionTable->columnCount() < 1)
            trackSectionTable->setColumnCount(1);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        trackSectionTable->setHorizontalHeaderItem(0, __qtablewidgetitem7);
        trackSectionTable->setObjectName(QString::fromUtf8("trackSectionTable"));
        trackSectionTable->setGeometry(QRect(320, 60, 101, 192));
        switchTableWidget = new QTableWidget(manageTracksPage);
        if (switchTableWidget->columnCount() < 1)
            switchTableWidget->setColumnCount(1);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        switchTableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem8);
        switchTableWidget->setObjectName(QString::fromUtf8("switchTableWidget"));
        switchTableWidget->setGeometry(QRect(470, 60, 91, 192));
        addTrackSectionButton = new QPushButton(manageTracksPage);
        addTrackSectionButton->setObjectName(QString::fromUtf8("addTrackSectionButton"));
        addTrackSectionButton->setGeometry(QRect(320, 290, 41, 22));
        removeTrackButton = new QPushButton(manageTracksPage);
        removeTrackButton->setObjectName(QString::fromUtf8("removeTrackButton"));
        removeTrackButton->setGeometry(QRect(380, 290, 41, 22));
        label = new QLabel(manageTracksPage);
        label->setObjectName(QString::fromUtf8("label"));
        label->setEnabled(false);
        label->setGeometry(QRect(630, -160, 1021, 761));
        label->setPixmap(QPixmap(QString::fromUtf8("green_and_red_track_small2.png")));
        trackLineEdit = new QLineEdit(manageTracksPage);
        trackLineEdit->setObjectName(QString::fromUtf8("trackLineEdit"));
        trackLineEdit->setGeometry(QRect(320, 260, 101, 21));
        maintenanceModeCheckBox = new QCheckBox(manageTracksPage);
        maintenanceModeCheckBox->setObjectName(QString::fromUtf8("maintenanceModeCheckBox"));
        maintenanceModeCheckBox->setGeometry(QRect(390, 10, 121, 20));
        addSwitchButton = new QPushButton(manageTracksPage);
        addSwitchButton->setObjectName(QString::fromUtf8("addSwitchButton"));
        addSwitchButton->setEnabled(false);
        addSwitchButton->setGeometry(QRect(470, 290, 41, 22));
        switchLineEdit = new QLineEdit(manageTracksPage);
        switchLineEdit->setObjectName(QString::fromUtf8("switchLineEdit"));
        switchLineEdit->setEnabled(false);
        switchLineEdit->setGeometry(QRect(470, 260, 101, 21));
        label_15 = new QLabel(manageTracksPage);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setGeometry(QRect(30, 60, 47, 14));
        label_16 = new QLabel(manageTracksPage);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setGeometry(QRect(150, 50, 41, 41));
        label_16->setFont(font);
        timeMinuteLineEdit_2 = new QLineEdit(manageTracksPage);
        timeMinuteLineEdit_2->setObjectName(QString::fromUtf8("timeMinuteLineEdit_2"));
        timeMinuteLineEdit_2->setGeometry(QRect(170, 60, 61, 21));
        timeHourLineEdit_2 = new QLineEdit(manageTracksPage);
        timeHourLineEdit_2->setObjectName(QString::fromUtf8("timeHourLineEdit_2"));
        timeHourLineEdit_2->setGeometry(QRect(80, 60, 61, 21));
        stackedWidget->addWidget(manageTracksPage);
        testInterfacePage = new QWidget();
        testInterfacePage->setObjectName(QString::fromUtf8("testInterfacePage"));
        submitBlockButton = new QPushButton(testInterfacePage);
        submitBlockButton->setObjectName(QString::fromUtf8("submitBlockButton"));
        submitBlockButton->setGeometry(QRect(80, 320, 80, 22));
        startBlockLineEdit = new QLineEdit(testInterfacePage);
        startBlockLineEdit->setObjectName(QString::fromUtf8("startBlockLineEdit"));
        startBlockLineEdit->setGeometry(QRect(30, 270, 113, 21));
        destinationBlockLineEdit = new QLineEdit(testInterfacePage);
        destinationBlockLineEdit->setObjectName(QString::fromUtf8("destinationBlockLineEdit"));
        destinationBlockLineEdit->setGeometry(QRect(170, 270, 113, 21));
        testOccupancyLineEdit = new QLineEdit(testInterfacePage);
        testOccupancyLineEdit->setObjectName(QString::fromUtf8("testOccupancyLineEdit"));
        testOccupancyLineEdit->setGeometry(QRect(130, 40, 171, 21));
        label_4 = new QLabel(testInterfacePage);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(30, 40, 71, 16));
        submitTestOccupancyPushButton = new QPushButton(testInterfacePage);
        submitTestOccupancyPushButton->setObjectName(QString::fromUtf8("submitTestOccupancyPushButton"));
        submitTestOccupancyPushButton->setGeometry(QRect(170, 70, 80, 22));
        label_5 = new QLabel(testInterfacePage);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(30, 120, 101, 16));
        testTicketsSoldLineEdit = new QLineEdit(testInterfacePage);
        testTicketsSoldLineEdit->setObjectName(QString::fromUtf8("testTicketsSoldLineEdit"));
        testTicketsSoldLineEdit->setGeometry(QRect(130, 120, 113, 21));
        SubmitTestTicketsSoldButton = new QPushButton(testInterfacePage);
        SubmitTestTicketsSoldButton->setObjectName(QString::fromUtf8("SubmitTestTicketsSoldButton"));
        SubmitTestTicketsSoldButton->setGeometry(QRect(150, 150, 80, 22));
        label_6 = new QLabel(testInterfacePage);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(30, 250, 191, 16));
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

        stackedWidget->setCurrentIndex(3);


        QMetaObject::connectSlotsByName(HomepageWindow);
    } // setupUi

    void retranslateUi(QMainWindow *HomepageWindow)
    {
        HomepageWindow->setWindowTitle(QCoreApplication::translate("HomepageWindow", "HomepageWindow", nullptr));
        systemThroughput->setText(QCoreApplication::translate("HomepageWindow", "Throughput Green (tickets/hour)", nullptr));
        label_3->setText(QCoreApplication::translate("HomepageWindow", "Throughput Red (tickets/Hour)", nullptr));
        QTableWidgetItem *___qtablewidgetitem = occupancyTableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("HomepageWindow", "Train", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = occupancyTableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("HomepageWindow", "Location", nullptr));
        trackFailureAlertTextEdit->setPlaceholderText(QString());
        label_11->setText(QCoreApplication::translate("HomepageWindow", "Total Occupancies: ", nullptr));
        label_12->setText(QCoreApplication::translate("HomepageWindow", "Number of Dispatched Trains", nullptr));
        label_13->setText(QCoreApplication::translate("HomepageWindow", ":", nullptr));
        label_14->setText(QCoreApplication::translate("HomepageWindow", "Time: ", nullptr));
        label_19->setText(QCoreApplication::translate("HomepageWindow", "Current Line:", nullptr));
        trackLineLineEdit->setText(QString());
        oneXButton->setText(QCoreApplication::translate("HomepageWindow", "Run at 1x Speed", nullptr));
        tenXButton->setText(QCoreApplication::translate("HomepageWindow", "Run at 10x Speed", nullptr));
        startSimulationButton->setText(QCoreApplication::translate("HomepageWindow", "Start/Stop Simulation", nullptr));
        uploadScheduleButton->setText(QCoreApplication::translate("HomepageWindow", "Upload Schedule", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = trainTableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("HomepageWindow", "Train", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = trainTableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("HomepageWindow", "Destination", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = trainTableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("HomepageWindow", "Arrival Time", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = trainTableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("HomepageWindow", "Departure Time", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = trainTableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("HomepageWindow", "S. Speed(mph)", nullptr));
        plusButton->setText(QCoreApplication::translate("HomepageWindow", "+", nullptr));
        scheduleTrainLineEdit->setPlaceholderText(QCoreApplication::translate("HomepageWindow", "Enter Train #", nullptr));
        scheduleDestinationLineEdit->setPlaceholderText(QCoreApplication::translate("HomepageWindow", "Enter Destination", nullptr));
        scheduleArrivalLineEdit->setText(QString());
        scheduleArrivalLineEdit->setPlaceholderText(QCoreApplication::translate("HomepageWindow", "Enter Arrival Time", nullptr));
        autoDispatchCheckBox->setText(QCoreApplication::translate("HomepageWindow", "Auto-dispatch", nullptr));
        label_2->setText(QString());
        dispatchButton->setText(QCoreApplication::translate("HomepageWindow", "Dispatch", nullptr));
        label_17->setText(QCoreApplication::translate("HomepageWindow", "Time: ", nullptr));
        label_18->setText(QCoreApplication::translate("HomepageWindow", ":", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = trackSectionTable->horizontalHeaderItem(0);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("HomepageWindow", "Closed Tracks", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = switchTableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem8->setText(QCoreApplication::translate("HomepageWindow", "Switches", nullptr));
        addTrackSectionButton->setText(QCoreApplication::translate("HomepageWindow", "+", nullptr));
        removeTrackButton->setText(QCoreApplication::translate("HomepageWindow", "-", nullptr));
        label->setText(QString());
        maintenanceModeCheckBox->setText(QCoreApplication::translate("HomepageWindow", "Maintenance Mode", nullptr));
        addSwitchButton->setText(QCoreApplication::translate("HomepageWindow", "+", nullptr));
        label_15->setText(QCoreApplication::translate("HomepageWindow", "Time: ", nullptr));
        label_16->setText(QCoreApplication::translate("HomepageWindow", ":", nullptr));
        submitBlockButton->setText(QCoreApplication::translate("HomepageWindow", "submit", nullptr));
        startBlockLineEdit->setPlaceholderText(QCoreApplication::translate("HomepageWindow", "Enter Starting Block", nullptr));
        destinationBlockLineEdit->setPlaceholderText(QCoreApplication::translate("HomepageWindow", "Enter Destination Block", nullptr));
        testOccupancyLineEdit->setPlaceholderText(QCoreApplication::translate("HomepageWindow", "Enter CSV of occupied blocks", nullptr));
        label_4->setText(QCoreApplication::translate("HomepageWindow", "Occupancy:", nullptr));
        submitTestOccupancyPushButton->setText(QCoreApplication::translate("HomepageWindow", "Submit", nullptr));
        label_5->setText(QCoreApplication::translate("HomepageWindow", "Enter Tickets Sold:", nullptr));
        testTicketsSoldLineEdit->setPlaceholderText(QCoreApplication::translate("HomepageWindow", "Enter tickets sold", nullptr));
        SubmitTestTicketsSoldButton->setText(QCoreApplication::translate("HomepageWindow", "Submit", nullptr));
        label_6->setText(QCoreApplication::translate("HomepageWindow", "Print Route to Console: ", nullptr));
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
