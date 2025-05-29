#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
//surface area of the box, which is 2*l*w + 2*w*h + 2*h*l
// A present with dimensions 2x3x4 requires 2*6 + 2*12 + 2*8 = 52 square feet 
//of wrapping paper plus 6 square feet of slack, for a total of 58 square feet.



    int calcArea(int l, int w, int h) {
        int min = -1;
        int side1 = l * w;
        min = side1;
        int side2 = w * h;
        if(side2<min) min = side2;
        int side3 = h * l;
        if(side3 < min) min = side3;
    
        int surfaceArea = 2 * side1 + 2 * side2 + 2 * side3;
        int extra = min;
    
        return surfaceArea + extra;
    }
    int ribbonCalc(int l, int w, int h){
        int sides[3] = {l, w, h};
        std::sort(sides, sides + 3);
        int ribbon = 2 * (sides[0] + sides[1]);
        int bow = l * w * h;
        int result = ribbon + bow;
        return result;
    }

int main(){

    std::ifstream input("input.txt");
    std::string line;
    int nums[3];
    int numsIndex = 0;
    std::string token;
    int result = 0;
    int rib = 0;
    while(getline(input, line, '\n')){
        std::stringstream ss(line);
        while(getline(ss, token, 'x') && numsIndex < 3){
            nums[numsIndex] = stoi(token);
            numsIndex++;
        }
        int calcs = calcArea(nums[0], nums[1], nums[2]);
        int ribcalc = ribbonCalc(nums[0], nums[1], nums[2]);
        rib += ribcalc;
        result += calcs;
        numsIndex = 0;
    }
    std::cout << result << std::endl;
    std::cout << rib << std::endl;
    return 0;
}