#include "HomepageWindow.h"
#include "ui_HomepageWindow.h"
#include <QFileDialog>
#include <QMessageBox>
#include <fstream>
#include <list>
#include <vector>

using std::string;
using std::list;
using std::ifstream;
using std::vector;

HomepageWindow::HomepageWindow(QWidget *parent, CtcOffice *ctcOffice)
    : QMainWindow(parent)
    , ui(new Ui::HomepageWindow), ctcOffice_(ctcOffice)
{
    ui->setupUi(this);
    initializeTestInterfaceUi();

}

HomepageWindow::~HomepageWindow()
{
    delete ui;
}

void HomepageWindow::initializeTestInterfaceUi(){
    ui->testTrackComboBox->insertItems(0, {"Blue:A", "Blue:B", "Blue:C"});
    ui->testTrackConditionComboBox->insertItems(0, {"Broken Rail", "Track Circuit Failure", "Power Failure"});
    ui->testTrainComboBox->insertItems(0, {"Train 1", "Train 2", "Train 3"});
    ui->testLocationComboBox->insertItems(0, {"Blue:A:1", "Blue:A:2", "Blue:A:3", "Blue:A:4", "Blue:A:5", "Blue:B:6", "Blue:B:7", "Blue:B:8", "Blue:B:9", "Blue:B:10", "Blue:C:11", "Blue:C:12", "Blue:C:13", "Blue:C:14", "Blue:C:15"});
}


void HomepageWindow::on_homepageButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void HomepageWindow::on_manageTrainsButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void HomepageWindow::on_manageTracksButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}


void HomepageWindow::on_testInterfaceButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}

void HomepageWindow::on_uploadScheduleButton_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this,"Select Train Schedule File","C://");
    qDebug() << fileName;
    if(!fileName.isEmpty()) {
        ifstream infile (fileName.toStdString());
        ctcOffice_->parseSchedule(infile);
        std::list<scheduleEntry> currentTrainSchedule = ctcOffice_->getSchedule()[ctcOffice_->getNumTrains()];
        updateTrainTable(currentTrainSchedule);
        updateTrainComboBox();
    }
}

void HomepageWindow::updateTrainTable(std::list<scheduleEntry> schedule){
    std::list<scheduleEntry>::iterator current=schedule.begin();
    auto next = std::next(current,1);
    auto trainTableWidget = ui->trainTableWidget;
    // from yard to first station
    int numRows = trainTableWidget->rowCount();
    trainTableWidget->insertRow(numRows);
    auto numTrains = ctcOffice_->getNumTrains();
    string trainString = "Train " + std::to_string(numTrains);
    trainTableWidget->setItem(numRows, 0, new QTableWidgetItem(trainString.c_str()));
    string routeString = "Yard->" + current->infrastructure;
    trainTableWidget->setItem(numRows, 1, new QTableWidgetItem(routeString.c_str()));

    // dwell is one minute
    auto arrivalTime = std::stod(current->timeToStation) -1;
    double previousDepartureTime = arrivalTime+1;
    string timeString = utility::convertMinutesToMinuteAndSecond(std::to_string(arrivalTime));
    trainTableWidget->setItem(numRows, 2, new QTableWidgetItem(timeString.c_str()));
    auto suggestedSpeed = ctcOffice_->computeRouteSuggestedSpeed(routeString);
    trainTableWidget->setItem(numRows, 3, new QTableWidgetItem(std::to_string(suggestedSpeed).c_str()));
    auto authority = ctcOffice_->computeRouteAuthority(routeString);
    trainTableWidget->setItem(numRows, 4, new QTableWidgetItem(std::to_string(authority).c_str()));
    ctcOffice_->getRouteBlockList(routeString);
    // other station
    for (current = schedule.begin(); next != schedule.end(); ++current){
        int numRows = trainTableWidget->rowCount();
        trainTableWidget->insertRow(numRows);
        trainTableWidget->setItem(numRows, 0, new QTableWidgetItem("Train 1"));
        routeString = current->infrastructure + "->" + next->infrastructure;
        trainTableWidget->setItem(numRows, 1, new QTableWidgetItem(routeString.c_str()));
        auto arrivalTime = std::stod(next->timeToStation) + previousDepartureTime -1;
        string timeString = utility::convertMinutesToMinuteAndSecond(std::to_string(arrivalTime));
        trainTableWidget->setItem(numRows, 2, new QTableWidgetItem(timeString.c_str()));
        auto suggestedSpeed = ctcOffice_->computeRouteSuggestedSpeed(routeString);
        trainTableWidget->setItem(numRows, 3, new QTableWidgetItem(std::to_string(suggestedSpeed).c_str()));
        auto authority = ctcOffice_->computeRouteAuthority(routeString);
        trainTableWidget->setItem(numRows, 4, new QTableWidgetItem(std::to_string(authority).c_str()));
        ctcOffice_->getRouteBlockList(routeString);
        next++;

        // 1 minute dwell
        previousDepartureTime = arrivalTime + 1;
    }
}

