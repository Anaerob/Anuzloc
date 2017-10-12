#include "Menu.h"

Menu::Menu(Player& player)
	: m_buttonSet{ { cf_mPX + 32.0f, cf_mPY + 32.0f },
	{ cf_mPX + 192.0f + 64.0f, cf_mPY + 32.0f },
	{ cf_mPX + 32.0f, cf_mPY + 100.0f + 64.0f },
	{ cf_mPX + 192.0f + 64.0f, cf_mPY + 100.0f + 64.0f } },
	m_markedButton{ 0 },
	m_player{ player }
{
	initialize();
}

void Menu::draw(sf::RenderWindow& window)
{
	for (int i = 0; i < c_buttons; ++i)
		m_buttonSet[i].draw(window);
}
/*void BattleMenu::enterFight()
{
	m_inFight = true;
	for (int i = 0; i < 4; ++i)
	{
		m_buttonSet4[i].setString(m_player.getPokemon(0).getMove(i).getName());
		m_buttonSet4[i].setActive(m_player.getPokemon(0).getMove(i).getIndex() != 0);
	}
}*/
void Menu::initialize()
{
	m_inFight = false;
	for (int i = 0; i < c_buttons; ++i)
	{
		m_buttonSet[i].setActive(true);
		m_buttonSet[i].setMarked(false);
	}
	m_buttonSet[m_markedButton].setMarked(true);

	m_buttonSet[0].setString("Fight");
	m_buttonSet[1].setString("Bag");
	m_buttonSet[2].setString("Pokemon");
	m_buttonSet[3].setString("Run");
}
void Menu::navigateDown()
{
	if (m_buttonSet[0].getMarked() && m_buttonSet[2].getActive())
	{
		m_buttonSet[0].setMarked(false);
		m_buttonSet[2].setMarked(true);
	}
	else if (m_buttonSet[1].getMarked() && m_buttonSet[3].getActive())
	{
		m_buttonSet[1].setMarked(false);
		m_buttonSet[3].setMarked(true);
	}
}
void Menu::navigateLeft()
{
	if (m_buttonSet[1].getMarked() && m_buttonSet[0].getActive())
	{
		m_buttonSet[1].setMarked(false);
		m_buttonSet[0].setMarked(true);
	}
	else if (m_buttonSet[3].getMarked() && m_buttonSet[2].getActive())
	{
		m_buttonSet[3].setMarked(false);
		m_buttonSet[2].setMarked(true);
	}
}
void Menu::navigateRight()
{
	if (m_buttonSet[0].getMarked() && m_buttonSet[1].getActive())
	{
		m_buttonSet[0].setMarked(false);
		m_buttonSet[1].setMarked(true);
	}
	else if (m_buttonSet[2].getMarked() && m_buttonSet[3].getActive())
	{
		m_buttonSet[2].setMarked(false);
		m_buttonSet[3].setMarked(true);
	}
}
void Menu::navigateUp()
{
	if (m_buttonSet[2].getMarked() && m_buttonSet[0].getActive())
	{
		m_buttonSet[2].setMarked(false);
		m_buttonSet[0].setMarked(true);
	}
	else if (m_buttonSet[3].getMarked() && m_buttonSet[1].getActive())
	{
		m_buttonSet[3].setMarked(false);
		m_buttonSet[1].setMarked(true);
	}
}
/*int BattleMenu::press()
{
	if (m_buttonSet4[0].getMarked() && !m_inFight)
	{
		enterFight();
		return 0;
	}
	for (int i = 0; i < 4; ++i)
		if (m_buttonSet4[i].getMarked() && m_inFight)
		{
			initialize();
			return i + 1;
		}
	return 0;
}*/