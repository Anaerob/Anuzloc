#ifndef BATTLE_H
#define BATTLE_H
#include <SFML/Graphics.hpp>
#include <map>
#include <random>
#include "Constants.h"
#include "Enemy.h"
#include "HealthBar.h"
#include "Menu.h"
#include "Player.h"
#include "Trainer.h"
#include "TextBox.h"

class Battle
{
	bool m_active;
	Enemy m_enemy;
	sf::VertexArray m_hasQueue;
	Menu& m_menu;
	eAction m_nextEnemyA;
	int m_nextEnemyI;
	eAction m_nextPlayerA;
	int m_nextPlayerI;
	Trainer m_opponent;
	HealthBar m_opponentHealthBar;
	Player& m_player;
	HealthBar m_playerHealthBar;
	std::map<int, std::string> m_strings;
	TextBox& m_textBox;
	
public:
	Battle(Menu& menu, Player& player, TextBox& textBox);

	void setNextAction(eAction nextPlayerA, int nextPlayerI);
	void setStrings(std::map<int, std::string> strings) { m_strings = strings; }
	
	bool getActive() { return m_active; }
	
	void advance();
	void dialogue(int i, std::string replace1, std::string replace2);
	void draw(sf::RenderWindow& window);
	void initialize(Trainer opponent);
	void opponentMove(int i);
	void playerMove(int i);
	bool queueEmpty();
	//void terminate();
	void updateHealthBars();
	
};
#endif