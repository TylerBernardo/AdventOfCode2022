//
// Created by tpixe on 12/7/2022.
//

#include "Day2.h"
int Day2Part1(std::ifstream &infile){
    int total = 0;
    std::string current;
    bool done = false;
    do{
        std::getline(infile,current);
        std::stringstream stream(current);
        char oppMove, myMove;
        stream >> oppMove >> myMove;
        int iOppMove = oppMove - 64, iMyMove = myMove - 87;
        if(iOppMove == iMyMove){
            total += 3 + iMyMove;
            std::cout << iOppMove  << "," << iMyMove << ",tie" << 3 + iMyMove <<std::endl;
        }else if(iMyMove -1 == iOppMove || (iMyMove == 1 && iOppMove == 3)){
            total += 6 + iMyMove;
            std::cout << iOppMove  << "," << iMyMove << ",win" << 6 + iMyMove <<std::endl;
        }else{
            total += iMyMove;
            std::cout << iOppMove  << "," << iMyMove << ",loss" << iMyMove <<std::endl;
        }
        if(infile.eof() || current == "end") {
            done = true;
        }
    }while(!done);
    return total;
}

int Day2Part2(std::ifstream &infile){
    int total = 0;
    std::string current;
    bool done = false;
    do{
        std::getline(infile,current);
        std::stringstream stream(current);
        char oppMove, end;
        stream >> oppMove >> end;
        int iOppMove = oppMove - 64, iEnd = end - 87;
        int move;
        if(iEnd == 1){
            move = iOppMove - 1;
            if(move == 0){
                move = 3;
            }
        }else if(iEnd == 2){
            move = iOppMove;
        }else if(iEnd == 3){
            move = iOppMove + 1;
            if(move == 4){
                move = 1;
            }
        }
        total += (iEnd -1) * 3 + move;
        if(infile.eof() || current == "end") {
            done = true;
        }
    }while(!done);
    return total;
}
