#ifndef BEACON_H
#define BEACON_H

#include <QMainWindow>
#include <string>

using namespace std;

namespace Ui {
class Beacon;
}

class Beacon : public QMainWindow
{
    Q_OBJECT

public:
    explicit Beacon(QWidget *parent = nullptr);

    ~Beacon();

private slots:
    void transmitting(string data);

signals:

private:
    Ui::Beacon *ui;
};

#endif // BEACON_H
