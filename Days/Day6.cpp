//
// Created by tpixe on 12/7/2022.
//

#include "Day6.h"

int Day6Part1(std::ifstream &infile) {
    std::string current;
    bool done = false;
    char first, second, third, fourth;
    std::getline(infile,current);
    std::stringstream stream(current);
    stream >> first >> second >> third >> fourth;
    if(first != second && second != third && third != fourth && first != fourth && second != fourth && first != third){
        std::cout << first << second << third << fourth << std::endl;
        done = true;
    }
    int i = 4;
    do{
        i++;
        first = second;
        second = third;
        third = fourth;
        stream >> fourth;
        if(first != second && second != third && third != fourth && first != fourth && second != fourth && first != third){
            std::cout << first << second << third << fourth << std::endl;
            done = true;
        }
    }while(!done);
    return i;
}

//returns true when there are no dupes
bool checkDupes(char* list){
    for(int x = 0; x < 14; x++){
        char toSearch = list[x];
        for(int y = 0; y < 14; y++){
            if(x != y){
                if(list[y] == toSearch){
                    return false;
                }
            }
        }
    }
    return true;
}

int Day6Part2(std::ifstream &infile) {
    std::string current;
    bool done = false;
    char c;
    std::getline(infile,current);
    std::stringstream stream(current);
    char chars[14];
    for(int n = 0; n < 14; n++){
        stream >> c;
        chars[n] = c;
    }
    //check for dupes
    if(checkDupes(chars)){
        done = true;
    }
    int i = 14;
    do{
        i++;
        stream >> c;
        for(int n = 1; n < 14; n++){
            chars[n-1] = chars[n];
        }
        chars[13] = c;
        //conditional to check for dupes
        if(checkDupes(chars)){
            //std::cout << first << second << third << fourth << std::endl;
            for(int n = 0; n < 14; n++){
                std::cout << chars[n];
            }
            std::cout << std::endl;
            done = true;
        }
    }while(!done);
    return i;
}