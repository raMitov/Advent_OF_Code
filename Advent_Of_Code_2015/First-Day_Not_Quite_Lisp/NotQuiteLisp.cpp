#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

void Part_One_And_Two(std::ifstream& input){
    int count = 0;
    int basementCount = 0;
    if(!input) return;
    char c;
    bool hasEntered = false;
    while(input.get(c)){
        if(c == '(') {count++; basementCount++;}
        else if(c == ')') {count--;basementCount++;}
        if(count == -1 && !hasEntered){
            std::cout << basementCount << std::endl;
            hasEntered = true;
        }
    }
    std::cout << count << std::endl;
}

int main(){
std::ifstream input("input.txt");
Part_One_And_Two(input);
return 0;
}