#include "Grid.hpp"
#include <SFML/Graphics.hpp>

using namespace sf;
Cell::Cell()
{
}
Cell::Cell(bool alive_cell,int x, int y) {

	this->shape = RectangleShape(Vector2f(15, 15));
	this->shape.setPosition(x, y);
	this->shape.setFillColor(Color::Blue);
	this->shape.setOutlineThickness(1);
	this->shape.setOutlineColor(Color::Black);

	this->alive_cell = alive_cell;

	if (alive_cell)
		this->shape.setFillColor(Color::White);
	else
		this->shape.setFillColor(Color::Blue);

}
void Cell::modify_cell(bool alive_cell) {

	this->alive_cell = alive_cell;

	if (alive_cell)
		this->shape.setFillColor(Color::White);
	else
		this->shape.setFillColor(Color::Blue);
}

RectangleShape* Cell::getShape() { return &shape; };

void Cell::draw(RenderWindow &window) {

	window.draw(shape);
}
bool Cell :: Alive() {

	return alive_cell;
}

