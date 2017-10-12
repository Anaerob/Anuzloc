#include "Battle.h"

Battle::Battle(Menu& menu, Player& player, TextBox& textBox)
	: m_menu{ menu },
	m_opponentHealthBar{ false },
	m_player{ player },
	m_playerHealthBar{ true },
	m_textBox{ textBox }
{
	
}

void Battle::draw(sf::RenderWindow& window)
{
	m_player.getPokemon(0).draw(window, 1);
	m_opponent.getPokemon(0).draw(window, 0);
	
	updateHealthBars();
	m_opponentHealthBar.draw(window);
	m_playerHealthBar.draw(window);
}
void Battle::initialize(Trainer opponent)
{
	m_opponent = opponent;
	m_active = true;
	m_menu.change(MENU_FIGHT);
}
void Battle::terminate()
{
	m_menu.change(MENU_NONE);
}
void Battle::updateHealthBars()
{
	float oHP = (float)m_opponent.getPokemon(0).getHP() / (float)m_opponent.getPokemon(0).getStat(0);
	m_opponentHealthBar.setHP(oHP);

	float pHP = (float)m_player.getPokemon(0).getHP() / (float)m_player.getPokemon(0).getStat(0);
	m_playerHealthBar.setHP(pHP);
}
void Battle::useMove(int move)
{
	double d_level;
	double d_power;
	double d_attack;
	double d_defense;
	double d_damage;
	int damage;

	std::random_device rd;
	std::mt19937 rng(rd());
	std::uniform_int_distribution<int> dist(0, 1);
	int opponentMove = dist(rng);

	if (m_player.m_pokemon[0].getMove(move).getStat(1) != 0)
	{
		d_level = (double)m_player.m_pokemon[0].getLevel();
		d_power = (double)m_player.m_pokemon[0].getMove(move).getStat(1);
		d_attack = (double)m_player.m_pokemon[0].getStat(1);
		d_defense = (double)m_opponent.m_pokemon[0].getStat(2);
		d_damage = 2 +
			d_power * d_attack * (2 + 2 * d_level / 5) / (50 * d_defense);
		damage = (int)d_damage;
	}
	else
		damage = 0;
	m_opponent.m_pokemon[0].changeHP(-damage);

	if (m_opponent.m_pokemon[0].getMove(opponentMove).getStat(1) != 0)
	{
		d_level = (double)m_opponent.m_pokemon[0].getLevel();
		d_power = (double)m_opponent.m_pokemon[0].getMove(opponentMove).getStat(1);
		d_attack = (double)m_opponent.m_pokemon[0].getStat(1);
		d_defense = (double)m_player.m_pokemon[0].getStat(2);
		d_damage = 2 +
			d_power * d_attack * (2 + 2 * d_level / 5) / (50 * d_defense);
		damage = (int)d_damage;
	}
	else
		damage = 0;
	m_player.m_pokemon[0].changeHP(-damage);

	m_active = m_opponent.m_pokemon[0].getHP() != 0;
}
/*void Pokemon::useMove(Move& move, Pokemon& opponent)
{
	int pp = move.getStat(0);
	if (pp > 0)
	{
		double d_accuracy = (double)move.getStat(2);
		std::random_device rd;
		std::mt19937 rng(rd());
		std::uniform_real_distribution<double> dist(0, 100);
		if (dist(rng) <= d_accuracy)
		{
			double d_level = (double)m_level;
			double d_power = (double)move.getStat(1);
			double d_attack = (double)getStat(1);
			double d_defense = (double)opponent.getStat(2);
			double d_damage = 2 + d_power * d_attack * (2 + 2 * d_level / 5) / (50 * d_defense);
			int damage = (int)d_damage;
			opponent.reduceHP(damage);
		}
	}
}*/