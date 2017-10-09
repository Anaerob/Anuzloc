#include <SFML/Graphics.hpp>
#include "Headers/Constants.h"
#include "Headers/Game.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(c_wSX, c_wSY),
		"Pokemon Nuzlocke Client");
	window.setVerticalSyncEnabled(true);
	window.setKeyRepeatEnabled(false);

	Game game;
	
	Direction moving{ DIRECTION_NONE };
	
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
				case sf::Keyboard::Down:
					game.pressKeyDown();
					break;
				case sf::Keyboard::Escape:
					window.close();
					break;
				case sf::Keyboard::Left:
					game.pressKeyLeft();
					break;
				case sf::Keyboard::Return:
					game.pressKeyReturn();
					break;
				case sf::Keyboard::Right:
					game.pressKeyRight();
					break;
				case sf::Keyboard::Space:
					game.pressKeySpace();
					break;
				case sf::Keyboard::Up:
					game.pressKeyUp();
					break;
				default:
					break;
				}
				break;
			default:
				break;
			}

		if ((sf::Keyboard::isKeyPressed(sf::Keyboard::A) && !game.getLock()) ||
			moving == DIRECTION_LEFT) // change to game.getMoving() == DIRECITON_
		{
			game.holdKeyA();
			moving = game.getMoving(); // remove everywhere
		}
		if ((sf::Keyboard::isKeyPressed(sf::Keyboard::D) && !game.getLock()) ||
			moving == DIRECTION_RIGHT)
		{
			game.holdKeyD();
			moving = game.getMoving();
		}
		if ((sf::Keyboard::isKeyPressed(sf::Keyboard::S) && !game.getLock()) ||
			moving == DIRECTION_DOWN)
		{
			game.holdKeyS();
			moving = game.getMoving();
		}
		if ((sf::Keyboard::isKeyPressed(sf::Keyboard::W) && !game.getLock()) ||
			moving == DIRECTION_UP)
		{
			game.holdKeyW();
			moving = game.getMoving();
		}

		window.clear(sf::Color::White);
		game.draw(window);
		window.display();
	}
	return 0;
}
