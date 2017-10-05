#ifndef PLAYER_H
#define PLAYER_H
#include <SFML/Graphics.hpp>
#include "Headers/Constants.h"
#include "Headers/Trainer.h"

class Player : public Trainer
{
	sf::VertexArray m_sprite;
	sf::Texture m_tileSet;

public:
	Player();

	void draw(sf::RenderTarget& window,
		bool edgeX, bool edgeY,
		int mapOffsetX, int mapOffsetY);
	bool move(int direction, int nextTile);
	bool moveDown(int nextTile);
	bool moveLeft(int nextTile);
	bool moveRight(int nextTile);
	bool moveUp(int nextTile);
	bool rotate(int direction);
};

#endif