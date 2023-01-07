
#include "Cell.hpp"

void Cell::initVariables(float x, float y)
{
    this->row = x;
    this->col = y;
    this->size = 20;
    this->visited = false;
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

int Cell::index(int j, int i)
{
    int cols, rows = 75;
    if (i < 0 || j < 0 || i > cols-1 || j > rows-1)
    {
        return -1;
    }
    
    return j + i * 75;
}

int Cell::checkNeighbours(std::vector<Cell> grid)
{
    std::vector<int> neighbors;
    try {
        Cell top = grid.at(this->index(this->row, this->col-1));
        
        if (!top.visited)
        {
            neighbors.push_back(this->index(this->row, this->col-1));
        }
    } catch (...) { std::cout << "Top Problem" << std::endl; }
    
    try {
        Cell right = grid.at(this->index(this->row+1, this->col));
        
        if (!right.visited)
        {
            neighbors.push_back(this->index(this->row+1, this->col));
        }
    } catch (...) { std::cout << "Right Problem" << std::endl; }

    try {
        Cell bottom = grid.at(this->index(this->row, this->col+1));
        
        if (!bottom.visited)
        {
            neighbors.push_back(this->index(this->row, this->col+1));
        }
    } catch (...) { std::cout << "Bottom Problem" << std::endl; }
    
    try {
        Cell left = grid.at(this->index(this->row-1, this->col));
        
        if (!left.visited)
        {
            neighbors.push_back(this->index(this->row-1, this->col));
        }
    } catch (...) { std::cout << "Left Problem" << std::endl; }
    
    if (neighbors.size() > 0)
    {
        int randomCell = rand() % neighbors.size();
        return neighbors.at(randomCell);
    }
    else
    {
        return -1;
    }
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
    if (this->visited == true)
    {

        this->cellRectangle.setPosition(this->x, this->y);
        this->cellRectangle.setSize(sf::Vector2f(this->size, this->size));
        this->cellRectangle.setFillColor(sf::Color(0, 255, 255, 100));
    }
}

void Cell::render(sf::RenderTarget *target)
{
    target->draw(&walls[0], walls.size(), sf::Lines);
    target->draw(this->cellRectangle);
}
