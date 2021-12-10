#ifndef CTCOFFICE_H
#define CTCOFFICE_H
#include <list>
#include <fstream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include "models.h"

using std::string;
using std::vector;

extern int systemClock;
extern int simulationSpeed;

typedef std::pair<int, int> Time;


namespace utility {
vector<string> split(string s, string delimeter);
string convertMinutesToMinuteAndSecond(string time);
}

class CtcOffice
{
public:
    CtcOffice(TrackLine line = Green);
    void parseSchedule(std::ifstream &scheduleFile);
    void parseTrack(std::string path);
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
    void addScheduleEntry(int trainNumber, string start, int destination, string arrivalTime);
    Time toPairTime(string time);
    string toStringTime(Time Time);
    void addClosedBlocks(vector<int> blocks);
    std::unordered_set<int>* getClosedBlocks();
    bool checkForDispatch(int time);
    Time toTimeFromSeconds(int time);
    void setTickets(int tickets);
    int getTickets();
    vector<TrainEntry> getDispatchedTrains();
    int getTrainFromOccupancy(int block);
    int getTotalOccupanccy();
    std::priority_queue<ScheduleEntry, vector<ScheduleEntry>, compare> getTrainHeap();
    TrackLine getCurrentLine();

private:
    std::unordered_map<int, std::vector<ScheduleEntry>> schedule_;
    void buildGreenLineGraph();
    void buildGreenLineStationMap();
    void buildRedLineGraph();
    void buildRedLineStationMap();
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
    std::priority_queue<ScheduleEntry, vector<ScheduleEntry>, compare> trainHeap;
    // maps node (track before switch) to it's preceeding track.
    // trains cannot back up
    // can only use switches if you were traveling in the direction of the switch
    std::unordered_map<int,int> trackSwitchNodes;
    // TODO: Use set for closed tracks
    void updateAuthorityGivenOccupancy();
    int tickets;
};
#endif // CTCOFFICE_H
