#include "waysidecontroller.h"

WaysideController::WaysideController(int lineSel){
    track_model.create_line(lineSel);

    //divide sections between PLCs
    if(lineSel==0){//green
       for(int i=0;i<4;i++){
           PLC temp(&track_model);
           waysides.push_back(temp);
       }

    } else {// red

    }
}

WaysideController::~WaysideController(){}

bool WaysideController::update_occupancy(int index){
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

}
