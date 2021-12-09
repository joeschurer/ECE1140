#include "trainsimwindow.h"
#include "ui_trainsimwindow.h"

trainsimwindow::trainsimwindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::trainsimwindow)
{
    ui->setupUi(this);
}

trainsimwindow::~trainsimwindow()
{
    delete ui;
}

