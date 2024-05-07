#include "Grid.hpp"

Grid:: Grid(int rows, int cols)
{
    this->rows = rows;
    this->cols = cols;
    for (int i=0; i<rows; i++)
    {
        this->grid.push_back({});
        for (int j=0; j<cols; j++)
        {
            this->grid[i].push_back(0);
        }
    }
}

Grid:: Grid(int rows, int cols, int width, int height)
{
    this->rows = rows;
    this->cols = cols;
    this->sizeX = width/cols;
    this->sizeY= height/rows;
    this->size = Vector2f(width/cols, height/rows);
    for (int i=0; i<rows; i++)
    {
        this->grid.push_back({});
        for (int j=0; j<cols; j++)
        {
            this->grid[i].push_back(0);
        }
    }

    this->next = vector<vector<int>>(rows, vector<int>(cols,0));
}


    
void Grid::drawTo (RenderWindow &window)
{
     for (int i=0; i<rows; i++)
    {
        for (int j=0; j<cols; j++)
        {
            RectangleShape rect(Vector2f(this->sizeX, this->sizeY));
            rect.setPosition(Vector2f(j*this->sizeX, i*this->sizeY));
            rect.setOutlineThickness(1);
            rect.setOutlineColor(Color::White);

            if(grid[j][i] == 0)
            {
                rect.setFillColor(Color(249,234,195));
            }
            if(grid[j][i] == 1)
            {
                rect.setFillColor(Color(228,113,122));
            }

            window.draw(rect);

        }
    }
}

void Grid::click(int x, int y)
{
    int indexX = x/this->sizeX;
    int indexY = y/this->sizeY;
    grid[indexX][indexY] = (grid [indexX][indexY]+1) % 2;

    /*if (grid [indexX][indexY] == 0)
    {
        grid[indexX][indexY] = 1;   
    }
    else{
        grid[indexX][indexY] = 0;
        
    } Es lo mismo que la linea de codigo anterior a este comentario*/
    

}

void Grid::update()
{
    for (int i=0; i<this->rows; i++)
    {
        for (int j=0; j<this->cols; j++)
        {
            
            if (this->grid[i][j] == 1)
            {   
                if (j == this->cols -1)
                {
                    this->next[i][j] = 1;
                }
                else
                {
                    if ( this->grid [i][j+1] == 0)
                    {
                        this->next [i][j] = 0;
                        this->next [i][j+1] = 1;
                    }
                    else
                    {
                        this->next [i][j] = 1;
                    }
                }
                
            }
        }
    }
    this->grid = this->next;
}
