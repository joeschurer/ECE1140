#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
//#include <cctype>

int main(){
    bool success;
	std::string inputString;
	std::ifstream plcFile("test.plc");

	std::vector<std::string> fileLines;

	//read in PLC file
	while(getline(plcFile,inputString)){
		//std::cout << inputString << std::endl;
		if(inputString[0] != '#' && !(isspace(inputString[0])) && !(inputString.empty()) ){
			fileLines.push_back(inputString);
		}
	}
	

	plcFile.close();

	bool occ[] = {0,1};
	bool auth[]= {1,1};
	bool SW[] = {0,0};
	int BL,SWPOS;

	//iterate thru file
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

}