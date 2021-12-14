#include "HomepageWindow.h"
#include "ui_HomepageWindow.h"
#include <QFileDialog>
#include <QMessageBox>
#include <fstream>
#include <list>
#include <vector>


using std::ifstream;
using std::list;
using std::string;
using std::vector;

int systemClock = 0;
int simulationSpeed = 15;
HomepageWindow::HomepageWindow(QWidget *parent, CtcOffice *ctcOffice)
    : QMainWindow(parent), ui(new Ui::HomepageWindow), ctcOffice_(ctcOffice) {
  ui->setupUi(this);
  auto line = ui->trackLineLineEdit;
  if(ctcOffice_->getCurrentLine()==Green){
      line->setStyleSheet("color: ""green""");
      line->setText("Green");
  } else {
      line->setStyleSheet("color: ""red""");
      line->setText("Red");
  }
  initializeTestInterfaceUi();
}

HomepageWindow::~HomepageWindow() { delete ui; }

void HomepageWindow::initializeTestInterfaceUi() {

}

void HomepageWindow::on_homepageButton_clicked() {
  ui->stackedWidget->setCurrentIndex(0);
}

void HomepageWindow::on_manageTrainsButton_clicked() {
  ui->stackedWidget->setCurrentIndex(1);
}

void HomepageWindow::on_manageTracksButton_clicked() {
  ui->stackedWidget->setCurrentIndex(2);
}

void HomepageWindow::on_testInterfaceButton_clicked() {
  ui->stackedWidget->setCurrentIndex(3);
}

void HomepageWindow::on_uploadScheduleButton_clicked() {
   QString fileName = QFileDialog::getOpenFileName(this,"Select Train Schedule File","C://");
  if(!fileName.isEmpty()) {
      ifstream infile(fileName.toStdString());
      ctcOffice_->parseSchedule(infile);
      std::vector<ScheduleEntry> currentTrainSchedule = ctcOffice_->getSchedule()[ctcOffice_->getNumTrains()];
      updateTrainTable(ctcOffice_->getSchedule());
  }
}
void HomepageWindow::updateTrainTable(
    std::unordered_map<int, std::vector<ScheduleEntry>> schedule) {
    // TODO: Consider changing to where it adds a schedule entry instead of adding the whole
    // schedule every time
  ui->trainTableWidget->clearContents();
  ui->trainTableWidget->setRowCount(0);

  for (auto element : schedule) {
    for (auto scheduleEntry : element.second) {
      auto trainTableWidget = ui->trainTableWidget;
      int numRows = trainTableWidget->rowCount();
      trainTableWidget->insertRow(numRows);
      string trainString = "Train " + std::to_string(element.first);
      trainTableWidget->setItem(numRows, 0,
                                new QTableWidgetItem(trainString.c_str()));
      string destinationString = scheduleEntry.destinationString.length()>0? scheduleEntry.destinationString + ", " +
                                 std::to_string(scheduleEntry.destination):std::to_string(scheduleEntry.destination);
      trainTableWidget->setItem(
          numRows, 1, new QTableWidgetItem(destinationString.c_str()));
      string arrivalTime = ctcOffice_->toStringTime(scheduleEntry.arrivalTime);
      trainTableWidget->setItem(numRows, 2,
                                new QTableWidgetItem(arrivalTime.c_str()));
      string departureTime =
          ctcOffice_->toStringTime(scheduleEntry.departureTime);
      trainTableWidget->setItem(numRows, 3,
                                new QTableWidgetItem(departureTime.c_str()));
      trainTableWidget->setItem(
          numRows, 4,
          new QTableWidgetItem(
              std::to_string(scheduleEntry.suggestedSpeed * 0.621371).c_str()));
    }
  }
}

void HomepageWindow::updateTrainComboBox() {
  /*
  auto comboBox = ui->selectTrainComboBox;
  auto numTrains = ctcOffice_->getNumTrains();
  comboBox->insertItem(numTrains, QString::fromStdString("Train "+
  std::to_string(numTrains)));
  */
}

