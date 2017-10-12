#ifndef BUTTON_H
#define BUTTON_H
#include <SFML/Graphics.hpp>
#include "Constants.h"

class Button
{
	int m_characterSize;
	sf::Font m_font;
	sf::VertexArray m_frame;
	bool m_isActive;
	bool m_isMarked;
	float m_positionX;
	float m_positionY;
	float m_sizeX;
	float m_sizeY;
	sf::Text m_text;

public:
	Button(float positionX = 10.0f, float positionY = 10.0f);

	void setActive(bool isActive) { m_isActive = isActive; }
	void setMarked(bool isMarked) { m_isMarked = isMarked; }
	void setPositionX(float positionX);
	void setPositionY(float positionY);
	void setString(std::string buttonText) { m_text.setString(buttonText); }
	
	bool getActive() { return m_isActive; }
	bool getMarked() { return m_isMarked; }

	void draw(sf::RenderWindow& window);

};
#endif