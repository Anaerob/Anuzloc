#include <SFML/Graphics.hpp>
#include "Constants.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(c_wSX, c_wSY), "Pokemon Nuzlocke Client");
	window.setVerticalSyncEnabled(true);
	window.setKeyRepeatEnabled(false);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
			switch (event.type)
			{
			case sf::Event::Closed:
				window.close();
				break;
			}
		window.clear(sf::Color::White);
		window.display();
	}
	return 0;
}
