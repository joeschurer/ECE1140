#ifndef SWTCCREATOR_H
#define SWTCCREATOR_H
#include "swtccalculations.h"
#include "swtcui.h"
#include "ui_swtcui.h"

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class SWTCCreator; }
QT_END_NAMESPACE

class SWTCCreator : public QMainWindow
{
    Q_OBJECT

public:
    SWTCCreator(QWidget *parent = nullptr);
    ~SWTCCreator();
    void MakeTrain(SWTCCalculations train, int ID, int CommandedSpeedForTrain);
    vector<SWTCUI*> AllTrains;

public slots:
    void DispatchTrain(int ID, int CommandedSpeed);

private:
    Ui::SWTCCreator *ui;
};
#endif // SWTCCREATOR_H
