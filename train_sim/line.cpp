#include "line.h"

using namespace std;

void Line::moveTrain(int trainNum) {
    int current = trains[trainNum-1].location;
    int next = current;
    if (current > 0) blocks[current-1].authority = false;

    //Get next block
    //If already done, stay put
    if (current == -1) {
        next = -1;
    }
    //If the block is a switch
    else if (blocks[current-1].hasSwitch) {
        if (blocks[current-1].swtch.point1) {
            int n;
            if (current == blocks[current-1].swtch.block1_1) {
                n = blocks[current-1].swtch.block1_2;
            }
            else {
                n = blocks[current-1].swtch.block1_1;
            }

            if (blocks[n-1].authority) {
                next = n;
            }
            else {
                if (blocks[current-1].inbound && blocks[current].authority) next = current+1;
                else if (blocks[current-1].outbound && blocks[current-2].authority) next = current-1;
            }
        }
        else {
            int n;
            if (current == blocks[current-1].swtch.block2_1) {
                n = blocks[current-1].swtch.block2_2;
            }
            else {
                n = blocks[current-1].swtch.block2_1;
            }

            if (blocks[n-1].authority) {
                next = n;
            }
            else {
                if (blocks[current-1].inbound && current+1 != n && blocks[current].authority) next = current+1;
                else if (blocks[current-1].outbound && current-1 != n && blocks[current-2].authority) next = current-1;
            }
        }
    }
    //If the block is not a switch
    else {
        //See if the block is connected to a switch
        bool con = false;
        int n = current;
        for (int i=0; i<blocks.size(); i++) {
            if (blocks[i].hasSwitch) {
                if (blocks[i].swtch.point1 == true) {
                   if (blocks[i].swtch.block1_1 == blocks[current-1].blockNum) {
                        n = blocks[i].swtch.block1_2;
                    }
                    else if (blocks[i].swtch.block1_2 == blocks[current-1].blockNum) {
                        n = blocks[i].swtch.block1_1;
                    }
                }
                else {
                    if (blocks[i].swtch.block2_1 == blocks[current-1].blockNum) {
                        n = blocks[i].swtch.block2_2;
                    }
                    else if (blocks[i].swtch.block2_2 == blocks[current-1].blockNum){
                        n = blocks[i].swtch.block2_1;
                    }
                }
                if (n>0 && n!=current && blocks[n-1].authority == true) {
                    next = n;
                    con = true;
                }
            }
        }

        if (!con || n == -1) {
            if (blocks[current-1].inbound && blocks[current].authority == true) {
                next = current+1;
            }
            else if (current == 1) {
                next = current;
            }
            else if (blocks[current-1].outbound && blocks[current-2].authority == true) {
                next = current-1;
            }
            else if (n == -1) {
                next = -1;
            }
        }
    }

    trains[trainNum-1].moveTrain(next);
}
