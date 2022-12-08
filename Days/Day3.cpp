//
// Created by tpixe on 12/7/2022.
//

#include "Day3.h"

int Day3Part1(std::ifstream &infile){
    int total = 0;
    std::string current;
    bool done = false;
    do{
        std::getline(infile,current);
        std::string half = current.substr(0, current.length()/2);
        std::string otherHalf = current.substr(current.length()/2);
        //std::cout << half << " + " << otherHalf << std::endl;
        std::stringstream stream(half);
        char toSearch;
        std::string found;
        while(stream >> toSearch){
            if(found.find(toSearch) == std::string::npos && otherHalf.find(toSearch) != std::string::npos){
                int ch = (int)toSearch;
                if(ch >= 97){
                    //std::cout << ch - 96 << std::endl;
                    total += ch - 96;
                    found += toSearch;
                }else if(ch >= 65){
                    //std::cout << ch - 64 + 26 << std::endl;
                    total += ch - 64 + 26;
                    found += toSearch;
                }
            }
        }
        if(infile.eof() || current == "end") {
            done = true;
        }
    }while(!done);
    return total;
}

int Day3Part2(std::ifstream &infile){
    int total = 0;
    std::string line1;
    std::string line2;
    std::string line3;
    bool done = false;
    do{
        std::getline(infile,line1);
        std::getline(infile,line2);
        std::getline(infile,line3);
        //std::cout << half << " + " << otherHalf << std::endl;
        std::stringstream stream(line1);
        char toSearch;
        std::string found;
        while(stream >> toSearch){
            if(found.find(toSearch) == std::string::npos && line2.find(toSearch) != std::string::npos){
                found += toSearch;
            }
        }
        std::cout << found << std::endl;
        std::stringstream line3_s(line3);
        while(line3_s >> toSearch){
            if(found.find(toSearch) != std::string::npos){
                int ch = (int)toSearch;
                if(ch >= 97){
                    //std::cout << ch - 96 << std::endl;
                    total += ch - 96;
                }else if(ch >= 65){
                    //std::cout << ch - 64 + 26 << std::endl;
                    total += ch - 64 + 26;
                }
                break;
            }
        }
        if(infile.eof()) {
            done = true;
        }
    }while(!done);
    return total;
}