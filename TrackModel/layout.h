#ifndef LAYOUT_H
#define LAYOUT_H

#include "line.h"
#include <fstream>
#include <iostream>

using namespace std;

class Layout
{
public:
    Line* line;
    fstream layoutFile;

    Layout();
};

#endif // LAYOUT_H
