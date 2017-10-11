#ifndef OVERWORLD_H
#define OVERWORLD_H
#include <fstream>
#include <map>
#include <SFML/Graphics.hpp>
#include <string>
#include <vector>
//#include "Battle.h"
#include "Constants.h"
#include "Event.h"
//#include "OverworldMenu.h"
//#include "OverworldView.h"
#include "Player.h"
#include "TextBox.h"
#include "Trainer.h"
#include "White.h"

class Overworld
{
	//Battle& m_battle;
	Event& m_event;
	//OverworldMenu m_menu;
	std::map<int, Trainer> m_NPCs;
	Player& m_player;
	std::ifstream m_read;
	int m_sizeX;
	int m_sizeY;
	std::map<int, std::string> m_strings;
	TextBox& m_textBox;
	std::vector<int> m_tileMap;
	//OverworldView m_view;
	White m_whiteMenu;
	White m_whiteTextBox;
	std::string m_world;

	bool m_edgeX;
	bool m_edgeY;
	int m_offsetX;
	int m_offsetY;
	sf::VertexArray m_tiles;
	sf::Texture m_tileSet;

public:
	Overworld(Event& event, Player& player, TextBox& textBox);// Player& player, Battle& battle, TextBox& textBox);

	int getTile(int x, int y) { return m_tileMap[x +	y * (m_sizeX + 2)] / 1000; }
	int getTrigger(int x, int y) { return m_tileMap[x + y * (m_sizeX + 2)] % 1000; }

	bool getEdgeX() { return m_edgeX; }
	bool getEdgeY() { return m_edgeY; }
	int getOffsetX() { return m_offsetX; }
	int getOffsetY() { return m_offsetY; }

	//void deallocateTriggerMap();
	//void deallocateTileMap();
	void draw(sf::RenderWindow& window);
	void interact();
	//void menuDown();
	//void menuReturn();
	//void menuUp();
	void readNPCs(std::string NPCsPath);
	void readStrings(std::string stringMapPath);
	void readTileMap(std::string tileMapPath);
	//void readTrainers(std::string trainersPath);
	//void readTriggerMap(std::string triggerMapPath);
	void readWorld();

	void calculateOffsetX(int overworldSizeX);
	void calculateOffsetY(int overworldSizeY);
	void drawV(sf::RenderWindow& window,
		std::vector<int> overworld, int overworldSizeX, int overworldSizeY);
};

#endif