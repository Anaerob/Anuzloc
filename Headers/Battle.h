#ifndef BATTLE_H
#define BATTLE_H
#include <SFML/Graphics.hpp>
#include "Constants.h"
#include "HealthBar.h"
#include "Player.h"
#include "Trainer.h"
#include "TextBox.h"

class Battle
{
	bool m_active;
	Trainer m_opponent;
	HealthBar m_opponentHealthBar;
	Player& m_player;
	HealthBar m_playerHealthBar;
	TextBox& m_textBox;
	
public:
	Battle(Player& player, TextBox& textBox);

	bool getActive() { return m_active; }
	
	void draw(sf::RenderWindow& window);
	void initialize(Trainer opponent);
	//void menuDown();
	//int menuReturn();
	//void menuLeft();
	//void menuRight();
	//void menuUp();
	void updateHealthBars();
	//bool useMoves(int i);

};
#endif