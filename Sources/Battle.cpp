#include "Battle.h"

Battle::Battle(Menu& menu, Player& player, TextBox& textBox)
	: m_hasQueue{ sf::Triangles, 3 },
	m_menu{ menu },
	m_nextEnemyA{ ACTION_NONE },
	m_nextEnemyI{ -1 },
	m_nextPlayerA{ ACTION_NONE },
	m_nextPlayerI{ -1 },
	m_opponentHealthBar{ false },
	m_player{ player },
	m_playerHealthBar{ true },
	m_textBox{ textBox }
{
	m_hasQueue[0].position = sf::Vector2f(c::fVPX + c::fVSX - 15.0f,
		c::fVPY + c::fVSY - 13.0f);
	m_hasQueue[1].position = sf::Vector2f(c::fVPX + c::fVSX - 5.0f,
		c::fVPY + c::fVSY - 13.0f);
	m_hasQueue[2].position = sf::Vector2f(c::fVPX + c::fVSX - 10.0f,
		c::fVPY + c::fVSY - 5.0f);

	for (int i = 0; i < 3; ++i)
		m_hasQueue[i].color = sf::Color::Black;
}

void Battle::setNextAction(eAction nextPlayerA, int nextPlayerI)
{
	if (nextPlayerA != ACTION_NONE)
	{
		if (nextPlayerA == ACTION_SWITCH && m_player.m_pokemon[m_player.m_activePokemon].getDead())
		{
			m_nextPlayerA = ACTION_POKEMON;
			m_nextPlayerI = nextPlayerI;

			m_nextEnemyA = ACTION_NONE;
			m_nextEnemyI = -1;
		}
		else
		{
			m_nextPlayerA = nextPlayerA;
			m_nextPlayerI = nextPlayerI;

			m_enemy.calculateAction();
			m_nextEnemyA = ACTION_MOVE;
			m_nextEnemyI = m_enemy.getMove();
		}

		advance();
	}
}

void Battle::advance()
{
	std::random_device rd;
	std::mt19937 rng(rd());
	std::uniform_int_distribution<int> dist(0, 1);
	int speedTie = dist(rng);
	bool playerFirst = true;
	
	std::string s_pPokemon = m_player.m_pokemon[m_player.m_activePokemon].getName();
	std::string s_pAction = "";
	std::string s_ePokemon = m_opponent.m_pokemon[m_opponent.m_activePokemon].getName();
	std::string s_eAction = "";

	switch (m_nextPlayerA)
	{
	case ACTION_NONE:
		if (m_nextEnemyA != ACTION_NONE)
		{
			opponentMove(m_nextEnemyI);
		}
		break;
	case ACTION_MOVE:
		if (m_nextEnemyA != ACTION_NONE)
		{
			playerFirst = m_player.m_pokemon[m_player.m_activePokemon].getStat(5) >=
				m_opponent.m_pokemon[m_opponent.m_activePokemon].getStat(5) + speedTie;
			if (playerFirst)
			{
				playerMove(m_nextPlayerI);
			}
			else
			{
				opponentMove(m_nextEnemyI);
			}
		}
		else
		{
			playerMove(m_nextPlayerI);
		}
		break;
	case ACTION_POKEMON:
		m_player.m_activePokemon = m_nextPlayerI;
		s_pAction = m_player.m_pokemon[m_player.m_activePokemon].getName();
		dialogue(7, s_pAction, "");

		m_nextPlayerA = ACTION_NONE;
		m_nextPlayerI = -1;
		break;
	case ACTION_SWITCH:
		if (m_nextPlayerI == m_player.m_activePokemon)
		{
			dialogue(5, s_pPokemon, "");

			m_nextEnemyA = ACTION_NONE;
			m_nextEnemyI = -1;
			m_nextPlayerA = ACTION_NONE;
			m_nextPlayerI = -1;
		}
		else
		{
			dialogue(6, s_pPokemon, "");

			m_nextPlayerA = ACTION_POKEMON;
		}
	default:
		break;
	}

	m_textBox.advance();
}
void Battle::dialogue(int i, std::string replace1, std::string replace2)
{
	std::string nextLine = m_strings.find(i)->second;
	nextLine.replace(nextLine.find("%"), 1, replace1);
	nextLine.replace(nextLine.find("%"), 1, replace2);
	m_textBox.queueString(nextLine);
}
void Battle::draw(sf::RenderWindow& window)
{
	if (!m_player.m_pokemon[m_player.m_activePokemon].getDead())
		m_player.m_pokemon[m_player.m_activePokemon].draw(window);
	if (!m_opponent.m_pokemon[m_opponent.m_activePokemon].getDead())
		m_opponent.m_pokemon[m_opponent.m_activePokemon].draw(window);
	
	if (!queueEmpty())
		window.draw(m_hasQueue);

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
	
	std::string s_ePokemon = m_opponent.m_pokemon[m_opponent.m_activePokemon].getName();
	std::string s_eMove = m_opponent.m_pokemon[m_opponent.m_activePokemon].getMove(move).getName();
	std::string s_pPokemon = m_player.m_pokemon[m_player.m_activePokemon].getName();

	std::random_device rd;
	std::mt19937 rng(rd());
	std::uniform_int_distribution<int> dist(0, 100);
	int hit = dist(rng);

	if (hit > m_opponent.m_pokemon[m_opponent.m_activePokemon].getMove(move).getStat(2))
	{
		dialogue(4, s_ePokemon, s_eMove);
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
		dialogue(2, s_ePokemon, s_eMove);
	}

	m_nextEnemyA = ACTION_NONE;
	m_nextEnemyI = -1;

	if (m_player.m_pokemon[m_player.m_activePokemon].getDead())
	{
		m_nextPlayerA = ACTION_NONE;
		m_nextPlayerI = -1;

		dialogue(8, s_pPokemon, "");
		dialogue(9, "", "");
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
	
	std::string s_ePokemon = m_opponent.m_pokemon[m_opponent.m_activePokemon].getName();
	std::string s_pPokemon = m_player.m_pokemon[m_player.m_activePokemon].getName();
	std::string s_pMove = m_player.m_pokemon[m_player.m_activePokemon].getMove(move).getName();

	std::random_device rd;
	std::mt19937 rng(rd());
	std::uniform_int_distribution<int> dist(0, 100);
	int hit = dist(rng);

	if (hit > m_player.m_pokemon[m_player.m_activePokemon].getMove(move).getStat(2))
	{
		dialogue(3, s_pPokemon, s_pMove);
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
		dialogue(1, s_pPokemon, s_pMove);
	}

	m_nextPlayerA = ACTION_NONE;
	m_nextPlayerI = -1;

	if (m_opponent.m_pokemon[m_opponent.m_activePokemon].getDead())
	{
		m_nextEnemyA = ACTION_NONE;
		m_nextEnemyI = -1;
		
		dialogue(10, s_ePokemon, "");
		dialogue(12, "", "");
	}
}
bool Battle::queueEmpty()
{
	return (m_nextEnemyA == ACTION_NONE && m_nextPlayerA == ACTION_NONE);
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