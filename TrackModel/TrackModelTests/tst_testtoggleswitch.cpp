#include <QtTest>
#include <TrackModel.h>

// add necessary includes here

class TestToggleSwitch : public QObject
{
    Q_OBJECT

public:
    TestToggleSwitch();
    ~TestToggleSwitch();

private slots:
    void initTestCase();
    void cleanupTestCase();
    void test_case1();

};

TestToggleSwitch::TestToggleSwitch()
{

}

TestToggleSwitch::~TestToggleSwitch()
{

}

void TestToggleSwitch::initTestCase()
{

}

void TestToggleSwitch::cleanupTestCase()
{

}

void TestToggleSwitch::test_case1()
{

}

QTEST_APPLESS_MAIN(TestToggleSwitch)

#include "tst_testtoggleswitch.moc"
