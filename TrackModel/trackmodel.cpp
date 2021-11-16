#include "trackmodel.h"
#include "ui_mainwindow.h"
#include "layout.h"
#include "QTableWidget"
#include <QLabel>
#include <QLineEdit>
#include <QTextEdit>
#include <QPushButton>
#include "QTableWidgetItem"
#include <QHeaderView>
#include <QFont>
#include <QComboBox>
#include <QTimer>

using namespace std;

TrackModel::TrackModel(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::TrackModel)
{
    ui->setupUi(this);
    trackModelDisplay();
}

TrackModel::~TrackModel()
{
    delete ui;
}

void TrackModel::trackModelDisplay() {
    blockdata = new QTableWidget(this);
    int bn = layout.line->blocks.size();
    blockdata->setRowCount(bn);
    blockdata->setColumnCount(11);
    blockdata->topLevelWidget();

    QTableWidgetItem* blockNums[bn];
    QTableWidgetItem* grades[bn];
    QTableWidgetItem* elevations[bn];
    QTableWidgetItem* lengths[bn];
    QTableWidgetItem* speedLimits[bn];
    QTableWidgetItem* sections[bn];
    QTableWidgetItem* stations[bn];
    QTableWidgetItem* switches[bn];
    QTableWidgetItem* crossings[bn];
    QTableWidgetItem* others[bn];
    QTableWidgetItem* heat[bn];


    blockdata->setRowCount(bn);
    blockdata->setColumnCount(11);
    QTableWidgetItem* block0 = new QTableWidgetItem("Block #");
    blockdata->setHorizontalHeaderItem(0, block0);
    QTableWidgetItem* b0 = new QTableWidgetItem(("Section"));
    blockdata->setHorizontalHeaderItem(1, b0);
    QTableWidgetItem* block1 = new QTableWidgetItem(("Grade"));
    blockdata->setHorizontalHeaderItem(2, block1);
    QTableWidgetItem* block2 = new QTableWidgetItem(("Elevation"));
    blockdata->setHorizontalHeaderItem(3, block2);
    QTableWidgetItem* block3 = new QTableWidgetItem(("Length"));
    blockdata->setHorizontalHeaderItem(4, block3);
    QTableWidgetItem* block4 = new QTableWidgetItem(("Speed Limit"));
    blockdata->setHorizontalHeaderItem(5, block4);
    QTableWidgetItem* block5 = new QTableWidgetItem(("Switch"));
    blockdata->setHorizontalHeaderItem(6, block5);
    QTableWidgetItem* block6 = new QTableWidgetItem(("Station"));
    blockdata->setHorizontalHeaderItem(7, block6);
    QTableWidgetItem* block7 = new QTableWidgetItem(("Crossing"));
    blockdata->setHorizontalHeaderItem(8, block7);
    QTableWidgetItem* block9 = new QTableWidgetItem(("Other"));
    blockdata->setHorizontalHeaderItem(9, block9);
    QTableWidgetItem* block10 = new QTableWidgetItem(("Heaters"));
    blockdata->setHorizontalHeaderItem(10, block10);

    for (int i=0; i<bn; i++) {
        string n = to_string(layout.line->blocks[i].blockNum);
        QTableWidgetItem* num = new QTableWidgetItem(QString::fromStdString(n));
        blockNums[i] = num;
        blockdata->setItem(i, 0, blockNums[i]);

        string se = layout.line->blocks[i].section;
        QTableWidgetItem* sec = new QTableWidgetItem(QString::fromStdString(se));
        sections[i] = sec;
        blockdata->setItem(i, 1, sections[i]);

        string gr = to_string(layout.line->blocks[i].grade);
        QTableWidgetItem* grade = new QTableWidgetItem(QString::fromStdString(gr));
        grades[i] = grade;
        blockdata->setItem(i, 2, grades[i]);

        string el = to_string(layout.line->blocks[i].elevation);
        QTableWidgetItem* elev = new QTableWidgetItem(QString::fromStdString(el));
        elevations[i] = elev;
        blockdata->setItem(i, 3, elevations[i]);

        string le = to_string(layout.line->blocks[i].lengthFeet);
        QTableWidgetItem* len = new QTableWidgetItem(QString::fromStdString(le));
        lengths[i] = len;
        blockdata->setItem(i, 4, lengths[i]);

        string sp = to_string(layout.line->blocks[i].speedLimit);
        QTableWidgetItem* sl = new QTableWidgetItem(QString::fromStdString(sp));
        speedLimits[i] = sl;
        blockdata->setItem(i, 5, speedLimits[i]);

        string a = "";
        if (layout.line->blocks[i].hasSwitch) {
            string a1, a2, a3, a4, aa="", ab="";
            a1 = to_string(layout.line->blocks[i].swtch.block1_1);
            a2 = to_string(layout.line->blocks[i].swtch.block1_2);
            a3 = to_string(layout.line->blocks[i].swtch.block2_1);
            a4 = to_string(layout.line->blocks[i].swtch.block2_2);
            if (a1 == "-1" || a1 == "0") a1 = "Y";
            if (a2 == "-1" || a2 == "0") a2 = "Y";
            if (a3 == "-1" || a3 == "0") a3 = "Y";
            if (a4 == "-1" || a4 == "0") a4 = "Y";

            if (layout.line->blocks[i].swtch.block1_1 == layout.line->blocks[i].blockNum) {
                aa = a2;
            }
            else if (layout.line->blocks[i].swtch.block1_2 == layout.line->blocks[i].blockNum) {
                aa = a1;
            }
            if (layout.line->blocks[i].swtch.block2_1 == layout.line->blocks[i].blockNum) {
                ab = a4;
            }
            else if (layout.line->blocks[i].swtch.block2_2 == layout.line->blocks[i].blockNum) {
                ab = a3;
            }

            if (aa == "") {
                if (a1 == ab) aa = a2;
                else aa = a1;
            }
            if (ab == "") {
                if (a3 == aa) ab = a4;
                else ab = a3;
            }

            a = aa + " or " + ab + ", ";
            if (layout.line->blocks[i].swtch.point1) a += aa;
            else a += ab;
        }
        QTableWidgetItem* sw = new QTableWidgetItem(QString::fromStdString(a));
        switches[i] = sw;
        blockdata->setItem(i, 6, switches[i]);

        string s = "";
        if (layout.line->blocks[i].hasStation) {
            s = layout.line->blocks[i].station.name + ", " + to_string(layout.line->blocks[i].station.passengers);
        }
        QTableWidgetItem* sta = new QTableWidgetItem(QString::fromStdString(s));
        stations[i] = sta;
        blockdata->setItem(i, 7, stations[i]);

        if (layout.line->blocks[i].hasCrossing) {
            if (layout.line->blocks[i].crossingLights) {
                QTableWidgetItem* cl = new QTableWidgetItem("On");
                crossings[i] = cl;
                blockdata->setItem(i, 8, crossings[i]);
            }
            else {
                QTableWidgetItem* cl = new QTableWidgetItem("Off");
                crossings[i] = cl;
                blockdata->setItem(i, 8, crossings[i]);
            }
        }
        else {
            QTableWidgetItem* cl = new QTableWidgetItem("");
            crossings[i] = cl;
            blockdata->setItem(i, 8, crossings[i]);
        }

        if (layout.line->blocks[i].underground) {
            QTableWidgetItem* u = new QTableWidgetItem("Underground");
            others[i] = u;
            blockdata->setItem(i, 9, others[i]);
        }

        if (layout.line->blocks[i].heatersOn) {
            QTableWidgetItem* h = new QTableWidgetItem("On");
            heat[i] = h;
            blockdata->setItem(i, 10, heat[i]);
        }
        else {
            QTableWidgetItem* h = new QTableWidgetItem("Off");
            heat[i] = h;
            blockdata->setItem(i, 10, heat[i]);
        }

    }

    blockdata->setGeometry(10, 10, 830, 400);
    blockdata->setColumnWidth(0, 50);
    blockdata->setColumnWidth(1, 50);
    blockdata->setColumnWidth(2, 60);
    blockdata->setColumnWidth(3, 60);
    blockdata->setColumnWidth(4, 70);
    blockdata->setColumnWidth(5, 75);
    blockdata->setColumnWidth(6, 85);
    blockdata->setColumnWidth(7, 150);
    blockdata->setColumnWidth(8, 60);
    blockdata->setColumnWidth(9, 90);
    blockdata->setColumnWidth(10, 50);
    blockdata->verticalHeader()->setVisible(false);
    blockdata->show();

    traindata = new QTableWidget(this);
    int trainCount = layout.line->trains.size();
    traindata->setRowCount(trainCount);
    traindata->setColumnCount(6);
    traindata->verticalHeader()->setVisible(false);
    QTableWidgetItem* ti = new QTableWidgetItem("ID");
    traindata->setHorizontalHeaderItem(0, ti);
    QTableWidgetItem* tl = new QTableWidgetItem("Block");
    traindata->setHorizontalHeaderItem(1, tl);
    QTableWidgetItem* ts = new QTableWidgetItem("Section");
    traindata->setHorizontalHeaderItem(2, ts);
    QTableWidgetItem* tc = new QTableWidgetItem("Commanded Speed");
    traindata->setHorizontalHeaderItem(3, tc);
    QTableWidgetItem* ta = new QTableWidgetItem("Actual Speed");
    traindata->setHorizontalHeaderItem(4, ta);
    QTableWidgetItem* tp = new QTableWidgetItem("Passengers");
    traindata->setHorizontalHeaderItem(5, tp);

    QTableWidgetItem* tis[trainCount];
    QTableWidgetItem* tls[trainCount];
    QTableWidgetItem* tss[trainCount];
    QTableWidgetItem* tcs[trainCount];
    QTableWidgetItem* tas[trainCount];
    QTableWidgetItem* tps[trainCount];

    for (unsigned int i=0; i<layout.line->trains.size(); i++) {
        string tid = to_string(layout.line->trains[i].id);
        QTableWidgetItem* id = new QTableWidgetItem(QString::fromStdString(tid));
        tis[i] = id;
        traindata->setItem(i, 0, tis[i]);

        string loc;
        if (layout.line->trains[i].location == -1) {
            loc = "Yard";
        }
        else {
            loc = to_string(layout.line->trains[i].location);
        }
        QTableWidgetItem* lo = new QTableWidgetItem(QString::fromStdString(loc));
        tls[i] = lo;
        traindata->setItem(i, 1, tls[i]);

        int blockNum = stoi(to_string(layout.line->trains[i].location));
        string sec;
        if (blockNum == -1) {
            sec = "Yard";
        }
        else {
            sec = layout.line->blocks[blockNum-1].section;
        }
        QTableWidgetItem* se = new QTableWidgetItem(QString::fromStdString(sec));
        tss[i] = se;
        traindata->setItem(i, 2, tss[i]);

        string com = to_string(layout.line->trains[i].commandedSpeed);
        QTableWidgetItem* co = new QTableWidgetItem(QString::fromStdString(com));
        tcs[i] = co;
        traindata->setItem(i, 3, tcs[i]);

        string act = to_string(layout.line->trains[i].actualSpeed);
        QTableWidgetItem* ac = new QTableWidgetItem(QString::fromStdString(act));
        tas[i] = ac;
        traindata->setItem(i, 4, tas[i]);

        string pass = to_string(layout.line->trains[i].passengers);
        QTableWidgetItem* pa = new QTableWidgetItem(QString::fromStdString(pass));
        tps[i] = pa;
        traindata->setItem(i, 5, tps[i]);
    }
    traindata->setColumnWidth(0, 40);
    traindata->setColumnWidth(1, 40);
    traindata->setColumnWidth(2, 50);
    traindata->setColumnWidth(3, 130);
    traindata->setColumnWidth(4, 80);
    traindata->setColumnWidth(5, 75);
    traindata->setGeometry(10, 425, 400, 210);
    traindata->show();

    string info = "There are no faults";
    for (int i=0; i<bn; i++) {
        if (layout.line->blocks[i].trackBroken == true) {
            info = "Block " + to_string(layout.line->blocks[i].blockNum) + " has a broken track";
        }
        if (layout.line->blocks[i].circuitBroken == true) {
            info = "Block " + to_string(layout.line->blocks[i].blockNum) + " has a broken circuit";
        }
        if (layout.line->blocks[i].powerBroken == true) {
            info = "Block " + to_string(layout.line->blocks[i].blockNum) + " has a power failure";
        }
    }
    ui->faultList->setText(QString::fromStdString(info));
}

