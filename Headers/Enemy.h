#ifndef ENEMY_H
#define ENEMY_H
#include <random>
#include "Constants.h"

class Enemy
{
	eAction m_action;
	int m_move;
	int m_pokemon;

public:
	Enemy();

	eAction getAction();
	int getMove();
	int getPokemon();

	void calculateAction();

};
#endif