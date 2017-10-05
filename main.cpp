#include <SFML/Graphics.hpp>
#include "Constants.h"
#include "Game.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(c_wSX, c_wSY), "Pokemon Nuzlocke Client");
	window.setVerticalSyncEnabled(true);
	window.setKeyRepeatEnabled(false);

	Game game;
	
	bool movingDown = false;
	bool movingLeft = false;
	bool movingRight = false;
	bool movingUp = false;

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

		if ((sf::Keyboard::isKeyPressed(sf::Keyboard::A) && !game.getLock()) ||
			movingLeft)
			movingLeft = game.holdKeyA();
		if ((sf::Keyboard::isKeyPressed(sf::Keyboard::D) && !game.getLock()) ||
			movingRight)
			movingRight = game.holdKeyD();
		if ((sf::Keyboard::isKeyPressed(sf::Keyboard::S) && !game.getLock()) ||
			movingDown)
			movingDown = game.holdKeyS();
		if ((sf::Keyboard::isKeyPressed(sf::Keyboard::W) && !game.getLock()) ||
			movingUp)
			movingUp = game.holdKeyW();

		window.clear(sf::Color::White);
		game.draw(window);
		window.display();
	}
	return 0;
}
