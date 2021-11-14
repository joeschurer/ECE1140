#include <fstream>
#include <string>
#include <iostream>
#include <vector>

struct block{
    int block_num;
    bool switch_head = false;
    bool switch_tail = false;
    double speed_limit;
    double real_speed = 0;
    //0 = yard else indexed by block numbers
    int headOptions[2] = {-1,-1};
    int auth;
    int route;
    bool station;
    bool heater=false;
    bool underground = false;
    bool yard;
    bool occupancy = false;
    double sugg_speed = 0;
    double comm_speed= 0;
    bool maintenance = false;
    int headConnect = -1;
    int tailConnect = -1;
    char section;
    bool crossing;
    //0 is inactive, 1 active
    bool crossingState;

    //0 = green, 1 = yellow, 2 = red
    int lights = 0;
};


std::vector<std::string> lineSplit(std::string s, std::string delimeter) {
    std::vector<std::string> result;
    int start = 0;
    int end = s.find(delimeter);
    while(end!=-1) {
        result.push_back(s.substr(start, end-start));
        start = end + delimeter.size();
        end = s.find(delimeter, start);
    }
    result.push_back(s.substr(start, end-start));
    return result;
}

int main(){
    std::ifstream trackFile;
    trackFile.open("GreenLine.txt");
    std::string fLine;
    getline(trackFile, fLine);
    while(getline(trackFile, fLine)){
        block temp;
        std::vector<std::string> splitLine = lineSplit(fLine, ",");
        temp.section = splitLine[1][0];
        //std::cout<< temp.section <<std::endl;
        temp.block_num = std::stoi(splitLine[2]);
        //std::cout<<   temp.block_num<<std::endl;
        temp.speed_limit = std::stoi(splitLine[5]);
        //std::cout<< temp.speed_limit<<std::endl;
        std::string inf = splitLine[6];
        //std::cout<<  inf<<std::endl;
        if(inf.find("STATION") != std::string::npos){
            //std::cout << "STATION: ";
            temp.station = true;
            //std::cout<<  temp.station<<std::endl;
        } else if(inf.find("UNDERGROUND") != std::string::npos){
            temp.underground = true;
        }else if(inf.find("RAILWAY") != std::string::npos){
            //std::cout << "CROSSING: ";
            temp.crossing= true;
            temp.crossingState = false;
            //std::cout<<  temp.crossing<<std::endl;
        }else if(inf.find("SWITCH") != std::string::npos){
            //std::cout << "SWITCH: ";
            std::string sw = inf.substr(inf.find('(')+1,inf.find(')'));
            sw.pop_back();
            //std::cout<<  sw<<std::endl;
            temp.switch_head=true;
            if(sw.find("ard") != std::string::npos){
                std::string left = sw.substr(0, sw.find('-'));
                sw.erase(0, sw.find('-')+1);
                std::string right = sw;
                //std::cout << left << " : "<<right <<std::endl;
                if(left.find("ar") != std::string::npos){
                    temp.headOptions[0] = 0;
                    temp.headOptions[1] = stoi(right);
                } else {
                    temp.headOptions[0] = stoi(left);
                    temp.headOptions[1] = 0;
                }
                //std::cout << temp.headOptions[0] << " : "<<temp.headOptions[1] <<std::endl;

            } else {
                std::string left = sw.substr(0, sw.find(';'));
                sw.erase(0, sw.find(';')+2);
                std::string right = sw;

                std::string ltemp = left.substr(0,left.find('-'));
                left.erase(0,left.find('-')+1);
                if(stoi(ltemp)==temp.block_num){
                    temp.headOptions[0]=stoi(left);
                } else {
                    temp.headOptions[0]=stoi(ltemp);
                }

                std::string rtemp = right.substr(0,right.find('-'));
                right.erase(0,right.find('-')+1);
                if(stoi(rtemp)==temp.block_num){
                    temp.headOptions[1]=stoi(right);
                } else {
                    temp.headOptions[1]=stoi(rtemp);
                }
            }
        }
        
        //new_block(temp);
    }

    return 0;
}