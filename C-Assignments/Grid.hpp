#ifndef grid_header
#define grid_header
#include <SFML/Graphics.hpp>

using namespace sf;
class Cell {

private:
	
	RectangleShape shape;
	bool alive_cell;
	
public:
	
	Cell(bool alive_cell, int x, int y);
	RectangleShape* getShape();
	void draw(RenderWindow &window);
	Cell();
	bool Alive();
	void modify_cell(bool alive_cell);
};

class Grid {

private:
	int w;
	int h;
	Cell cell[40][40];
	bool nber_left, nber_right, nber_top, nber_bot;
public:
	
	Grid(int w, int h);
	void draw(RenderWindow &window);
	void cell_locate(bool alive, int x, int y);
	bool alive_cell_locate(int x, int y);
	void execute();
};
#endif // !Grid