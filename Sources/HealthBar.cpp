#include "HealthBar.h"

HealthBar::HealthBar(bool player) : m_bar{ sf::Quads, 4 }, m_player{ player }
{
	m_tileSet.loadFromFile("Resources/Tiles/HealthBar.png");
	reset();
}

void HealthBar::draw(sf::RenderTarget& window)
{
	float x = cf_vPX + cf_tS;
	float y = cf_vPY + cf_tS;

	if (m_player)
	{
		x = cf_vPX + cf_vSX - cf_hBSX - cf_tS;
		y = cf_vPY + cf_vSY - cf_hBSY - cf_tS;
	}

	float size = m_HP * cf_hBSX;
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
		y + cf_hBSY);
	quad[3].position = sf::Vector2f(x,
		y + cf_hBSY);

	quad[0].texCoords = sf::Vector2f(0.0f,
		(color - 1) * cf_hBSY);
	quad[1].texCoords = sf::Vector2f(cf_hBSX,
		(color - 1) * cf_hBSY);
	quad[2].texCoords = sf::Vector2f(cf_hBSX,
		color * cf_hBSY);
	quad[3].texCoords = sf::Vector2f(0.0f,
		color * cf_hBSY);

	window.draw(m_bar, &m_tileSet);
}
void HealthBar::reset()
{
	m_HP = 1.0f;
}
