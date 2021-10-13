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

bool PLC::ctc_reccomend(int index,int auth,double speed=0){
    //check speed
    index--;
    double speed_limit;
    //test authority forward
    int open=index;
    if(auth >15){
        auth=15;
    }

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

    for(int i=index+1;i<auth;i++){
       if(track_model.track.at(i).occupancy == false){
           open = i;
       } else {
           break;
       }
    }
    int tempStart,tempEnd;
    if(index<6){
        tempStart=index;
        tempEnd = 5;
        if(auth>5){
            if(auth < 11){
                for(int i=5;i<open;i++){
                    track_model.track[i].auth = open+1;
                    //update the speed
                    speed_limit = track_model.track.at(i).speed_limit;
                    track_model.track.at(i).sugg_speed = speed;
                    if(speed > speed_limit){
                        track_model.track.at(i).comm_speed = speed_limit;
                    } else {
                        track_model.track.at(i).comm_speed = speed;
                    }
                }
            } else {
                for(int i=10;i<open;i++){
                    track_model.track[i].auth = open+1;
                    //update the speed
                    speed_limit = track_model.track.at(i).speed_limit;
                    track_model.track.at(i).sugg_speed = speed;
                    if(speed > speed_limit){
                        track_model.track.at(i).comm_speed = speed_limit;
                    } else {
                        track_model.track.at(i).comm_speed = speed;
                    }
                }
            }
        }
    } else if(index < 11){
        tempStart=5;
        tempEnd = 11;
    } else{
        tempStart=10;
        tempEnd=14;

    }

    for(int i=tempStart;i<tempEnd;i++){
        track_model.track[i].auth = open+1;
        //update the speed
        speed_limit = track_model.track.at(i).speed_limit;
        track_model.track.at(i).sugg_speed = speed;
        if(speed > speed_limit){
            track_model.track.at(i).comm_speed = speed_limit;
        } else {
            track_model.track.at(i).comm_speed = speed;
        }

    }

    //fix switch position if necessary
    if(track_model.track[4].occupancy == false){
            if(track_model.track[4].auth > 5 && track_model.track[4].auth > 10 && track_model.track[4].headConnect != 11){
                toggleSwitch(5);
            } else if(track_model.track[4].auth > 5 && track_model.track[4].auth < 10 &&track_model.track[4].headConnect != 6){
                toggleSwitch(5);
            }
    }

    updateBlocks();
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

bool PLC::get_maintenance_mode(int index){
    return track_model.track[index-1].maintenance;
}

void PLC::authUpdate(int index){
    std::vector<int> occBlocks;

    if(index<6 && index> 0){//before switch
        for(int i=0;i<index-1;i++){
            //if block is occupied
            if(track_model.track[i].occupancy == true){
                occBlocks.push_back(i);
            }
        }
    } else if (index <11) {
        for(int i=5;i<index;i++){
            //if block is occupied
            if(track_model.track[i].occupancy == true){
                occBlocks.push_back(track_model.track[i].block_num);
            }
        }

    } else {
        for(int i=10;i<index;i++){
            //if block is occupied
            if(track_model.track[i].occupancy == true){
                occBlocks.push_back(track_model.track[i].block_num);
            }
        }
    }
    if(index>1){
        int dist;
        block temp;
        for(int i=occBlocks.back();i<index;i++){
            track_model.track[i].auth = index;

        }
    }
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
    int temp = -1;
    int len = static_cast<int>(occBlocks.size());
    for(int i=0;i<len;i++){
        if(occBlocks[i] <5){
            temp = occBlocks[i];
        }
    }

    //fix switch position if necessary
    if(track_model.track[4].occupancy == false){

        if(temp == -1){//no trains
            if(track_model.track[4].auth > 5 && track_model.track[4].auth > 10 && track_model.track[4].headConnect != 11){
                toggleSwitch(5);
            } else if(track_model.track[4].auth > 5 && track_model.track[4].auth < 10 && track_model.track[4].headConnect != 6){
                toggleSwitch(5);
            }
        } else{

            if(track_model.track[temp-1].auth > 5 && track_model.track[temp-1].auth > 10 && track_model.track[4].headConnect != 11){
                toggleSwitch(5);
            } else if(track_model.track[temp-1].auth > 5 && track_model.track[temp-1].auth < 10 &&track_model.track[4].headConnect != 6){
                toggleSwitch(5);
            }
        }
    }

    for(int i=0;i<trackLength;i++){
        //if block is occupied
        if(track_model.track[i].occupancy == true){
            track_model.track[i].lights = 2;
            if(i==1){
                track_model.track[0].lights=2;
            } else{
                //check for switch
                if(track_model.track[i].switch_tail == false && track_model.track[i-1].switch_tail==false){
                    track_model.track[i-1].lights = 2;
                    if(track_model.track[i-2].occupancy == false){
                        track_model.track[i-2].lights=1;
                    }
                } else {//handle switch
                    if(track_model.track[i].switch_tail == true){
                        int connection = track_model.track[i].tailConnect;
                        if(connection != -1){
                            track_model.track[connection-1].lights = 2;
                            if(track_model.track[i-2].occupancy == false){
                                track_model.track[i-2].lights=1;
                            }
                        }
                    } else {
                        int connection = track_model.track[i-1].tailConnect;
                        if(connection != -1){
                            if(track_model.track[connection-1].occupancy == false){
                                track_model.track[connection-1].lights=1;
                            }
                        }
                    }

                }

            }
        }
    }

    //update blocks auth backwards
    while(!occBlocks.empty()){
       authUpdate(occBlocks.back());
       occBlocks.pop_back();
    }
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
