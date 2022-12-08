//
// Created by tpixe on 12/7/2022.
//

#include "Day4.h"

int Day4Part1(std::ifstream &infile){
    int total = 0;
    std::string current;
    bool done = false;
    do{
        std::getline(infile,current);
        //std::cout << half << " + " << otherHalf << std::endl;
        std::stringstream stream(current);
        int fStart, fEnd, sStart, sEnd;
        char junk;
        stream >> fStart >> junk >> fEnd >> junk >> sStart >> junk >> sEnd;
        if((fStart <= sStart && fEnd >= sEnd) || (sStart <= fStart && sEnd >= fEnd)){
            total++;
        }
        if(infile.eof()) {
            done = true;
        }
    }while(!done);
    return total;
}

int Day4Part2(std::ifstream &infile){
    int total = 0;
    std::string current;
    bool done = false;
    do{
        bool found = false;
        std::getline(infile,current);
        //std::cout << half << " + " << otherHalf << std::endl;
        std::stringstream stream(current);
        int fStart, fEnd, sStart, sEnd;
        char junk;
        stream >> fStart >> junk >> fEnd >> junk >> sStart >> junk >> sEnd;
        for(int i = fStart; i <= fEnd; i++){
            if(i == sStart || i==sEnd){
                total++;
                std::cout << current << std::endl;
                found = true;
                break;
            }
        }
        if(!found){
            for(int i = sStart; i <= sEnd; i++){
                if(i == fStart || i==fEnd){
                    total++;
                    std::cout << current << std::endl;
                    break;
                }
            }
        }
        if(infile.eof()) {
            done = true;
        }
    }while(!done);
    return total;
}