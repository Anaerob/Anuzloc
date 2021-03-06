#include "Trainer.h"

Trainer::Trainer(std::string type, std::string name, eDirection direction, int x, int y)
	: m_activePokemon{ 0 },
	m_dead{ false },
	m_direction{ direction },
	m_name{ name },
	m_partialRotate{ 0 },
	m_partialX{ 0 },
	m_partialY{ 0 },
	m_sprite{ sf::Quads, 4 },
	m_type{ type },
	m_x{ x },
	m_y{ y }
{
	std::string tilePath = "Resources/Tiles/";
	tilePath.append(type);
	tilePath.append(".png");
	m_tileSet.loadFromFile(tilePath);
}

void Trainer::check()
{
	m_dead = true;
	for (int i = 0; i < 6; ++i)
	{
		if (m_pokemon[i].getIndex() != 0)
		{
			if (!m_pokemon[i].getDead())
			{
				m_dead = false;
			}
		}
	}
}
void Trainer::draw(sf::RenderTarget& window,
	bool edgeX, bool edgeY,
	int overworldViewOffsetX, int overworldViewOffsetY,
	int playerPartialX, int playerPartialY)
{
	float f_d = (float)m_direction;
	float f_pX;
	float f_pY;
	float f_x = (float)(m_x - overworldViewOffsetX - playerPartialX / c::iTS);
	float f_y = (float)(m_y - overworldViewOffsetY - playerPartialY / c::iTS);

	if (edgeX)
		f_pX = 0.0f;
	else
		f_pX = (float)(playerPartialX % c::iTS);
	if (edgeY)
		f_pY = 0.0f - c::fTS * (float)(playerPartialY / c::iTS);
	else
		f_pY = (float)(playerPartialY % c::iTS);

	sf::Vertex* quad = &m_sprite[0];

	quad[0].position = sf::Vector2f((f_x - 1) * c::fTS - f_pX,
		(f_y - 1) * c::fTS - f_pY);
	quad[1].position = sf::Vector2f(f_x * c::fTS - f_pX,
		(f_y - 1) * c::fTS - f_pY);
	quad[2].position = sf::Vector2f(f_x * c::fTS - f_pX,
		f_y * c::fTS - f_pY);
	quad[3].position = sf::Vector2f((f_x - 1) * c::fTS - f_pX,
		f_y * c::fTS - f_pY);

	quad[0].texCoords = sf::Vector2f((f_d - 1) * c::fTS,
		0.0f);
	quad[1].texCoords = sf::Vector2f((f_d + 0) * c::fTS,
		0.0f);
	quad[2].texCoords = sf::Vector2f((f_d + 0) * c::fTS,
		c::fTS);
	quad[3].texCoords = sf::Vector2f((f_d - 1) * c::fTS,
		c::fTS);

	window.draw(m_sprite, &m_tileSet);
}