#ifndef MENU_H
#define MENU_H
#include <SFML/Graphics.hpp>
#include <vector>
#include "Button.h"
#include "Constants.h"
#include "Player.h"

class Menu
{
	eAction m_action;
	std::vector<Button> m_buttonSet;
	int m_index;
	bool m_lock;
	int m_marked;
	//int m_move;
	eMenu m_menu;
	Player& m_player;
	//int m_pokemon;
	
public:
	Menu(Player& player);

	eAction getAction();
	eMenu getCurrent() { return m_menu; }
	int getIndex();
	//int getMove();
	//int getPokemon();

	void back();
	void change(eMenu menu);
	void draw(sf::RenderWindow& window);
	void enter();
	void lock() { m_lock = true; }
	void moveMark(int i);
	void navigateDown();
	void navigateLeft();
	void navigateRight();
	void navigateUp();
	//void reset();
	void resetMark();
  
};
#endif