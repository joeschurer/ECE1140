#ifndef WAYSIDE_H
#define WAYSIDE_H

#include <string>
#include <QDialog>

using namespace std;

namespace Ui {
class Wayside;
}

class Wayside : public QDialog
{
    Q_OBJECT

public:
    explicit Wayside(QWidget *parent = nullptr);
    ~Wayside();

private slots:
    void on_test1_clicked();

    void on_cont1_1_clicked();

    void on_toggleSwitch_editingFinished();

    void on_cont1_2_clicked();

    void on_cont1_3_clicked();

    void on_testYard_clicked();

    void on_toggleCrossing_returnPressed();


    void on_red_test_clicked();

signals:
    int addedPassengers(int added);
    vector<string> trainChanged(vector<string> data);
    vector<int> toggleSwitch(vector<int> sw);
    int toggleCrossing(int cross);

private:
    Ui::Wayside *ui;
};

#endif // WAYSIDE_H
