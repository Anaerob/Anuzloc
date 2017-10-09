#ifndef PLAYER_H
#define PLAYER_H
#include <SFML/Graphics.hpp>
#include "Constants.h"
#include "Trainer.h"

class Player : public Trainer
{
	sf::VertexArray m_sprite;
	sf::Texture m_tileSet;

public:
	Player();

	void draw(sf::RenderTarget& window,
		bool edgeX, bool edgeY,
		int mapOffsetX, int mapOffsetY);
	void move(Direction direction, int nextTile);
	void moveDown(int nextTile);
	void moveLeft(int nextTile);
	void moveRight(int nextTile);
	void moveUp(int nextTile);
	void rotate(Direction direction);
};

#endif