void HomepageWindow::on_plusButton_clicked() {
  auto scheduleTrainText = ui->scheduleTrainLineEdit->text();
  auto scheduleDestinationText = ui->scheduleDestinationLineEdit->text();
  auto scheduleArrivalText = ui->scheduleArrivalLineEdit->text();
  if (!scheduleTrainText.isEmpty() && !scheduleDestinationText.isEmpty() &&
      !scheduleArrivalText.isEmpty()) {
    auto destinationStr = scheduleDestinationText.toStdString();
    if(!destinationStr.empty() && std::find_if(destinationStr.begin(),
            destinationStr.end(), [](unsigned char c) { return !std::isdigit(c); }) == destinationStr.end()){
            // is block
        ctcOffice_->addScheduleEntry(stoi(scheduleTrainText.toStdString()), "Yard",
                                     stoi(destinationStr),
                                     scheduleArrivalText.toStdString());

    } else {
        // is station
        ctcOffice_->addScheduleEntry(stoi(scheduleTrainText.toStdString()), "Yard",
                                     scheduleDestinationText.toStdString(),
                                     scheduleArrivalText.toStdString());
    }
    updateTrainTable(ctcOffice_->getSchedule());
  }
}

void HomepageWindow::on_addTrackSectionButton_clicked() {
  auto trackInput = ui->trackLineEdit->text();
  if (!trackInput.isEmpty()) {
    auto stringBlocks = utility::split(trackInput.toStdString(), ",");
    vector<int> intBlocks;
    std::transform(stringBlocks.begin(), stringBlocks.end(),
                   std::back_inserter(intBlocks),
                   [](string c) -> int { return stoi(c); });
    auto trackTable = ui->trackSectionTable;
    for (auto block : intBlocks) {
      if (ctcOffice_->getClosedBlocks()->count(block) == 0) {
        int numRows = trackTable->rowCount();
        trackTable->insertRow(numRows);
        trackTable->setItem(
            numRows, 0, new QTableWidgetItem(std::to_string(block).c_str()));
      }
    }
    ctcOffice_->addClosedBlocks(intBlocks);
  }
  auto closedBlocks = ctcOffice_->sendClosedBlocks();
  emit sendClosedBlocks(closedBlocks);
}

void HomepageWindow::on_maintenanceModeCheckBox_stateChanged(int arg1) {
  auto checkbox = ui->maintenanceModeCheckBox;
  if (checkbox->isChecked()) {
    ui->addSwitchButton->setEnabled(true);
    ui->switchLineEdit->setEnabled(true);
  } else {
    ui->addSwitchButton->setEnabled(false);
    ui->switchLineEdit->setEnabled(false);
  }
}

void HomepageWindow::on_addSwitchButton_clicked() {
  auto switchTable = ui->switchTableWidget;
  vector<string> switchString =
      utility::split(ui->switchLineEdit->text().toStdString(), "->");
  auto closedBlocks = ctcOffice_->getClosedBlocks();
  if (closedBlocks->count(stoi(switchString[0])) == 1 &&
      closedBlocks->count(stoi(switchString[1])) == 1) {
    int numRows = switchTable->rowCount();
    switchTable->insertRow(numRows);
    switchTable->setItem(numRows, 0,
                         new QTableWidgetItem(ui->switchLineEdit->text()));
    emit sendSwitchPosition({stoi(switchString[0]), stoi(switchString[1])});
  }
}

void HomepageWindow::on_dispatchButton_clicked() {
  auto schedule = ctcOffice_->getSchedule();
  emit sendDispatchInfo(ctcOffice_->dispatchTrain(1, schedule[1][0]));
}

void HomepageWindow::receiveOccupancy(vector<bool> occupancy) {
  ctcOffice_->updateOccupancy(occupancy);
  updateOccupancyTable(occupancy);
}

void HomepageWindow::receiveTicketSales(int tickets){
    ctcOffice_->setTickets(tickets);
}

