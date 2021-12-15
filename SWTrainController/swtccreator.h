#ifndef SWTCCREATOR_H
#define SWTCCREATOR_H

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

private:
    Ui::SWTCCreator *ui;
};
#endif // SWTCCREATOR_H
