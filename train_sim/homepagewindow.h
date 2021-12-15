#ifndef HOMEPAGEWINDOW_H
#define HOMEPAGEWINDOW_H

#include <QMainWindow>
#include "CtcOffice.h"

QT_BEGIN_NAMESPACE
namespace Ui { class HomepageWindow; }
QT_END_NAMESPACE

class HomepageWindow : public QMainWindow
{
    Q_OBJECT

public:
    HomepageWindow(QWidget *parent = nullptr, CtcOffice *ctcOffice = nullptr);
    ~HomepageWindow();

public slots:
    void receiveOccupancy(vector<bool> occupancy);
    void receiveTicketSales(int tickets);
    void timerSlot();

signals:
    void sendClosedBlocks(vector<bool>);
    void sendSwitchPosition(vector<int>);
    void sendDispatchInfo(TrainEntry);

private slots:
    void on_uploadScheduleButton_clicked();

    void updateOccupancyTable(vector<bool> occupancy);
    void updateTrainTable(std::unordered_map<int, std::vector<ScheduleEntry>>);

    void updateTrainComboBox();

    void on_plusButton_clicked();

    void on_addTrackSectionButton_clicked();

    void on_maintenanceModeCheckBox_stateChanged(int arg1);

    void on_testInterfaceButton_clicked();

    void on_homepageButton_clicked();

    void on_manageTrainsButton_clicked();

    void on_manageTracksButton_clicked();

    void on_addSwitchButton_clicked();

    void on_dispatchButton_clicked();

    void on_submitBlockButton_clicked();

    void on_removeTrackButton_clicked();

    void on_submitTestOccupancyPushButton_clicked();

    void on_SubmitTestTicketsSoldButton_clicked();

    void on_oneXButton_clicked();

    void on_tenXButton_clicked();

    void on_startSimulationButton_clicked();

private:
    Ui::HomepageWindow *ui;
    CtcOffice *ctcOffice_;
    void initializeTestInterfaceUi();
};
#endif // HOMEPAGEWINDOW_H
