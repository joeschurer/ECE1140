#include "trackmodel.h"
#include "layout.h"
#include "QTableWidget"
#include "ui_trackmodel.h"
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
    QTableWidgetItem* dir[bn];
    QTableWidgetItem* beac[bn];


    blockdata->setRowCount(bn);
    blockdata->setColumnCount(13);
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
    QTableWidgetItem* block11 = new QTableWidgetItem(("Direction"));
    blockdata->setHorizontalHeaderItem(11, block11);
    QTableWidgetItem* block12 = new QTableWidgetItem(("Beacons"));
    blockdata->setHorizontalHeaderItem(12, block12);

    QColor red(250, 0, 0, 125);
    QColor blue(0, 0, 250, 125);
    QColor green(0, 250, 0, 125);
    QColor nor(100, 100, 100, 0);
    QColor gray(100, 100, 100, 100);
    QColor col;

    for (int i=0; i<bn; i++) {
        if (layout.line->blocks[i].circuitBroken || layout.line->blocks[i].trackBroken || layout.line->blocks[i].powerBroken) {
            col = red;
        }
        else {
            col = nor;
        }
        for (int j=0; j<layout.line->trains.size(); j++) {
            if (layout.line->trains[j].location == i+1) col = blue;
        }

        string n = to_string(layout.line->blocks[i].blockNum);
        QTableWidgetItem* num = new QTableWidgetItem(QString::fromStdString(n));
        num->setBackground(col);
        blockNums[i] = num;
        blockdata->setItem(i, 0, blockNums[i]);

        string se = layout.line->blocks[i].section;
        QTableWidgetItem* sec = new QTableWidgetItem(QString::fromStdString(se));
        sec->setBackground(col);
        sections[i] = sec;
        blockdata->setItem(i, 1, sections[i]);

        string gr = to_string(layout.line->blocks[i].grade);
        QTableWidgetItem* grade = new QTableWidgetItem(QString::fromStdString(gr));
        grade->setBackground(col);
        grades[i] = grade;
        blockdata->setItem(i, 2, grades[i]);

        string el = to_string(layout.line->blocks[i].elevation);
        QTableWidgetItem* elev = new QTableWidgetItem(QString::fromStdString(el));
        elev->setBackground(col);
        elevations[i] = elev;
        blockdata->setItem(i, 3, elevations[i]);

        string le = to_string(layout.line->blocks[i].lengthFeet);
        QTableWidgetItem* len = new QTableWidgetItem(QString::fromStdString(le));
        len->setBackground(col);
        lengths[i] = len;
        blockdata->setItem(i, 4, lengths[i]);

        string sp = to_string(layout.line->blocks[i].speedLimit);
        QTableWidgetItem* sl = new QTableWidgetItem(QString::fromStdString(sp));
        sl->setBackground(col);
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
        sw->setBackground(col);
        switches[i] = sw;
        blockdata->setItem(i, 6, switches[i]);

        string s = "";
        if (layout.line->blocks[i].hasStation) {
            layout.line->blocks[i].station.addPassengers();
            s = layout.line->blocks[i].station.name + ", " + to_string(layout.line->blocks[i].station.passengers);
        }
        QTableWidgetItem* sta = new QTableWidgetItem(QString::fromStdString(s));
        sta->setBackground(col);
        stations[i] = sta;
        blockdata->setItem(i, 7, stations[i]);

        if (layout.line->blocks[i].hasCrossing) {
            if (layout.line->blocks[i].crossingLights) {
                QTableWidgetItem* cl = new QTableWidgetItem("On");
                cl->setBackground(col);
                crossings[i] = cl;
                blockdata->setItem(i, 8, crossings[i]);
            }
            else {
                QTableWidgetItem* cl = new QTableWidgetItem("Off");
                cl->setBackground(col);
                crossings[i] = cl;
                blockdata->setItem(i, 8, crossings[i]);
            }
        }
        else {
            QTableWidgetItem* cl = new QTableWidgetItem("");
            cl->setBackground(col);
            crossings[i] = cl;
            blockdata->setItem(i, 8, crossings[i]);
        }

        if (layout.line->blocks[i].underground) {
            QTableWidgetItem* u = new QTableWidgetItem("Underground");
            u->setBackground(col);
            others[i] = u;
            blockdata->setItem(i, 9, others[i]);
        }
        else {
            QTableWidgetItem* u = new QTableWidgetItem("");
            u->setBackground(col);
            others[i] = u;
            blockdata->setItem(i, 9, others[i]);
        }

        if (layout.line->blocks[i].heatersOn) {
            QTableWidgetItem* h = new QTableWidgetItem("On");
            h->setBackground(col);
            heat[i] = h;
            blockdata->setItem(i, 10, heat[i]);
        }
        else {
            QTableWidgetItem* h = new QTableWidgetItem("Off");
            h->setBackground(col);
            heat[i] = h;
            blockdata->setItem(i, 10, heat[i]);
        }

        if (layout.line->blocks[i].inbound && layout.line->blocks[i].outbound) {
            QTableWidgetItem* d = new QTableWidgetItem("Both");
            d->setBackground(col);
            dir[i] = d;
            blockdata->setItem(i, 11, dir[i]);
        }
        else if (layout.line->blocks[i].inbound) {
            QTableWidgetItem* d = new QTableWidgetItem("Inbound");
            d->setBackground(col);
            dir[i] = d;
            blockdata->setItem(i, 11, dir[i]);
        }
        else if (layout.line->blocks[i].outbound) {
            QTableWidgetItem* d = new QTableWidgetItem("Outbound");
            d->setBackground(col);
            dir[i] = d;
            blockdata->setItem(i, 11, dir[i]);
        }
        else {
            QTableWidgetItem* d = new QTableWidgetItem("None");
            d->setBackground(col);
            dir[i] = d;
            blockdata->setItem(i, 11, dir[i]);
        }

        if (layout.line->blocks[i].hasBeacon) {
            QTableWidgetItem* b = new QTableWidgetItem(QString::fromStdString(layout.line->blocks[i].beacon.name));
            b->setBackground(col);
            beac[i] = b;
            blockdata->setItem(i, 12, beac[i]);
        }
        else {
            QTableWidgetItem* b = new QTableWidgetItem("");
            b->setBackground(col);
            beac[i] = b;
            blockdata->setItem(i, 12, beac[i]);
        }
    }

    blockdata->setGeometry(10, 10, 1030, 600);
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
    blockdata->setColumnWidth(11, 75);
    blockdata->setColumnWidth(12, 85);
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
    QTableWidgetItem* tc = new QTableWidgetItem("Com Speed");
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
        int a = layout.line->trains[i].location;
        if (a <= 0) {
            col = gray;
        }
        else if (layout.line->blocks[a-1].hasStation) {
            col = green;
        }
        else {
            col = nor;
        }

        string tid = to_string(layout.line->trains[i].id);
        QTableWidgetItem* id = new QTableWidgetItem(QString::fromStdString(tid));
        id->setBackground(col);
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
        lo->setBackground(col);
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
        se->setBackground(col);
        tss[i] = se;
        traindata->setItem(i, 2, tss[i]);

        string com = to_string(layout.line->trains[i].commandedSpeed);
        QTableWidgetItem* co = new QTableWidgetItem(QString::fromStdString(com));
        co->setBackground(col);
        tcs[i] = co;
        traindata->setItem(i, 3, tcs[i]);

        string act = to_string(layout.line->trains[i].actualSpeed);
        QTableWidgetItem* ac = new QTableWidgetItem(QString::fromStdString(act));
        ac->setBackground(col);
        tas[i] = ac;
        traindata->setItem(i, 4, tas[i]);

        string pass = to_string(layout.line->trains[i].passengers);
        QTableWidgetItem* pa = new QTableWidgetItem(QString::fromStdString(pass));
        pa->setBackground(col);
        tps[i] = pa;
        traindata->setItem(i, 5, tps[i]);
    }
    traindata->setColumnWidth(0, 40);
    traindata->setColumnWidth(1, 40);
    traindata->setColumnWidth(2, 50);
    traindata->setColumnWidth(3, 100);
    traindata->setColumnWidth(4, 80);
    traindata->setColumnWidth(5, 75);
    traindata->setGeometry(10, 625, 400, 210);
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
    QFont f;
    f.setPointSize(20);
    ui->faultList->setFont(f);
    ui->faultList->setGeometry(420, 630, 400, 50);
    ui->breakPower->setGeometry(420, 700, 125, 20);
    ui->breakTrack->setGeometry(550, 700, 125, 20);
    ui->breakCircuit->setGeometry(680, 700, 125, 20);
    ui->label_3->setGeometry(420, 740, 125, 10);
    ui->label_2->setGeometry(550, 740, 125, 10);
    ui->label->setGeometry(680, 740, 125, 10);

    string t = "Temp: " + to_string(layout.line->temp);
    ui->temp->setText(QString::fromStdString(t));
    ui->temp->setGeometry(820, 630, 100, 30);
    ui->setTemp->setGeometry(820, 660, 100, 20);
}

