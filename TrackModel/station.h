#ifndef STATION_H
#define STATION_H

#include <string>
#include <QObject>

using namespace std;

class Station
{
    public:
        int passengers;
        bool leftBoarding;
        bool rightBoarding;
        string name;

        Station();
        Station(string name);
        Station(string name, int pass, bool left, bool right);

    public slots:
        void addPassengers();
};
#endif // STATION_H
