#ifndef BATTLE_H
#define BATTLE_H
#include <SFML/Graphics.hpp>
//#include "BattleMenu.h"
//#include "BattleView.h"
#include "Constants.h"
#include "Player.h"
#include "Trainer.h"
#include "TextBox.h"

class Battle
{
	bool m_active;
	//BattleMenu m_menu;
	Trainer m_opponent;
	Player& m_player;
	TextBox& m_textBox;
	//BattleView m_view;

public:
	Battle(Player& player, TextBox& textBox);

	bool getActive() { return m_active; }
	//BattleMenu& getMenu() { return m_menu; }

	//void draw(sf::RenderWindow& window);
	void initialize(Trainer opponent);
	//void menuDown();
	//int menuReturn();
	//void menuLeft();
	//void menuRight();
	//void menuUp();
	//bool useMoves(int i);

};
#endif