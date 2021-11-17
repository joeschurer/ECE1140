#ifndef PLC_H
#define PLC_H
#include "track_layout.h"

class PLC{
private:
    track_layout track_model;

public:
    PLC();
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
