#include <iostream>
#include <fstream>
#include <set>
typedef struct Point{
    int x;
    int y;
    bool operator<(const Point& other) const {
        return (x < other.x) || (x == other.x && y < other.y);
    }
}Point;

int housesPresents(std::ifstream& input){
    std::set<Point> points;
    Point start = {0,0};
    char c;
    while(input.get(c)){
        if(c == '<'){
            start.x -= 1;
        }
        else if(c == '>'){
            start.x += 1;
        }
        else if(c == '^'){
            start.y += 1;
        }
        else if(c == 'v'){
            start.y -= 1;
        }
        points.insert(start);
    }
    int count = 0;
    for(auto p : points){
        count++;
    }
    return count;
    
}
int robSanta(std::ifstream& input){
    std::set<Point> santaPoints;
    std::set<Point> roboSantaPoints;
    Point santaStart = {0, 0};
    Point roboSantaStart = {0, 0};
    bool santa = true;
    char c;
    while(input.get(c)){
        if(santa){
            if(c == '<'){
                santaStart.x -= 1;
            }
            else if(c == '>'){
                santaStart.x += 1;
            }
            else if(c == '^'){
                santaStart.y += 1;
            }
            else if(c == 'v'){
                santaStart.y -= 1;
            }
            santaPoints.insert(santaStart);
            santa = false;
        }
        else{
            if(c == '<'){
                roboSantaStart.x -= 1;
            }
            else if(c == '>'){
                roboSantaStart.x += 1;
            }
            else if(c == '^'){
                roboSantaStart.y += 1;
            }
            else if(c == 'v'){
                roboSantaStart.y -= 1;
            }
            roboSantaPoints.insert(roboSantaStart);
            santa = true;
        }
    }
    for(auto p : santaPoints){
        roboSantaPoints.insert(p);
    }
    int count = 0;
    for(auto p : roboSantaPoints){
        count++;
    }
    return count;
}

int main(){
    std::ifstream input("input.txt");
    std::cout << robSanta(input);
}