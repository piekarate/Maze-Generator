#include "Grid.hpp"

void Grid::initVariables()
{
    this->size = 150;
    this->rows = (int) 1500/this->size;
    this->cols = (int) 1500/this->size;
    
}

void Grid::initGrid()
{
    
    for (int y = 0; y < this->rows; y++)
    {
        for (int x = 0; x < this->cols; x++)
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
    this->current = 0;
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
    
    this->grid.at(this->current).visited = true;
    int next = this->grid.at(this->current).checkNeighbours(this->grid);
    
    // Remove walls between cells
    if (next != -1)
    {
        this->grid.at(next).visited = true;
        
        int x = this->grid.at(this->current).getRow() - this->grid.at(next).getRow();
        if (x == 1) {
            this->grid.at(this->current).isWall[3] = false;
            this->grid.at(next).isWall[1] = false;
        } else if (x == -1)
        {
            this->grid.at(this->current).isWall[1] = false;
            this->grid.at(next).isWall[3] = false;
        }
        int y = this->grid.at(this->current).getCol() - this->grid.at(next).getCol();
        if (y == 1) {
            this->grid.at(this->current).isWall[0] = false;
            this->grid.at(next).isWall[2] = false;
        } else if (y == -1)
        {
            this->grid.at(this->current).isWall[2] = false;
            this->grid.at(next).isWall[0] = false;
        }
        
        this->current = next;
    }
    
    
}

void Grid::render(sf::RenderTarget *target)
{
    for (int i = 0; i < this->grid.size(); i++)
    {
        grid.at(i).render(target);
    }
}
