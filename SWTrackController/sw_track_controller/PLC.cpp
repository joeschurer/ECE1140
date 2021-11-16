#include "PLC.h"

PLC::PLC(){
    //create the blue line
    track_model.create_line(1);

}

PLC::~PLC(){}

bool PLC::update_occupancy(int index){
    bool curr_occ = track_model.track[index].occupancy;
    if(curr_occ == false){
        track_model.track[index].occupancy = true;
        track_model.track[index].lights = 2;//set the light to red
        updateBlocks();
        return true;
    } else {
        //not good...
        return false;
    }
}

bool PLC::ctc_reccomend(bool a[151]){
    //find occupied blocks
    std::vector<int> occBlocks;
    int trackLength = static_cast<int>(track_model.track.size());
    for(int i=0;i<trackLength;i++){
        track_model.track[i].auth = a[i];
        //if block is occupied
        if(track_model.track[i].occupancy == true){
            occBlocks.push_back(track_model.track[i].block_num);
            track_model.track[i].lights = 2;
        }
    }

    //eventually move to PLC
    for(int i=0;i<trackLength;i++){
        if(track_model.track[i].switch_head == true){
            int connection = track_model.track[i].headConnect;
            if(track_model.track[connection].auth== false){
                track_model.toggle_switch(connection);
            }
        }
    }
    updateBlocks();
    return true;
}

block PLC::get_block(int index){

    return track_model.track[index];
}

void PLC::heater(int index,bool state){
    track_model.track[index].heater = state;
}

void PLC::set_maintenance_mode(int index, bool state){
    track_model.track[index].maintenance = state;
    if(state==true){
        track_model.track[index].lights = 2;
        track_model.track[index].comm_speed = 0;
    } else {
        if(track_model.track[index].occupancy == false){
            track_model.track[index].lights = 0;
            track_model.track[index].comm_speed = track_model.track[index].speed_limit;
        }
    }
}

bool PLC::get_maintenance_mode(int index){
    return track_model.track[index].maintenance;
}

void PLC::authUpdate(int index){
    std::vector<int> occBlocks;

}

bool PLC::updateBlocks(){
    //find occupied blocks
    std::vector<int> occBlocks;
    int trackLength = static_cast<int>(track_model.track.size());
    for(int i=0;i<trackLength;i++){
        //if block is occupied
        if(track_model.track[i].occupancy == true){
            occBlocks.push_back(track_model.track[i].block_num);
            track_model.track[i].lights = 2;
        }
    }

    //determine switch position

    //fix switch position if necessary

    //update blocks auth backwards
    /*while(!occBlocks.empty()){
       authUpdate(occBlocks.back());
       occBlocks.pop_back();
    }*/
    return true;
}

void PLC::toggleSwitch(int index){
    //only toggle if block is unoccupied
    index--;
    if(track_model.track[index].occupancy == false){
        int currentConnect = track_model.track[index].headConnect;
        track_model.track[currentConnect-1].tailConnect = -1;

        int newConnect = track_model.track[index].headOptions[0];
        if(track_model.track[index].headOptions[0] == currentConnect){
            newConnect = track_model.track[index].headOptions[1];
        }
        track_model.track[index].headConnect = newConnect;
        track_model.track[newConnect-1].tailConnect = index+1;




    }


}
