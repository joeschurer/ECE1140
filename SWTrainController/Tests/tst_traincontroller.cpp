#include <QtTest/QtTest>
#include "C:\Users\jakeb\OneDrive\Documents\SWTrainController\traincontrol.cpp"

// add necessary includes here

class TrainController : public QObject
{
    Q_OBJECT

public:
    TrainController();
    ~TrainController();

private slots:
    void initTestCase();
    void cleanupTestCase();
    void testChangeCurrentSpeed();
    void testChangeEmergencyBrake();
    void testChangeDestination();

};

TrainController::TrainController()
{

}

TrainController::~TrainController()
{

}

void TrainController::initTestCase()
{

}

void TrainController::cleanupTestCase()
{

}

void TrainController::testChangeCurrentSpeed()
{
    traincontrol SWTC;
    SWTC.CurrentSpeedChanged(10);
    int speed = SWTC.getCurrentSpeed();
    QCOMPARE(speed, 10);
}

void TrainController::testChangeEmergencyBrake()
{
    traincontrol SWTC;
    SWTC.EmergencyBrakeChanged(false);
    bool EBrake = SWTC.getEmergencyBrakeState();
    QCOMPARE(EBrake, false);
}

void TrainController::testChangeDestination()
{
    traincontrol SWTC;
    SWTC.DestinationChanged("Pittsburgh");
    std::string destination = SWTC.getDestination();
    QCOMPARE(destination, "Pittsburgh");
}

QTEST_APPLESS_MAIN(TrainController)

#include "tst_traincontroller.moc"
