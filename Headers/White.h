#ifndef WHITE_H
#define WHITE_H
#include <SFML/Graphics.hpp>
#include "Headers/Constants.h"

class White
{
	sf::VertexArray m_white;

public:
	White(float positionX = 0.0f, float positionY = 0.0f, float sizeX = 0.0f, float sizeY = 0.0f);

	void draw(sf::RenderWindow& window);
};

#endif