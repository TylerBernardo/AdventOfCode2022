//
// Created by tpixe on 12/7/2022.
//

#include "Day8.h"

class Grid{
public:
    int width = 0;
    int height = 0;
    std::vector<std::vector<int>> grid;
    Grid(){

    }

    int visible(int x_index, int y_index){
        if(x_index == 0 || y_index == 0){
            return true;
        }
        int current = grid[y_index][x_index];
        //check 4 directions
        bool left = true;
        //std::cout << "left" << std::endl;
        for(int x = x_index - 1; x >= 0; x--){
            //std::cout << x << std::endl;
            if(grid[y_index][x] >= current){
                left = false;
                break;
            }
        }

        bool right = true;
        //std::cout << "right" << std::endl;
        for(int x = x_index + 1; x <= width - 1; x++){
           // std::cout << x << std::endl;
            if(grid[y_index][x] >= current){
                right = false;
                break;
            }
        }

        bool up = true;
        //std::cout << "up" << std::endl;
        for(int y = y_index - 1; y >= 0; y--){
            //std::cout << y << std::endl;
            if(grid[y][x_index] >= current){
                up = false;
                break;
            }
        }

        bool down = true;
        //std::cout << "down" << std::endl;
        for(int y = y_index + 1; y <= height - 1; y++){
            //std::cout << y << std::endl;
            if(grid[y][x_index] >= current){
                down = false;
                break;
            }
        }
        if(left || right || up || down){
            //std::cout << x_index << "," << y_index << std::endl;
        }
        return left || right || up || down;
    }

    int score(int x_index, int y_index){
        int current = grid[y_index][x_index];
        //check 4 directions
        int left = 0;
        //std::cout << "left" << std::endl;
        for(int x = x_index - 1; x >= 0; x--){
            //std::cout << x << std::endl;
            if(grid[y_index][x] >= current){
                left++;
                break;
            }else{
                left++;
            }
        }

        int right = 0;
        //std::cout << "right" << std::endl;
        for(int x = x_index + 1; x <= width - 1; x++){
            // std::cout << x << std::endl;
            if(grid[y_index][x] >= current){
                right++;
                break;
            }else{
                right++;
            }
        }

        int up = 0;
        //std::cout << "up" << std::endl;
        for(int y = y_index - 1; y >= 0; y--){
            //std::cout << y << std::endl;
            if(grid[y][x_index] >= current){
                up++;
                break;
            }else{
                up++;
            }
        }

        int down = 0;
        //std::cout << "down" << std::endl;
        for(int y = y_index + 1; y <= height - 1; y++){
            //std::cout << y << std::endl;
            if(grid[y][x_index] >= current){
                down++;
                break;
            }else{
                down++;
            }
        }

        return left * right * up * down;
    }
};

int Day8Part1(std::ifstream &infile) {
    std::string current;
    bool done = false;
    Grid grid;
    do{
        std::vector<int> row;
        std::getline(infile,current);
        //std::stringstream stream(current);
        if(grid.width == 0){
            grid.width = current.length();
        }
        for(int i = 0; i < current.length(); i++){
            std::string toConvert;
            toConvert += current[i];
            row.push_back(std::stoi(toConvert));
        }
        grid.grid.push_back(row);
        if(infile.eof()) {
            done = true;
        }
    }while(!done);
    int total = 0;
    grid.height = grid.grid.size();
    for(int x = 0; x < grid.width; x++){
        for(int y = 0; y < grid.height; y++){
            total += grid.visible(x,y);
        }
    }
    return total;
}

int Day8Part2(std::ifstream &infile) {
    std::string current;
    bool done = false;
    Grid grid;
    do{
        std::vector<int> row;
        std::getline(infile,current);
        //std::stringstream stream(current);
        if(grid.width == 0){
            grid.width = current.length();
        }
        for(int i = 0; i < current.length(); i++){
            std::string toConvert;
            toConvert += current[i];
            row.push_back(std::stoi(toConvert));
        }
        grid.grid.push_back(row);
        if(infile.eof()) {
            done = true;
        }
    }while(!done);
    int output = 0;
    grid.height = grid.grid.size();
    for(int x = 0; x < grid.width; x++){
        for(int y = 0; y < grid.height; y++){
            int result = grid.score(x,y);
            if(result > output){
                output = result;
            }
        }
    }
    return output;
}
