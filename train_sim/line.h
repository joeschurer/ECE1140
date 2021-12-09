#ifndef LINE_H
#define LINE_H

#include "block.h"
#include "train.h"
#include <iostream>
#include <vector>

using namespace std;
class Line
{
public:
    vector<Block> blocks;
    vector<Train> trains;
    string name;
    vector<int> switched;
    double temp = 72.5;

    static Line& getLine() {
        static Line line;
        return line;
    };

    void moveTrain(int trainNum);
private:
    Line() {};
    Line(Line const&);
    void operator=(Line const&);
};

#endif // LINE_H
