#ifndef GAME_H
#define GAME_H
#include <fstream>
#include <SFML/Graphics.hpp>
//#include "Battle.h"
#include "Constants.h"
//#include "Event.h"
//#include "Overworld.h"
//#include "Player.h"
//#include "TextBox.h"

class Game
{
	//Battle m_battle;
	sf::VertexArray m_frameLines;
	//std::map<int, std::string> m_generalStringMap;
	//bool m_inBattle;
	//bool m_intro;
	bool m_lock;
	//Overworld m_overworld;
	//Player m_player;
	//std::ifstream m_read;
	//TextBox m_textBox;

	/*bool m_inEvent;
	std::map<int, Trainer> m_NPCMap;
	std::ifstream m_read;
	int m_sizeX;
	int m_sizeY;
	std::map<int, std::string> m_stringMap;
	int *m_tileMap;
	int *m_triggerMap;
	std::string m_world;*/


public:
	Game();

	~Game();

	bool getLock() { return m_lock; }

	void draw(sf::RenderWindow& window);
	//void exit();
	//bool holdKeyA();
	//bool holdKeyD();
	//bool holdKeyS();
	//bool holdKeyW();
	//void initialize();
	//void pressKeyDown();
	//void pressKeyLeft();
	//void pressKeyReturn();
	//void pressKeyRight();
	//void pressKeySpace();
	//void pressKeyUp();
	//void readGeneral();
};

#endif