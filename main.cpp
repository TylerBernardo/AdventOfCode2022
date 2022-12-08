#include <fstream>
#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>
#include <vector>
//include new files
#include "Days/Day8.h"

std::ifstream parseInput(std::string &filename) {
    std::ifstream file(filename);
    return file;
}

int main() {
    std::string fileName = R"(C:\Users\tpixe\CLionProjects\AdventOfCode2022\input.txt)";
    std::ifstream file = parseInput(fileName);
    std::cout << Day8Part2(file);
}
