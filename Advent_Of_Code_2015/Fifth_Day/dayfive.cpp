#include <iostream>
#include <fstream>
#include <string>

#define s1 "ab"
#define s2 "cd"
#define s3 "pq"
#define s4 "xy"

bool ThreeVowels(std::string& line){
    int len = line.length();
    bool afound = false;
    bool efound = false;
    bool ifound = false;
    bool ofound = false;
    bool ufound = false;
    int vowew = 0;
    for(int i = 0; i < len; i++){
        if(line[i] == 'a' && !afound){
            vowew++;
            afound;
        }
        else if(line[i] == 'e' && !efound){
            vowew++;
            efound;
        }
        else if(line[i] == 'i' && !ifound){
            vowew++;
            ifound;
        }
        else if(line[i] == 'o' && !ofound){
            vowew++;
            ofound;
        }
        else if(line[i] == 'u' && !ufound){
            vowew++;
            ufound;
        }
    }
    if(vowew >= 3) return true;
    else return false;
}
//look into this this may not work because i dont know if i get only certain letters only twice
bool twiceInARow(std::string& line){
    int len = line.length();
    for(int i = 0; i < len; i++){
        for(int j = i+1; j < len; j++){
            if(line[i] == line[j]){
                return true;
            }
        }
    }
    return false;
}
bool containsStrings(std::string& line){
    int i = 0;
    int j = i +1;
    int len = line.length();
    while(j!= len){

        std::string check;
        check += line[i];
        check += line[j];
        if(check != s1 && check != s2 && check != s3 && check != s4){
            i++;
            j = i + 1;
        }
        else{
            return true;
        }
    }
    return false;
    
}

int numberOfNice(std::ifstream& input){
    bool hasThreeVowels = false;
    bool hasDoubleLetter = false;
    bool containsString = false;
    std::string line;
    int count = 0;
    while(getline(input, line, '\n')){
        hasThreeVowels = ThreeVowels(line);
        hasDoubleLetter = twiceInARow(line);
        containsString = containsStrings(line);
        if(hasThreeVowels && hasDoubleLetter && !containsString) count++;
    }


    return count;
}

int main(){

    std::ifstream input("input.txt");


    return 0;
}