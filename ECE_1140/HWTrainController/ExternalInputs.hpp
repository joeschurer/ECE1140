#ifndef EXTERNALINPUTS_H
#define EXTERNALINPUTS_H

class ExternalInputs {
    private:
        int trainWeight, speedLimit;
        double currentSpeed, commandedSpeed;
        bool failure;
        std::string trackSignal;
        char tmpArr[5];

    public:
        ExternalInputs();
        void setTrainWeight(int);
        void setSpeedLimit(int);
        void setCommandedSpeed(double);
        void setCurrentSpeed(double);
        void setFailure(bool);
        int getTrainWeight() const;
        int getSpeedLimit() const;
        double getCurrentSpeed() const;
        double getCommandedSpeed() const;
        bool getFailure() const;
        char *getCurrentSpeedStr();
        char *getCommandedSpeedStr();
        char *getSpeedLimitStr();
};

#include "ExternalInputs.cpp"
#endif