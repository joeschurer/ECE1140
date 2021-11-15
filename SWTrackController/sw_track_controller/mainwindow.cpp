#include "mainwindow.h"
#include "ui_mainwindow.h"

QString curr_line = "";
int curr_wayside = -1;
int curr_block = -1;
bool block_selected = false;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    //PLC plc;
    ui->setupUi(this);

    //set the default text for all boxes
    ui->sel_line->setText(QStringLiteral("- Line"));
    ui->sel_block->setText(QStringLiteral("Block "));
    ui->sel_wayside->setText(QStringLiteral("Wayside #"));
    ui->line_select->setPlaceholderText(QStringLiteral("--Select Line--"));
    ui->wayside_select->setPlaceholderText(QStringLiteral("--Select Wayside--"));
    ui->block_select->setPlaceholderText(QStringLiteral("--Select Block--"));

    //disable the block and wayside boxes until a line is selected
    ui->wayside_select->setEnabled(false);
    ui->block_select->setEnabled(false);
    ui->ctc_submit->setEnabled(false);
    ui->track_submit->setEnabled(false);
    ui->heater_submit->setEnabled(false);
    ui->maintenance_submit->setEnabled(false);
    ui->maintenance_toggle->setEnabled(false);

    //define the options for the options for the line selection
    ui->line_select->addItem("Red Line");
    ui->line_select->addItem("Green Line");
    ui->line_select->addItem("Blue Line");

    connect(ui->line_select,SIGNAL(activated(int)),this,SLOT(sel_line()));
    connect(ui->wayside_select,SIGNAL(activated(int)),this,SLOT(sel_wayside()));
    connect(ui->block_select,SIGNAL(activated(int)),this,SLOT(sel_block()));
    connect(ui->speed_test,SIGNAL(editingFinished()),this,SLOT(check_ctc_lines()));
    connect(ui->auth_test,SIGNAL(editingFinished()),this,SLOT(check_ctc_lines()));
    connect(ui->block_test,SIGNAL(editingFinished()),this,SLOT(check_ctc_lines()));
    connect(ui->ctc_submit,SIGNAL(released()),this,SLOT(ctc_test()));
    connect(ui->track_submit,SIGNAL(released()),this,SLOT(track_test()));
    connect(ui->occupancy_edit,SIGNAL(editingFinished()),this,SLOT(check_track_lines()));
    connect(ui->heater_test,SIGNAL(editingFinished()),this,SLOT(check_heater_line()));
    connect(ui->heater_submit,SIGNAL(released()),this,SLOT(track_heater()));
    connect(ui->maintenance_test,SIGNAL(editingFinished()),this,SLOT(check_maintenance_line()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::upload_clicked(){

}

void MainWindow::sel_line(){
    block_selected= false;
    //first clear the drop-down
    ui->wayside_select->clear();
    ui->block_select->clear();
    ui->sel_block->setText(QStringLiteral("Block "));
    ui->sel_wayside->setText(QStringLiteral("Wayside #"));
    int num_waysides = -1;

    //determine which line is selected
    if(ui->line_select->currentText() == "Red Line"){
        //red
        num_waysides = 10;
        curr_line = "red";
        ui->sel_line->setText(QStringLiteral("Red Line"));
    }
    else if(ui->line_select->currentText() == "Green Line"){
        //green
        num_waysides = 12;
        curr_line = "green";
        ui->sel_line->setText(QStringLiteral("Green Line"));
    } else {
        //blue
        num_waysides = 1;
        curr_line = "blue";
        ui->sel_line->setText(QStringLiteral("Blue Line"));
    }

    //Add the waysides to the box
    QString temp;
    for(int i=1; i<=num_waysides;i++){
        temp = "Wayside " + QString::number(i);
        ui->wayside_select->addItem(temp);
    }

    //enable wayside selection
    ui->wayside_select->setEnabled(true);
}


void MainWindow::sel_block(){
    int selection = ui->block_select->currentIndex() +1;

    ui->sel_block->setText(QStringLiteral("Block ")+ QString::number(selection));
    qDebug()<<"help";
    //get block info
    block temp_block = plc.get_block(selection);
    qDebug()<<"help2";
    ui->auth_status->setText(QString::number(temp_block.auth));
    ui->sugg_status->setText(QString::number(temp_block.sugg_speed)+ " mph");
    ui->commanded_status->setText(QString::number(temp_block.comm_speed)+ " mph");
    ui->presence_status->setText(QString::number(temp_block.occupancy));
    //get heater status
    QString state = "Off";
    if(temp_block.heater == true){
        state = "On";
    }
    QString mode = "No";
    if(temp_block.maintenance == true){
        mode = "Yes";
    }
    QString light = "Green";
    if(temp_block.lights == 1){
        light = "Yellow";
    }
    else if(temp_block.lights == 2){
        light = "Red";
    }
    QString switchString = "No Switch";
    if(temp_block.switch_tail == true){
       switchString = "Switch Not connected";
       if(temp_block.tailConnect != -1){
           switchString = "Connected to " + QString::number(temp_block.tailConnect);
       }
    }
    if(temp_block.switch_head == true){
        switchString = "Connected to " + QString::number(temp_block.headConnect);
    }
    ui->maintenance_status->setText(mode);
    ui->heater_status->setText(state);
    ui->light_status->setText(light);
    ui->switch_status->setText(switchString);
    ui->crossing_status->setText("None");
    block_selected = true;

}

void MainWindow::sel_wayside(){
    //clear the drop-down
    block_selected=false;
    ui->block_select->clear();
    ui->sel_block->setText(QStringLiteral("Block "));

    //set the number of blocks
    int num_blocks = -1;
    if(curr_line=="blue"){
       num_blocks = 15;
    } else if(curr_line == "red") {
        num_blocks = 20;
    } else {
        num_blocks = 150;
    }

    //add block to the drop-down
    QString temp;
    for(int i=1; i<=num_blocks;i++){
        temp = "Block " + QString::number(i);
        ui->block_select->addItem(temp);
    }
    int selection = ui->wayside_select->currentIndex() +1;
    ui->sel_wayside->setText(QStringLiteral("Wayside #")+ QString::number(selection));

    //enable block selection
    ui->block_select->setEnabled(true);
}

void MainWindow::ctc_test(){
    int index = ui->block_test->text().toInt();
    int auth = ui->auth_test->text().toInt();
    double speed = ui->speed_test->text().toDouble();
    plc.ctc_reccomend(index,auth,speed);
    if(block_selected){
        sel_block();
    }
}

void MainWindow::check_ctc_lines(){
    if(!ui->speed_test->text().isEmpty() && !ui->auth_test->text().isEmpty() && !ui->block_test->text().isEmpty()){
        ui->ctc_submit->setEnabled(true);
    }
}

void MainWindow::check_track_lines(){
    if(!ui->occupancy_edit->text().isEmpty()){
        ui->track_submit->setEnabled(true);
    }
}

void MainWindow::check_heater_line(){
    if(!ui->heater_test->text().isEmpty()){
        ui->heater_submit->setEnabled(true);
    }
}

void MainWindow::track_test(){
    int index = ui->occupancy_edit->text().toInt();
    plc.update_occupancy(index);
    if(block_selected){
        sel_block();
    }
}

void MainWindow::track_heater(){
    int index = ui->heater_test->text().toInt();
    bool state = ui->heater_state->isChecked();
    plc.heater(index,state);
    if(block_selected){
        sel_block();
    }
}



void MainWindow::check_maintenance_line(){
    if(!ui->maintenance_test->text().isEmpty()){
        ui->maintenance_submit->setEnabled(true);
    }
}


void MainWindow::on_uploadButton_clicked()
{
    fileName = QFileDialog::getOpenFileName(this,"Open the PLC File","C://");
    if(fileName != ""){
        ui->uploadNotif->setText("Uploaded " + fileName);
    }

}


void MainWindow::on_maintenance_submit_clicked()
{
    int index = ui->maintenance_test->text().toInt();
    bool check = plc.get_maintenance_mode(index);
    plc.set_maintenance_mode(index,!check);
    block temp = plc.get_block(index);
    if(temp.switch_head == true){
        if(!check == true){
            ui->maintenance_toggle->setEnabled(true);
        } else {
            ui->maintenance_toggle->setEnabled(false);
        }
    } else {
        ui->maintenance_toggle->setEnabled(false);
    }

    if(block_selected){
        sel_block();
    }

}


void MainWindow::on_maintenance_toggle_clicked()
{
    int index = ui->maintenance_test->text().toInt();
    plc.toggleSwitch(index);

    if(block_selected){
        sel_block();
    }
}

