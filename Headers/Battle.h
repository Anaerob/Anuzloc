#ifndef BATTLE_H
#define BATTLE_H
#include <SFML/Graphics.hpp>
#include <map>
#include <random>
#include "Constants.h"
#include "HealthBar.h"
#include "Menu.h"
#include "Player.h"
#include "Trainer.h"
#include "TextBox.h"

class Battle
{
	bool m_active;
	Menu& m_menu;
	Trainer m_opponent;
	HealthBar m_opponentHealthBar;
	Player& m_player;
	HealthBar m_playerHealthBar;
	std::map<int, std::string> m_strings;
	TextBox& m_textBox;
	
public:
	Battle(Menu& menu, Player& player, TextBox& textBox);

	void setStrings(std::map<int, std::string> strings) { m_strings = strings; }
	
	bool getActive() { return m_active; }
	
	void draw(sf::RenderWindow& window);
	void initialize(Trainer opponent);
	//void terminate();
	void updateHealthBars();
	void useMove(int i);

};
#endif