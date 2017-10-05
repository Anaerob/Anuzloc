#include "Headers/White.h"

White::White(float positionX, float positionY, float sizeX, float sizeY)
	: m_white{ sf::Quads, 4 }
{
	m_white[0].position = sf::Vector2f(positionX,
		positionY);
	m_white[1].position = sf::Vector2f(positionX + sizeX,
		positionY);
	m_white[2].position = sf::Vector2f(positionX + sizeX,
		positionY + sizeY);
	m_white[3].position = sf::Vector2f(positionX,
		positionY + sizeY);

	for (int i = 0; i < 4; ++i)
		m_white[i].color = sf::Color::White;
}

void White::draw(sf::RenderWindow& window)
{
	window.draw(m_white);
}
