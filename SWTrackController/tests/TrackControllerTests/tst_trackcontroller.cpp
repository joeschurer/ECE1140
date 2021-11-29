#include <QtTest>
#include "PLC.cpp"

class TrackController : public QObject
{
    Q_OBJECT

public:
    TrackController();
    ~TrackController();

private slots:
    void initTestCase();
    void cleanupTestCase();
    void test_maintenance();

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

void TrackController::test_maintenance(){
    PLC plc;
    //test simple maintenance mode
    QVERIFY2(plc.get_maintenance_mode(1)==false,"Mainenetance mode should be false at start. May fail if track path is wrong in track_layout.cpp");
    plc.set_maintenance_mode(1,true);
    QVERIFY2(plc.get_maintenance_mode(1)==true,"Mainenetance mode toggled");
    plc.set_maintenance_mode(1,true);
    QVERIFY2(plc.get_maintenance_mode(1)==true,"Mainenetance mode should remain true");
    plc.set_maintenance_mode(1,false);
    QVERIFY2(plc.get_maintenance_mode(1)==false,"Mainenetance mode should again be false");

}

QTEST_APPLESS_MAIN(TrackController)

#include "tst_trackcontroller.moc"
