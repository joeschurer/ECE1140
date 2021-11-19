#include "switch.h"

Switch::Switch()
{
    block1_1 = -1;
    block1_2 = -1;
    block2_1 = -1;
    block2_2 = -1;
    point1 = true;
}

Switch::Switch(int b11, int b12, int b21,int b22, bool p1) {
    block1_1 = b11;
    block1_2 = b12;
    block2_1 = b21;
    block2_2 = b22;
    point1 = p1;
}
