#include "trainmodel.h"
#include "ui_trainmodel.h"
#include <string>

using namespace std;

TrainModel::TrainModel(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::TrainModel)
{
    ui->setupUi(this);
}

TrainModel::~TrainModel()
{
    delete ui;
}

void TrainModel::on_moveEdit_editingFinished()
{
    QString item = ui->moveEdit->text();
    int train = item.toInt();
    emit trainMoved(train);
}


void TrainModel::on_speedEdit_editingFinished()
{
    QString item = ui->speedEdit->text();
    emit trainSpeedUpdated(item);
}

