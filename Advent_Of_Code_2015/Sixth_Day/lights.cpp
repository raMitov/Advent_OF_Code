#include <iostream>
#include <fstream>
#include <sstream>
#include <string>



int main(){
    std::ifstream input("input.txt");
    if (!input) {
        std::cerr << "Could not open file.\n";
        return 1;
    }
    bool matrix[1000][1000] = {false};
    std::string line;
    std::string command,action, coord1, through, coord2;
    int arr[4];
    while(getline(input, line)){
        std::istringstream iss(line);
        iss >> command;
        if(command == "toggle"){
            iss >> coord1 >> through >> coord2;
            command = "toggle";
        }
        else if(command == "turn"){
            iss >> action >> coord1 >> through >> coord2;
            command = "toggle" + action;
        }

        auto parseCoord = [](const std::string& coordStr, int& x, int& y) {
            size_t commaPos = coordStr.find(',');
            x = std::stoi(coordStr.substr(0, commaPos));
            y = std::stoi(coordStr.substr(commaPos + 1));
        };
    
        parseCoord(coord1, arr[0], arr[1]);
        parseCoord(coord2, arr[2], arr[3]);
        std::cout << command << std::endl;
        for(int i = 0; i < 4; i++){
            std::cout << arr[i];
        }
        std::cout << std::endl;
    }
}