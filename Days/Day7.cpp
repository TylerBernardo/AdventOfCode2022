//
// Created by tpixe on 12/7/2022.
//

#include "Day7.h"

class Dir{
public:
    int size = 0;
    std::string name;
    std::vector<Dir> sub;
    Dir* parent;
    bool found = false;
    std::vector<std::string> files;

    Dir(std::string name, Dir* _parent){
        this->name = name;
        this->parent = _parent;
    }

    int calcSize(){
        int toReturn = this->size;
        for(auto & i : sub){
            i.calcSize();
            toReturn += i.size;
        }
        this->size = toReturn;
        return toReturn;
    }
    //bug : when returning to base case after finding match, the 3rd return in the chain does not happen. toFind -> parent -> something(fails second bool)
    void find(std::string parent, std::string toFind, Dir* &toReturn){
        if(toReturn != nullptr){
            return;
        }
        if(this->name == toFind && this->parent->name == parent){
            toReturn = this;
            return;
        }
        for(auto & i : sub){
            i.find(parent,toFind,toReturn);
            if(toReturn != nullptr){
                return;
            }
        }
        return;
    }

    void findSmallest(int lowerBound, int* smallest){
        if(this->size > lowerBound && this->size < *smallest){
            *smallest = this->size;
        }

        for(auto & i : sub){
            i.findSmallest(lowerBound,smallest);
        }
    }

    int calcOutput(){
        int output = 0;
        if(this->size <= 100000){
            output += this->size;
            std::cout << this->name << " " << this->size << std::endl;
        }
        for(auto & i : sub){
            output += i.calcOutput();
        }
        return output;
    }

    void print(int spacing){
        for(int i = 0; i < spacing; i++){
            std::cout << "   ";
        }
        std::cout << "- " << this->name << "(" << this->size << ")" << std::endl;

        for(auto & file : files){
            for(int i = 0; i < spacing + 1; i++){
                std::cout << "   ";
            }
            std::cout << "* " << file << std::endl;
        }

        for(auto & i : sub){
            i.print(spacing + 1);
        }

    }
};

int Day7Part1(std::ifstream &infile){
    int output;
    std::string current;
    bool done = false;
    int lineCount = 1;
    std::vector<Dir*> allDirs;
    Dir root = Dir("/",nullptr);

    allDirs.push_back(&root);
    std::getline(infile,current);
    //std::cout << half << " + " << otherHalf << std::endl;
    char c;
    std::string s;
    Dir* parent = &root;
    while(!done) {
        std::stringstream streamTop(current);
        std::cout << lineCount << std::endl;
        if(current == "$ cd .."){
            std::getline(infile,current);
            lineCount++;
            parent = parent->parent;
            continue;
        }
        streamTop >> c;
        //starting a $ cd "something"
        std::string location;
        streamTop >> s >> s;
        location = s;
        Dir *cDir;
        if(location == "dgpfcftj"){
            std::cout << "Test" << std::endl;
            //root.print(0);
        }
        if (location == "/") {
            cDir = &root;
        } else {
            cDir = nullptr;
            (*parent).find(parent->name,location,cDir);
        }
        parent = cDir;

        if (c == '$') {
            std::getline(infile, current);
            lineCount++;
            std::stringstream stream(current);
            stream >> c >> s;
            if (s == "ls") {
                //determine the directory;
                while(true){
                    std::getline(infile, current);
                    lineCount++;
                    std::stringstream line(current);
                    line >> s;
                    if((*cDir).name == "dgpfcftj"){
                        std::cout << "this is a test" << std::endl;
                    }
                    if(s == "$"){
                        std::string test;
                        line >> test;
                        if(s == test){
                            done = true;
                        }
                        break;
                    }
                    if (s == "dir") {
                        line >> s;
                        if(s.empty()){
                            std::cout << "oh no" << std::endl;
                        }
                        (*cDir).sub.emplace_back(s,parent);
                        allDirs.push_back(&((*cDir).sub[(*cDir).sub.size() - 1]));
                    } else {
                        int size = std::stoi(s);
                        (*cDir).size += size;
                        std::string name;
                        line >> name;
                        cDir->files.push_back(name + "(" + s + ")");
                    }
                }

            }
        }

        if(infile.eof()) {
            done = true;
        }
    }
    root.calcSize();
    root.print(0);
    /*
int toReturn = 0;
for(auto & allDir : allDirs){
    int result = (*allDir).size;
    if(result <= 100000){
        toReturn += result;
        if(result < 0){
            std::cout << "oh no" << std::endl;
        }
    }
}
     */
    return root.calcOutput();
}

int Day7Part2(std::ifstream &infile){
    int output;
    std::string current;
    bool done = false;
    int lineCount = 1;
    std::vector<Dir*> allDirs;
    Dir root = Dir("/",nullptr);

    allDirs.push_back(&root);
    std::getline(infile,current);
    //std::cout << half << " + " << otherHalf << std::endl;
    char c;
    std::string s;
    Dir* parent = &root;
    while(!done) {
        std::stringstream streamTop(current);
        std::cout << lineCount << std::endl;
        if(current == "$ cd .."){
            std::getline(infile,current);
            lineCount++;
            parent = parent->parent;
            continue;
        }
        streamTop >> c;
        //starting a $ cd "something"
        std::string location;
        streamTop >> s >> s;
        location = s;
        Dir *cDir;
        if(location == "dgpfcftj"){
            std::cout << "Test" << std::endl;
            //root.print(0);
        }
        if (location == "/") {
            cDir = &root;
        } else {
            cDir = nullptr;
            (*parent).find(parent->name,location,cDir);
        }
        parent = cDir;

        if (c == '$') {
            std::getline(infile, current);
            lineCount++;
            std::stringstream stream(current);
            stream >> c >> s;
            if (s == "ls") {
                //determine the directory;
                while(true){
                    std::getline(infile, current);
                    lineCount++;
                    std::stringstream line(current);
                    line >> s;
                    if((*cDir).name == "dgpfcftj"){
                        std::cout << "this is a test" << std::endl;
                    }
                    if(s == "$"){
                        std::string test;
                        line >> test;
                        if(s == test){
                            done = true;
                        }
                        break;
                    }
                    if (s == "dir") {
                        line >> s;
                        if(s.empty()){
                            std::cout << "oh no" << std::endl;
                        }
                        (*cDir).sub.emplace_back(s,parent);
                        allDirs.push_back(&((*cDir).sub[(*cDir).sub.size() - 1]));
                    } else {
                        int size = std::stoi(s);
                        (*cDir).size += size;
                        std::string name;
                        line >> name;
                        cDir->files.push_back(name + "(" + s + ")");
                    }
                }

            }
        }

        if(infile.eof()) {
            done = true;
        }
    }

    root.calcSize();
    //root.print(0);
    /*
int toReturn = 0;
for(auto & allDir : allDirs){
    int result = (*allDir).size;
    if(result <= 100000){
        toReturn += result;
        if(result < 0){
            std::cout << "oh no" << std::endl;
        }
    }
}
     */
    int toDelete = 30000000 - (70000000 - root.size);
    std::cout << toDelete << std::endl;
    output = root.size;
    root.findSmallest(toDelete,&output);
    return output;
}