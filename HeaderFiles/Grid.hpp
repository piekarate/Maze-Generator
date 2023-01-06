#pragma once

#include "Cell.hpp"

#include <iostream>

class Grid
{
private:
    
    int rows, cols;
    int size;
    
    std::vector<Cell> grid;
    int current;
    
    void initVariables();
    void initGrid();
public:
    Grid();
    ~Grid();
    
    void update();
    void render(sf::RenderTarget *target);
};
