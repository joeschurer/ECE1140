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

void Beacon::transmitting(string data) {
    ui->beaconData->setText(QString::fromStdString(data));
}
