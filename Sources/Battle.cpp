#include "Battle.h"

Battle::Battle(Menu& menu, Player& player, TextBox& textBox)
	: m_menu{ menu },
	m_opponentHealthBar{ false },
	m_player{ player },
	m_playerHealthBar{ true },
	m_textBox{ textBox }
{
	
}

void Battle::advance(eAction action, int i)
{
	m_enemy.calculateAction();
	int enemyMove = m_enemy.getMove();

	std::random_device rd;
	std::mt19937 rng(rd());
	std::uniform_int_distribution<int> dist(0, 1);
	int speedTie = dist(rng);
	
	std::string nextLine = "";

	switch (action)
	{
	case ACTION_MOVE:
		if (m_player.m_pokemon[m_player.m_activePokemon].getStat(5) >=
			m_opponent.m_pokemon[m_opponent.m_activePokemon].getStat(5) + speedTie)
		{
			playerMove(i);
			opponentMove(enemyMove);
		}
		else
		{
			opponentMove(enemyMove);
			playerMove(i);
		}

		m_active = m_opponent.m_pokemon[m_opponent.m_activePokemon].getHP() != 0;
		break;
	case ACTION_POKEMON:
		if (i == m_player.m_activePokemon)
		{
			nextLine = m_strings.find(5)->second;
			nextLine.replace(nextLine.find("%"), 1, m_player.m_pokemon[m_player.m_activePokemon].getName());
			m_textBox.addString(nextLine);
		}
		else
		{
			nextLine = m_strings.find(6)->second;
			nextLine.replace(nextLine.find("%"), 1, m_player.m_pokemon[m_player.m_activePokemon].getName());
			m_textBox.addString(nextLine);

			m_player.m_activePokemon = i;

			nextLine = m_strings.find(7)->second;
			nextLine.replace(nextLine.find("%"), 1, m_player.m_pokemon[m_player.m_activePokemon].getName());
			m_textBox.addString(nextLine);

			opponentMove(enemyMove);
		}
	default:
		break;
	}
}
void Battle::draw(sf::RenderWindow& window)
{
	m_player.m_pokemon[m_player.m_activePokemon].draw(window);
	m_opponent.m_pokemon[m_opponent.m_activePokemon].draw(window);
	
	updateHealthBars();
	m_opponentHealthBar.draw(window);
	m_playerHealthBar.draw(window);
}
void Battle::initialize(Trainer opponent)
{
	m_opponent = opponent;
	m_active = true;
	m_menu.change(MENU_BATTLE);
}
void Battle::opponentMove(int move)
{
	double d_level;
	double d_power;
	double d_attack;
	double d_defense;
	double d_damage;
	int damage; 
	std::string nextLine;

	std::random_device rd;
	std::mt19937 rng(rd());
	std::uniform_int_distribution<int> dist(0, 100);
	int hit = dist(rng);

	if (hit > m_opponent.m_pokemon[m_opponent.m_activePokemon].getMove(move).getStat(2))
	{
		nextLine = m_strings.find(4)->second;
		nextLine.replace(nextLine.find("%"), 1, m_opponent.m_pokemon[m_opponent.m_activePokemon].getName());
		nextLine.replace(nextLine.find("%"), 1, m_opponent.m_pokemon[m_opponent.m_activePokemon].getMove(move).getName());
		m_textBox.addString(nextLine);
	}
	else
	{
		if (m_opponent.m_pokemon[m_opponent.m_activePokemon].getMove(move).getStat(1) != 0)
		{
			d_level = (double)m_opponent.m_pokemon[m_opponent.m_activePokemon].getLevel();
			d_power = (double)m_opponent.m_pokemon[m_opponent.m_activePokemon].getMove(move).getStat(1);
			d_attack = (double)m_opponent.m_pokemon[m_opponent.m_activePokemon].getStat(1);
			d_defense = (double)m_player.m_pokemon[m_player.m_activePokemon].getStat(2);
			d_damage = 2 + d_power * d_attack * (2 + 2 * d_level / 5) / (50 * d_defense);
			damage = (int)d_damage;

			m_player.m_pokemon[m_player.m_activePokemon].changeHP(-damage);
		}
		nextLine = m_strings.find(2)->second;
		nextLine.replace(nextLine.find("%"), 1, m_opponent.m_pokemon[m_opponent.m_activePokemon].getName());
		nextLine.replace(nextLine.find("%"), 1, m_opponent.m_pokemon[m_opponent.m_activePokemon].getMove(move).getName());
		m_textBox.addString(nextLine);
	}

	
}
void Battle::playerMove(int move)
{
	double d_level;
	double d_power;
	double d_attack;
	double d_defense;
	double d_damage;
	int damage; 
	std::string nextLine;

	std::random_device rd;
	std::mt19937 rng(rd());
	std::uniform_int_distribution<int> dist(0, 100);
	int hit = dist(rng);

	if (hit > m_player.m_pokemon[m_player.m_activePokemon].getMove(move).getStat(2))
	{
		nextLine = m_strings.find(3)->second;
		nextLine.replace(nextLine.find("%"), 1, m_player.m_pokemon[m_player.m_activePokemon].getName());
		nextLine.replace(nextLine.find("%"), 1, m_player.m_pokemon[m_player.m_activePokemon].getMove(move).getName());
		m_textBox.addString(nextLine);
	}
	else
	{
		if (m_player.m_pokemon[m_player.m_activePokemon].getMove(move).getStat(1) != 0)
		{
			d_level = (double)m_player.m_pokemon[m_player.m_activePokemon].getLevel();
			d_power = (double)m_player.m_pokemon[m_player.m_activePokemon].getMove(move).getStat(1);
			d_attack = (double)m_player.m_pokemon[m_player.m_activePokemon].getStat(1);
			d_defense = (double)m_opponent.m_pokemon[m_opponent.m_activePokemon].getStat(2);
			d_damage = 2 + d_power * d_attack * (2 + 2 * d_level / 5) / (50 * d_defense);
			damage = (int)d_damage;

			m_opponent.m_pokemon[m_opponent.m_activePokemon].changeHP(-damage);
		}
		nextLine = m_strings.find(1)->second;
		nextLine.replace(nextLine.find("%"), 1, m_player.m_pokemon[m_player.m_activePokemon].getName());
		nextLine.replace(nextLine.find("%"), 1, m_player.m_pokemon[m_player.m_activePokemon].getMove(move).getName());
		m_textBox.addString(nextLine);
	}
}
/*void Battle::terminate()
{
	
}*/
void Battle::updateHealthBars()
{
	float oHP = (float)m_opponent.m_pokemon[m_opponent.m_activePokemon].getHP() /
		(float)m_opponent.m_pokemon[m_opponent.m_activePokemon].getStat(0);
	m_opponentHealthBar.setHP(oHP);

	float pHP = (float)m_player.m_pokemon[m_player.m_activePokemon].getHP() /
		(float)m_player.m_pokemon[m_player.m_activePokemon].getStat(0);
	m_playerHealthBar.setHP(pHP);
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