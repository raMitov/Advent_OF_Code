#include <iostream>
#include <fstream>
#include <string>
bool oneLetterRepeats(std::string& line){
    for(int i = 0; i < line.length() - 2; i++){
        int check = i + 2;
        if(line[i] == line[check]) return true;
    }
    return false;
}
    bool repeatingDoubles(const std::string& line) {
        for (int i = 0; i < line.length() - 1; ++i) {
            std::string pair = line.substr(i, 2);
            for (int j = i + 2; j < line.length() - 1; ++j) {
                if (line.substr(j, 2) == pair) return true;
            }
        }
        return false;
    }
    

int numberOfNice(std::ifstream& input, std::ofstream & output){
    std::string line;
    int count = 0;
    while (getline(input, line)) {
       if(repeatingDoubles(line) && oneLetterRepeats(line)) count++;
       output << line << " " << std::to_string(repeatingDoubles(line)) << " " << std::to_string(oneLetterRepeats(line)) << "\n";
    }
    return count;
}


int main() {
    std::ifstream input("input.txt");
    std::ofstream output("outputDEBUBBING.txt", std::ios::app);
    if (!input) {
        std::cerr << "Could not open file.\n";
        return 1;
    }

    std::cout << numberOfNice(input, output) << std::endl;

    input.close();
    output.close();
    return 0;
}
