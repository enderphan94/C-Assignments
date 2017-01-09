#include <SFML/Graphics.hpp>
#include <SFML\Window.hpp>
#include <iostream>
#include "Grid.hpp"

using namespace sf;
using namespace std;
int width = 600;
int height = 600;
const int play = 0;
const int edit = 1;

int main()
{
	Grid grid(width, height);
	RenderWindow window(sf::VideoMode(width, height), "Game of Life");
	Event event;
	int mode = edit;
	
	while (window.isOpen()) {
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed) {
				window.close();
			}
			if (event.type == Event::KeyPressed) {

				switch (event.key.code) {
				case Keyboard::Q:
					window.close();
					break;
				case Keyboard::Return:
					switch (mode) {
					case edit:
						window.setTitle("Edit mode: Off");
						mode = play;
						break;
					case play:
						window.setTitle("Edit mode: On");
						mode = edit;
						break;
					default:break;
					}
					break;
				default:break;
				}
			}
			//Mouse event
			if (event.type == Event::MouseButtonPressed) {
				if (event.mouseButton.button == Mouse::Left && mode==edit) {
				
					int z = width / 40;
					 int x = Mouse::getPosition(window).x / z;
					 int y = Mouse::getPosition(window).y / z;		
					grid.cell_locate(!grid.alive_cell_locate(x, y), x, y);
			
				}
			}
		}
		
		if (mode == play) {
			//do movement here
			grid.execute();

		}

		grid.draw(window);
		window.display();
	}


	return 0;
	
}
