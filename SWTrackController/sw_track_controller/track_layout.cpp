#include "track_layout.h"
#include <fstream>
#include <string>
#include <iostream>
#include <QDebug>
#include <QFile>
#include "models.h"


std::vector<std::string> lineSplit(std::string s, std::string delimeter) {
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

track_layout::track_layout(){
    //create the red line for iteration 3
   // this->create_line(1);
}
track_layout::~track_layout(){}

//push block onto the track
bool track_layout::new_block(block new_block){
    track.push_back(new_block);
    return true;
}

//create a track
bool track_layout::create_line(int line){
    block tempYard;
    tempYard.yard=true;
    new_block(tempYard);

    //std::ifstream trackFile;
    //trackFile.open("C:\\Users\\daisy1\\Documents\\GitHub\\ECE1140\\train_sim\\GreenLine.txt");
    std::string fLine;
    QString fileName(":/line/GreenLine.txt");
    QFile inputFile(fileName);
    //getline(trackFile, fLine);
    //qDebug() << QString::fromStdString(fLine);
    if (inputFile.open(QIODevice::ReadOnly))
    {
        QTextStream in(&inputFile);
        QString temp = in.readLine();
        while (!in.atEnd()){
        //while(getline(trackFile, fLine)){
            QString line = in.readLine();
            std::string fLine = line.toStdString();
            block temp;
            std::vector<std::string> splitLine = lineSplit(fLine, ",");
            temp.section = splitLine[1][0];
            //std::cout<< temp.section <<std::endl;
            temp.block_num = std::stoi(splitLine[2]);
            //std::cout<<   temp.block_num<<std::endl;
            temp.speed_limit = std::stoi(splitLine[5]);
            //std::cout<< temp.speed_limit<<std::endl;
            std::string inf = splitLine[6];
            //std::cout<<  inf<<std::endl;
            if(inf.find("STATION") != std::string::npos){
                //std::cout << "STATION: ";
                temp.station = true;
                //std::cout<<  temp.station<<std::endl;
            } else if(inf.find("UNDERGROUND") != std::string::npos){
                temp.underground = true;
            }else if(inf.find("RAILWAY") != std::string::npos){
                //std::cout << "CROSSING: ";
                temp.crossing= true;
                temp.crossingState = false;
                //std::cout<<  temp.crossing<<std::endl;
            }else if(inf.find("SWITCH") != std::string::npos){
                //std::cout << "SWITCH: ";
                std::string sw = inf.substr(inf.find('(')+1,inf.find(')'));
                sw.pop_back();
                //std::cout<<  sw<<std::endl;
                temp.switch_head=true;
                if(sw.find("ard") != std::string::npos){
                    std::string left = sw.substr(0, sw.find('-'));
                    sw.erase(0, sw.find('-')+1);
                    std::string right = sw;
                    //std::cout << left << " : "<<right <<std::endl;
                    if(left.find("ar") != std::string::npos){
                        temp.headOptions[0] = 0;
                        temp.headOptions[1] = stoi(right);
                    } else {
                        temp.headOptions[0] = stoi(left);
                        temp.headOptions[1] = 0;
                    }
                    //std::cout << temp.headOptions[0] << " : "<<temp.headOptions[1] <<std::endl;

                } else {
                    std::string left = sw.substr(0, sw.find(';'));
                    sw.erase(0, sw.find(';')+2);
                    std::string right = sw;

                    std::string ltemp = left.substr(0,left.find('-'));
                    left.erase(0,left.find('-')+1);
                    if(stoi(ltemp)==temp.block_num){
                        temp.headOptions[0]=stoi(left);
                    } else {
                        temp.headOptions[0]=stoi(ltemp);
                    }

                    std::string rtemp = right.substr(0,right.find('-'));
                    right.erase(0,right.find('-')+1);
                    if(stoi(rtemp)==temp.block_num){
                        temp.headOptions[1]=stoi(right);
                    } else {
                        temp.headOptions[1]=stoi(rtemp);
                    }
                }
            }

            new_block(temp);
        }
        inputFile.close();
    }
    for (int i = 0; i < track.size(); i++)
    {
        if(track[i].switch_head==true){
            track[i].headConnect=track[i].headOptions[0];
            track[track[i].headOptions[0]].switch_tail = true;
            track[track[i].headOptions[0]].tailConnect = i;
            track[track[i].headOptions[1]].switch_tail = true;
        }
        track[i].auth = true;
    }

    //trackFile.close();
    return true;
}

//retrieve a block
block track_layout::get_block(int index){
    return track.at(index);
}

bool track_layout::add_block(){

    return true;
}

bool track_layout::toggle_switch(int index){
    if(track[index].occupancy==true){
        return false;
    }
    int current = track[index].headConnect;
    int nPos = track[index].headOptions[1];
    if(track[index].headOptions[1]==current){
        nPos = track[index].headOptions[0];
    }
    track[index].switch_pos= !track[index].switch_pos;
    track[index].headConnect=nPos;
    track[current].tailConnect=-1;
    track[nPos].tailConnect=index;

    return true;
}
