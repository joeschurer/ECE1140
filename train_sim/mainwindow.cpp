#include "mainwindow.h"
#include "ui_mainwindow.h"

QString curr_line = "";
int curr_wayside = -1;
int curr_block = -1;
bool block_selected = false;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
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
    ui->uploadButton->setEnabled(false);

    //define the options for the options for the line selection
    ui->line_select->addItem("Red Line");
    ui->line_select->addItem("Green Line");
    //ui->line_select->addItem("Blue Line");

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
    //qDebug() << globalLine;
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
        num_waysides = 3;
        curr_line = "red";
        ui->sel_line->setText(QStringLiteral("Red Line"));
    }
    else if(ui->line_select->currentText() == "Green Line"){
        //green
        num_waysides = 4;
        curr_line = "green";
        ui->sel_line->setText(QStringLiteral("Green Line"));
    } else {
        //blue
        num_waysides = 1;
        curr_line = "blue";
        ui->sel_line->setText(QStringLiteral("Blue Line"));
    }

    //get the num of waysides
    num_waysides = waysideController.returnNumWaysides();

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
    int selection = ui->block_select->currentIndex();
    QString selected = ui->block_select->currentText();
    //qDebug() << selected;

    string sel_string = selected.toStdString();
    sel_string.erase(0,6);
    //qDebug() << QString::fromStdString(sel_string);
    selection = std::stoi(sel_string);


    ui->sel_block->setText(QStringLiteral("Block ")+ QString::number(selection));

    //get block info
    block temp_block = waysideController.get_block(selection);

    //get heater status
    if(selection==0){
        ui->maintenance_status->setText("-");
        ui->heater_status->setText("-");
        ui->light_status->setText("-");
        ui->switch_status->setText("-");
        ui->crossing_status->setText("-");
        ui->auth_status->setText(QString::number(temp_block.auth));
        ui->sugg_status->setText("-");
        ui->commanded_status->setText("-");
        ui->presence_status->setText("-");
    } else{
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
        QString crossing = "-";
        if(temp_block.crossing == true){
            if(temp_block.crossingState==true){
                crossing = "Active";
            } else {
                crossing = "Inactive";
            }
        }
        ui->maintenance_status->setText(mode);
        ui->heater_status->setText(state);
        ui->light_status->setText(light);
        ui->switch_status->setText(switchString);
        ui->crossing_status->setText(crossing);
        ui->auth_status->setText(QString::number(temp_block.auth));
        ui->sugg_status->setText(QString::number(temp_block.sugg_speed)+ " mph");
        ui->commanded_status->setText(QString::number(temp_block.comm_speed)+ " mph");
        ui->presence_status->setText(QString::number(temp_block.occupancy));
    }
    block_selected = true;

}

void MainWindow::sel_wayside(){
    int selection = ui->wayside_select->currentIndex() +1;
    qDebug() << selection;
    //clear the drop-down
    block_selected=false;
    ui->block_select->clear();
    ui->sel_block->setText(QStringLiteral("Block "));

    //get owned blocks
    vector<int> blocks;
    blocks=waysideController.returnOwned(selection);


    //add block to the drop-down
    QString temp;
    for(int i=0; i<blocks.size();i++){
        //qDebug() << blocks[i];
        temp = "Block " + QString::number(blocks[i]);
        ui->block_select->addItem(temp);
    }

    ui->sel_wayside->setText(QStringLiteral("Wayside #")+ QString::number(selection));

    //enable block selection
    ui->block_select->setEnabled(true);
    ui->uploadButton->setEnabled(true);
}

void MainWindow::ctc_test(){
    int index = ui->block_test->text().toInt();
    int auth = ui->auth_test->text().toInt();
    double speed = ui->speed_test->text().toDouble();
    waysideController.ctc_test(index,auth,speed);
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
    waysideController.update_occupancy(index);
    if(block_selected){
        sel_block();
    }
}

