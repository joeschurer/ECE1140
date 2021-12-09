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
    WaysideController waysideController;

signals:
   void sendCTCOcc(std::vector<bool>);
   void sendTrackModelAuth(std::vector<bool>);
   void sendTrackModelSwitches(std::vector<int>);
   void sendTrainDispatch(std::vector<std::string>);

public slots:
    void receiveOcc(std::vector<bool> occ);
    void recieveAuth(TrainEntry);
    void getMaintenaceMode(std::vector<bool> blocks);
    void changeSwitch(std::vector<int> pos);


};
#endif // MAINWINDOW_H
