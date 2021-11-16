#ifndef SWITCH_H
#define SWITCH_H


class Switch
{
public:
    int block1_1;
    int block1_2;
    int block2_1;
    int block2_2;
    bool point1;

    Switch();
    Switch(int b11, int b12, int b21,int b22, bool p1 = true);
};

#endif // SWITCH_H
