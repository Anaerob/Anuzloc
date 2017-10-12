#include "Battle.h"

Battle::Battle(Player& player, TextBox& textBox)
	: //m_menu{ player },
	m_opponent{ },
	m_player{ player },
	m_textBox{ textBox }//,
	//m_view{ player }
{
	
}

/*void Battle::draw(sf::RenderWindow& window)
{
	//m_menu.draw(window);
	//m_view.draw(m_opponent, window);
	//m_textBox.draw(window);
}*/
void Battle::initialize(Trainer opponent)
{
	m_opponent = opponent;
	m_active = true;
	//m_menu.initialize();
}
/*void Battle::menuDown()
{
	m_menu.navigateDown();
}
int Battle::menuReturn()
{
	return m_menu.press();
}
void Battle::menuLeft()
{
	m_menu.navigateLeft();
}
void Battle::menuRight()
{
	m_menu.navigateRight();
}
void Battle::menuUp()
{
	m_menu.navigateUp();
}*/
/*bool Battle::useMoves(int i)
{
	Pokemon& opponentPokemon = m_opponent.getPokemon(0);
	Pokemon& playerPokemon = m_player.getPokemon(0);
	
	Move& opponentMove = opponentPokemon.getMove(i - 1);
	Move& playerMove = playerPokemon.getMove(i - 1);

	double d_level;
	double d_power;
	double d_attack;
	double d_defense;
	double d_damage;
	int damage;

	if (playerMove.getStat(1) != 0)
	{
		d_level = (double)playerPokemon.getLevel();
		d_power = (double)playerMove.getStat(1);
		d_attack = (double)playerPokemon.getStat(1);
		d_defense = (double)opponentPokemon.getStat(2);
		d_damage = 2 +
			d_power * d_attack * (2 + 2 * d_level / 5) / (50 * d_defense);
		damage = (int)d_damage;
	}
	else
		damage = 0;
	opponentPokemon.changeHP(-damage);

	if (opponentMove.getStat(1) != 0)
	{
		d_level = (double)opponentPokemon.getLevel();
		d_power = (double)opponentMove.getStat(1);
		d_attack = (double)opponentPokemon.getStat(1);
		d_defense = (double)playerPokemon.getStat(2);
		d_damage = 2 +
			d_power * d_attack * (2 + 2 * d_level / 5) / (50 * d_defense);
		damage = (int)d_damage;
	}
	else
		damage = 0;
	playerPokemon.changeHP(-damage);

	return (playerPokemon.getHP() != 0 &&
		opponentPokemon.getHP() != 0);
}*/
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