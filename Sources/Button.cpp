#include "Button.h"

Button::Button(float positionX,	float positionY)
	: m_characterSize{ 32 },
	m_frame{ sf::Quads, 16 },
	m_isActive{ false },
	m_isMarked{ false },
	m_positionX{ positionX },
	m_positionY{ positionY },
	m_sizeX{ 192.0f },
	m_sizeY{ 100.0f }
{
	m_font.loadFromFile("Resources/Fonts/arial.ttf");

	m_text.setCharacterSize(32);
	m_text.setFillColor(sf::Color::Black);
	m_text.setFont(m_font);
	m_text.setPosition(sf::Vector2f(positionX + 16.0f,
		positionY + 28.0f));
	m_text.setString("BUTTON");
}

void Button::setPositionX(float positionX)
{ 
	m_positionX = positionX;
	m_text.setPosition(sf::Vector2f(m_positionX + 16.0f,
		m_positionY + 28.0f));
}
void Button::setPositionY(float positionY)
{
	m_positionY = positionY;
	m_text.setPosition(sf::Vector2f(m_positionX + 16.0f,
		m_positionY + 28.0f));
}

void Button::draw(sf::RenderWindow& window)
{
	if (m_isActive)
	{
		sf::Color color = sf::Color::Black;
		float frameThickness = 1.0f;

		if (m_isMarked)
			frameThickness = 3.0f;

		for (int i = 0; i < 16; ++i)
			m_frame[i].color = color;

		m_frame[0].position = sf::Vector2f(m_positionX,
			m_positionY);
		m_frame[1].position = sf::Vector2f(m_positionX + m_sizeX,
			m_positionY);
		m_frame[2].position = sf::Vector2f(m_positionX + m_sizeX,
			m_positionY + frameThickness);
		m_frame[3].position = sf::Vector2f(m_positionX,
			m_positionY + frameThickness);

		m_frame[4].position = sf::Vector2f(m_positionX + m_sizeX - frameThickness,
			m_positionY);
		m_frame[5].position = sf::Vector2f(m_positionX + m_sizeX,
			m_positionY);
		m_frame[6].position = sf::Vector2f(m_positionX + m_sizeX,
			m_positionY + m_sizeY);
		m_frame[7].position = sf::Vector2f(m_positionX + m_sizeX - frameThickness,
			m_positionY + m_sizeY);

		m_frame[8].position = sf::Vector2f(m_positionX,
			m_positionY + m_sizeY - frameThickness);
		m_frame[9].position = sf::Vector2f(m_positionX + m_sizeX,
			m_positionY + m_sizeY - frameThickness);
		m_frame[10].position = sf::Vector2f(m_positionX + m_sizeX,
			m_positionY + m_sizeY);
		m_frame[11].position = sf::Vector2f(m_positionX,
			m_positionY + m_sizeY);

		m_frame[12].position = sf::Vector2f(m_positionX,
			m_positionY);
		m_frame[13].position = sf::Vector2f(m_positionX + frameThickness,
			m_positionY);
		m_frame[14].position = sf::Vector2f(m_positionX + frameThickness,
			m_positionY + m_sizeY);
		m_frame[15].position = sf::Vector2f(m_positionX,
			m_positionY + m_sizeY);

		window.draw(m_frame);
		window.draw(m_text);
	}
}
