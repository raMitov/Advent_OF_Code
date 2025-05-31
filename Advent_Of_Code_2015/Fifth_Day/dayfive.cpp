#include <iostream>
#include <fstream>
#include <string>

bool ThreeVowels(std::string& line) {
    int vowels = 0;
    for (char c : line) {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            vowels++;
        }
    }
    return vowels >= 3;
}

bool twiceInARow(std::string& line){
    for (int i = 0; i < line.length() - 1; ++i) {
        if (line[i] == line[i + 1]) return true;
    }
    return false;
}

bool containsForbiddenStrings(std::string& line){
    for (int i = 0; i < line.length() - 1; ++i) {
        std::string check = line.substr(i, 2);
        if (check == "ab" || check == "cd" || check == "pq" || check == "xy") return true;
    }
    return false;
}

int numberOfNice(std::ifstream& input) {
    std::string line;
    int count = 0;
    while (getline(input, line)) {
        if (ThreeVowels(line) && twiceInARow(line) && !containsForbiddenStrings(line)) {
            count++;
        }
    }
    return count;
}

int main() {
    std::ifstream input("input.txt");
    if (!input) {
        std::cerr << "Could not open file.\n";
        return 1;
    }

    std::cout << numberOfNice(input) << std::endl;

    input.close();
    return 0;
}
