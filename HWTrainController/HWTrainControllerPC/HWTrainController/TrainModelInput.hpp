#ifndef TRAINMODELINPUT_HPP
#define TRAINMODELINPUT_HPP

#include <stdio.h>

class TrainModelInput {
    private:
        bool powerFailure, signalFailure, brakeFailure, authority, openLeftDoor, openRightDoor;
        int speedLimit;
        double suggestedSpeed, currentSpeed;
        char trackSignal[16];

    public:
        TrainModelInput();
        char *createWriteString();
        void setPowerFailure(bool b);
        void setSignalFailure(bool b);
        void setBrakeFailure(bool b);
        void setAuthority(bool b);
        void setOpenLeftDoor(bool b);
        void setOpenRightDoor(bool b);
        void setSpeedLimit(int i);
        void setSuggestedSpeed(double d);
        void setCurrentSpeed(double d);
        bool getPowerFailure() const;
        bool getSignalFailure() const;
        bool getBrakeFailure() const;
        bool getAuthority() const;
        bool getOpenLeftDoor() const;
        bool getOpenRightDoor() const;
        int getSpeedLimit() const;
        double getSuggestedSpeed() const;
        double getCurrentSpeed() const;
};

#include "TrainModelInput.cpp"

#endif // TRAINMODELINPUT_HPP
