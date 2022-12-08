//
// Created by tpixe on 12/7/2022.
//
#include "Day5.h";

class Stack{
public:
    std::vector<char> stack;
    Stack(){

    }

    void moveTo(Stack& other, int amount){
        for(int i = 0; i < amount; i++){
            other.stack.insert(other.stack.begin(),stack.front());
            this->stack.erase(this->stack.begin());
        }
    }

    void moveToNew(Stack& other, int amount){
        for(int i = amount-1; i >= 0; i--){
            other.stack.insert(other.stack.begin(),stack[i]);
        }
        for(int i = amount-1; i >= 0; i--){
            this->stack.erase(this->stack.begin() + i);
        }

    }
};

std::string Day5Part1(std::ifstream &infile){
    std::string output;
    Stack stacks[9];
    std::string current;
    bool done = false;
    do{
        std::getline(infile,current);
        //std::cout << half << " + " << otherHalf << std::endl;
        // std::stringstream stream(current);
        if(current[0] == '['){
            for(int i = 0; i < 9; i++){
                int index = 4 * i + 1;
                //std::cout << current[index] << std::endl;
                if(current[index] != ' '){
                    stacks[i].stack.push_back(current[index]);
                }
            }
        }else if(current[0] == 'm'){
            int amount, start, end;
            char junk;
            std::stringstream stream(current);
            stream >> junk >> junk >> junk >> junk >> amount >> junk >> junk >> junk >> junk >> start >> junk >> junk >> end;
            //std::cout << amount << start << end << std::endl;
            stacks[start-1].moveTo(stacks[end-1], amount);
        }
        if(infile.eof()) {
            done = true;
        }
    }while(!done);
    for(int i = 0; i < 9; i++){
        output += stacks[i].stack[0];
    }
    return output;
}

std::string Day5Part2(std::ifstream &infile){
    std::string output;
    Stack stacks[9];
    std::string current;
    bool done = false;
    do{
        std::getline(infile,current);
        //std::cout << half << " + " << otherHalf << std::endl;
        // std::stringstream stream(current);
        if(current[0] == '['){
            for(int i = 0; i < 9; i++){
                int index = 4 * i + 1;
                //std::cout << current[index] << std::endl;
                if(current[index] != ' '){
                    stacks[i].stack.push_back(current[index]);
                }
            }
        }else if(current[0] == 'm'){
            int amount, start, end;
            char junk;
            std::stringstream stream(current);
            stream >> junk >> junk >> junk >> junk >> amount >> junk >> junk >> junk >> junk >> start >> junk >> junk >> end;
            //std::cout << amount << start << end << std::endl;
            stacks[start-1].moveToNew(stacks[end-1], amount);
        }
        if(infile.eof()) {
            done = true;
        }
    }while(!done);
    for(int i = 0; i < 9; i++){
        output += stacks[i].stack[0];
    }
    return output;
}