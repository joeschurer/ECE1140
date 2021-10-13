#include "track_layout.h"
track_layout::track_layout(){}
track_layout::~track_layout(){}

//push block onto the track
bool track_layout::new_block(block new_block){
    track.push_back(new_block);
    return true;
}

//create a track
bool track_layout::create_line(){
    //currently only blue
    double speed = 50;
    double elev = 0;

    for(int i=1; i<16; i++){
        block temp;
        temp.block_num = i;
        temp.speed_limit = speed;
        temp.heater = false;
        if(i==1){
            temp.yard=true;
        }
        if(i==5){
            temp.switch_head = true;
            temp.headOptions[0] = 6;
            temp.headOptions[1] = 11;
            temp.headConnect = 6;
        }
        if(i==6 || i == 11){
            temp.switch_tail = true;
            if(i==6){
                temp.tailConnect = 5;
            }
        }
        if(i==10){
            temp.station='B';
        }
        if(i==15){
            temp.station='C';
        }
        temp.auth = 10;
        temp.comm_speed = 50;
        new_block(temp);
    }

    return true;
}

//retrieve a block
//use 1 index
block track_layout::get_block(int index){
    return track.at(index);
}

bool track_layout::edit_block(){
    return true;
}
