#include "waysidecontroller.h"

WaysideController::WaysideController(){
    //create the blue line
    //track_model.create_line(1);

}

WaysideController::~WaysideController(){}

bool WaysideController::update_occupancy(int index){
    bool curr_occ = track_model.track[index-1].occupancy;
    if(curr_occ == false){
        track_model.track[index-1].occupancy = true;
        track_model.track[index-1].lights = 2;//set the light to red
        if(track_model.track[index-1].switch_tail == false){

            if(index>2){
                track_model.track[index-2].lights = 2;
                track_model.track[index-2].comm_speed = 0;
                if(track_model.track[index-3].occupancy == false){
                    track_model.track[index-3].lights = 1;
                }
            }
            else if(index == 2){
                track_model.track[index-2].lights =2;
            }
        } else {
            int connection = track_model.track[index-1].tailConnect;
            if(connection != -1){
                track_model.track[connection-1].lights = 2;
                track_model.track[connection-2].lights = 1;
            }
        }
        updateBlocks();
        return true;
    } else {
        //not good...
        return false;
    }
}

bool WaysideController::ctc_reccomend(bool auth[151]){
    return true;
}

block WaysideController::get_block(int index){

    return track_model.track[index-1];
}

void WaysideController::heater(int index,bool state){
    track_model.track[index-1].heater = state;
}

void WaysideController::set_maintenance_mode(int index, bool state){
    track_model.track[index-1].maintenance = state;
    if(state==true){
        track_model.track[index-1].lights = 2;
        track_model.track[index-1].comm_speed = 0;
    } else {
        if(track_model.track[index-1].occupancy == false){
            track_model.track[index-1].lights = 0;
            track_model.track[index-1].comm_speed = track_model.track[index-1].speed_limit;
        }
    }
}

bool WaysideController::get_maintenance_mode(int index){
    return track_model.track[index-1].maintenance;
}

void WaysideController::authUpdate(bool auth[151]){
    std::vector<int> occBlocks;

}

bool WaysideController::updateBlocks(){

    return true;
}

void WaysideController::toggleSwitch(int index){
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
