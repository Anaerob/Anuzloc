#include <SFML/Graphics.hpp>
#include "Constants.h"
#include "Game.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(c_wSX, c_wSY), "Pokemon Nuzlocke Client");
	window.setVerticalSyncEnabled(true);
	window.setKeyRepeatEnabled(false);

	Game game;

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
			switch (event.type)
			{
			case sf::Event::Closed:
				window.close();
				break;
			case sf::Event::KeyPressed:
				switch (event.key.code)
				{
				case sf::Keyboard::Escape:
					window.close();
					break;
				}
				break;
			}

		window.clear(sf::Color::White);
		game.draw(window);
		window.display();
	}
	return 0;
}
