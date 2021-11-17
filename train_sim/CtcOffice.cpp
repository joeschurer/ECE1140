#include "CtcOffice.h"
#include <QDebug>
#include <fstream>
#include <vector>
#include <queue>
#include <math.h>

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

CtcOffice::CtcOffice(TrackLine line)
{
    numTrains_ = 0;
    parseTrack();
    setupLine(line);
}

void CtcOffice::setupLine(TrackLine line){
    currentLine = line;
    if (line==Green) {
        buildGreenLineGraph();
        buildGreenStationMap();
        // can only use switches if you were traveling in the direction of the switch
        //63 to 62 or 63 to yard
        trackSwitchNodes = {{13,14},
                            {29, 28},
                            {57, 56},
                            {77,78},
                            {85,84},
                            {63,64}
                           };
    }
}
void CtcOffice::parseSchedule(std::ifstream &scheduleFile) {
    std::string line;
    // get line for column headers
    std::getline(scheduleFile, line);
    while(std::getline(scheduleFile, line)){
        vector<string> splitLine = utility::split(line, ",");
        addScheduleEntry(stoi(splitLine[0]), splitLine[1], splitLine[2], splitLine[3]);
        //ScheduleEntry entry = {splitLine[1], toPairTime(splitLine[2])};
        //schedule_[stoi(splitLine[0])].push_back(entry);
    }
    // maybe not neccesary, want to track number of dispatched trains
    numTrains_++;
    scheduleFile.close();
}

Time CtcOffice::toPairTime(string time){
    auto splitResult = utility::split(time,":");
    return {stoi(splitResult[0]),stoi(splitResult[1])};

}

string CtcOffice::toStringTime(Time time){
    string hourString = time.first<10? "0" + std::to_string(time.first): std::to_string(time.first);
    string minuteString = time.second<10? "0" + std::to_string(time.second): std::to_string(time.second);
    return hourString + ":" + minuteString;

}

void CtcOffice::parseTrack() {
    std::ifstream trackFile;
    trackFile.open("C:\\Users\\akina\\OneDrive - University of Pittsburgh\\PITT\\PITT Senior Year\\Semester 1\\ECE 1140-Systems and Project Engineering\\Green_Track_Layout.csv");
    // get line for column headers
    string line="chicken";
    std::getline(trackFile, line);
    while(std::getline(trackFile, line)){
        vector<string> splitLine = utility::split(line, ",");
        TrackEntry entry = {splitLine[0], splitLine[1], stoi(splitLine[5]), stoi(splitLine[3]), splitLine[6]};
        track_.push_back(entry);
    }
}

vector<int> CtcOffice::getRoute(int startingBlock, int destinationBlock) {
    std::queue<int> q;
    vector<int> route;
    vector<bool>visited (151, false);

    vector<int> prev(151);
    q.push(startingBlock);
    visited[startingBlock]=true;
    prev[startingBlock]=-1;
    bool destinationFound = false;

    while(!q.empty()) {
           int v = q.front();
           q.pop();
           for(int u: trackGraph[v]) {
               // Todo: check not in closed tracks
               if(v>=77){
                    string s = "hi";
               }
               bool isTrainBackingUp = trackSwitchNodes.count(v)==1 && prev[v]!=trackSwitchNodes[v] && std::abs(u-v)!=1 && v!=startingBlock;
               bool isIllegallyEnteringYard = u==0 && destinationBlock!=0;
                if(!visited[u] && !isTrainBackingUp && closedBlocks.count(u)==0 && !isIllegallyEnteringYard) {
                   visited[u]=true;
                   q.push(u);
                   prev[u] = v;
                   if(u == destinationBlock) {
                      destinationFound = true;
                      break;
                    }
               }
           }
           if(destinationFound){
               break;
           }
    }
    if(destinationFound) {
        for(int v = destinationBlock; v!=-1; v = prev[v]) {
            route.push_back(v);
        }
        reverse(route.begin(), route.end());
        qDebug() << "path: ";
        for (auto block: route) {
            std::string blockString = std::to_string(block) + "->";
            qDebug() << blockString.c_str();
        }
        return route;
    } else {
        qDebug() << "No route found";
        return {};
    }
}

