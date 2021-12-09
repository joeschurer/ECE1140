#ifndef ENGINEER_H
#define ENGINEER_H

#include <QMainWindow>

namespace Ui {
class Engineer;
}

class Engineer : public QMainWindow
{
    Q_OBJECT

public:
    explicit Engineer(QWidget *parent = nullptr);
    ~Engineer();

signals:
    void SubmitKpKi(double Kp, double Ki);

private slots:
    void on_SubmitButton_released();

private:
    Ui::Engineer *ui;
    double KpValue;
    double KiValue;
};

#endif // ENGINEER_H
