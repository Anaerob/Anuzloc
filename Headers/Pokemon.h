#ifndef POKEMON_H
#define POKEMON_H
#include <SFML/Graphics.hpp>
#include <random>
#include <string>
#include "Constants.h"
#include "Move.h"

class Pokemon
{
	int m_BSs[6];
	int m_EVs[6];
	int m_HP;
	int m_index;
	int m_IVs[6];
	int m_level;
	Move m_moves[4];
	std::string m_name;
	std::string m_nickname;
	sf::VertexArray m_sprite;
	int m_stats[6];
	sf::Texture m_tileSet; // spriteSet?

public:
	Pokemon(int index = 0, int level = 1);

	void setMove(int i, Move move) { m_moves[i] = move; }
	void setNickname(std::string nickname) { m_nickname = nickname; }
	void setStat(int i, int stat) { m_stats[i] = stat; }

	int getBS(int i) { return m_BSs[i]; }
	int getHP() { return m_HP; }
	int getEV(int i) { return m_EVs[i]; }
	int getIndex() { return m_index; }
	int getIV(int i) { return m_IVs[i]; }
	int getLevel() { return m_level; }
	Move getMove(int i) { return m_moves[i]; }
	std::string getName() { return m_name; }
	std::string getNickname() { return m_nickname; }
	int getStat(int i) { return m_stats[i]; }
	
	void changeHP(int change);
	void draw(sf::RenderTarget& window, int direction);
	void generateMoves();
	void generateStats();
	void levelUp(int level);
	void resetAll();
	void updateStats();
	
};
#endif