void HomepageWindow::updateTrainComboBox() {
    auto comboBox = ui->selectTrainComboBox;
    auto numTrains = ctcOffice_->getNumTrains();
    comboBox->insertItem(numTrains, QString::fromStdString("Train "+ std::to_string(numTrains)));
}


void HomepageWindow::on_plusButton_clicked()
{
    auto scheduleTrainText = ui->scheduleTrainLineEdit->text();
    auto scheduleRouteText = ui->scheduleRouteLineEdit->text();
    auto scheduleArrivalText = ui->scheduleArrivalLineEdit->text();

    if(!scheduleTrainText.isEmpty() && !scheduleRouteText.isEmpty() && !scheduleArrivalText.isEmpty()){
        auto trainTableWidget = ui->trainTableWidget;
        int numRows = trainTableWidget->rowCount();
        trainTableWidget->insertRow(numRows);
        trainTableWidget->setItem(numRows, 0, new QTableWidgetItem(scheduleTrainText));
        trainTableWidget->setItem(numRows, 1, new QTableWidgetItem(scheduleRouteText));
        string timeString = utility::convertMinutesToMinuteAndSecond(scheduleArrivalText.toStdString());
        trainTableWidget->setItem(numRows, 2, new QTableWidgetItem(timeString.c_str()));
        auto suggestedSpeed = ctcOffice_->computeRouteSuggestedSpeed(scheduleRouteText.toStdString());
        trainTableWidget->setItem(numRows, 3, new QTableWidgetItem(std::to_string(suggestedSpeed).c_str()));
        auto authority = ctcOffice_->computeRouteAuthority(scheduleRouteText.toStdString());
        trainTableWidget->setItem(numRows, 4, new QTableWidgetItem(std::to_string(authority).c_str()));
        ctcOffice_->getRouteBlockList(scheduleRouteText.toStdString());
    }
}


void HomepageWindow::on_addTrackSectionButton_clicked()
{
    auto trackInput = ui->trackLineEdit->text();

    if(!trackInput.isEmpty()){
        auto trackTable = ui->trackSectionTable;
        int numRows = trackTable->rowCount();
        trackTable->insertRow(numRows);
        trackTable->setItem(numRows, 0, new QTableWidgetItem(trackInput));
    }
}


void HomepageWindow::on_maintenanceModeCheckBox_stateChanged(int arg1)
{
    auto checkbox = ui->maintenanceModeCheckBox;
    if(checkbox->isChecked()) {
        ui->addSwitchButton->setEnabled(true);
        ui->removeSwitchButton->setEnabled(true);
        ui->switchLineEdit->setEnabled(true);
    } else {
        ui->addSwitchButton->setEnabled(false);
        ui->removeSwitchButton->setEnabled(false);
        ui->switchLineEdit->setEnabled(false);
    }
}

void HomepageWindow::on_submitTestTrackInputButton_clicked()
{
    auto trackTable = ui->trackSectionTable;
    int numRows = trackTable->rowCount();
    trackTable->insertRow(numRows);
    trackTable->setItem(numRows, 0, new QTableWidgetItem(ui->testTrackComboBox->currentText()));
    ui->stackedWidget->setCurrentIndex(2);
}


void HomepageWindow::on_submitTestTrainInputButton_clicked()
{
    auto comboBox = ui->selectTrainComboBox;
    comboBox->insertItem(0, ui->testTrainComboBox->currentText());
    comboBox->setCurrentIndex(0);
    ui->speedLineEdit->setText(ui->testSpeedLineEdit->text());
    ui->authorityLineEdit->setText(ui->testAuthorityLineEdit->text());
    ui->locationLineEdit->setText(ui->testLocationComboBox->currentText());
    ui->destinationLineEdit->setText(ui->testDestinationLineEdit->text());
    ui->stackedWidget->setCurrentIndex(0);
}


void HomepageWindow::on_addSwitchButton_clicked()
{
    auto switchTable = ui->switchTableWidget;
    int numRows = switchTable->rowCount();
    switchTable->insertRow(numRows);
    switchTable->setItem(numRows, 0, new QTableWidgetItem(ui->switchLineEdit->text()));
}


void HomepageWindow::on_dispatchButton_clicked()
{
    auto trainTable =ui->trainTableWidget;
    auto route = trainTable->item(trainTable->rowCount()-1, 1);
    ctcOffice_->getRouteBlockList(route->text().toStdString());
}
