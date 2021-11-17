#ifndef ENGINEER_H
#define ENGINEER_H

#include <QWidget>

namespace Ui {
class Engineer;
}

class Engineer : public QWidget
{
    Q_OBJECT

public:
    explicit Engineer(QWidget *parent = nullptr);
    ~Engineer();

signals:
    void SubmitKpKi(int Kp, int Ki);

private slots:
    void on_SubmitButton_released();

private:
    Ui::Engineer *ui;
    int KpValue;
    int KiValue;

};

#endif // ENGINEER_H
