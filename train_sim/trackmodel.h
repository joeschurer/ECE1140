#ifndef TRACKMODEL_H
#define TRACKMODEL_H

#include <QMainWindow>
#include "layout.h"
#include <QTableWidget>
#include <QGroupBox>
#include <QLabel>
#include <QLineEdit>
#include "ui_trackmodel.h"

namespace Ui {
class TrackModel;
}

class TrackModel : public QMainWindow
{
    Q_OBJECT

public:
    Layout layout;
    explicit TrackModel(QWidget *parent = nullptr);
    QTableWidget* blockdata;
    QTableWidget* traindata;
    void trackModelDisplay();
    ~TrackModel();

public slots:
    void trainMoved(int trainNum);
    void actualSpeedChanged(QString item);
    void trainUpdated(vector<string> item);
    void toggleSwitch(vector<int> sw);
    void toggleCrossing(int cross);
    void doorsOpen(int trainNum);
    void openDoors(vector<int> train);

private slots:
    void on_breakCircuit_returnPressed();

    void on_breakTrack_returnPressed();

    void on_breakPower_returnPressed();

    void  on_setTemp_returnPressed();


signals:
    vector<int> newBlock(vector<int> data);
    vector<string> newTrainData(vector<string> newData);
    vector<int> passengersChanged(vector<int> pass);
    vector<bool> occupancyChanged(vector<bool> occ);
    string beaconData(string data);
    double tempChanged(double temp);

private:
    Ui::TrackModel *ui;
};

#endif // TRACKMODEL_H
