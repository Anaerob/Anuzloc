#ifndef OVERWORLD_H
#define OVERWORLD_H
#include <fstream>
#include <map>
#include <SFML/Graphics.hpp>
#include <string>
#include <vector>
#include "Battle.h"
#include "Constants.h"
#include "Event.h"
#include "Player.h"
#include "TextBox.h"
#include "Trainer.h"
#include "White.h"

class Overworld
{
	Battle& m_battle;
	bool m_edgeX;
	bool m_edgeY;
	Event& m_event;
	std::map<int, Trainer> m_NPCs;
	int m_offsetX;
	int m_offsetY;
	Player& m_player;
	std::ifstream m_read;
	int m_sizeX;
	int m_sizeY;
	std::map<int, std::string> m_strings;
	TextBox& m_textBox;
	std::vector<int> m_tileMap;
	sf::VertexArray m_tiles;
	sf::Texture m_tileSet;
	White m_whiteMenu;
	White m_whiteTextBox;
	std::string m_world;

public:
	Overworld(Battle& battle, Event& event, Player& player, TextBox& textBox);

	void setWorld(std::string world);

	int getPortal(int x, int y);
	int getTile(int x, int y);
	int getTrigger(int x, int y);
	std::string getWorld() { return m_world; }

	void calculateOffsetX();
	void calculateOffsetY();
	void draw(sf::RenderWindow& window);
	void interact();
	void readNPCs(std::string NPCsPath);
	void readPortals(std::string portalsPath);
	void readStrings(std::string stringsPath);
	void readTileMap(std::string tileMapPath);
	void readWorld();

};
#endif