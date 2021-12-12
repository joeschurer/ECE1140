#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QMessageBox>
#include "waysidecontroller.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void upload_clicked();
    void sel_line();
    void sel_block();
    void sel_wayside();
    void ctc_test();
    void check_ctc_lines();
    void check_track_lines();
    void check_heater_line();
    void track_test();
    void track_heater();
    void check_maintenance_line();


    void on_uploadButton_clicked();

    void on_maintenance_submit_clicked();

    void on_maintenance_toggle_clicked();

private:
    Ui::MainWindow *ui;
    QString fileName = "";
    //add line here
    WaysideController waysideController;

signals:
   void sendCTCOcc(std::vector<bool>);
   void sendTrackModelAuth(std::vector<bool>);
   void sendTrackModelSwitches(std::vector<int>);
   void sendTrainDispatch(std::vector<std::string>);
   void sendCTCHeater(bool);
   void activateCrossing(vector<int>);
   void sendThroughput(int);
   void sendFixed(int);
   void sendMaintenace(vector<bool>);

public slots:
    void receiveOcc(std::vector<bool> occ);
    void receiveHeater(bool);
    void recieveAuth(TrainEntry);
    void getMaintenaceMode(std::vector<bool> blocks);
    void changeSwitch(std::vector<int> pos);
    void receiveThroughput(int);
    void receiveLine(string);


};
#endif // MAINWINDOW_H
