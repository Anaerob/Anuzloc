#ifndef GAME_H
#define GAME_H
#include <fstream>
#include <SFML/Graphics.hpp>
//#include "Battle.h"
#include "Constants.h"
//#include "Event.h"
#include "Overworld.h"
#include "Player.h"
#include "TextBox.h"

class Game
{
	//Battle m_battle;
	sf::VertexArray m_frameLines;
	//std::map<int, std::string> m_generalStrings;
	//bool m_inBattle;
	//bool m_intro;
	bool m_lock;
	Direction m_moving;
	Overworld m_overworld;
	Player m_player;
	//std::ifstream m_read;
	TextBox m_textBox;

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

	bool getLock() { return m_lock; }
	Direction getMoving() { return m_moving; }

	void draw(sf::RenderWindow& window);
	//void exit();
	void holdA();
	void holdD();
	void holdS();
	void holdW();
	//void initialize();
	void pressBackSpace();
	void pressDown();
	void pressLeft();
	void pressReturn();
	void pressRight();
	void pressSpace();
	void pressUp();
	//void readGeneral();
};

#endif