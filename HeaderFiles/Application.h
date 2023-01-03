#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

class Application
{
private:
    // Variables
    sf::VideoMode videoMode;
    sf::RenderWindow *window;
    
    sf::Event event;

    
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