void MainWindow::track_heater(){
    int index = ui->heater_test->text().toInt();
    bool state = ui->heater_state->isChecked();
    waysideController.heater(state);
    if(block_selected){
        sel_block();
    }
}



void MainWindow::check_maintenance_line(){
    if(!ui->maintenance_test->text().isEmpty()){
        ui->maintenance_submit->setEnabled(true);
    }
}


void MainWindow::on_uploadButton_clicked(){
    fileName = QFileDialog::getOpenFileName(this,"Open the PLC File","C://");
    string fName = fileName.toStdString();
    if(fileName != ""){
        int selection = ui->wayside_select->currentIndex() +1;
        waysideController.uploadPLC(selection, fName);
        //add upload here
        ui->uploadNotif->setText("Uploaded " + fileName);
    }
    if(block_selected){
        sel_block();
    }
}


void MainWindow::on_maintenance_submit_clicked(){
    int index = ui->maintenance_test->text().toInt();
    bool check = waysideController.get_maintenance_mode(index);
    waysideController.set_maintenance_mode(index,!check);
    block temp = waysideController.get_block(index);
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
    waysideController.toggleSwitch(index);
    vector<int> temp;
    temp.push_back(index);

    emit sendTrackModelSwitches(temp);


    if(block_selected){
        sel_block();
    }


}

/*std::vector<bool>  MainWindow::sendCTCOcc(){
    std::vector<bool> temp =plc.sendCTCOcc();
    return(temp);
}*/

void  MainWindow::receiveOcc(std::vector<bool> occ){
    vector<vector<int>> changes = waysideController.receiveOcc(occ);

    vector<int> switches = changes[0];
    vector<int> cross = changes[1];

    std::vector<bool> temp =waysideController.sendCTCOcc();
    emit sendCTCOcc(temp);
    emit sendTrackModelSwitches(switches);
    emit activateCrossing(cross);
    if(block_selected){
        sel_block();
    }


}

void MainWindow::recieveAuth(TrainEntry t){
    std::vector<bool> auth = t.authority;

    vector<vector<int>> changes = waysideController.ctc_reccomend(auth);

    vector<int> sw = changes[0];
    vector<int> cross = changes[1];
    emit sendTrackModelSwitches(sw);
    emit activateCrossing(cross);
    std::vector<bool> temp = waysideController.sendTrackModelAuth();
    //emit sendTrackModelAuth(temp);
    std::string auth_string;
    for(int i=0;i<temp.size();i++){
        if(temp[i]==true){
            auth_string.push_back('1');
        } else {
            auth_string.push_back('0');
        }
    }

    std::vector<std::string> out;
    out.push_back(std::to_string(t.trainNumber));
    out.push_back(std::to_string(t.suggestedSpeed));
    out.push_back(auth_string);
    emit sendTrainDispatch(out);
    if(block_selected){
        sel_block();
    }
}

void MainWindow::getMaintenaceMode(std::vector<bool> blocks){
    emit sendMaintenace(blocks);
    for(int i=0; i< blocks.size(); i++){
        waysideController.set_maintenance_mode(i,blocks[i]);
        if(waysideController.get_maintenance_mode(i)== true){
            emit sendFixed(i);
        }
    }
    if(block_selected){
        sel_block();
    }
}

void MainWindow::changeSwitch(std::vector<int> pos){
    bool change = waysideController.maintenance_mode_switch(pos[0],pos[1]);
    if(change==true){
        std::vector<int> temp;
        temp.push_back(pos[0]);

        emit sendTrackModelSwitches(temp);
    }
    if(block_selected){
        sel_block();
    }

}

void MainWindow::receiveHeater(bool state){
    waysideController.heater(state);
    emit sendCTCHeater(state);

    if(block_selected){
        sel_block();
    }
}

void MainWindow::receiveThroughput(int index){
    emit sendThroughput(index);
    if(block_selected){
        sel_block();
    }
}

void MainWindow::receiveLine(string line){

}
