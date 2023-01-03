#include "Grid.hpp"

void Grid::initVariables()
{
    this->size = 150;
    this->rows = (int) 1500/this->size;
    this->cols = (int) 1500/this->size;
    
}

void Grid::initGrid()
{
    
    for (int x = 0; x < this->rows; x++)
    {
        for (int y = 0; y < this->cols; y++)
        {
            Cell cell(x, y);

            this->grid.push_back(cell);
        }
    }
}

Grid::Grid()
{
    this->initVariables();
    this->initGrid();
}

Grid::~Grid()
{
    
}

void Grid::update()
{
    for (int i = 0; i < this->grid.size(); i++)
    {
        grid.at(i).update();
    }

}

void Grid::render(sf::RenderTarget *target)
{
    for (int i = 0; i < this->grid.size(); i++)
    {
        grid.at(i).render(target);
    }
}