void HomepageWindow::updateOccupancyTable(vector<bool> occupancy) {
  auto occupancyTable = ui->occupancyTableWidget;
  occupancyTable->clearContents();
  occupancyTable->setRowCount(0);
  for (int i = 0; i < occupancy.size(); i++) {
    if (occupancy[i] == 1) {
      int numRows = occupancyTable->rowCount();
      occupancyTable->insertRow(numRows);
      auto trainNumber = ctcOffice_->getTrainFromOccupancy(i);
      string trainString = trainNumber!=-1? "Train " + std::to_string(trainNumber): "";
      occupancyTable->setItem(numRows, 0,
                              new QTableWidgetItem(trainString.c_str()));
      occupancyTable->setItem(numRows, 1,
                              new QTableWidgetItem(std::to_string(i).c_str()));
    }
  }
  int totalOccupancy = ctcOffice_->getTotalOccupanccy();
  int totalDispatchedTrains = ctcOffice_->getDispatchedTrains().size();
  ui->totalOccupancyLineEdit->setText(QString::number(totalOccupancy));
  ui->dispatchedTrainsCountLineEdit->setText(QString::number(totalDispatchedTrains));
  if(totalOccupancy>totalDispatchedTrains) {
      ui->trackFailureAlertTextEdit->setTextColor(QColor("red"));
      ui->trackFailureAlertTextEdit->setText("Alert: Occupancies>Dispatched Trains, Potential Track Failure");
  } else {
      ui->trackFailureAlertTextEdit->clear();
  }
}

void HomepageWindow::timerSlot() {
  systemClock += 1;
  //qDebug() << systemClock;
  bool trainDispatched = ctcOffice_->checkForDispatch(systemClock);
  Time currentTime = ctcOffice_->toTimeFromSeconds(systemClock);
  ui->timeHourLineEdit->setText(std::to_string(currentTime.first).c_str());
  ui->timeHourLineEdit_2->setText(std::to_string(currentTime.first).c_str());
  ui->timeHourLineEdit_3->setText(std::to_string(currentTime.first).c_str());
  ui->timeMinuteLineEdit->setText(std::to_string(currentTime.second).c_str());
  ui->timeMinuteLineEdit_2->setText(std::to_string(currentTime.second).c_str());
  ui->timeMinuteLineEdit_3->setText(std::to_string(currentTime.second).c_str());

  if (trainDispatched) {
    emit sendDispatchInfo(ctcOffice_->getDispatchedTrains().back());
  }
  auto currentLine = ctcOffice_->getCurrentLine();
  double ticketsPerHour;
  auto s = systemClock;
  if(systemClock>0){
    ticketsPerHour = (double)ctcOffice_->getTickets()/((double)systemClock/3600);
  } else {
    ticketsPerHour = 0;
  }

  if(currentLine==Green){
    ui->greenThroughputLineEdit->setText(QString::number(ticketsPerHour));
  } else {
    ui->redThroughputLineEdit->setText(QString::number(ticketsPerHour));
  }
}

void HomepageWindow::on_submitBlockButton_clicked() {
  int startBlock = std::stoi(ui->startBlockLineEdit->text().toStdString());
  int destinationBlock =
      std::stoi(ui->destinationBlockLineEdit->text().toStdString());
  ctcOffice_->getRoute(startBlock, destinationBlock);
}

void HomepageWindow::on_removeTrackButton_clicked()
{
    auto trackTable = ui->trackSectionTable;
    auto selectedItems = trackTable->selectedItems();
    if(selectedItems.size()>0){
        for(auto item: selectedItems){
            auto closedBlocks = ctcOffice_->getClosedBlocks();
            auto block = item->text().toInt();
            closedBlocks->erase(block);
            trackTable->removeRow(item->row());
        }
        auto closedBlocksVector = ctcOffice_->sendClosedBlocks();
        emit sendClosedBlocks(closedBlocksVector);
    }
}


void HomepageWindow::on_submitTestOccupancyPushButton_clicked()
{
    vector<bool> occupancy;
    if(ctcOffice_->getCurrentLine()==Green){
        occupancy = vector<bool>(150, false);

    } else {
        occupancy = vector<bool>(76, false);
    }
    auto occupiedBlocksString = ui->testOccupancyLineEdit->text().toStdString();
    auto blockVector = utility::split(occupiedBlocksString, ",");
    for(auto block: blockVector){
        occupancy[stoi(block)]=true;
    }
    ctcOffice_->updateOccupancy(occupancy);
    updateOccupancyTable(occupancy);
}


void HomepageWindow::on_SubmitTestTicketsSoldButton_clicked()
{
    auto tickets = ui->testTicketsSoldLineEdit->text().toInt();
    ctcOffice_->setTickets(tickets);
}

