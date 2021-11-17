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

typedef std::pair<int, int> Time;
enum TrainLine {Green, Red};

struct ScheduleEntry {
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

#endif // MODELS_H
