#include "CtcOffice.h"
#include <QDebug>
#include <fstream>
#include <vector>
#include <queue>
#include <math.h>
#include <QFile>

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
    setupLine(line);
}

void CtcOffice::setupLine(TrackLine line){
    currentLine = line;
    if (line==Green) {
        parseTrack("://Green_Track_Layout.csv");
        buildGreenLineGraph();
        buildGreenLineStationMap();
        // can only use switches if you were traveling in the direction of the switch
        //63 to 62 or 63 to yard
        //TODO: Don't need this, could fnid preceeding switch with a function
        trackSwitchNodes = {{13,14},
                            {29, 28},
                            {57, 56},
                            {77,78},
                            {85,84},
                            {63,64}
                           };
    }
    else if (line==Red) {
        parseTrack("://Red_Track_Layout.csv");
        buildRedLineGraph();
        buildRedLineStationMap();
        trackSwitchNodes = {{9,8},
                            {27, 26},
                            {16,17},
                            {33, 34},
                            {38,37},
                            {44,45},
                            {52,51}
                           };
    }
}
void CtcOffice::parseSchedule(std::ifstream &scheduleFile) {
    std::string line;
    while(std::getline(scheduleFile, line)){
        if(line!=""){
            vector<string> splitLine = utility::split(line, ",");
            addScheduleEntry(stoi(splitLine[0]), splitLine[1], splitLine[2], splitLine[3]);
        }
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

void CtcOffice::parseTrack(std::string path) {
    std::ifstream trackFile;
    QString fileName(path.c_str());
    QFile inputFile(fileName);
    if(inputFile.open(QIODevice::ReadOnly)){
        QTextStream in(&inputFile);
        QString temp = in.readLine();
        while (!in.atEnd()) {
            QString qline = in.readLine();
            std::string line = qline.toStdString();
            vector<string> splitLine = utility::split(line, ",");
            TrackEntry entry = {splitLine[0], splitLine[1], stoi(splitLine[5]), stoi(splitLine[3]), splitLine[6]};
            track_.push_back(entry);
        }
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
               bool isTrainBackingUp = trackSwitchNodes.count(v)==1 && prev[v]!=trackSwitchNodes[v] && v!=startingBlock && u!=trackSwitchNodes[v];
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
    scheduleEntry.trainNumber = trainNumber;
    int size = stationMap[start].size();
    int startBlock;
    // station can be accesed from multiple blocks. Must start at block where the last schedule entry ended.
    auto scheduleSize = schedule_[trainNumber].size();
    if(size>1 && scheduleSize>0) {
        startBlock = schedule_[trainNumber][scheduleSize-1].destination;
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
        int timeToDestination = computeTimeToDestination(route);
        auto pairArrivalTime = toPairTime(arrivalTime);
        auto arrivalTimeInSeconds = pairArrivalTime.first*60*60 + pairArrivalTime.second*60;
        scheduleEntry.departureTime = toTimeFromSeconds(arrivalTimeInSeconds-timeToDestination);
    } else {
        scheduleEntry.destinationString = destination;
        auto route1 = getRoute(startBlock, stationBlocks[0]);
        auto route2 = getRoute(startBlock, stationBlocks[1]);
        scheduleEntry.destination = route1.size()<route2.size()? stationBlocks[0]: stationBlocks[1];
        scheduleEntry.authority = route1.size()<route2.size()? computeAuthority(route1): computeAuthority(route2);
        scheduleEntry.suggestedSpeed = route1.size()<route2.size()? computeSuggestedSpeed(route1): computeSuggestedSpeed(route2);
        int timeToDestination = route1.size()<route2.size()? computeTimeToDestination(route1): computeTimeToDestination(route2);
        auto pairArrivalTime = toPairTime(arrivalTime);
        auto arrivalTimeInSeconds = pairArrivalTime.first*60*60 + pairArrivalTime.second*60;
        scheduleEntry.departureTime = toTimeFromSeconds(arrivalTimeInSeconds-timeToDestination);
    }
    schedule_[trainNumber].push_back(scheduleEntry);
    trainHeap.push(scheduleEntry);
    auto top = trainHeap.top();
    string s = "hi";
}

std::priority_queue<ScheduleEntry, vector<ScheduleEntry>, compare> CtcOffice::getTrainHeap(){
    return trainHeap;
}

void CtcOffice::buildGreenLineStationMap() {
    // TODO: Make stationmap entries lowercase. Convert input form gui to lowercase
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
    stationMap["MT Lebanon"] = {77};
    stationMap["Poplar"] = {88};
    stationMap["Castle Shannon"] = {96};

}

TrainEntry CtcOffice::dispatchTrain(int trainNumber, ScheduleEntry scheduleEntry){
    TrainEntry t = {trainNumber, scheduleEntry.suggestedSpeed, scheduleEntry.authority};
    dispatchedTrains.push_back(t);
    return t;
}

bool CtcOffice::checkForDispatch(int time){
    auto scheduleEntry = trainHeap.top();
    auto departureTime = trainHeap.top().departureTime;
    if(time == departureTime.first*60*60 + departureTime.second*60) {
        dispatchTrain(scheduleEntry.trainNumber, scheduleEntry);
        trainHeap.pop();
        return true;
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

int CtcOffice::getTrainFromOccupancy(int block){
    for(auto entry: dispatchedTrains) {
        if(entry.authority[block]){
            return entry.trainNumber;
        }
    }
    // occupancy is not from a train
    return -1;
}

void CtcOffice::updateOccupancy(vector<bool> occupancy){
    occupancies = occupancy;
    totalOccupancies = std::count(occupancy.begin(), occupancy.end(), 1);
    // TODO: update authority, need a slot for this
}

void CtcOffice::updateAuthorityGivenOccupancy(){
    for(int i = 0; i<occupancies.size(); i++){
        if(occupancies[i]){
            auto train = getTrainFromOccupancy(i);

        }
    }
}

int CtcOffice::getTotalOccupanccy(){
    return totalOccupancies;
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

void CtcOffice::buildRedLineGraph(){
    // TODO: Fix this
    trackGraph = vector<vector<int>>(77);
    trackGraph[1].push_back(2);
    trackGraph[1].push_back(16);
    for(int i =2; i<76; i++) {
        trackGraph[i].push_back(i+1);
        trackGraph[i].push_back(i-1);
    }
    //switches
    trackGraph[72].pop_back();
    trackGraph[72].push_back(33);
    trackGraph[71].clear();
    trackGraph[71].push_back(70);
    trackGraph[71].push_back(38);
    trackGraph[67].pop_back();
    trackGraph[67].push_back(44);
    trackGraph[66].clear();
    trackGraph[66].push_back(65);
    trackGraph[66].push_back(52);
    trackGraph[9].push_back(0);
    trackGraph[0].push_back(9);
    trackGraph[16].push_back(1);
    trackGraph[27].push_back(76);
    trackGraph[33].push_back(72);
    trackGraph[38].push_back(71);
    trackGraph[44].push_back(67);
    trackGraph[52].push_back(66);


    trackGraph[76].push_back(75);
    trackGraph[76].push_back(27);
}

void CtcOffice::buildRedLineStationMap(){
    // TODO: Make stationmap entries lowercase. Convert input form gui to lowercase
    stationMap["Yard"] = {0};
    stationMap["Shadyside"]={7};
    stationMap["Herron Ave"] = {16};
    stationMap["Swissville"] = {21};
    stationMap["Penn Station"] = {25};
    stationMap["Steel Plaza"] = {35};
    stationMap["First Ave"] = {45};
    stationMap["Station Square"] = {48};
    stationMap["South Hills Junction"] = {60};
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
