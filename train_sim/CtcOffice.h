#ifndef CTCOFFICE_H
#define CTCOFFICE_H
#include "models.h"
#include <list>
#include <fstream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using std::string;
using std::vector;

typedef std::pair<int, int> Time;
//enum TrainLine {Green, Red};
//struct and other declarations moved to models.h

namespace utility {
vector<string> split(string s, string delimeter);
string convertMinutesToMinuteAndSecond(string time);
}

class CtcOffice
{
public:
    CtcOffice(TrackLine line = Green);
    void parseSchedule(std::ifstream &scheduleFile);
    void parseTrack();
    std::unordered_map<int, std::vector<ScheduleEntry>> getSchedule();
    std::list<TrackEntry> getTrack();
    int computeRouteAuthority(std::string route);
    vector<bool> computeAuthority(vector<int> route);
    int computeSuggestedSpeed(vector<int> route);
    // computes departure time from yard to block
    int computeTimeToDestination(vector<int> route);
    vector<int> sendSwitchPosition(int switchNode, int blockToConnect);
    void updateOccupancy(vector<bool> occupancy);
    std::string getRouteBlockList(std::string route);
    vector<int> getRoute(int startingBlock, int destinationBlock);
    int getNumTrains();
    void setNumTrains(int numTrains);
    TrainEntry dispatchTrain(int trainNumber, ScheduleEntry scheduleEntry);
    vector<bool> sendClosedBlocks();
    void addScheduleEntry(int trainNumber, string start, string destination, string arrivalTime);
    Time toPairTime(string time);
    string toStringTime(Time Time);
    void addClosedBlocks(vector<int> blocks);
    std::unordered_set<int> getClosedBlocks();
    bool checkForDispatch(int time);
    Time toTimeFromSeconds(int time);
    vector<TrainEntry> getDispatchedTrains();

private:
    std::unordered_map<int, std::vector<ScheduleEntry>> schedule_;
    void buildGreenLineGraph();
    void buildGreenStationMap();
    void setupLine(TrackLine line);
    TrackLine currentLine;
    std::unordered_map<std::string, vector<int>> stationMap;
    std::vector<TrackEntry> track_;
    int numTrains_;
    vector<vector<int>> trackGraph;
    std::unordered_set<int> closedBlocks;
    vector<bool> occupancies;
    vector<TrainEntry> dispatchedTrains;

    int totalOccupancies;

    // maps node (track before switch) to it's preceeding track.
    // trains cannot back up
    // can only use switches if you were traveling in the direction of the switch
    std::unordered_map<int,int> trackSwitchNodes;
    // TODO: Use set for closed tracks
};
#endif // CTCOFFICE_H

