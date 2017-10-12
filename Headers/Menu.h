#ifndef MENU_H
#define MENU_H
#include <SFML/Graphics.hpp>
#include "Button.h"
#include "Constants.h"
#include "Player.h"

class Menu
{
	Button m_buttonSet[c_buttons];
	int m_marked;
	int m_move;
	e_menu m_menu;
	Player& m_player;
	
public:
	Menu(Player& player);

	int getMove() { return m_move; }

	void back();
	void change(e_menu menu);
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