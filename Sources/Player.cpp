#include "../Headers/Player.h"

Player::Player()
{
	m_sprite.setPrimitiveType(sf::Quads);
	m_sprite.resize(4);
	m_tileSet.loadFromFile("Resources/Tiles/Player.png");
}

void Player::draw(sf::RenderTarget& window,
	bool edgeX, bool edgeY, int mapOffsetX, int mapOffsetY)
{
	float f_d = (float)getDirection();
	float f_pX;
	float f_pY;
	float f_x = (float)(getX() - mapOffsetX);
	float f_y = (float)(getY() - mapOffsetY);

	if (edgeX)
		f_pX = (float)getPartialX();
	else
		f_pX = 0.0f;
	if (edgeY)
		f_pY = (float)getPartialY();
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

	quad[0].texCoords = sf::Vector2f(f_d * cf_tS,
		0.0f);
	quad[1].texCoords = sf::Vector2f((f_d + 1) * cf_tS,
		0.0f);
	quad[2].texCoords = sf::Vector2f((f_d + 1) * cf_tS,
		cf_tS);
	quad[3].texCoords = sf::Vector2f(f_d * cf_tS,
		cf_tS);

	window.draw(m_sprite, &m_tileSet);
}
bool Player::move(int direction, int nextTile)
{
	bool moving = false;

	if (getDirection() != direction)
		moving = rotate(direction);
	else
		switch (direction)
		{
		case 0:
			moving = moveDown(nextTile);
			break;
		case 1:
			moving = moveUp(nextTile);
			break;
		case 2:
			moving = moveLeft(nextTile);
			break;
		case 3:
			moving = moveRight(nextTile);
			break;
		}

	return moving;
}
bool Player::moveDown(int nextTile)
{
	bool moving = false;

	if (nextTile == 1 || nextTile == 2)
	{
		setPartialY((getPartialY() + c_walkSpeed) %
			c_tS);
		moving = (!(getPartialY() % c_tS == 0));
		if (!moving)
			setY(getY() + 1);
	}
	else if (nextTile == 4)
	{
		setPartialY((getPartialY() + c_ledgeSpeed) %
			(2 * c_tS));
		moving = (!(getPartialY() % (2 * c_tS) == 0));
		if (!moving)
			setY(getY() + 2);
	}

	return moving;
}
bool Player::moveLeft(int nextTile)
{
	bool moving = false;

	if (nextTile == 1 || nextTile == 2)
	{
		setPartialX((getPartialX() - c_walkSpeed) %
			c_tS);
		moving = (!(getPartialX() % c_tS == 0));
		if (!moving)
			setX(getX() - 1);
	}

	return moving;
}
bool Player::moveRight(int nextTile)
{
	bool moving = false;

	if (nextTile == 1 || nextTile == 2)
	{
		setPartialX((getPartialX() + c_walkSpeed) %
			c_tS);
		moving = (!(getPartialX() % c_tS == 0));
		if (!moving)
			setX(getX() + 1);
	}

	return moving;
}
bool Player::moveUp(int nextTile)
{
	bool moving = false;

	if (nextTile == 1 || nextTile == 2)
	{
		setPartialY((getPartialY() - c_walkSpeed) %
			c_tS);
		moving = (!(getPartialY() % c_tS == 0));
		if (!moving)
			setY(getY() - 1);
	}

	return moving;
}
bool Player::rotate(int direction)
{
	setPartialRotate((getPartialRotate() + c_rotateSpeed) %
		c_tS);
	bool rotating = (!(getPartialRotate() % c_tS == 0));
	if (!rotating)
		setDirection(direction);
	return rotating;
}