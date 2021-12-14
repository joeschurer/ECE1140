#include "layout.h"

Layout::Layout() {
    //Route to and open selected file
    layoutFile.open("layoutfile.txt");

    line = &(Line::getLine());

    //Skip first line of file, only headers
    string text;
    getline(layoutFile, text);

    //Read data in from file line by line to create the blocks
    while (getline(layoutFile, text)) {
        //Find line name
        int div = text.find(",");
        line->name = text.substr(0, div);
        text.erase(0, div+1);
        //Find section name
        div = text.find(",");
        string sect = text.substr(0, div);
        text.erase(0, div+1);
        //Find block number
        div = text.find(",");
        int block = stoi(text.substr(0, div));
        text.erase(0, div+1);
        //Find block length
        div = text.find(",");
        double length = stod(text.substr(0, div));
        text.erase(0, div+1);
        //Find block grade
        div = text.find(",");
        double grade = stod(text.substr(0, div));
        text.erase(0, div+1);
        //Find speed limit
        div = text.find(",");
        int limit = stoi(text.substr(0, div));
        //Convert to mph
        limit = limit * .621371;
        text.erase(0, div+1);
        //Find infrastructure
        div = text.find(",");
        string infrastructure = text.substr(0, div);
        text.erase(0, div+1);
        //Find side
        div = text.find(",");
        string side = text.substr(0, div);
        if (div < 0) div = 0;
        text.erase(0, div+1);
        //Find elevation
        div = text.find(",");
        double elev = stod(text.substr(0, div));
        text.erase(0, div+1);
        //Find and remove cumulative elevation
        div = text.find(",");
        text.erase(0, div+1);
        //Find direction
        div = text.find(",");
        string dir = text.substr(0, div);
        text.erase(0, div+1);

        Block b(block, sect, length, limit, grade, elev);
        //Loop through any infrastructure infrormation
        while (infrastructure.length() > 1) {
            int f = infrastructure.find(";");
            string s1 = infrastructure.substr(0, 7);
            if (s1 == "STATION") {
                infrastructure.erase(0, f+2);
                f = infrastructure.find(";");
                if (f < 0) f = infrastructure.length();
                string s2 = infrastructure.substr(0, f);
                infrastructure.erase(0, f+2);
                b.station.name = s2;
                b.station.passengers = 0;
                b.hasStation = true;
                if (side == "Left") {
                    b.station.leftBoarding = true;
                    b.station.rightBoarding = false;
                }
                else if (side == "Right") {
                    b.station.leftBoarding = false;
                    b.station.rightBoarding = true;
                }
                else {
                    b.station.leftBoarding = true;
                    b.station.rightBoarding = true;
                }
            }
            else if (s1 == "SWITCH ") {
                b.hasSwitch = true;
                string sw = infrastructure.substr(0, 16);
                if (sw == "SWITCH TO YARD (") {
                    f = infrastructure.find("(");
                    infrastructure.erase(0, f+1);
                    f = infrastructure.find("-");
                    string a = infrastructure.substr(0, f);
                    if (a == "yard" || a == "Yard") {
                        b.swtch.block1_1 = -1;
                        f = infrastructure.find(")");
                        a = infrastructure.substr(0, f);
                        b.swtch.block1_2 = stoi(a);
                        b.swtch.block2_1 = stoi(a);
                        b.swtch.block2_2 = b.blockNum;
                        infrastructure.erase(0, f+1);
                    }
                    else {
                        b.swtch.block1_1 = stoi(a);
                        b.swtch.block1_2 = -1;
                        b.swtch.block2_1 = stoi(a);
                        b.swtch.block2_2 = b.blockNum;\
                        f = infrastructure.find(")");
                        infrastructure.erase(0, f+1);
                    }
                }
                else if (sw == "SWITCH FROM YARD") {
                    f = infrastructure.find("(");
                    infrastructure.erase(0, f+1);
                    f = infrastructure.find("-");
                    string a = infrastructure.substr(0, f);
                    if (a == "yard" || a == "Yard") {
                        b.swtch.block1_1 = -1;
                        infrastructure.erase(0, f+1);
                        f = infrastructure.find(")");
                        a = infrastructure.substr(0, f);
                        b.swtch.block1_2 = stoi(a);
                        b.swtch.block2_1 = stoi(a);
                        b.swtch.block2_2 = b.blockNum;
                        infrastructure.erase(0, f+1);
                    }
                    else {
                        b.swtch.block1_1 = stoi(a);
                        b.swtch.block1_2 = -1;
                        b.swtch.block2_1 = stoi(a);
                        b.swtch.block2_2 = b.blockNum;
                        f = infrastructure.find(")");
                        infrastructure.erase(0, f+1);
                    }
                }
                else if (sw == "SWITCH TO/FROM Y") {
                    f = infrastructure.find("(");
                    infrastructure.erase(0, f+1);
                    f = infrastructure.find("-");
                    string a = infrastructure.substr(0, f);
                    if (a == "yard" || a == "Yard") {
                        infrastructure.erase(0, f+1);
                        b.swtch.block1_1 = -1;
                        f = infrastructure.find(")");
                        a = infrastructure.substr(0, f);
                        b.swtch.block1_2 = stoi(a);
                        b.swtch.block2_1 = stoi(a);
                        b.swtch.block2_2 = b.blockNum;
                        infrastructure.erase(0, f+1);
                    }
                    else {
                        b.swtch.block1_1 = stoi(a);
                        b.swtch.block1_2 = -1;
                        b.swtch.block2_1 = stoi(a);
                        b.swtch.block2_2 = b.blockNum;
                        f = infrastructure.find(")");
                        infrastructure.erase(0, f+1);
                    }

                }
                else {
                    infrastructure.erase(0, 8);
                    f = infrastructure.find("-");
                    b.swtch.block1_1 = stoi(infrastructure.substr(0, f));
                    infrastructure.erase(0, f+1);
                    f = infrastructure.find(";");
                    b.swtch.block1_2 = stoi(infrastructure.substr(0, f));
                    infrastructure.erase(0, f+2);
                    f = infrastructure.find("-");
                    b.swtch.block2_1 = stoi(infrastructure.substr(0, f));
                    infrastructure.erase(0, f+1);
                    f = infrastructure.find(")");
                    b.swtch.block2_2 = stoi(infrastructure.substr(0, f));

                    infrastructure.erase(0, f+1);
                }
            }
            else if (s1 == "RAILWAY") {
                b.hasCrossing = true;
                b.crossingLights = false;
                infrastructure.erase(0, 15);
            }
            else if (s1 == "UNDERGR") {
                b.underground = true;
                infrastructure.erase(0, 11);
            }
            else if (s1 == "BEACON(") {
                b.hasBeacon = true;
                infrastructure.erase(0, 7);
                int f = infrastructure.find("~");
                string nam = infrastructure.substr(0, f);
                infrastructure.erase(0, f+1);
                f = infrastructure.find(")");
                string sid = infrastructure.substr(0, f);
                infrastructure.erase(0, f+1);
                if (sid == "Left") {
                    b.beacon.left = true;
                    b.beacon.right = false;
                }
                else if (sid == "Right") {
                    b.beacon.left = false;
                    b.beacon.right = true;
                }
                else {
                    b.beacon.left = true;
                    b.beacon.right = true;
                }
                b.beacon.name = nam;
                f = infrastructure.find(";");
                if (f >= 0) infrastructure.erase(0, f+2);
            }
        }

        if (dir == "Both") {
            b.inbound = true;
            b.outbound = true;
        }
        else if (dir == "Inbound") {
            b.inbound = true;
            b.outbound = false;
        }
        else if (dir == "Outbound") {
            b.inbound = false;
            b.outbound = true;
        }

        line->blocks.push_back(b);
    }

    //Add lights before and after a switch
    for (int i=0; i<(int)line->blocks.size(); i++) {
        if (line->blocks[i].hasSwitch) {
            line->blocks[line->blocks[i].swtch.block1_1-1].hasCrossing = true;
            line->blocks[line->blocks[i].swtch.block1_1-1].crossingLights = 2;
            line->blocks[line->blocks[i].swtch.block1_2-1].hasCrossing = true;
            line->blocks[line->blocks[i].swtch.block1_2-1].crossingLights = 2;
            line->blocks[line->blocks[i].swtch.block2_1-1].hasCrossing = true;
            line->blocks[line->blocks[i].swtch.block2_1-1].crossingLights = 2;
            line->blocks[line->blocks[i].swtch.block2_2-1].hasCrossing = true;
            line->blocks[line->blocks[i].swtch.block2_2-1].crossingLights = 2;
        }
    }

    //Add lights before and after a station
    for (int i=0; i<(int)line->blocks.size(); i++) {
        if (line->blocks[i].hasStation) {
            line->blocks[i-1].hasCrossing = true;
            line->blocks[i+1].hasCrossing = true;
        }
    }
}