Time CtcOffice::toTimeFromSeconds(int time){
    int hour = time/3600;
    int minute = (time%3600)/60;
    return {hour, minute};
}

void CtcOffice::addScheduleEntry(int trainNumber, string start, string destination, string arrivalTime){
    ScheduleEntry scheduleEntry;
    scheduleEntry.arrivalTime=toPairTime(arrivalTime);
    int size = stationMap[start].size();
    int startBlock;
    // station can be accesed from multiple blocks. Must start at block where the last schedule entry ended.
    if(size>1 && schedule_[trainNumber].size()>0) {
        startBlock = schedule_[trainNumber][size-1].destination;
        scheduleEntry.start = startBlock;
    } else {
        startBlock = stationMap[start][0];
        scheduleEntry.start = startBlock;
    }

    auto stationBlocks = stationMap[destination];
    int destinationBlock;
    if(stationBlocks.size()==1) {
        destinationBlock = stationBlocks[0];
        scheduleEntry.destination = stationBlocks[0];
        scheduleEntry.destinationString = destination;
        auto route = getRoute(startBlock, destinationBlock);
        scheduleEntry.authority = computeAuthority(route);
        scheduleEntry.suggestedSpeed = computeSuggestedSpeed(route);
    } else {
        scheduleEntry.destinationString = destination;
        auto route1 = getRoute(0, stationBlocks[0]);
        auto route2 = getRoute(0, stationBlocks[1]);
        scheduleEntry.destination = route1.size()<route2.size()? stationBlocks[0]: stationBlocks[1];
        scheduleEntry.authority = route1.size()<route2.size()? computeAuthority(route1): computeAuthority(route2);
        scheduleEntry.suggestedSpeed = route1.size()<route2.size()? computeSuggestedSpeed(route1): computeSuggestedSpeed(route2);
        int timeToDestination = route1.size()<route2.size()? computeTimeToDestination(route1): computeTimeToDestination(route2);
        auto pairArrivalTime = toPairTime(arrivalTime);
        auto arrivalTimeInSeconds = pairArrivalTime.first*60*60 + pairArrivalTime.second*60;

        scheduleEntry.departureTime = toTimeFromSeconds(arrivalTimeInSeconds-timeToDestination);
    }
    schedule_[trainNumber].push_back(scheduleEntry);
}

void CtcOffice::buildGreenStationMap() {
    stationMap["Yard"] = {0};
    stationMap["Pioneer"] = {2};
    stationMap["Edgebrook"] = {9};
    stationMap["South Bank"] = {31};
    stationMap["Central"] = {39,141};
    stationMap["Station"] = {16};
    stationMap["Whited"] = {22};
    stationMap["IngleWood"] = {48,132};
    stationMap["Overbrook"] = {57,123};
    stationMap["Glenbury"] = {65,114};
    stationMap["Dormont"] = {105,73};
    stationMap["Mt Lebanon"] = {77};
    stationMap["Poplar"] = {88};
    stationMap["Castle Shannon"] = {96};

}

TrainEntry CtcOffice::dispatchTrain(int trainNumber, ScheduleEntry scheduleEntry){
    qDebug() << "dispatching train " << trainNumber;
    TrainEntry t = {trainNumber, scheduleEntry.suggestedSpeed, scheduleEntry.authority};
    dispatchedTrains.push_back(t);
    return t;
}

bool CtcOffice::checkForDispatch(int time){
    for(auto element: schedule_) {
        for(auto scheduleEntry: element.second){
           int timeInSeconds = scheduleEntry.departureTime.first*60*60 + scheduleEntry.departureTime.second*60;
           if(timeInSeconds==time){
               dispatchTrain(element.first, scheduleEntry);
               return true;
           }
        }
    }
    return false;
}

