#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
//#include <cctype>

std::vector<std::string> lineSplit(std::string s, std::string delimeter);


int main(){
    bool success;
	std::string inputString;
	std::ifstream plcFile("test.plc");

	//std::vector<lineContainer> plcContainer;
	std::vector<std::vector<std::string>> plcContainer;
	//read in PLC file
	while(getline(plcFile,inputString)){
		std::vector<std::string> fileLines;
		std::cout << inputString << std::endl;
		if(inputString[0] != '#'){
			fileLines = lineSplit(inputString," ");
			plcContainer.push_back(fileLines);
		}
	}
	plcFile.close();

	
	for (size_t i = 0; i < plcContainer.size(); i++)
	{
		std::cout << "line " << i << std::endl;
		for (size_t j = 0; j < plcContainer[i].size(); j++)
		{
			std::cout << plcContainer[i][j] << "-";
		}
		std::cout << std::endl;
		
	}
	
	for (size_t i = 0; i < plcContainer.size(); i++)
	{
		if(plcContainer[i][0])
	}
	


	

	bool occ[] = {0,1};
	bool auth[]= {1,1};
	bool SW[] = {0,0};
	int BL,SWPOS;

	
	/*/iterate thru file
	for (int i = 0; i < fileLines.size(); i++)
	{
		//holds the tokens of each line
		std::vector<std::string> tokens;
		std::string buffer;
		std::stringstream ss((fileLines[i]));
		
		while (ss >> buffer){
        	tokens.push_back(buffer);
			std::cout << buffer << std::endl;
		}
		
		//check format of the line
		if(tokens[0] == "IF" && tokens[2]=="THEN"){
			if (tokens[1].substr(0,2) == "BL"){
				BL = std::stoi(tokens[1].substr(2,tokens[1].length()));
				SWPOS = std::stoi(tokens[3].substr(2,tokens[3].length()));

				//toggle switch
				if(occ[BL]==true){
					SW[SWPOS]=true;
				} else {
					SW[SWPOS]=false;
				}
			}
			else if (tokens[1].substr(0,4) == "AUTH"){
				BL = std::stoi(tokens[1].substr(2,tokens[1].length()));
				SWPOS = std::stoi(tokens[3].substr(2,tokens[3].length()));

				//toggle switch
				if(occ[BL]==true){
					SW[SWPOS]=true;
				} else {
					SW[SWPOS]=false;
				}
			}	
		}

		std::cout << SW[1];
	}
	*/
}

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