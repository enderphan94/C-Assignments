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
	for (int x = 0; x < w; x++) {
		for (int y = 0; y < h; y++) {
			if (x >= 0 && x < w && y >= 0 && y < h) {
				int left = x - 1;

				int right = x + 1;

				int top = y - 1;

				int bot = y + 1;

				int count = 0;
				
				if (nber_left) {
					if (cell[left][y].Alive()) ++count;
					if (cell[left][top].Alive()) ++count;
					if (nber_bot && cell[left][bot].Alive()) ++count;
				}
				if (nber_right) {
					if (cell[right][y].Alive()) ++count;
					if (nber_top && cell[right][top].Alive()) ++count;
					if (nber_bot && cell[right][bot].Alive()) ++count;

				}
				if (nber_top && cell[x][top].Alive()) ++count;

				if (nber_bot && cell[x][bot].Alive()) ++count;

				if (count < 2) {
					cell[x][y].modify_cell(false);
				}
				else if (count == 2) {
					// do nothing
				}
				else if (count == 3) {
					cell[x][y].modify_cell(true);
				}
				else if (count > 3) {
					cell[x][y].modify_cell(true);
				}
			
			}
		}
	}
	
}