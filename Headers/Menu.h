#ifndef MENU_H
#define MENU_H
#include <SFML/Graphics.hpp>
#include <vector>
#include "Button.h"
#include "Constants.h"
#include "Player.h"

class Menu
{
	std::vector<Button> m_buttonSet;
	int m_marked;
	int m_move;
	eMenu m_menu;
	Player& m_player;
	
public:
	Menu(Player& player);

	int getMove() { return m_move; }

	void back();
	void change(eMenu menu);
	void draw(sf::RenderWindow& window);
	void enter();
	void moveMark(int i);
	void navigateDown();
	void navigateLeft();
	void navigateRight();
	void navigateUp();
	void reset();
	void resetMark();
  
};
#endif