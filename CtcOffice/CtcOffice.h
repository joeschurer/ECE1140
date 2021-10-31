#ifndef CTCOFFICE_H
#define CTCOFFICE_H
#include <list>
#include <fstream>
#include <string>
#include <vector>
#include <unordered_map>

using std::string;
using std::vector;

struct scheduleEntry {
    string line;
    string infrastructure;
    string timeToStation;
};

struct trackEntry {
    string line;
    string section;
    string blockNumber;
    string speedLimit;
    string infrastructure;
};

namespace utility {
vector<string> split(string s, string delimeter);
string convertMinutesToMinuteAndSecond(string time);
}

class CtcOffice
{
public:
    CtcOffice();
    void parseSchedule(std::ifstream &scheduleFile);
    void parseTrack();
    std::unordered_map<int, std::list<scheduleEntry>> getSchedule();
    std::list<trackEntry> getTrack();
    int computeRouteAuthority(std::string route);
    int computeRouteSuggestedSpeed(std::string route);
    std::string getRouteBlockList(std::string route);
    int getNumTrains();
    void setNumTrains(int numTrains);
private:
    //TODO: Make hashmap of station name to track entry to make calculating authority easier.
    std::unordered_map<int, std::list<scheduleEntry>> schedule_;
    std::list<trackEntry> track_;
    int numTrains_;

};

#endif // CTCOFFICE_H
