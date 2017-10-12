#include "HealthBar.h"

HealthBar::HealthBar(bool player) : m_bar{ sf::Quads, 4 }, m_player{ player }
{
	m_tileSet.loadFromFile("Resources/Tiles/HealthBar.png");
	reset();
}

void HealthBar::draw(sf::RenderTarget& window)
{
	float x = c::fVPX + c::fTS;
	float y = c::fVPY + c::fTS;

	if (m_player)
	{
		x = c::fVPX + c::fVSX - c::fHBSX - c::fTS;
		y = c::fVPY + c::fVSY - c::fHBSY - c::fTS;
	}

	float size = m_HP * c::fHBSX;
	float color = 1.0f;

	if (m_HP < 0.5 && m_HP > 0.2)
		color = 2.0f;
	if (m_HP < 0.2)
		color = 3.0f;

	sf::Vertex* quad = &m_bar[0];

	quad[0].position = sf::Vector2f(x,
		y);
	quad[1].position = sf::Vector2f(x + size,
		y);
	quad[2].position = sf::Vector2f(x + size,
		y + c::fHBSY);
	quad[3].position = sf::Vector2f(x,
		y + c::fHBSY);

	quad[0].texCoords = sf::Vector2f(0.0f,
		(color - 1) * c::fHBSY);
	quad[1].texCoords = sf::Vector2f(c::fHBSX,
		(color - 1) * c::fHBSY);
	quad[2].texCoords = sf::Vector2f(c::fHBSX,
		color * c::fHBSY);
	quad[3].texCoords = sf::Vector2f(0.0f,
		color * c::fHBSY);

	window.draw(m_bar, &m_tileSet);
}
void HealthBar::reset()
{
	m_HP = 1.0f;
}
