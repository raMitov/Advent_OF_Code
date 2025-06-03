#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

void toggle_on(int (&matrix)[1000][1000], int arr[4]){
    int fromRows = arr[1];
    int fromCols = arr[0];
    int toRows = arr[3];
    int toCols = arr[2];
    for(int i = fromRows; i <= toRows; i++){
        for(int j = fromCols; j <= toCols; j++){
            matrix[i][j] += 1;
        }
    }
}
void toggle_off(int (&matrix)[1000][1000], int arr[4]){
    int fromRows = arr[1];
    int fromCols = arr[0];
    int toRows = arr[3];
    int toCols = arr[2];
    for(int i = fromRows; i <= toRows; i++){
        for(int j = fromCols; j <= toCols; j++){
            if(matrix[i][j] > 0){
                matrix[i][j] -= 1;
            }
        }
    }
}
void toggle(int (&matrix)[1000][1000], int arr[4]){
    int fromRows = arr[1];
    int fromCols = arr[0];
    int toRows = arr[3];
    int toCols = arr[2];
    for(int i = fromRows; i <= toRows; i++){
        for(int j = fromCols; j <= toCols; j++){
            matrix[i][j] += 2;
        }
    }
}
int main(){
    std::ifstream input("input.txt");
    if (!input) {
        std::cerr << "Could not open file.\n";
        return 1;
    }
    int matrix[1000][1000] = {false};
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
       
        if(command == "toggleoff"){
            toggle_off(matrix, arr);
        }
        else if(command == "toggleon"){
            toggle_on(matrix, arr);
        }
        else if(command == "toggle"){
            toggle(matrix, arr);
        }
    }

    //dun
    int sum = 0;
    for(int i = 0; i < 1000; i++){
        for(int j = 0; j < 1000; j++){
            sum+= matrix[i][j];
        }
    }
    std::cout << sum << std::endl;
}