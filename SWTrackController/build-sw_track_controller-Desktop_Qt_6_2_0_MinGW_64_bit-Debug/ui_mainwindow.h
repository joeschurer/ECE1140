/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_6;
    QVBoxLayout *verticalLayout_6;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QComboBox *line_select;
    QComboBox *wayside_select;
    QComboBox *block_select;
    QVBoxLayout *verticalLayout_8;
    QLabel *sel_line;
    QLabel *sel_wayside;
    QLabel *sel_block;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton;
    QGridLayout *gridLayout_3;
    QLabel *switch_label;
    QLabel *light_status;
    QSpacerItem *verticalSpacer_3;
    QLabel *presence_status;
    QLabel *switch_status;
    QLabel *crossing_status;
    QLabel *heater_status;
    QSpacerItem *verticalSpacer;
    QLabel *presence_label;
    QLabel *light_label;
    QLabel *train_info_label;
    QLabel *crossing_label;
    QLabel *heater_label;
    QSpacerItem *verticalSpacer_2;
    QLabel *maintenance_label;
    QLabel *maintenance_status;
    QGridLayout *gridLayout_4;
    QLabel *commanded_status;
    QLabel *auth_status;
    QLabel *auth_label;
    QLabel *suggested_label;
    QLabel *commanded_label;
    QLabel *sugg_status;
    QSpacerItem *verticalSpacer_4;
    QSpacerItem *horizontalSpacer_2;
    QFrame *line;
    QVBoxLayout *verticalLayout_7;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *speed_test;
    QLineEdit *auth_test;
    QLineEdit *block_test;
    QPushButton *ctc_submit;
    QLabel *label_4;
    QLineEdit *maintenance_test;
    QPushButton *maintenance_submit;
    QCheckBox *maintenance_toggle;
    QLabel *label_3;
    QLineEdit *occupancy_edit;
    QPushButton *track_submit;
    QLineEdit *heater_test;
    QCheckBox *heater_state;
    QPushButton *heater_submit;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(662, 518);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        centralwidget->setStyleSheet(QString::fromUtf8("QWidget {\n"
"	background-color: #BOC4DE;\n"
"}"));
        verticalLayout_2 = new QVBoxLayout(centralwidget);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        line_select = new QComboBox(centralwidget);
        line_select->setObjectName(QString::fromUtf8("line_select"));

        verticalLayout->addWidget(line_select);

        wayside_select = new QComboBox(centralwidget);
        wayside_select->setObjectName(QString::fromUtf8("wayside_select"));

        verticalLayout->addWidget(wayside_select);

        block_select = new QComboBox(centralwidget);
        block_select->setObjectName(QString::fromUtf8("block_select"));

        verticalLayout->addWidget(block_select);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        sel_line = new QLabel(centralwidget);
        sel_line->setObjectName(QString::fromUtf8("sel_line"));
        QFont font;
        font.setPointSize(14);
        sel_line->setFont(font);

        verticalLayout_8->addWidget(sel_line);

        sel_wayside = new QLabel(centralwidget);
        sel_wayside->setObjectName(QString::fromUtf8("sel_wayside"));
        sel_wayside->setFont(font);

        verticalLayout_8->addWidget(sel_wayside);

        sel_block = new QLabel(centralwidget);
        sel_block->setObjectName(QString::fromUtf8("sel_block"));
        sel_block->setFont(font);

        verticalLayout_8->addWidget(sel_block);


        horizontalLayout->addLayout(verticalLayout_8);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout->addWidget(pushButton);


        verticalLayout_6->addLayout(horizontalLayout);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        switch_label = new QLabel(centralwidget);
        switch_label->setObjectName(QString::fromUtf8("switch_label"));
        switch_label->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(switch_label, 1, 2, 1, 1);

        light_status = new QLabel(centralwidget);
        light_status->setObjectName(QString::fromUtf8("light_status"));
        light_status->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(light_status, 3, 1, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Minimum);

        gridLayout_3->addItem(verticalSpacer_3, 0, 2, 1, 1);

        presence_status = new QLabel(centralwidget);
        presence_status->setObjectName(QString::fromUtf8("presence_status"));
        presence_status->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(presence_status, 3, 0, 1, 1);

        switch_status = new QLabel(centralwidget);
        switch_status->setObjectName(QString::fromUtf8("switch_status"));
        switch_status->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(switch_status, 3, 2, 1, 1);

        crossing_status = new QLabel(centralwidget);
        crossing_status->setObjectName(QString::fromUtf8("crossing_status"));
        crossing_status->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(crossing_status, 3, 4, 1, 1);

        heater_status = new QLabel(centralwidget);
        heater_status->setObjectName(QString::fromUtf8("heater_status"));
        heater_status->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(heater_status, 3, 3, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Minimum);

        gridLayout_3->addItem(verticalSpacer, 2, 2, 1, 1);

        presence_label = new QLabel(centralwidget);
        presence_label->setObjectName(QString::fromUtf8("presence_label"));
        presence_label->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(presence_label, 1, 0, 1, 1);

        light_label = new QLabel(centralwidget);
        light_label->setObjectName(QString::fromUtf8("light_label"));
        light_label->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(light_label, 1, 1, 1, 1);

        train_info_label = new QLabel(centralwidget);
        train_info_label->setObjectName(QString::fromUtf8("train_info_label"));
        QFont font1;
        font1.setPointSize(12);
        train_info_label->setFont(font1);

        gridLayout_3->addWidget(train_info_label, 5, 2, 1, 1);

        crossing_label = new QLabel(centralwidget);
        crossing_label->setObjectName(QString::fromUtf8("crossing_label"));
        crossing_label->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(crossing_label, 1, 4, 1, 1);

        heater_label = new QLabel(centralwidget);
        heater_label->setObjectName(QString::fromUtf8("heater_label"));
        heater_label->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(heater_label, 1, 3, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Minimum);

        gridLayout_3->addItem(verticalSpacer_2, 4, 2, 1, 1);

        maintenance_label = new QLabel(centralwidget);
        maintenance_label->setObjectName(QString::fromUtf8("maintenance_label"));

        gridLayout_3->addWidget(maintenance_label, 1, 5, 1, 1);

        maintenance_status = new QLabel(centralwidget);
        maintenance_status->setObjectName(QString::fromUtf8("maintenance_status"));

        gridLayout_3->addWidget(maintenance_status, 3, 5, 1, 1);


        verticalLayout_6->addLayout(gridLayout_3);

        gridLayout_4 = new QGridLayout();
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        commanded_status = new QLabel(centralwidget);
        commanded_status->setObjectName(QString::fromUtf8("commanded_status"));
        commanded_status->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(commanded_status, 2, 1, 1, 1);

        auth_status = new QLabel(centralwidget);
        auth_status->setObjectName(QString::fromUtf8("auth_status"));
        auth_status->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(auth_status, 2, 2, 1, 1);

        auth_label = new QLabel(centralwidget);
        auth_label->setObjectName(QString::fromUtf8("auth_label"));
        auth_label->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(auth_label, 0, 2, 1, 1);

        suggested_label = new QLabel(centralwidget);
        suggested_label->setObjectName(QString::fromUtf8("suggested_label"));
        suggested_label->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(suggested_label, 0, 0, 1, 1);

        commanded_label = new QLabel(centralwidget);
        commanded_label->setObjectName(QString::fromUtf8("commanded_label"));
        commanded_label->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(commanded_label, 0, 1, 1, 1);

        sugg_status = new QLabel(centralwidget);
        sugg_status->setObjectName(QString::fromUtf8("sugg_status"));
        sugg_status->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(sugg_status, 2, 0, 1, 1);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Minimum);

        gridLayout_4->addItem(verticalSpacer_4, 1, 1, 1, 1);


        verticalLayout_6->addLayout(gridLayout_4);


        horizontalLayout_6->addLayout(verticalLayout_6);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_2);

        line = new QFrame(centralwidget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);

        horizontalLayout_6->addWidget(line);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout_7->addWidget(label);

        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout_7->addWidget(label_2);

        speed_test = new QLineEdit(centralwidget);
        speed_test->setObjectName(QString::fromUtf8("speed_test"));

        verticalLayout_7->addWidget(speed_test);

        auth_test = new QLineEdit(centralwidget);
        auth_test->setObjectName(QString::fromUtf8("auth_test"));

        verticalLayout_7->addWidget(auth_test);

        block_test = new QLineEdit(centralwidget);
        block_test->setObjectName(QString::fromUtf8("block_test"));

        verticalLayout_7->addWidget(block_test);

        ctc_submit = new QPushButton(centralwidget);
        ctc_submit->setObjectName(QString::fromUtf8("ctc_submit"));

        verticalLayout_7->addWidget(ctc_submit);

        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        verticalLayout_7->addWidget(label_4);

        maintenance_test = new QLineEdit(centralwidget);
        maintenance_test->setObjectName(QString::fromUtf8("maintenance_test"));
        maintenance_test->setLayoutDirection(Qt::LeftToRight);

        verticalLayout_7->addWidget(maintenance_test);

        maintenance_submit = new QPushButton(centralwidget);
        maintenance_submit->setObjectName(QString::fromUtf8("maintenance_submit"));

        verticalLayout_7->addWidget(maintenance_submit);

        maintenance_toggle = new QCheckBox(centralwidget);
        maintenance_toggle->setObjectName(QString::fromUtf8("maintenance_toggle"));

        verticalLayout_7->addWidget(maintenance_toggle);

        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout_7->addWidget(label_3);

        occupancy_edit = new QLineEdit(centralwidget);
        occupancy_edit->setObjectName(QString::fromUtf8("occupancy_edit"));

        verticalLayout_7->addWidget(occupancy_edit);

        track_submit = new QPushButton(centralwidget);
        track_submit->setObjectName(QString::fromUtf8("track_submit"));

        verticalLayout_7->addWidget(track_submit);

        heater_test = new QLineEdit(centralwidget);
        heater_test->setObjectName(QString::fromUtf8("heater_test"));

        verticalLayout_7->addWidget(heater_test);

        heater_state = new QCheckBox(centralwidget);
        heater_state->setObjectName(QString::fromUtf8("heater_state"));

        verticalLayout_7->addWidget(heater_state);

        heater_submit = new QPushButton(centralwidget);
        heater_submit->setObjectName(QString::fromUtf8("heater_submit"));

        verticalLayout_7->addWidget(heater_submit);


        horizontalLayout_6->addLayout(verticalLayout_7);


        verticalLayout_2->addLayout(horizontalLayout_6);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        sel_line->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        sel_wayside->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        sel_block->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Upload Program", nullptr));
        switch_label->setText(QCoreApplication::translate("MainWindow", "Switch Position", nullptr));
        light_status->setText(QString());
        presence_status->setText(QString());
        switch_status->setText(QString());
        crossing_status->setText(QString());
        heater_status->setText(QString());
        presence_label->setText(QCoreApplication::translate("MainWindow", "Train Presence", nullptr));
        light_label->setText(QCoreApplication::translate("MainWindow", "Light", nullptr));
        train_info_label->setText(QCoreApplication::translate("MainWindow", "Train Information", nullptr));
        crossing_label->setText(QCoreApplication::translate("MainWindow", "Crossing", nullptr));
        heater_label->setText(QCoreApplication::translate("MainWindow", "Heater", nullptr));
        maintenance_label->setText(QCoreApplication::translate("MainWindow", "Maintenance", nullptr));
        maintenance_status->setText(QString());
        commanded_status->setText(QString());
        auth_status->setText(QString());
        auth_label->setText(QCoreApplication::translate("MainWindow", "Authority", nullptr));
        suggested_label->setText(QCoreApplication::translate("MainWindow", "Suggested Speed", nullptr));
        commanded_label->setText(QCoreApplication::translate("MainWindow", "Commanded Speed", nullptr));
        sugg_status->setText(QString());
        label->setText(QCoreApplication::translate("MainWindow", "Testing", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "CTC", nullptr));
        speed_test->setPlaceholderText(QCoreApplication::translate("MainWindow", "Suggested Speed", nullptr));
        auth_test->setPlaceholderText(QCoreApplication::translate("MainWindow", "Suggested Authority", nullptr));
        block_test->setPlaceholderText(QCoreApplication::translate("MainWindow", "Block", nullptr));
        ctc_submit->setText(QCoreApplication::translate("MainWindow", "Submit", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Maintenance Mode", nullptr));
        maintenance_test->setPlaceholderText(QCoreApplication::translate("MainWindow", "Block", nullptr));
        maintenance_submit->setText(QCoreApplication::translate("MainWindow", "Submit", nullptr));
        maintenance_toggle->setText(QCoreApplication::translate("MainWindow", "Toggle Switch", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Track Model", nullptr));
        occupancy_edit->setText(QString());
        occupancy_edit->setPlaceholderText(QCoreApplication::translate("MainWindow", "Train location", nullptr));
        track_submit->setText(QCoreApplication::translate("MainWindow", "Submit", nullptr));
        heater_test->setPlaceholderText(QCoreApplication::translate("MainWindow", "Block to toggle heater", nullptr));
        heater_state->setText(QCoreApplication::translate("MainWindow", "Heater State", nullptr));
        heater_submit->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
