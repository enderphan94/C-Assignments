#include <SFML/Graphics.hpp>

#include "Grid.hpp"

using namespace sf;

Grid::Grid(int w, int h){
	for (int x = 0; x < w /15;x++) {
		for (int y = 0; y < h/15;y++) {
			cell[x][y] = Cell(false,x*15, y*15);
		}
	}
	this->w = w / 15;
	this->h = h / 15;

}

void Grid::draw(RenderWindow &window) {

	for (int x = 0; x < w;x++) {
		for (int y = 0;y < h;y++) {
			cell[x][y].draw(window);
		}
	}

}

void Grid::cell_locate(bool alive_cell,int x, int y) {

	cell[x][y].modify_cell(alive_cell);
}
bool Grid::alive_cell_locate(int x, int y) {
	return cell[x][y].Alive();
}

void Grid::execute() {
	//bool nber_left, nber_right, nber_top, nber_bot;
	
	for (int x = 0; x < 40; x++) {
		for (int y = 0; y < 40; y++) {
			cell_die[x][y] = false;
			cell_alive[x][y] = false;
		}
	}
	for (int x = 0; x < w; x++) {
		for (int y = 0; y < h; y++) {
			if (x >= 0 && x < w && y >= 0 && y < h) {
				int count = 0;
				bool nber_left = x - 1 >= 0 && x - 1 < w;
				bool nber_right = x + 1 >= 0 && x + 1 < w;
				bool nber_top = y + 1 >= 0 && y + 1 < h;
				bool nber_bot = y - 1 >= 0 && y - 1 < h;

				if (nber_left) {
					if (cell[x - 1][y].Alive())
						++count;
					if (cell[x - 1][y + 1].Alive())
						++count;
					if (nber_bot && cell[x - 1][y - 1].Alive())
						++count;
				}
				 if (nber_right) {
					if (cell[x + 1][y].Alive())
						++count;
				
					if (nber_top && cell[x + 1][y + 1].Alive())
						++count;
					
					if (nber_bot && cell[x + 1][y - 1].Alive())
						++count;

				}
				if (nber_top && cell[x][y + 1].Alive())
					++count;

				if (nber_bot && cell[x][y - 1].Alive())
					++count;


				//check cell die or alive based on rules
				if (cell[x][y].Alive()) {
					if (count != 2 && count != 3) {
						cell_die[x][y] = true;
					}

				}

				else
				{
					if (count == 3)
						cell_alive[x][y] = true;
				}


			}
			
		}
	}

	for (int x = 0; x < w; x++) {
		for (int y = 0; y < h; y++) {

			if (cell_die[x][y]) {
				cell[x][y].modify_cell(false);
			}
			if (cell_alive[x][y]) {
				cell[x][y].modify_cell(true);
			}
		}
	}

	
}
