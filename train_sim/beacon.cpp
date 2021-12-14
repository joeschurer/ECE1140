#include "beacon.h"
#include "ui_beacon.h"

using namespace std;

Beacon::Beacon(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Beacon)
{
    ui->setupUi(this);
}

Beacon::~Beacon()
{
    delete ui;
}

void Beacon::transmitting(vector<string> data) {
    string d = data[1];
    int a = d.find(";");
    string f = d.substr(0, a);
    d.erase(0, a+2);
    ui->beaconData->setText(QString::fromStdString(d));
    vector<string> beac;
    beac.push_back(data[0]);
    beac.push_back(f);
    beac.push_back(f);
    emit beaconData(beac);
}
