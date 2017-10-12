#include <SFML/Graphics.hpp>
#include "Constants.h"
#include "Game.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(c::iWSX, c::iWSY),
		"Pokemon Nuzlocke Client");
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
				case sf::Keyboard::BackSpace:
					game.pressBackSpace();
					break;
				case sf::Keyboard::Down:
					game.pressDown();
					break;
				case sf::Keyboard::Escape:
					window.close();
					break;
				case sf::Keyboard::Left:
					game.pressLeft();
					break;
				case sf::Keyboard::Return:
					game.pressReturn();
					break;
				case sf::Keyboard::Right:
					game.pressRight();
					break;
				case sf::Keyboard::Space:
					game.pressSpace();
					break;
				case sf::Keyboard::Up:
					game.pressUp();
					break;
				default:
					break;
				}
				break;
			default:
				break;
			}

		if ((sf::Keyboard::isKeyPressed(sf::Keyboard::A)
			&& game.getMoving() == DIRECTION_NONE)
			|| game.getMoving() == DIRECTION_LEFT)
			game.holdA();
		if ((sf::Keyboard::isKeyPressed(sf::Keyboard::D)
			&& game.getMoving() == DIRECTION_NONE)
			|| game.getMoving() == DIRECTION_RIGHT)
			game.holdD();
		if ((sf::Keyboard::isKeyPressed(sf::Keyboard::S)
			&& game.getMoving() == DIRECTION_NONE)
			|| game.getMoving() == DIRECTION_DOWN)
			game.holdS();
		if ((sf::Keyboard::isKeyPressed(sf::Keyboard::W)
			&& game.getMoving() == DIRECTION_NONE)
			|| game.getMoving() == DIRECTION_UP)
			game.holdW();

		window.clear(sf::Color::White);
		game.draw(window);
		window.display();
	}
	return 0;
}
