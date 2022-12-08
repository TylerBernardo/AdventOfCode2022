//
// Created by tpixe on 12/7/2022.
//

#include "Day1.h"
int Day1Part1(std::ifstream &infile) {
    std::string current;
    int best = 0;
    int total = 0;
    bool done = false;
    do{
        std::getline(infile,current);
        if(current != ""){
            int input = std::stoi(current);
            total += input;
        }else{
            if(total > best){
                best = total;
            }
            total = 0;
        }
        if(infile.eof() || current == "end") {
            done = true;
        }
    }while(!done);
    return best;
}

int Day1Part2(std::ifstream &infile) {
    std::string current;
    int best[3] {0,0,0};
    int total = 0;
    bool done = false;
    do{
        std::getline(infile,current);
        if(current != ""){
            int input = std::stoi(current);
            total += input;
        }else{
            if(total > best[2]){
                best[2] = total;
                std::sort(best,best+3,std::greater<int>());
            }
            total = 0;
        }
        if(infile.eof() || current == "end") {
            done = true;
            if(total > best[2]){
                best[2] = total;
                std::sort(best,best+3,std::greater<int>());
            }
        }
    }while(!done);
    return best[0] + best[1] + best[2];
}