#include "Player.h"

Player::Player()
	: Trainer{ "Player", "Red", DIRECTION_DOWN, 11, 31 },
	m_lock{ false }
{
	m_tileSet.loadFromFile("Resources/Tiles/Player.png");
}

void Player::draw(sf::RenderTarget& window,
	bool edgeX, bool edgeY, int mapOffsetX, int mapOffsetY)
{
	float f_d = (float)m_direction;
	float f_pX;
	float f_pY;
	float f_x = (float)(m_x - mapOffsetX);
	float f_y = (float)(m_y - mapOffsetY);

	if (edgeX)
		f_pX = (float)m_partialX;
	else
		f_pX = 0.0f;
	if (edgeY)
		f_pY = (float)m_partialY;
	else
		f_pY = 0.0f;

	sf::Vertex* quad = &m_sprite[0];

	quad[0].position = sf::Vector2f((f_x - 1) * c::fTS + f_pX,
		(f_y - 1) * c::fTS + f_pY);
	quad[1].position = sf::Vector2f(f_x * c::fTS + f_pX,
		(f_y - 1) * c::fTS + f_pY);
	quad[2].position = sf::Vector2f(f_x * c::fTS + f_pX,
		f_y * c::fTS + f_pY);
	quad[3].position = sf::Vector2f((f_x - 1) * c::fTS + f_pX,
		f_y * c::fTS + f_pY);

	quad[0].texCoords = sf::Vector2f((f_d - 1) * c::fTS,
		0.0f);
	quad[1].texCoords = sf::Vector2f(f_d * c::fTS,
		0.0f);
	quad[2].texCoords = sf::Vector2f(f_d * c::fTS,
		c::fTS);
	quad[3].texCoords = sf::Vector2f((f_d - 1) * c::fTS,
		c::fTS);

	window.draw(m_sprite, &m_tileSet);
}
void Player::move(eDirection direction, int nextTile)
{
	if (m_direction != direction)
		rotate(direction);
	else
		switch (direction)
		{
		case DIRECTION_UP:
			moveUp(nextTile);
			break;
		case DIRECTION_DOWN:
			moveDown(nextTile);
			break;
		case DIRECTION_LEFT:
			moveLeft(nextTile);
			break;
		case DIRECTION_RIGHT:
			moveRight(nextTile);
			break;
		default:
			break;
		}
}
void Player::moveDown(int nextTile)
{
	if (nextTile == 1 || nextTile == 2)
	{
		m_partialY = (m_partialY + c::iWSp) % c::iTS;
		m_moving = !(m_partialY % c::iTS == 0);
		if (!m_moving)
			m_y++;
	}
	else if (nextTile == 4)
	{
		m_partialY = (m_partialY + c::iLSp) % (2 * c::iTS);
		m_moving = !(m_partialY % (2 * c::iTS) == 0);
		if (!m_moving)
			m_y += 2;
	}
}
void Player::moveLeft(int nextTile)
{
	if (nextTile == 1 || nextTile == 2)
	{
		m_partialX = (m_partialX - c::iWSp) % c::iTS;
		m_moving = !(m_partialX % c::iTS == 0);
		if (!m_moving)
			m_x--;
	}
}
void Player::moveRight(int nextTile)
{
	if (nextTile == 1 || nextTile == 2)
	{
		m_partialX = (m_partialX + c::iWSp) % c::iTS;
		m_moving = !(m_partialX % c::iTS == 0);
		if (!m_moving)
			m_x++;
	}
}
void Player::moveUp(int nextTile)
{
	if (nextTile == 1 || nextTile == 2)
	{
		m_partialY = (m_partialY - c::iWSp) % c::iTS;
		m_moving = !(m_partialY % c::iTS == 0);
		if (!m_moving)
			m_y--;
	}
}
void Player::rotate(eDirection direction)
{
	m_partialRotate = (m_partialRotate + c::iRSp) % c::iTS;
	m_moving = !(m_partialRotate % c::iTS == 0);
	if (!m_moving)
		m_direction = direction;
}