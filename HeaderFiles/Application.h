#pragma once

#include "Grid.hpp"

class Application
{
private:
    // Variables
    sf::VideoMode videoMode;
    sf::RenderWindow *window;
    
    sf::Event event;

    Grid grid;
    // Initializer Functions
    
    void initVariables();
    void initWindow();
    
public:
    // Constructors | Deconstructors
    Application();
    ~Application();
    
    // Functions
    const bool isRunning();
    void pollEvents();

    void updatePlayer();
    
    void update();
    void render();
};

