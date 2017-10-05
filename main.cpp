#include <SFML/Graphics.hpp>

const int c_wSX = 960;
const int c_wSY = 540;

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
