#include <QtTest/QtTest>
#include "C:\Users\jakeb\OneDrive\Documents\SWTrainController\swtraincontrollerui.cpp"

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
    SWTrainControllerUI SWTC;
    SWTC.CurrentSpeedChanged(10);
    int speed = SWTC.getCurrentSpeed();
    QCOMPARE(speed, 10);
}

void TrainController::testChangeEmergencyBrake()
{
    SWTrainControllerUI SWTC;
    SWTC.EmergencyBrakeChanged("true");
    bool EBrake = SWTC.getEmergencyBrakeState();
    QCOMPARE(EBrake, true);
}

void TrainController::testChangeDestination()
{
    SWTrainControllerUI SWTC;
    SWTC.DestinationChanged("Pittsburgh");
    std::string destination = SWTC.getDestination();
    QCOMPARE(destination, "Pittsburgh");
}

QTEST_APPLESS_MAIN(TrainController)

#include "tst_traincontroller.moc"
