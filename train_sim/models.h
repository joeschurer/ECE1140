#ifndef MODELS_H
#define MODELS_H
#include <list>
#include <fstream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using std::string;
using std::vector;
extern int systemClock;
extern int simulationSpeed;

typedef std::pair<int, int> Time;
enum TrackLine {Green, Red};

struct ScheduleEntry {
    int trainNumber;
    int destination;
    string destinationString;
    int start;
    Time arrivalTime;
    Time departureTime;
    int suggestedSpeed;
    vector<bool> authority;
};

struct TrackEntry {
    string line;
    string section;
    int speedLimit;
    int blockLength;
    string infrastructure;
};

struct TrainEntry{
    int trainNumber;
    int suggestedSpeed;
    vector<bool> authority;
};

struct compare {
    bool operator()(ScheduleEntry const& t1, ScheduleEntry const& t2){
        return t1.departureTime.first*60*60 + t1.departureTime.second*60 >  t2.departureTime.first*60*60 + t2.departureTime.second*60;
    }
};

namespace utility {
vector<string> split(string s, string delimeter);
string convertMinutesToMinuteAndSecond(string time);
}


#endif // MODELS_H
