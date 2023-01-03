#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

#include <iostream>

class Cell
{
private:
    int row, col;
    int size;
    
    int x, y;
    
    bool isWall [4] = {true, true, true, true};
    
    std::vector<sf::Vertex> walls;
    
    void initVariables(float x, float y);
    void generatePosition();
    
public:
    // Constructors | Deconstructors
    Cell(float x, float y);
    ~Cell();
    
    
    
    void update();
    void render(sf::RenderTarget *target);
    
};
