#ifndef WAYSIDECONTROLLER_H
#define WAYSIDECONTROLLER_H
#include "track_layout.h"
#include "PLC.h"
class WaysideController{
private:
    track_layout track_model;
    //PLC waysides[10];
    vector<PLC> waysides;
    vector<vector<int>> waysideOwned;
    vector<int> toggledSwitches;
    vector<int> toggledCrossings;
public:
    WaysideController(int =0);
    //0 == gren, 1 == red
    ~WaysideController();

    bool update_occupancy(int);
    void heater(bool);
    vector<vector<int>> ctc_reccomend(std::vector<bool> a);//here get switch changes
    vector<vector<int>> ctc_test(int,int,int);
    block get_block(int);
    void set_maintenance_mode(int,bool);
    bool get_maintenance_mode(int);
    bool updateBlocks();
    void toggleSwitch(int);
    void authUpdate(bool[151]);
    bool uploadPLC(int,string fname);


    //CTC
    std::vector<bool> sendCTCOcc();
    bool maintenance_mode_switch(int,int);

    //Track Model
    vector<vector<int>> receiveOcc(std::vector<bool> occ);
    std::vector<bool> sendTrackModelAuth();
    //std::vector<int>  sendTrackModelSpeed();
    int sendTrackModelSpeed();
    std::vector<int> sendSwitchPos();

    //For UI
    vector<int> returnOwned(int);
    int returnNumWaysides();

    /*
    //CTC;

    void maintenaceSwitchCTC(std::vector<int> pos);
    void maintenanceModeCTC(std::vector<int> blocks);
    */

};


#endif // WAYSIDECONTROLLER_H
