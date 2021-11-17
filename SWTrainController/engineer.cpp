#include "engineer.h"
#include "ui_engineer.h"

Engineer::Engineer(QWidget *parent) :
    QWidget(parent),
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
    KpValue = Kp.toInt();

    QString Ki = ui->KiBox->text();
    KiValue = Ki.toInt();

    emit SubmitKpKi(KpValue, KiValue);
    close();
}

