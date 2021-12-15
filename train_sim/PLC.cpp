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

std::vector<int> GetValues(std::string str){
    std::vector<int> v;
    std::stringstream ss(str);
    int i;
    while (ss >> i){
        v.push_back(i);
        //qDebug() << i;
        if (ss.peek() == ',')
            ss.ignore();
    }
    return v;
}

void push_range_or_number(const std::string &str, std::vector<int> &out) {
    size_t hyphen_index;
    int first = std::stoi(str, &hyphen_index);
    out.push_back(first);
    if (hyphen_index != str.size()) {
        int second = std::stoi(str.substr(hyphen_index + 1), &hyphen_index);
        for (int i = first + 1; i <= second; ++i) {
            out.push_back(i);
        }
    }
}

//returns
void PLC::setPrev(int index,int gap =3){
    //starting behind the train


    int tempIndex=index;
    bool otherOcc=false;
    vector<int> prevVec;
    for(int i=0; i< gap+2;i++){
        if(track->track[tempIndex].occupancy==true && i>0){
            otherOcc=true;
            break;
        }

        if(track->track[tempIndex].switch_tail==true){
            int nextPrev = switchPrev(tempIndex);
            if(nextPrev == -1){
                break;
            }
            prevVec.push_back(nextPrev);
            tempIndex = nextPrev;
        }else{
            tempIndex = track->track[tempIndex].prev;
            prevVec.push_back(track->track[tempIndex].prev);
        }

    }

    for(int i=0;i<prevVec.size();i++){
        track->track[prevVec[i]].auth= (!otherOcc);
    }

}

