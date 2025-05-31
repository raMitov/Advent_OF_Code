#include <iostream>
#include <string>
#include <hashtable.h>
#include <hash_fun.h>
#include "MD5.h"
int getHash(std::string& input){
    int i = 1;
    while(1){
        std::string attempt = input + std::to_string(i);
        std::string hash = md5(attempt);
        if(hash.substr(0,5) == "00000"){
            return i;
        }
        i++;
    }
}

int main(){
    std::string input;
    getline(std::cin, input);
    std::cout << getHash(input) << std::endl;

    return 0;
}