void TrackModel::trainUpdated(vector<string> item) {
    string ids = item[0];
    int id = stoi(ids);
    bool found = false;
    int com = stoi(item[1]);
    string a = item[2];
    for (int i=0; i<layout.line->blocks.size(); i++) {
        if (a[i] == '0') layout.line->blocks[i].authority = false;
        else layout.line->blocks[i].authority = true;
    }
    for (int i=0; i<layout.line->trains.size(); i++) {
        if (layout.line->trains[i].id == id && found == false) {
            layout.line->trains[i].commandedSpeed = com;
            found = true;
        }
    }

    if (!found) {
        int star = stoi(item[3]);
        Train train(id, com, star);
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
            layout.line->moveTrain(i+1);
            tb = i;
        }
    }

    if (tb >= 0) {
        //Pass new block's data to train model and emit beacon if applicable
        int bn = layout.line->trains[tb].location;
        vector<int> data;
        data.push_back(trainNum);
        data.push_back(layout.line->trains[tb].location);
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
        else {
            string e = "Waiting for input";
            emit beaconData(e);
        }
    }

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

void TrackModel::on_breakCircuit_returnPressed() {
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

void TrackModel::on_breakTrack_returnPressed() {
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


void TrackModel::on_breakPower_returnPressed() {
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

void TrackModel::toggleSwitch(vector<int> sw) {
    for (int i=0; i<sw.size(); i++) {
        if (layout.line->blocks[sw[i]-1].hasSwitch == true) {
            layout.line->blocks[sw[i]-1].swtch.point1 = !layout.line->blocks[sw[i]-1].swtch.point1;
        }
    }
}

void TrackModel::doorsOpen(int trainNum) {
    int a = -1;//layout.line->trains[trainNum-1].location;
    for (int i=0; i<layout.line->trains.size(); i++) {
        if (layout.line->trains[i].id == trainNum) a = i;
    }
    if (a >= 0) {
        int b = layout.line->trains[a].location;
        int pa = layout.line->trains[a].passengers;
        layout.line->trains[a].passengers = 0;
        layout.line->trains[a].addPassengers(layout.line->blocks[b-1].station.passengers);
        if (pa > 255) layout.line->blocks[b-1].station.passengers -= pa;
        else layout.line->blocks[b-1].station.passengers = 0;
        vector<int> pass;
        pass.push_back(trainNum);
        pass.push_back(layout.line->trains[a].passengers);
        emit passengersChanged(pass);
        trackModelDisplay();
    }
}

void TrackModel::toggleCrossing(int cross) {
    if (layout.line->blocks[cross-1].hasCrossing) {
        layout.line->blocks[cross-1].crossingLights = !layout.line->blocks[cross-1].crossingLights;
        trackModelDisplay();
    }
}

void TrackModel::on_setTemp_returnPressed() {
    string a = ui->setTemp->text().toStdString();
    double temp = stod(a);
    layout.line->temp = temp;
    trackModelDisplay();
}

void TrackModel::openDoors(vector<int> train) {
    int tn = train[0];
    int a = -1;
    for (int i=0; i<layout.line->trains.size(); i++) {
        if (layout.line->trains[i].id == tn) a = i;
    }
    if (a >= 0) {
        int deboard = train[1];
        int b = layout.line->trains[a].location;
        layout.line->trains[a].passengers -= deboard;
        int pa = layout.line->trains[a].passengers;
        layout.line->trains[a].addPassengers(layout.line->blocks[b-1].station.passengers);
        vector<int> pass;
        pass.push_back(tn);
        pass.push_back(layout.line->trains[a].passengers);
        emit passengersChanged(pass);
        trackModelDisplay();
    }
}