vector<TrainEntry> CtcOffice::getDispatchedTrains(){
    return dispatchedTrains;
}
vector<int> CtcOffice::sendSwitchPosition(int switchNode, int blockToConnect){
    return {switchNode, blockToConnect};
}

vector<bool> CtcOffice::sendClosedBlocks(){
    vector<bool> isBlockClosed(150);
    for(int i = 0; i<150; i++) {
        if(closedBlocks.count(i)==1){
            isBlockClosed[i] = true;
        }
    }
    return isBlockClosed;
}

void CtcOffice::updateOccupancy(vector<bool> occupancy){
    // TODO: Check for track failure
    occupancies = occupancy;
    // TODO: update authority, need a slot for this
}

void CtcOffice::buildGreenLineGraph() {
    trackGraph = vector<vector<int>>(151);
    trackGraph[0].push_back(63); // edge from yard to block 63
    // section A
    for(int i = 1; i<4; i++) {
        if(i == 1){
            trackGraph[i].push_back(13); //switch

        } else {
             trackGraph[i].push_back(i-1);
        }
    }

    //Section B-C
    for(int i = 4; i<13; i++) {
        trackGraph[i].push_back(i-1);
    }

    // Section D - F
    for(int i = 13; i<29; i++) {
        trackGraph[i].push_back(i-1);
        trackGraph[i].push_back(i+1);
    }
    // Section G-H
    for(int i = 29; i<36; i++) {
        trackGraph[i].push_back(i+1);
    }

    // Section I

    for(int i = 36; i<58; i++) {
        if(i ==57) {
            trackGraph[i].push_back(0);
        }
        trackGraph[i].push_back(i+1);
    }
    // Section J - M
    for(int i = 58; i<77; i++) {
        trackGraph[i].push_back(i+1);
    }
    // Section N
    for(int i = 77; i<86; i++) {
        if(i == 77){
            trackGraph[i].push_back(101);
        }
        trackGraph[i].push_back(i+1);
        trackGraph[i].push_back(i-1);
    }
    // Section O-Z
    for(int i = 86; i<150; i++) {
        trackGraph[i].push_back(i+1);
    }
    trackGraph[150].push_back(29);

}

int CtcOffice::computeTimeToDestination(vector<int> route) {
    double timeToDestination = 0;
    int suggestedSpeed = computeSuggestedSpeed(route);
    int totalBlockLength = 0;
    int stationsToStopAt = 0;
    for(auto block: route) {
        if(block==0)
            continue;
        totalBlockLength += track_[block-1].blockLength;
        string infrastructure = track_[block-1].infrastructure;

        if(infrastructure.find("STATION")!=string::npos){
            // 30 second dwell
            stationsToStopAt++;
            // TODO: Don't include destination station in time
        }

    }
    // in seconds
    timeToDestination = ((totalBlockLength/1000.00)/suggestedSpeed)*60*60 + stationsToStopAt*30;
    return ceil(timeToDestination);
    // return time in minutes
    //return std::ceil(timeToDestination/60);
}

int CtcOffice::computeSuggestedSpeed(vector<int> route){
    int suggestedSpeed = 100; // TODO: may want to make this meters per second
    for(auto block: route) {
        if(block==0)
            continue;
        int speedLimit = track_[block-1].speedLimit;
        suggestedSpeed = std::min(suggestedSpeed, speedLimit);
    }
    // In Km/hr
    return suggestedSpeed;
}

std::unordered_set<int> CtcOffice::getClosedBlocks(){
    return closedBlocks;
}

vector<bool> CtcOffice::computeAuthority(vector<int> route){
    vector<bool> authority(151,false);
    for(auto block: route) {
        authority[block]=true;
    }
    return authority;
}
void CtcOffice::addClosedBlocks(vector<int> blocks) {
    for(auto block: blocks){
        closedBlocks.insert(block);
    }
}

std::unordered_map<int, std::vector<ScheduleEntry>> CtcOffice::getSchedule(){
    return schedule_;
}
int CtcOffice::getNumTrains(){
    return numTrains_;
}

void CtcOffice::setNumTrains(int numTrains){
    numTrains_=numTrains;
}
