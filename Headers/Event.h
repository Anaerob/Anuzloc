#ifndef EVENT_H
#define EVENT_H
#include <fstream>
#include <map>
#include <string>
#include "Battle.h"
#include "Player.h"
#include "TextBox.h"

class Event
{
	bool m_active;
	Battle& m_battle;
	//Trainer m_opponent;
	Player& m_player;
	std::ifstream m_read;
	std::map<int, std::string> m_strings;
	TextBox& m_textBox;
	std::string m_world;

public:
	Event(Battle& battle, Player& player, TextBox& textBox);

	void setStrings(std::map<int, std::string> strings) { m_strings = strings; }
	//void setWorld(std::string world) { m_world = world; }

	bool getActive() { return m_active; }

	void advance();
	void initialize(int ID);
	//void readWorld();

};
#endif