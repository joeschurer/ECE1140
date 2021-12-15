#ifndef PLC_H
#define PLC_H
#include "track_layout.h"
#include "models.h"

//Joseph Schurer
//this class is an individual wayside

class PLC{
private:
    track_layout track_model;
    PLC* nextPLC = nullptr;
    PLC* prevPLC = nullptr;
    track_layout * track=nullptr;
    vector<int> ownedBlocks;
    vector<vector<string>> plcContainer;
    int index;
    int line = -1;//0 = green, 1= red
    vector<int> * toggledSwitches;
    vector<int> * toggledCrossings;

    void setPrev(int,int);
    int switchPrev(int);


public:
    vector<vector<int>> parsePLC();
    bool readPLCFile(string);
    vector<int> returnOwned();
    PLC();
    PLC(track_layout*,int,int,vector<int>*,vector<int>*);
    ~PLC();
    bool update_occupancy(int);
    void heater(int,bool);
    block get_block(int);
    void set_maintenance_mode(int,bool);
    bool get_maintenance_mode(int);
    bool updateBlocks();
    void toggleSwitch(int);
    void authUpdate(int);
    std::vector<bool> getAuth();
    bool maintenance_mode_switch(int,int);

    //CTC
    std::vector<int> ctc_reccomend(std::vector<bool> a);
    std::vector<bool> sendCTCOcc();
    void maintenaceSwitchCTC(std::vector<int> pos);
    void maintenanceModeCTC(std::vector<int> blocks);

    //Track Model
    void receiveOcc(std::vector<bool> occ);
    std::vector<bool> sendTrackModelAuth();
    int sendTrackModelSpeed();
    std::vector<int> sendSwitchPos();



};

#endif // PLC_H
