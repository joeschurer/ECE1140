#include "PLC.h"
#include <QTextStream>
#include <QDebug>
#include <sstream>

std::vector<std::string> linetoStrings(std::string s, std::string delimeter) {
    std::vector<std::string> result;
    int start = 0;
    int end = s.find(delimeter);
    while(end!=-1) {
        result.push_back(s.substr(start, end-start));
        start = end + delimeter.size();
        end = s.find(delimeter, start);
    }
    result.push_back(s.substr(start, end-start));
    return result;
}

std::vector<int> GetValues(std::string str)
{
    std::vector<int> v;
    std::stringstream ss(str);

    int i;

    while (ss >> i)
    {
        v.push_back(i);
        //qDebug() << i;
        if (ss.peek() == ',')
            ss.ignore();
    }

    return v;
}

PLC::PLC(){
    //create the blue line
    track_model.create_line(1);

}

bool PLC::readPLCFile(string file){
    QString fName = QString::fromStdString(file);
    QFile inputFile(fName);
    int start = 0;
    if (inputFile.open(QIODevice::ReadOnly)){
        QTextStream in(&inputFile);
        QString temp = in.readLine();// strip the comment from top

        while (!in.atEnd()){
            QString line = in.readLine();
            std::string inputString = line.toStdString();
            if(start==0){
                inputString.erase(0,6);
                qDebug() << QString::fromStdString(inputString);
                ownedBlocks = GetValues(inputString);
                start++;
            } else if(start ==1){
                inputString.erase(0,6);
                qDebug() << QString::fromStdString(inputString);
                std::vector<int> temp = GetValues(inputString);
                for(int i=0;i<temp.size();i++){
                    ownedBlocks.push_back((temp[i]));
                }
                start++;
            } else {
                std::vector<std::string> fileLines;
                qDebug() << QString::fromStdString(inputString);
                if(inputString[0] != '#'){
                    fileLines = linetoStrings(inputString," ");
                    plcContainer.push_back(fileLines);
                }
            }
        }
    } else{
        qDebug() << "File could not be opened." << fName;
        return false;
    }

    //for(int i=0;i<ownedBlocks.size();i++){
       // qDebug() << ownedBlocks[i];
    //}
    inputFile.close();
    return true;
}

vector<vector<int>> PLC::parsePLC(){
    vector<int> toggleSW,toggleCROSS;
    for(int i=0;i< plcContainer.size();i++){
        int BL, SWPOS;
        if(plcContainer[i][0] == "IF" && plcContainer[i][2]=="THEN"){
            if (plcContainer[i][1].substr(0,2) == "BL"){
                BL = std::stoi(plcContainer[i][1].substr(2,plcContainer[i][1].length()));
                SWPOS = std::stoi(plcContainer[i][3].substr(2,plcContainer[i][3].length()));

                //toggle switch
                if(track->track[BL].occupancy==true){

                } else {
                   // track->track[SWPOS]=false;
                }
            }
            else if (plcContainer[i][1].substr(0,4) == "AUTH"){
                BL = std::stoi(plcContainer[i][1].substr(4,plcContainer[i][1].length()));
                SWPOS = std::stoi(plcContainer[i][3].substr(2,plcContainer[i][3].length()));
                //check for occupancy on switch
                if(track->track[SWPOS].occupancy==true || track->track[SWPOS].maintenance == true){
                    qDebug() << "Avoiding switching occupied/maintenance switch";
                } else {
                    if(track->track[SWPOS].headConnect!=BL){
                        qDebug() << "Switch: " << SWPOS << "auth for: " << BL << "curr conn:" <<track->track[SWPOS].headConnect;
                        track->toggle_switch(SWPOS);
                        toggleSW.push_back(SWPOS);
                        qDebug()<< "Toggled switch: " << SWPOS;
                    }
                }

            }
        } else if(plcContainer[i][0] == "CROSSING"){
            int cross = std::stoi(plcContainer[i][1]);
            if(track->track[cross].occupancy == true){
                track->track[cross].crossing == true;
                qDebug() << "Crossing active at: " << cross;
            } else{
                toggleCROSS.push_back(cross);
                track->track[cross].crossing == false;
            }
        }
    }

    //update authority with gap
    vector<bool> newAuth;
    int gap = 2;//maybe read from PLC
    for(int i=0;i<track->track.size(); i++){
        if(track->track[i].occupancy==true){
            //search for trains in 3 blocks on either side
        }
    }

    //also consider updating authority for empty blocks
    //something like looking for non-switch blocks and if not near a train flip back to one
    //am tired but it might be that if there is only one train you can still give authority
    //count maintenance mode as an occupancy for these purposes
    //probably needs to happen last
    updateData toSend;
    toSend.toggledCrossings = toggleCROSS;
    toSend.toggledSwitches = toggleSW;
    toSend.auth = newAuth;

    vector<vector<int>> temp;
    temp.push_back(toggleSW);
    temp.push_back(toggleCROSS);
    return temp;
}
vector<int> PLC::returnOwned(){
    return ownedBlocks;
}

