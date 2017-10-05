#ifndef OVERWORLD_H
#define OVERWORLD_H
#include <fstream>
//#include <map>
#include <SFML/Graphics.hpp>
//#include "Battle.h"
#include "Constants.h"
//#include "Event.h"
//#include "OverworldMenu.h"
#include "OverworldView.h"
#include "Player.h"
//#include "TextBox.h"
#include "Trainer.h"
#include "White.h"

class Overworld
{
	//Battle& m_battle;
	//Event& m_event;
	//bool m_inEvent;
	//OverworldMenu m_menu;
	//std::map<int, Trainer> m_NPCs;
	Player& m_player;
	std::ifstream m_read;
	int m_sizeX;
	int m_sizeY;
	//std::map<int, std::string> m_stringMap;
	//TextBox& m_textBox;
	int *m_tileMap;
	//int *m_triggerMap;
	OverworldView m_view;
	White m_whiteMenu;
	White m_whiteTextBox;
	//std::string m_world;

public:
	Overworld(Player& player);// Player& player, Battle& battle, TextBox& textBox);

	~Overworld();

	//TextBox& getTextBox() { return m_textBox; }
	int getTile(int x, int y) { return m_tileMap[x +	y * (m_sizeX + 2)]; }
	//int getTrigger(int x, int y) { return m_triggerMap[x + y * (m_sizeX + 2)]; }

	//void deallocateTriggerMap();
	void deallocateTileMap();
	void draw(sf::RenderWindow& window);
	//bool interact();
	//void menuDown();
	//void menuReturn();
	//void menuUp();
	//void readNPCs(std::string NPCsPath);
	//void readStringMap(std::string stringMapPath);
	void readTileMap(std::string tileMapPath);
	//void readTrainers(std::string trainersPath);
	//void readTriggerMap(std::string triggerMapPath);
	void readWorld();
};

#endif