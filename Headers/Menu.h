#ifndef MENU_H
#define MENU_H
#include <SFML/Graphics.hpp>
#include "Button.h"
#include "Constants.h"
#include "Player.h"

class Menu
{
	Button m_buttonSet[c_buttons];
	bool m_inFight;
	int m_markedButton;
	Player& m_player;
	
public:
	Menu(Player& player);

	void draw(sf::RenderWindow& window);
	//void enterFight();
	void initialize();
	void navigateDown();
	void navigateLeft();
	void navigateRight();
	void navigateUp();
	//int press();
  
};
#endif