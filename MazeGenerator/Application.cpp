#include "Application.h"

void Application::initVariables()
{
//    this->grid = Grid();
    
}

void Application::initWindow()
{
    this->videoMode = sf::VideoMode(1500, 1500);
    this->window = new sf::RenderWindow(this->videoMode, "Maze Generator", sf::Style::Titlebar | sf::Style::Close);
    this->window->setFramerateLimit(2);
}

Application::Application()
{
    this->initVariables();
    this->initWindow();
}

Application::~Application()
{
    delete this->window;
}

const bool Application::isRunning()
{
    return this->window->isOpen();
}

void Application::pollEvents()
{
    while (this->window->pollEvent(this->event))
    {
        switch (this->event.type) {
            case sf::Event::Closed:
                this->window->close();
                break;
                
            default:
                break;
        }
    }
}

void Application::update()
{
    this->pollEvents();
    
    // Update objects
    
    this->grid.update();
}

void Application::render()
{
    this->window->clear(sf::Color::Black);
    
    // Render objects
    this->grid.render(this->window);
    
    this->window->display();
}
