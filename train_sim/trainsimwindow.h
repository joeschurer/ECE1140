#ifndef TRAINSIMWINDOW_H
#define TRAINSIMWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class trainsimwindow; }
QT_END_NAMESPACE

class trainsimwindow : public QMainWindow
{
    Q_OBJECT

public:
    trainsimwindow(QWidget *parent = nullptr);
    ~trainsimwindow();

private:
    Ui::trainsimwindow *ui;
};
#endif // TRAINSIMWINDOW_H
