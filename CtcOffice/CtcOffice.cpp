#include "CtcOffice.h"
#include <QDebug>
#include <fstream>
#include <vector>

namespace utility {
vector<string> split(string s, string delimeter) {
    vector<string> result;
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
string convertMinutesToMinuteAndSecond(string time){
   int decimalPointIndex = time.find(".");
   string minuteString = time.substr(0,decimalPointIndex);
   double secondsInMinutes = std::stod(time.substr(decimalPointIndex));
   string seconds = std::to_string(secondsInMinutes*60).substr(0,2);
   if(seconds.back()=='.'){
   seconds.pop_back();
   seconds = "0" + seconds;
   }
   return minuteString + ":" + seconds;
}
}

CtcOffice::CtcOffice()
{
    numTrains_ = 0;
    parseTrack();
}

void CtcOffice::parseSchedule(std::ifstream &scheduleFile) {
    std::string line;
    // get line for column headers
    std::getline(scheduleFile, line);
    while(std::getline(scheduleFile, line)){
        vector<string> splitLine = utility::split(line, ",");
        scheduleEntry entry = {splitLine[0], splitLine[1],splitLine[2]};
        schedule_[numTrains_+1].push_back(entry);
    }
    numTrains_++;
    scheduleFile.close();
}

void CtcOffice::parseTrack() {
    std::ifstream trackFile;
    trackFile.open("C:\\Users\\akina\\OneDrive - University of Pittsburgh\\PITT\\PITT Senior Year\\Semester 1\\ECE 1140-Systems and Project Engineering\\Blue_Track_Layout.csv");
    // get line for column headers
    string line="chicken";
    std::getline(trackFile, line);
    while(std::getline(trackFile, line)){
        vector<string> splitLine = utility::split(line, ",");
        trackEntry entry = {splitLine[0], splitLine[1],splitLine[2], splitLine[5], splitLine[6]};
        track_.push_back(entry);
    }
}

int CtcOffice::computeRouteAuthority(std::string route){
    vector<string> splitRoute = utility::split(route, "->");
    string departure = splitRoute[0], destination = splitRoute[1];
    std::list<trackEntry>::iterator current=track_.begin();
    auto authority = 0;
    if(departure!="Yard") {
        // advance past departure station
        while(current->infrastructure!= departure){
            ++current;
        }
        ++current;
    }
    while (current->infrastructure!= destination){
       ++authority;
        ++current;
    }
    return ++authority;
}
int CtcOffice::computeRouteSuggestedSpeed(std::string route){
    vector<string> splitRoute = utility::split(route, "->");
    string departure = splitRoute[0], destination = splitRoute[1];
    std::list<trackEntry>::iterator current=track_.begin();
    auto suggestedSpeed = 1000;
    if(departure!="Yard") {
        // advance past departure station
        while(current->infrastructure!= departure){
            ++current;
        }
        ++current;
    }
    while (current->infrastructure!= destination){
        suggestedSpeed = std::min(suggestedSpeed, stoi(current->speedLimit));
        ++current;
    }
    return std::min(suggestedSpeed, stoi(current->speedLimit));
}

std::string CtcOffice::getRouteBlockList(std::string route){
    vector<string> splitRoute = utility::split(route, "->");
    string blockList = "";
    string departure = splitRoute[0], destination = splitRoute[1];
    std::list<trackEntry>::iterator current=track_.begin();
    if(departure!="Yard") {
        // advance to departure station
        while(current->infrastructure!= departure){
            ++current;
        }
    } else {
        blockList+=current->line + ":" + "Yard" + "->";
    }
    while (current->infrastructure!= destination){
        blockList+=current->line + ":" + current->section + ":" + current->blockNumber + "->";
        ++current;
    }
    blockList+=current->line + ":" + current->section + ":" + current->blockNumber;
    qDebug() << blockList.c_str();
    return blockList;
}

std::unordered_map<int, std::list<scheduleEntry>> CtcOffice::getSchedule(){
    return schedule_;
}

std::list<trackEntry> CtcOffice::getTrack(){
    return track_;
}

int CtcOffice::getNumTrains(){
    return numTrains_;
}

void CtcOffice::setNumTrains(int numTrains){
    numTrains_=numTrains;
}
