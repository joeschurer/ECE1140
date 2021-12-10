#include "waysidecontroller.h"
#include <QDebug>

WaysideController::WaysideController(int lineSel){
    track_model.create_line(lineSel);

    //divide sections between PLCs
    if(lineSel==0){//green
       for(int i=1;i<5;i++){
           PLC temp(&track_model,i,0,&toggledSwitches,&toggledCrossings);
           waysides.push_back(temp);
       }

    } else {// red
        for(int i=1;i<4;i++){
            PLC temp(&track_model,i,1,&toggledSwitches,&toggledCrossings);
            waysides.push_back(temp);
        }
    }

    //get the owned blocks
    for(int i=0;i<waysides.size();i++){
        waysideOwned.push_back(waysides[i].returnOwned());
    }
}

vector<int> WaysideController::returnOwned(int index){
    return waysideOwned[index-1];
}

int WaysideController::returnNumWaysides(){
    return waysides.size();
}

WaysideController::~WaysideController(){}

bool WaysideController::update_occupancy(int index){
    for(int i=0; i<waysides.size() ;i++){
        if(std::find(waysideOwned[i].begin(),waysideOwned[i].end(),index)!=waysideOwned[i].end()){
             waysides[i].update_occupancy(i);
        }
    }
    return true;
}

vector<vector<int>> WaysideController::ctc_reccomend(std::vector<bool> a){
    toggledSwitches.clear();
    for(int i=0;i<track_model.track.size();i++){
        qDebug() << a[i];
        track_model.track[i].auth = a[i];
    }

    vector<int> toggleSW,toggleCR;
    vector<vector<int>> temp;
    for(int i=0;i<waysides.size(); i++){
        vector<vector<int>>temp = waysides[i].parsePLC();
        toggleSW.insert(std::end(toggleSW), std::begin(temp[0]), std::end(temp[0]));
        toggleCR.insert(std::end(toggleCR), std::begin(temp[1]), std::end(temp[1]));
    }

    temp.push_back(toggleSW);
    temp.push_back(toggleCR);
    return temp;
}

//CTC Test
vector<vector<int>> WaysideController::ctc_test(int index,int auth,int speed){
    toggledSwitches.clear();
    track_model.track[index].auth = auth;
    track_model.track[index].sugg_speed = speed;

    vector<int> toggleSW,toggleCR;
    vector<vector<int>> temp;
    for(int i=0;i<waysides.size(); i++){
        vector<vector<int>>temp = waysides[i].parsePLC();
        toggleSW.insert(std::end(toggleSW), std::begin(temp[0]), std::end(temp[0]));
        toggleCR.insert(std::end(toggleCR), std::begin(temp[1]), std::end(temp[1]));
    }

    temp.push_back(toggleSW);
    temp.push_back(toggleCR);
    return temp;
}


//CTC
std::vector<bool> WaysideController::sendCTCOcc(){
    vector<bool> temp;
    for(int i=0;i<track_model.track.size(); i++){
        temp.push_back(track_model.track[i].occupancy);
    }

    return temp;
}

//Track Model
vector<vector<int>> WaysideController::receiveOcc(std::vector<bool> occ){
    for(int i=0;i<occ.size(); i++){
        track_model.track[i].occupancy = occ[i];
    }

    vector<int> toggleSW,toggleCR;
    vector<vector<int>> temp;
    for(int i=0;i<waysides.size(); i++){
        vector<vector<int>>temp = waysides[i].parsePLC();
        toggleSW.insert(std::end(toggleSW), std::begin(temp[0]), std::end(temp[0]));
        toggleCR.insert(std::end(toggleCR), std::begin(temp[1]), std::end(temp[1]));
    }

    temp.push_back(toggleSW);
    temp.push_back(toggleCR);
    return temp;
}

std::vector<bool> WaysideController::sendTrackModelAuth(){
    std::vector<bool> temp;
    for(int i=0;i<track_model.track.size(); i++){
        temp.push_back(track_model.track[i].auth);

    }

    return temp;
}

int WaysideController::sendTrackModelSpeed(){
    return track_model.track[0].sugg_speed;
}

block WaysideController::get_block(int index){

    return track_model.track[index];
}

void WaysideController::heater(bool state){
    for(int i=0;i<track_model.track.size(); i++){
        track_model.track[i].heater = state;
    }
}

void WaysideController::set_maintenance_mode(int index, bool state){
    track_model.track[index].maintenance =  state;
}

bool WaysideController::get_maintenance_mode(int index){
    return track_model.track[index].maintenance;
}

void WaysideController::authUpdate(bool auth[151]){
    std::vector<int> occBlocks;

}

bool WaysideController::updateBlocks(){

    return true;
}

void WaysideController::toggleSwitch(int index){
    track_model.toggle_switch(index);
}

bool WaysideController::maintenance_mode_switch(int block,int conn){
    if(track_model.track[block].switch_head==true){
        if(track_model.track[block].headOptions[0]==conn || track_model.track[block].headOptions[1]==conn){
            if(track_model.track[block].headConnect != conn){
                toggleSwitch(block);
                return true;
            }
        }
    }
    return false;
}


bool WaysideController::uploadPLC(int index, string fName){
    waysides[index].readPLCFile(fName);
    return true;
}
