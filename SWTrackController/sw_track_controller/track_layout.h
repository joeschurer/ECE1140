#ifndef TRACK_LAYOUT_H
#define TRACK_LAYOUT_H
#include <vector>

struct block{
    int block_num;
    bool switch_head = false;
    bool switch_tail = false;
    double speed_limit;
    double real_speed = 0;
    int head_connect[2] = {-1,-1};
    int tail_connect = -1;
    int auth;
    bool station;
    bool heater;
    //char section;
    bool underground = false;
    bool yard;
    bool occupancy = false;
    double sugg_speed = 0;
    double comm_speed= 0;
    bool maintenance = false;
    bool switch_connection = -1;

    //0 = green, 1 = yellow, 2 = red
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
    bool create_line();
    block get_block(int);
    bool edit_block();
};

#endif // TRACK_LAYOUT_H
