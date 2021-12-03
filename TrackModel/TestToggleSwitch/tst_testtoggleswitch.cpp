#include <QtTest>

// add necessary includes here
#include "C://Users/Lexi/Documents/ECE 1140/TrackModel/TrackModel.h"
#include "C://Users/Lexi/Documents/ECE 1140/TrackModel/Wayside.h"
#include <fstream>

class TestToggleSwitch : public QObject
{
    Q_OBJECT

public:
    TestToggleSwitch();
    ~TestToggleSwitch();
    TrackModel* mod;
    Wayside* way;

private slots:
    void test_case1();

};

TestToggleSwitch::TestToggleSwitch()
{
    mod = new TrackModel();
    way = new Wayside();
}

TestToggleSwitch::~TestToggleSwitch()
{
    bool a = mod->layout.line->blocks[12].swtch.point1;
    vector<int> i;
    i.push_back(13);
    emit way->toggleSwitch(i);
    bool b = mod->layout.line->blocks[12].swtch.point1;
    QVERIFY(a != b);
}

void TestToggleSwitch::test_case1()
{

}

QTEST_APPLESS_MAIN(TestToggleSwitch)

#include "tst_testtoggleswitch.moc"