//return the index of the previous block if it is a switch
int PLC::switchPrev(int index){
    //do switch heads matter here, maybe not...
    int prev = track->track[index].prev;
    //is the previous a switch connecting to it
    if(track->track[prev].switch_head==true){
        if(track->track[prev].tailConnect == index){
            return prev;

        } else {
            return -1;
        }
    }
    return prev;
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
        ownedBlocks.clear();
        plcContainer.clear();
        while (!in.atEnd()){
            QString line = in.readLine();
            std::string inputString = line.toStdString();
            if(start==0){
                inputString.erase(0,6);
                //qDebug() << QString::fromStdString(inputString);
                ownedBlocks = GetValues(inputString);

                start++;
            } else if(start ==1){
                inputString.erase(0,6);
                //qDebug() << QString::fromStdString(inputString);
                std::vector<int> temp = GetValues(inputString);
                for(int i=0;i<temp.size();i++){
                    ownedBlocks.push_back((temp[i]));
                }
                start++;
            } else {
                std::vector<std::string> fileLines;
                //qDebug() << QString::fromStdString(inputString);
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

    for(int i=0;i<ownedBlocks.size();i++){
        qDebug() << ownedBlocks[i];
    }
    inputFile.close();
    return true;
}

vector<vector<int>> PLC::parsePLC(){
    vector<int> toggleSW,toggleCROSS;
    vector<vector<int>> temp;
    for(int i=0;i< plcContainer.size();i++){
        int authSel;
        vector<int> lauthVec,rauthVec;
        bool waiting = false;
        bool letGo = false;
        int BL, SWPOS;
        if(plcContainer[i][0] == "IF" && plcContainer[i][2]=="THEN"){
            if (plcContainer[i][1].substr(0,2) == "BL"){
                BL = std::stoi(plcContainer[i][1].substr(2,plcContainer[i][1].length()));
                SWPOS = std::stoi(plcContainer[i][3].substr(2,plcContainer[i][3].length()));

                //toggle switch
                if(track->track[BL].occupancy==true){

                } else {

                }
            }
            else if (plcContainer[i][1].substr(0,4) == "AUTH"){
                lauthVec = GetValues(plcContainer[i][5]);
                rauthVec = GetValues(plcContainer[i][7]);
                BL = std::stoi(plcContainer[i][1].substr(4,plcContainer[i][1].length()));
                SWPOS = std::stoi(plcContainer[i][3].substr(2,plcContainer[i][3].length()));
                //check for occupancy on switch
                if(track->track[SWPOS].occupancy==true || track->track[SWPOS].maintenance == true){
                    qDebug() << "Avoiding switching occupied/maintenance switch";
                } else {

                    //Check the check blocks
                    bool safe = true;
                    for(int i=0; i<track->track[SWPOS].check.size(); i++){
                        int index = track->track[SWPOS].check[i];
                        if(track->track[index].occupancy == true){
                            safe = false;
                            qDebug() << "Stopped unsafe switching at " << SWPOS << " due to occ at "<< index;
                        }
                    }

                    //get the auth of tails to do routing
                    bool authBL = track->track[BL].auth;
                    bool auth2 = track->track[track->track[SWPOS].headOptions[1]].auth;
                    if(track->track[SWPOS].headOptions[0] != BL){
                        auth2 = track->track[track->track[SWPOS].headOptions[0]].auth;
                    }

                    //Check for an occupancy to allow switching
                    //if LAUTH is occupied and CHECK is clear allow that train to leave
                    for(int i=0;i<lauthVec.size();i++){
                        if(track->track[lauthVec[i]].occupancy == true){
                            waiting = true;//train waiting to leave loop
                        }
                    }
                    if(track->track[SWPOS].headConnect==BL){
                        if(waiting==true && safe==true){
                            qDebug()<< "Toggling to allow passing of switch: " << SWPOS;
                            track->toggle_switch(SWPOS);
                            toggleSW.push_back(SWPOS);
                            qDebug()<< "Toggled switch: " << SWPOS;
                            letGo = true;
                        }
                    }

                    //check for auth on the block
                    if(track->track[BL].auth == true || (auth2 == true && authBL ==true)){
                         qDebug() << "Switch: " << SWPOS << "auth for: " << BL << "curr conn:" <<track->track[SWPOS].headConnect;
                        if(track->track[SWPOS].headConnect!=BL){
                            //if safe switch
                            if(safe == true && letGo == false){
                                track->toggle_switch(SWPOS);
                                toggleSW.push_back(SWPOS);
                                qDebug()<< "Toggled switch: " << SWPOS;

                                //set the authority in the proper position
                            }
                        }
                    } else {
                        if(track->track[SWPOS].headConnect==BL){
                            qDebug() << "Switch: " << SWPOS << "auth for: " << BL << "curr conn:" <<track->track[SWPOS].headConnect;
                            //if safe switch
                            if(safe == true && letGo == false){
                                track->toggle_switch(SWPOS);
                                toggleSW.push_back(SWPOS);
                                qDebug()<< "Toggled switch: " << SWPOS;

                            }
                        }
                    }

                    if(track->track[SWPOS].headConnect==BL){//USE LAUTH
                        if(lauthVec[0]!= -1){
                            for(int i=0; i< lauthVec.size();i++){
                                track->track[lauthVec[i]].auth = false;
                            }
                        }
                        if(rauthVec[0]!= -1){
                            for(int i=0; i< rauthVec.size();i++){
                                track->track[rauthVec[i]].auth = true;
                            }
                        }
                    }else {
                        if(lauthVec[0]!= -1){
                            for(int i=0; i< lauthVec.size();i++){
                                track->track[lauthVec[i]].auth = true;
                            }
                        }
                        if(rauthVec[0]!= -1){
                            for(int i=0; i< rauthVec.size();i++){
                                track->track[rauthVec[i]].auth = false;
                            }
                        } else {
                            //qDebug() << "hi";
                        }
                    }
                }
            }
        } else if(plcContainer[i][0] == "CROSSING"){
           int cross = std::stoi(plcContainer[i][1]);
            if(track->track[cross].occupancy == true || track->track[cross-1].occupancy == true ||track->track[cross+1].occupancy == true ){
                track->track[cross].crossingState = true;
                qDebug() << "Crossing active at: " << cross;
                toggleCROSS.push_back(cross);
            } else if(track->track[cross].crossingState == true){
                track->track[cross].crossingState = false;
                toggleCROSS.push_back(cross);
            }
        }
    }

    //update authority with gap
    vector<int> newAuth;
    int gap = 3;//maybe read from PLC
    vector<int> occVector;

    for(int i=0;i<ownedBlocks.size();i++){
        if(track->track[ownedBlocks[i]].occupancy==true || track->track[ownedBlocks[i]].maintenance == true){
           setPrev(ownedBlocks[i]);
        }
    }

    //Handle Lights
    for(int i=0;i<ownedBlocks.size();i++){
        if(track->track[ownedBlocks[i]].hasLights==true){
            bool inCheck= false;
            for(int j=0;j<track->track[ownedBlocks[i]].check.size();j++){
                int block = track->track[ownedBlocks[i]].check[j];
                if(track->track[block].occupancy== true){
                    track->track[ownedBlocks[i]].lights = 1;
                    inCheck = true;
                }
            }

            if(track->track[ownedBlocks[i]].auth== false){
                track->track[ownedBlocks[i]].lights = 2;
            } else if(inCheck==false){
                track->track[ownedBlocks[i]].lights = 0;
            }
        }
    }

    for(int i=0;i<track->track.size();i++){
        if(track->track[i].auth==0){
            newAuth.push_back(0);
        } else {
            newAuth.push_back(1);
        }
    }

  /*  updateData toSend;
    toSend.toggledCrossings = toggleCROSS;
    toSend.toggledSwitches = toggleSW;
    */
    //toSend.auth = newAuth;

    temp.push_back(toggleSW);
    temp.push_back(toggleCROSS);
    temp.push_back(newAuth);
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
    vector<int> temp;
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
