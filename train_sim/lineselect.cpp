#include "lineselect.h"
#include "ui_lineselect.h"
#include <fstream>
#include <string>
#include <iostream>
#include "models.h"

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
    //ifile.open("C:/Users/awilk/OneDrive/Documents/ECE 1140/TrackModel/GreenLine_Test.txt");
    ifile.open("GreenLine_Test.txt");

    ofstream ofile;
    ofile.open("layoutfile.txt");
    ofile.clear();

    string line;
    while (getline(ifile, line)) {
        ofile << line << endl;
    }

    ifile.close();
    ofile.close();
    globalLine = 0;
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
    globalLine = 1;
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

