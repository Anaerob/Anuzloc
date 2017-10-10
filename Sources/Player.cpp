#include "Player.h"

Player::Player()
{
	m_sprite.setPrimitiveType(sf::Quads);
	m_sprite.resize(4);
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

	quad[0].position = sf::Vector2f((f_x - 1) * cf_tS + f_pX,
		(f_y - 1) * cf_tS + f_pY);
	quad[1].position = sf::Vector2f(f_x * cf_tS + f_pX,
		(f_y - 1) * cf_tS + f_pY);
	quad[2].position = sf::Vector2f(f_x * cf_tS + f_pX,
		f_y * cf_tS + f_pY);
	quad[3].position = sf::Vector2f((f_x - 1) * cf_tS + f_pX,
		f_y * cf_tS + f_pY);

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
void Player::move(Direction direction, int nextTile)
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
		m_partialY = (m_partialY + c_walkSpeed) % c_tS;
		m_moving = !(m_partialY % c_tS == 0);
		if (!m_moving)
			m_y++;
	}
	else if (nextTile == 4)
	{
		m_partialY = (m_partialY + c_ledgeSpeed) % (2 * c_tS);
		m_moving = !(m_partialY % (2 * c_tS) == 0);
		if (!m_moving)
			m_y += 2;
	}
}
void Player::moveLeft(int nextTile)
{
	if (nextTile == 1 || nextTile == 2)
	{
		m_partialX = (m_partialX - c_walkSpeed) % c_tS;
		m_moving = !(m_partialX % c_tS == 0);
		if (!m_moving)
			m_x--;
	}
}
void Player::moveRight(int nextTile)
{
	if (nextTile == 1 || nextTile == 2)
	{
		m_partialX = (m_partialX + c_walkSpeed) % c_tS;
		m_moving = !(m_partialX % c_tS == 0);
		if (!m_moving)
			m_x++;
	}
}
void Player::moveUp(int nextTile)
{
	if (nextTile == 1 || nextTile == 2)
	{
		m_partialY = (m_partialY - c_walkSpeed) % c_tS;
		m_moving = !(m_partialY % c_tS == 0);
		if (!m_moving)
			m_y--;
	}
}
void Player::rotate(Direction direction)
{
	m_partialRotate = (m_partialRotate + c_rotateSpeed) % c_tS;
	m_moving = !(m_partialRotate % c_tS == 0);
	if (!m_moving)
		m_direction = direction;
}