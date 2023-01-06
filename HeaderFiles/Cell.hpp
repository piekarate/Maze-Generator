#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

#include <iostream>
#include <cstdlib>
#include <time.h>

class Cell
{
private:
    int row, col;
    int size;
    
    int x, y;
    
    std::vector<sf::Vertex> walls;
    sf::RectangleShape cellRectangle;
    
    void initVariables(float x, float y);
    void generatePosition();
    
public:
    // Constructors | Deconstructors
    Cell(float x, float y);
    ~Cell();
    
    bool visited;
    
    int checkNeighbours(std::vector<Cell> grid);
    int index(int j, int i);
    
    int getRow() {return this->row;}
    int getCol() {return this->col;}
    bool isWall [4] = {true, true, true, true};
    
    void update();
    void render(sf::RenderTarget *target);
    
};
