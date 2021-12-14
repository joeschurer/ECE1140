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
    ui->beaconData->setText(QString::fromStdString(d));
    emit beaconData(data);
}
