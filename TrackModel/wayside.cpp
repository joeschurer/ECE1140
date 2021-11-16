#include "wayside.h"
#include "ui_wayside.h"
#include "layout.h"

Wayside::Wayside(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Wayside)
{
    ui->setupUi(this);
}

Wayside::~Wayside()
{
    delete ui;
}

void Wayside::on_timer_userTimeChanged(const QTime &time)
{
    Line* line =&(Line::getLine());
    //Add more people to stations
    int j = line->blocks.size();
    int a = 0;
    int b = 0;
    for (int i=0; i<j; i++) {
        if (line->blocks[i].hasStation) {
            a += line->blocks[i].station.passengers;
            line->blocks[i].station.addPassengers();
            b += line->blocks[i].station.passengers;
        }
    }

    emit timeChanged();

    int added = b-a;
    emit addedPassengers(added);
}

void Wayside::on_test1_clicked()
{
    string name = "1";
    string com = "50";
    string a = "000";
    string b = "000";
    string c = "000000";
    string d = "0000";
    string e = "0000";
    string f = "00000000";
    string g = "0000";
    string h = "000";
    string i = "0000000000000000000000";
    string j = "00000";
    string k = "111111";
    string l = "11111";
    string m = "111";
    string n = "111111111";
    string o = "111";
    string p = "111111111";
    string q = "111";
    string r = "0";
    string s = "000";
    string t = "00000";
    string u = "0000000";
    string v = "00000";
    string w = "0000000000000000000000";
    string x = "000";
    string y = "000";
    string z = "0";
    string auth = a+b+c+d+e+f+g+h+i+j+k+l+m+n+o+p+q+r+s+t+u+v+w+x+y+z;
    string star = "63"; //Start at K-63, block right outside yard
    vector<string> vec;
    vec.push_back(name);
    vec.push_back(com);
    vec.push_back(auth);
    vec.push_back(star);
    emit trainChanged(vec);
}


void Wayside::on_cont1_1_clicked()
{
    emit toggleSwitch(86);
    emit toggleSwitch(76);
    vector<string> vec;
    vec.push_back("1");
    vec.push_back("70");
    string a = "000";
    string b = "000";
    string c = "000000";
    string d = "0000";
    string e = "0000";
    string f = "00000000";
    string g = "0000";
    string h = "000";
    string i = "0000000000000000000000";
    string j = "00000";
    string k = "111111";
    string l = "11111";
    string m = "111";
    string n = "111111111";
    string o = "000";
    string p = "000000000";
    string q = "001";
    string r = "1";
    string s = "111";
    string t = "11111";
    string u = "1111111";
    string v = "11111";
    string w = "1111111111111111111111";
    string x = "111";
    string y = "111";
    string z = "1";
    string auth = a+b+c+d+e+f+g+h+i+j+k+l+m+n+o+p+q+r+s+t+u+v+w+x+y+z;
    vec.push_back(auth);
    emit trainChanged(vec);
}


void Wayside::on_toggleSwitch_editingFinished()
{
    QString s = ui->toggleSwitch->text();
    string a = s.toStdString();
    int num = stoi(a);
    emit toggleSwitch(num);
}


void Wayside::on_cont1_2_clicked()
{
    emit toggleSwitch(29);
    vector<string> vec;
    vec.push_back("1");
    vec.push_back("45");
    string a = "111";
    string b = "111";
    string c = "111111";
    string d = "1111";
    string e = "1111";
    string f = "11111111";
    string g = "1000";
    string h = "000";
    string i = "0000000000000000000000";
    string j = "00000";
    string k = "000000";
    string l = "00000";
    string m = "000";
    string n = "000000000";
    string o = "000";
    string p = "000000000";
    string q = "000";
    string r = "0";
    string s = "000";
    string t = "00000";
    string u = "0000000";
    string v = "00000";
    string w = "0000000000000000000000";
    string x = "000";
    string y = "000";
    string z = "1";
    string auth = a+b+c+d+e+f+g+h+i+j+k+l+m+n+o+p+q+r+s+t+u+v+w+x+y+z;
    vec.push_back(auth);
    emit trainChanged(vec);
}


void Wayside::on_cont1_3_clicked()
{
    emit toggleSwitch(29);
    emit toggleSwitch(13);
    vector<string> vec;
    vec.push_back("1");
    vec.push_back("60");
    string a = "000";
    string b = "000";
    string c = "000000";
    string d = "1111";
    string e = "1111";
    string f = "11111111";
    string g = "1111";
    string h = "111";
    string i = "1111111111111111111111";
    string j = "00000";
    string k = "000000";
    string l = "00000";
    string m = "000";
    string n = "000000000";
    string o = "000";
    string p = "000000000";
    string q = "000";
    string r = "0";
    string s = "000";
    string t = "00000";
    string u = "0000000";
    string v = "00000";
    string w = "0000000000000000000000";
    string x = "000";
    string y = "000";
    string z = "0";
    string auth = a+b+c+d+e+f+g+h+i+j+k+l+m+n+o+p+q+r+s+t+u+v+w+x+y+z;
    vec.push_back(auth);
    emit trainChanged(vec);
}


void Wayside::on_testYard_clicked()
{
    vector<string> vec;
    vec.push_back("2");
    vec.push_back("60");
    string a = "000";
    string b = "000";
    string c = "000000";
    string d = "0000";
    string e = "0000";
    string f = "00000000";
    string g = "0000";
    string h = "000";
    string i = "0000000000000011111111";
    string j = "00000";
    string k = "000000";
    string l = "00000";
    string m = "000";
    string n = "000000000";
    string o = "000";
    string p = "000000000";
    string q = "000";
    string r = "0";
    string s = "000";
    string t = "00000";
    string u = "0000000";
    string v = "00000";
    string w = "0000000000000000000000";
    string x = "000";
    string y = "000";
    string z = "0";
    string auth = a+b+c+d+e+f+g+h+i+j+k+l+m+n+o+p+q+r+s+t+u+v+w+x+y+z;
    vec.push_back(auth);
    vec.push_back("50"); //Start at 50, yard off 57
    emit trainChanged(vec);
}
