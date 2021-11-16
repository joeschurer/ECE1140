#ifndef WAYSIDECONTROLLER_H
#define WAYSIDECONTROLLER_H
#include "track_layout.h"
#include "PLC.h"
class WaysideController{
private:
    track_layout track_model;
    //PLC waysides[10];
    PLC wayside;

public:
    WaysideController();
    ~WaysideController();
    bool update_occupancy(int);
    void heater(int,bool);
    bool ctc_reccomend(bool[50]);
    block get_block(int);
    void set_maintenance_mode(int,bool);
    bool get_maintenance_mode(int);
    bool updateBlocks();
    void toggleSwitch(int);
    void authUpdate(bool[151]);

};


#endif // WAYSIDECONTROLLER_H
