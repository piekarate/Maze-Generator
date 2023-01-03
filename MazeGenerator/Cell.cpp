
#include "Cell.hpp"

void Cell::initVariables(float x, float y)
{
    this->row = x;
    this->col = y;
    this->size = 150;
}

void Cell::generatePosition()
{
    this->x = this->row*this->size;
    this->y = this->col*this->size;
}


Cell::Cell(float x, float y)
{
    this->initVariables(x, y);
    this->generatePosition();
}

Cell::~Cell()
{
    
}

void Cell::update()
{
    walls.clear();
    if (this->isWall[0])
    {
        sf::Vertex topX(sf::Vector2f(this->x, this->y), sf::Color::White);
        sf::Vertex topY(sf::Vector2f(this->x + this->size, this->y), sf::Color::White);
        walls.push_back(topX);
        walls.push_back(topY);
    }
    if (this->isWall[1])
    {
        sf::Vertex rightX(sf::Vector2f(this->x + this->size, this->y), sf::Color::White);
        sf::Vertex rightY(sf::Vector2f(this->x + this->size, this->y + this->size), sf::Color::White);
        walls.push_back(rightX);
        walls.push_back(rightY);
    }
    if (this->isWall[2])
    {
        sf::Vertex bottomX(sf::Vector2f(this->x + this->size, this->y + this->size), sf::Color::White);
        sf::Vertex bottomY(sf::Vector2f(this->x, this->y + this->size), sf::Color::White);
        walls.push_back(bottomX);
        walls.push_back(bottomY);
    }
    if (this->isWall[3])
    {
        sf::Vertex leftX(sf::Vector2f(this->x, this->y + this->size), sf::Color::White);
        sf::Vertex leftY(sf::Vector2f(this->x, this->y), sf::Color::White);
        walls.push_back(leftX);
        walls.push_back(leftY);
    }
}

void Cell::render(sf::RenderTarget *target)
{
    target->draw(&walls[0], walls.size(), sf::Lines);
}
