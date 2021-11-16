#ifndef TRACKMODEL_H
#define TRACKMODEL_H

#include <QMainWindow>
#include "layout.h"
#include <QTableWidget>
#include <QGroupBox>
#include <QLabel>
#include <QLineEdit>

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
    void timeout();
    void trainMoved(int trainNum);
    void actualSpeedChanged(QString item);
    void trainUpdated(vector<string> item);
    void toggleSwitch(int sw);

private slots:
    void on_breakCircuit_textChanged(const QString &arg1);

    void on_breakTrack_textChanged(const QString &arg1);

    void on_breakPower_textChanged(const QString &arg1);

signals:
    vector<int> newBlock(vector<int> data);
    vector<string> newTrainData(vector<string> newData);
    vector<int> passengersChanged(vector<int> pass);
    vector<int> occupancyChanged(vector<int> occ);
    string beaconData(string data);

private:
    Ui::TrackModel *ui;
};

#endif // TRACKMODEL_H
