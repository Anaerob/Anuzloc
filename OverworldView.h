#ifndef OVERWORLDVIEW_H
#define OVERWORLDVIEW_H
#include <fstream>
#include <SFML/Graphics.hpp>
#include "Constants.h"
//#include "Player.h"
//#include "Trainer.h"

class OverworldView
{
	bool m_edgeX;
	bool m_edgeY;
	//Player& m_player;
	int m_offsetX;
	int m_offsetY;
	sf::VertexArray m_tiles;
	sf::Texture m_tileSet;

public:
	OverworldView();// Player& player);

	bool getEdgeX() { return m_edgeX; }
	bool getEdgeY() { return m_edgeY; }
	int getOffsetX() { return m_offsetX; }
	int getOffsetY() { return m_offsetY; }

	//void calculateOffsetX(int overworldSizeX);
	//void calculateOffsetY(int overworldSizeY);
	//void draw(sf::RenderWindow& window, int overworld[], int overworldSizeX, int overworldSizeY);
};

#endif