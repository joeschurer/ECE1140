#ifndef LINESELECT_H
#define LINESELECT_H

#include <QDialog>

namespace Ui {
class LineSelect;
}

class LineSelect : public QDialog
{
    Q_OBJECT

public:
    explicit LineSelect(QWidget *parent = nullptr);
    ~LineSelect();

private slots:
    void on_selectgreen_clicked();

    void on_selectred_clicked();

    void on_selectblue_clicked();

private:
    Ui::LineSelect *ui;
};

#endif // LINESELECT_H
