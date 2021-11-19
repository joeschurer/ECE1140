#include <QtTest>
#include "C:\Users\akina\Desktop\ECE1140\CtcOffice\CtcOffice.cpp"

class TestCtcOffice : public QObject
{
    Q_OBJECT

public:
    TestCtcOffice();
    ~TestCtcOffice();

private slots:
    void initTestCase();
    void cleanupTestCase();
    void test_close_block();
    void test_route();
    void test_suggested_speed();

};

TestCtcOffice::TestCtcOffice()
{


}

TestCtcOffice::~TestCtcOffice()
{

}

void TestCtcOffice::initTestCase()
{

}

void TestCtcOffice::cleanupTestCase()
{
}

void TestCtcOffice::test_close_block()
{
  CtcOffice ctcOffice;
  vector<int> blocks = {1,12,13};
  ctcOffice.addClosedBlocks(blocks);
  auto closedBlocks = ctcOffice.getClosedBlocks();
  QCOMPARE(closedBlocks.count(1), 1);
  QCOMPARE(closedBlocks.count(12), 1);
  QCOMPARE(closedBlocks.count(13), 1);
  QCOMPARE(closedBlocks.count(5), 0);
}

void TestCtcOffice::test_route() {
    CtcOffice ctcOffice;
    auto route = ctcOffice.getRoute(0,73);
    vector<int> dormontRoute = {0,63,64,65,66,67,68,69,70,71,72,73};
    QCOMPARE(route, dormontRoute);
}

void TestCtcOffice::test_suggested_speed() {

    CtcOffice ctcOffice;
    auto route = ctcOffice.getRoute(0,73);
    auto suggestedSpeed = ctcOffice.computeSuggestedSpeed(route);
    QCOMPARE(suggestedSpeed, 40);
}

QTEST_APPLESS_MAIN(TestCtcOffice)

#include "tst_ctcoffice.moc"
