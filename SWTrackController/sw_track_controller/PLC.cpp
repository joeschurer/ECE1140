#include "PLC.h"

PLC::PLC(){
    //create the blue line
    track_model.create_line();
}

PLC::~PLC(){}

bool PLC::update_occupancy(int index){
    bool curr_occ = track_model.track[index-1].occupancy;
    if(curr_occ == false){
        track_model.track[index-1].occupancy = true;
        return true;
    } else {
        //not good...
        return false;
    }
}

bool PLC::ctc_reccomend(int index,int auth,double speed=0){
    //check speed
    index--;
    double speed_limit;
    //test authority forward
    int open=index;
    if(auth >15){
        auth=15;
    }

    for(int i=index+1;i<=auth;i++){
       if(track_model.track.at(i).occupancy == false){
           open = i;
       } else {
           break;
       }
    }
    for(int i=index;i<open;i++){
        track_model.track[i].auth = open;
        //update the speed
        speed_limit = track_model.track.at(i).speed_limit;
        track_model.track.at(i).sugg_speed = speed;
        if(speed > speed_limit){
            track_model.track.at(i).comm_speed = speed_limit;
        } else {
            track_model.track.at(i).comm_speed = speed;
        }

    }

    return true;
}

block PLC::get_block(int index){

    return track_model.track[index-1];
}

void PLC::heater(int index,bool state){
    track_model.track[index-1].heater = state;
}

void PLC::set_maintenance_mode(int index, bool state){
    track_model.track[index-1].maintenance = state;
}

bool PLC::get_maintenance_mode(int index){
    return track_model.track[index-1].maintenance;
}
