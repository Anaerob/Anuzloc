#include "Event.h"

Event::Event(Battle& battle, Player& player, TextBox& textBox)
	: m_active{ false },
	m_battle{ battle },
	m_player{ player },
	//m_stringMap{ stringMap },
	m_textBox{ textBox },
	m_world{ "route1" }
{
	//readWorld();
}

void Event::advance()
{
	char nextChar;
	do
	{
		m_read >> nextChar;
	} while (nextChar != 'b' && nextChar != 'e' && nextChar != 's');

	int nextInt;
	m_read >> nextInt;
	switch (nextChar)
	{
	case 'b':
		m_battle.initialize(m_opponent);
		break;
	case 's':
		m_textBox.addString(m_strings.find(nextInt)->second);
		break;
	case 'e':
		m_textBox.clear();
		m_read.close();
		m_active = false;
		m_player.setLock(false);
		break;
	default:
		break;
	}
}
void Event::initialize(int ID, Trainer opponent)
{
	m_read.open("Resources/Maps/route1Events.dat");
	std::string key = "e";
	key.append(std::to_string(ID));
	m_opponent = opponent;

	std::string nextString;
	do
	{
		m_read >> nextString;
		m_active = (nextString == key);
	} while (!m_active && m_read.good());
	if (m_active)
	{
		advance();
		m_player.setLock(true);
	}
	else
		m_read.close();
}