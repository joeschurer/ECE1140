#include "lineselect.h"
#include "ui_lineselect.h"
#include <fstream>
#include <string>
#include <iostream>

using namespace std;

LineSelect::LineSelect(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LineSelect)
{
    ui->setupUi(this);
}

LineSelect::~LineSelect()
{
    delete ui;
}

void LineSelect::on_selectgreen_clicked()
{
    ifstream ifile;
    ifile.open("C:/Users/daisy1/Documents/GitHub/ECE1140/train_sim/GreenLine_Test.txt");

    ofstream ofile;
    ofile.open("layoutfile.txt");
    ofile.clear();

    string line;
    while (getline(ifile, line)) {
        ofile << line << endl;
    }

    ifile.close();
    ofile.close();

    this->close();
}


void LineSelect::on_selectred_clicked()
{
    ifstream ifile;
    ifile.open("C:/Users/Lexi/Documents/ECE 1140/TrackModel/RedLine.txt");

    ofstream ofile;
    ofile.open("layoutfile.txt");
    ofile.clear();

    string line;
    while (getline(ifile, line)) {
        ofile << line << endl;
    }

    ifile.close();
    ofile.close();

    this->close();
}


void LineSelect::on_selectblue_clicked()
{
    ifstream ifile;
    ifile.open("C:/Users/Lexi/Documents/ECE 1140/TrackModel/BlueLine.txt");

    ofstream ofile;
    ofile.open("layoutfile.txt");
    ofile.clear();

    string line;
    while (getline(ifile, line)) {
        ofile << line << endl;
    }

    ifile.close();
    ofile.close();

    this->close();
}