PLC::PLC(track_layout *in,int ind,int l,vector<int>* switchVector, vector<int> *crossingVector){
    track = in;
    index = ind;
    line = 0;
    string lFile = "g";
    if(l==1){lFile = "r";}
    string fName = ":/PLC/PLCs/PLCdefault"+lFile+std::to_string(ind)+".plc";
    toggledSwitches= switchVector;
    toggledCrossings = crossingVector;
    readPLCFile(fName);
}

PLC::~PLC(){
    nextPLC = nullptr;
    prevPLC = nullptr;
    track=nullptr;
    toggledSwitches= nullptr;
}

bool PLC::update_occupancy(int index){
    track->track[index].occupancy == true;
    parsePLC();
    return true;
}

std::vector<int> PLC::ctc_reccomend(std::vector<bool> a){
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
    std::vector<int> temp;
    for(int i=0;i<trackLength;i++){
        if(track_model.track[i].switch_head == true){
            int connection = track_model.track[i].headConnect;
            if(track_model.track[connection].auth== false){
                track_model.toggle_switch(connection);
                temp.push_back(i);
            }
        }
    }
    updateBlocks();
    return temp;
}

block PLC::get_block(int index){

    return track_model.track[index];
}

void PLC::heater(int index,bool state){
    track_model.track[index].heater = state;
}

void PLC::set_maintenance_mode(int index, bool state){
    if(index<148 && index>0){
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

    return true;
}

void PLC::toggleSwitch(int index){
    //only toggle if block is unoccupied
    //index--;
    if(track_model.track[index].occupancy == false){
        int currentConnect = track_model.track[index].headConnect;
        track_model.track[currentConnect].tailConnect = -1;

        int newConnect = track_model.track[index].headOptions[0];
        if(track_model.track[index].headOptions[0] == currentConnect){
            newConnect = track_model.track[index].headOptions[1];
        }
        track_model.track[index].headConnect = newConnect;
        track_model.track[newConnect].tailConnect = index;
    }
}

//send akin the occupancy
std::vector<bool> PLC::sendCTCOcc(){
    //construct occ vetctor
    std::vector<bool> occVector;

    for(int i=1;i<track_model.track.size();i++){
        if(track_model.track[i].occupancy == true){
            occVector.push_back(true);
        } else {
            occVector.push_back(false);
        }
    }

    return occVector;
}

void PLC::receiveOcc(std::vector<bool> occ){
    for(int i=1;i<track_model.track.size();i++){
        if(occ[i-1]==true){
            track_model.track[i].occupancy=true;
        } else {
            track_model.track[i].occupancy=false;
        }
    }
}

std::vector<bool> PLC::getAuth(){
    std::vector<bool> temp;
    for(int i=0;i<track_model.track.size();i++){
        temp.push_back(track_model.track[i].auth);
    }
    return temp;
}

bool PLC::maintenance_mode_switch(int block,int conn){
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
