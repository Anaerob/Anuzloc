#include "Enemy.h"

Enemy::Enemy()
	: m_action{ ACTION_NONE }, m_move{ -1 }, m_pokemon{ -1 }
{

}

eAction Enemy::getAction()
{
	eAction temp = m_action;
	m_action = ACTION_NONE;
	return temp;
}
int Enemy::getMove()
{
	int temp = m_move;
	m_move = -1;
	return temp;
}
int Enemy::getPokemon()
{
	int temp = m_pokemon;
	m_pokemon = -1;
	return temp;
}

void Enemy::calculateAction()
{
	m_action = ACTION_MOVE;
	
	std::random_device rd;
	std::mt19937 rng(rd());
	std::uniform_int_distribution<int> dist(0, 1);
	
	m_move = dist(rng);
}