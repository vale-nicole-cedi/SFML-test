#ifndef grid_h
#define grid_h
#include <SFML/Graphics.hpp>
#include <vector>
using namespace sf;
using namespace std;

class Grid 
{
private:
    vector<vector<int>> grid;
    vector<vector<int>> next;
    int rows, cols;
    int sizeX, sizeY;
    Vector2f size;

public:
    Grid(int rows, int cols);
    Grid (int rows, int cols, int width, int height);

    void update();
    int contarVecinos (int i, int j);
    void drawTo (RenderWindow &window);
    void click (int x, int y);
};



#endif