void TrackModel::timeout() {
    trackModelDisplay();
}

void TrackModel::trainUpdated(vector<string> item) {
    string ids = item[0];
    int id = stoi(ids);
    bool found = false;
    int com = stoi(item[1]);
    vector<bool> auth;
    string a = item[2];
    for (int j=0; j<a.length(); j++) {
        if (a[j] == '0') auth.push_back(false);
        else auth.push_back(true);
    }
    for (int i=0; i<layout.line->trains.size(); i++) {
        if (layout.line->trains[i].id == id && found == false) {
            layout.line->trains[i].commandedSpeed = com;
            found = true;
            layout.line->trains[i].setAuthority(auth);
        }
    }

    if (!found) {
        int star = stoi(item[3]);
        Train train(id, com, star, auth);
        layout.line->trains.push_back(train);
    }

    emit newTrainData(item);
    trackModelDisplay();
}

void TrackModel::trainMoved(int trainNum) {
    int a = layout.line->trains.size();
    int tb = -1;
    for (int i=0; i<a; i++) {
        if (layout.line->trains[i].id == trainNum) {
            layout.line->moveTrain(trainNum);
            tb = i;
        }
    }

    if (tb >= 0) {
        //Pass new block's data to train model and emit beacon if applicable
        int bn = layout.line->trains[tb].location;
        vector<int> data;
        data.push_back(layout.line->blocks[bn-1].length);
        data.push_back(layout.line->blocks[bn-1].grade);
        data.push_back(layout.line->blocks[bn-1].speedLimit);
        data.push_back(layout.line->trains[trainNum-1].commandedSpeed);
        emit newBlock(data);
        if (layout.line->blocks[bn-1].hasBeacon) {
            string e = layout.line->blocks[bn-1].beacon.name;
            if (layout.line->blocks[bn-1].beacon.left) e += ",LEFT";
            if (layout.line->blocks[bn-1].beacon.right) e+= ",RIGHT";
            emit beaconData(e);
        }
    }
    //Send new passenger count to train model
    emit passengersChanged(layout.line->trains[trainNum-1].passengers);

    //Get occupancy and send it to the wayside
    vector<int> occ;
    for (int i=0; i<layout.line->trains.size(); i++) {
        occ.push_back(i);
    }
    for (int i=0; i<layout.line->blocks.size(); i++) {
        if (layout.line->blocks[i].trackBroken || layout.line->blocks[i].circuitBroken || layout.line->blocks[i].powerBroken) {
            occ.push_back(i);
        }
    }
    emit occupancyChanged(occ);

    //Refresh display
    trackModelDisplay();
}

