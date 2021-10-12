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
    bool ctc_reccomend(int,int,double);
    block get_block(int);
    void set_maintenance_mode(int,bool);
    bool get_maintenance_mode(int);

};

#endif // PLC_H
