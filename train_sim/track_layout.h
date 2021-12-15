#ifndef TRACK_LAYOUT_H
#define TRACK_LAYOUT_H
#include <vector>
#include <QFile>
//Joseph Schurer
//Track data structure
//is a vector of blocks

struct block{
    //true is left item in switch declaration,false is right
    bool switch_pos= true;
    int block_num;
    bool switch_head = false;
    bool switch_tail = false;
    double speed_limit;
    double real_speed = 0;
    //0 = yard else indexed by block numbers
    int headOptions[2] = {-1,-1};
    bool auth;
    bool station;
    bool heater=false;
    bool underground = false;
    bool yard= false;
    bool occupancy = false;
    double sugg_speed = 0;
    double comm_speed= 0;
    bool maintenance = false;
    int headConnect = -1;
    int tailConnect = -1;
    bool hasLights = false;
    char section;
    bool crossing;
    //0 is inactive, 1 active
    bool crossingState;
    int prev;
    std::vector<int> check;
    block* prevBlock = nullptr;
    block* nextBlock = nullptr;

    //0 = green, 1 = yellow, 2 = red, -1 no light
    int lights = 0;
};

class track_layout{
private:
    //std::vector<block> track;
public:
    std::vector<block> track;
    track_layout();
    ~track_layout();
    bool new_block(block);
    //0 = green,1 = red
    bool create_line(int line);
    block get_block(int);
    bool add_block();
    //index should be in block number
    bool toggle_switch(int index);
};

#endif // TRACK_LAYOUT_H