void TrackModel::actualSpeedChanged(QString item) {
    string words = item.toStdString();
    int a = words.find(",");
    int train = stoi(words.substr(0, a));
    words.erase(0, a+1);
    double speed = stod(words);
    int b = layout.line->trains.size();
    for (int i=0; i<b; i++) {
        if (layout.line->trains[i].id == train) {
            layout.line->trains[i].setActualSpeed(speed);
        }
    }
    trackModelDisplay();
}

void TrackModel::on_breakCircuit_textChanged(const QString &arg1)
{
    QString item = ui->breakCircuit->text();
    int block = item.toInt();
    if (block > layout.line->blocks.size()) {
        ui->breakCircuit->clear();
    }
    else {
        for (int i=0; i<layout.line->blocks.size(); i++) {
            layout.line->blocks[i].circuitBroken = false;
            layout.line->blocks[i].trackBroken = false;
            layout.line->blocks[i].powerBroken = false;
        }
        layout.line->blocks[block-1].circuitBroken = true;
    }
    ui->breakTrack->clear();
    ui->breakPower->clear();
    trackModelDisplay();
}


void TrackModel::on_breakTrack_textChanged(const QString &arg1)
{
    QString item = ui->breakTrack->text();
    int block = item.toInt();
    if (block > layout.line->blocks.size()) {
        ui->breakTrack->clear();
    }
    else {
        for (int i=0; i<layout.line->blocks.size(); i++) {
            layout.line->blocks[i].circuitBroken = false;
            layout.line->blocks[i].trackBroken = false;
            layout.line->blocks[i].powerBroken = false;
        }
        layout.line->blocks[block-1].trackBroken = true;
    }
    ui->breakCircuit->clear();
    ui->breakPower->clear();
    trackModelDisplay();
}


void TrackModel::on_breakPower_textChanged(const QString &arg1)
{
    QString item = ui->breakPower->text();
    int block = item.toInt();
    if (block > layout.line->blocks.size()) {
        ui->breakPower->clear();
    }
    else {
        for (int i=0; i<layout.line->blocks.size(); i++) {
            layout.line->blocks[i].circuitBroken = false;
            layout.line->blocks[i].trackBroken = false;
            layout.line->blocks[i].powerBroken = false;
        }
        layout.line->blocks[block-1].powerBroken = true;
    }
    ui->breakCircuit->clear();
    ui->breakTrack->clear();
    trackModelDisplay();
}

void TrackModel::toggleSwitch(int sw) {
    if (layout.line->blocks[sw-1].hasSwitch == true) {
        layout.line->blocks[sw-1].swtch.point1 = !layout.line->blocks[sw-1].swtch.point1;
    }
}