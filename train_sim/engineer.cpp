#include "engineer.h"
#include "ui_engineer.h"

Engineer::Engineer(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Engineer)
{
    ui->setupUi(this);
}

Engineer::~Engineer()
{
    delete ui;
}

void Engineer::on_SubmitButton_released()
{
    QString Kp = ui->KpBox->text();
    KpValue = Kp.toDouble();

    QString Ki = ui->KiBox->text();
    KiValue = Ki.toDouble();

    emit SubmitKpKi(KpValue, KiValue);
    close();
}
