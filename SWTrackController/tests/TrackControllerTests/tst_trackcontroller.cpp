#include <QtTest>

// add necessary includes here

class TrackController : public QObject
{
    Q_OBJECT

public:
    TrackController();
    ~TrackController();

private slots:
    void initTestCase();
    void cleanupTestCase();
    void test_case1();

};

TrackController::TrackController()
{

}

TrackController::~TrackController()
{

}

void TrackController::initTestCase()
{

}

void TrackController::cleanupTestCase()
{

}

void TrackController::test_case1()
{

}

QTEST_APPLESS_MAIN(TrackController)

#include "tst_trackcontroller.moc"
