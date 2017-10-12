#ifndef GAME_H
#define GAME_H
#include <fstream>
#include <SFML/Graphics.hpp>
#include "Battle.h"
#include "Constants.h"
#include "Event.h"
#include "Menu.h"
#include "Overworld.h"
#include "Player.h"
#include "TextBox.h"

class Game
{
	Battle m_battle;
	Event m_event;
	sf::VertexArray m_frameLines;
	//std::map<int, std::string> m_generalStrings;
	Menu m_menu;
	eDirection m_moving;
	Overworld m_overworld;
	Player m_player;
	//std::ifstream m_read;
	TextBox m_textBox;

public:
	Game();

	eDirection getMoving() { return m_moving; }

	void draw(sf::RenderWindow& window);
	void holdA();
	void holdD();
	void holdS();
	void holdW();
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