#ifndef EXTERNALINPUTS_H
#define EXTERNALINPUTS_H

#include <cstring>

class ExternalInputs {
    private:
        int speedLimit;
        double currentSpeed, suggestedSpeed;
        bool powerFailure, brakeFailure, signalFailure, authority;
        char tmpArr[5], speedLimitStr[3], currentStr[5], suggestedStr[5];

    public:
        ExternalInputs();
        void parseTrackSignal(char *);
        void setSpeedLimit(int);
        void setSuggestedSpeed(double);
        void setCurrentSpeed(double);
        void setFailure(bool);
        int getSpeedLimit() const;
        double getCurrentSpeed() const;
        double getSuggestedSpeed() const;
        bool getFailure() const;
        char *getCurrentSpeedStr();
        char *getSuggestedSpeedStr();
        char *getSpeedLimitStr();
};

#include "ExternalInputs.cpp"
#endif