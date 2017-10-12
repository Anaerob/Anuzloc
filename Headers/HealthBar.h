#ifndef HEALTHBAR_H
#define HEALTHBAR_H
#include <SFML/Graphics.hpp>
#include "Constants.h"

class HealthBar
{
	sf::VertexArray m_bar;
	float m_HP;
	bool m_player;
	sf::Texture m_tileSet;

public:
	HealthBar(bool player = true);

	void setHP(float HP) { m_HP = HP; }

	void draw(sf::RenderTarget& window);
	void reset();

};
#endif