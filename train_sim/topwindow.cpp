#include "topwindow.h"
#include "ui_topwindow.h"

TopWindow::TopWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::TopWindow)
{
    ui->setupUi(this);
}

TopWindow::~TopWindow()
{
    delete ui;
}

