#include "Menu.h"

Menu::Menu(Player& player)
	: m_action{ ACTION_NONE },
	m_index{ -1 },
	m_lock{ false },
	m_marked{ 0 },
	m_menu{ MENU_NONE },
	//m_move{ -1 },
	m_player{ player }
	//m_pokemon{ -1 }
{
	m_buttonSet.clear();
	m_buttonSet.resize(c::iBN);
	for (int i = 0; i < c::iBN; ++i)
	{
		m_buttonSet[i].setPositionX(c::fMPX + 32.0f + (i % 2) * (32.0f + 192.0f));
		m_buttonSet[i].setPositionY(c::fMPY + 32.0f + (i / 2) * (32.0f + 100.0f));
	}

	m_buttonSet[m_marked].setMarked(true);
	//initialize();
}

eAction Menu::getAction()
{
	eAction temp = m_action;
	m_action = ACTION_NONE;
	return temp;
}
int Menu::getIndex()
{
	int temp = m_index;
	m_index = -1;
	return temp;
}
/*int Menu::getMove()
{
	int temp = m_move;
	m_move = -1;
	return temp;
}
int Menu::getPokemon()
{
	int temp = m_pokemon;
	m_pokemon = -1;
	return temp;
}*/

void Menu::back()
{
	switch (m_menu)
	{
	case MENU_FIGHT:
		change(MENU_BATTLE);
		break;
	case MENU_POKEMON:
		change(MENU_BATTLE);
		break;
	default:
		break;
	}
}
void Menu::change(eMenu menu)
{
	if (!m_lock)
	{
		m_menu = menu;
		resetMark();

		switch (menu)
		{
		case MENU_NONE:
			for (int i = 0; i < c::iBN; ++i)
				m_buttonSet[i].setActive(false);
			break;
		case MENU_BATTLE:
			m_buttonSet[0].setActive(true);
			m_buttonSet[0].setString("Fight");
			m_buttonSet[1].setActive(true);
			m_buttonSet[1].setString("Pokemon");
			for (int i = 2; i < c::iBN; ++i)
				m_buttonSet[i].setActive(false);
			break;
		case MENU_FIGHT:
			for (int i = 0; i < 4; ++i)
			{
				bool activate = m_player.m_pokemon[m_player.m_activePokemon].getMove(i).getIndex() != 0;
				if (activate)
				{
					m_buttonSet[i].setString(m_player.m_pokemon[m_player.m_activePokemon].getMove(i).getName());
					m_buttonSet[i].setActive(true);
				}
				else
				{
					m_buttonSet[i].setActive(false);
					if (m_marked == i)
						moveMark(1);
				}
			}
			break;
		case MENU_POKEMON:
			for (int i = 0; i < 6; ++i)
			{
				bool activate = m_player.m_pokemon[i].getIndex() != 0 && !m_player.m_pokemon[i].getDead();
				if (activate)
				{
					m_buttonSet[i].setString(m_player.m_pokemon[i].getName());
					m_buttonSet[i].setActive(true);
				}
				else
				{
					m_buttonSet[i].setActive(false);
					if (m_marked == i)
						moveMark(1);
				}
			}
			break;
		default:
			break;
		}
	}
}
void Menu::draw(sf::RenderWindow& window)
{
	for (int i = 0; i < c::iBN; ++i)
		m_buttonSet[i].draw(window);
}
void Menu::enter()
{
	switch (m_menu)
	{
	case MENU_BATTLE:
		if (m_marked == 0)
			change(MENU_FIGHT);
		if (m_marked == 1)
			change(MENU_POKEMON);
		break;
	case MENU_FIGHT:
		m_action = ACTION_MOVE;
		m_index = m_marked;
		change(MENU_NONE);
		break;
	case MENU_POKEMON:
		m_action = ACTION_SWITCH;
		m_index = m_marked;
		m_lock = false;
		change(MENU_NONE);
		break;
	default:
		break;
	}
}
/*void Menu::initialize()
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
}*/
void Menu::moveMark(int i)
{
	m_buttonSet[m_marked].setMarked(false);
	m_marked += i;
	m_buttonSet[m_marked].setMarked(true);
}
void Menu::navigateDown()
{
	if (m_marked + 2 < c::iBN)
		if (m_buttonSet[m_marked + 2].getActive())
			moveMark(2);
}
void Menu::navigateLeft()
{
	if (m_marked % 2 == 1)
		if (m_buttonSet[m_marked - 1].getActive())
			moveMark(-1);
}
void Menu::navigateRight()
{
	if (m_marked % 2 == 0 && m_marked + 1 < c::iBN)
		if (m_buttonSet[m_marked + 1].getActive())
			moveMark(1);
}
void Menu::navigateUp()
{
	if (m_marked - 2 >= 0)
		if (m_buttonSet[m_marked - 2].getActive())
			moveMark(-2);
}
/*void Menu::reset()
{
	m_move = -1;
	m_pokemon = -1;
}*/
void Menu::resetMark()
{
	m_buttonSet[m_marked].setMarked(false);
	m_marked = 0;
	m_buttonSet[m_marked].setMarked(true);
}