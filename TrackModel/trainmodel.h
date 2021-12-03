#ifndef TRAINMODEL_H
#define TRAINMODEL_H

#include <QMainWindow>
#include <QTableWidget>

namespace Ui {
class TrainModel;
}

class TrainModel : public QMainWindow
{
    Q_OBJECT

public:
    explicit TrainModel(QWidget *parent = nullptr);
    ~TrainModel();

private slots:
    void on_moveEdit_editingFinished();

    void on_speedEdit_editingFinished();

    void on_openDoors_returnPressed();

signals:
    int trainMoved(int trainNum);
    QString trainSpeedUpdated(QString item);
    int doorsOpen(int trainNum);

private:
    Ui::TrainModel *ui;
};

#endif // TRAINMODEL_H
