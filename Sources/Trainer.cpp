#include "../Headers/Trainer.h"

Trainer::Trainer(std::string type, std::string name, Direction direction, int x, int y)
	: m_direction{ direction },
	m_name{ name },
	m_partialRotate{ 0 },
	m_partialX{ 0 },
	m_partialY{ 0 },
	m_type{ type },
	m_x{ x },
	m_y{ y }
{
	m_sprite.setPrimitiveType(sf::Quads);
	m_sprite.resize(4);
	std::string tilePath = "Resources/Tiles/";
	tilePath.append(type);
	tilePath.append(".png");
	m_tileSet.loadFromFile(tilePath);
}

void Trainer::draw(sf::RenderTarget& window,
	bool edgeX, bool edgeY,
	int overworldViewOffsetX, int overworldViewOffsetY,
	int playerPartialX, int playerPartialY)
{
	float f_d = (float)getDirection();
	float f_pX;
	float f_pY;
	float f_x = (float)(getX() - overworldViewOffsetX - playerPartialX / c_tS);
	float f_y = (float)(getY() - overworldViewOffsetY - playerPartialY / c_tS);

	if (edgeX)
		f_pX = 0.0f;
	else
		f_pX = (float)(playerPartialX % c_tS);
	if (edgeY)
		f_pY = 0.0f - cf_tS * (float)(playerPartialY / c_tS);
	else
		f_pY = (float)(playerPartialY % c_tS);

	sf::Vertex* quad = &m_sprite[0];

	quad[0].position = sf::Vector2f((f_x - 1) * cf_tS - f_pX,
		(f_y - 1) * cf_tS - f_pY);
	quad[1].position = sf::Vector2f(f_x * cf_tS - f_pX,
		(f_y - 1) * cf_tS - f_pY);
	quad[2].position = sf::Vector2f(f_x * cf_tS - f_pX,
		f_y * cf_tS - f_pY);
	quad[3].position = sf::Vector2f((f_x - 1) * cf_tS - f_pX,
		f_y * cf_tS - f_pY);

	quad[0].texCoords = sf::Vector2f((f_d - 1) * cf_tS,
		0.0f);
	quad[1].texCoords = sf::Vector2f((f_d + 0) * cf_tS,
		0.0f);
	quad[2].texCoords = sf::Vector2f((f_d + 0) * cf_tS,
		cf_tS);
	quad[3].texCoords = sf::Vector2f((f_d - 1) * cf_tS,
		cf_tS);

	window.draw(m_sprite, &m_tileSet);
}