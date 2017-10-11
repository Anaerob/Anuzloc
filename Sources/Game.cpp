#include "Game.h"

Game::Game()
	: //m_battle{ m_player , m_textBox },
	m_event{ m_player, m_textBox },
	m_overworld{ m_event, m_player, m_textBox },
	m_frameLines{ sf::Lines, 4 }
{
	m_frameLines[0].position = sf::Vector2f(cf_vSX,
		0.0f);
	m_frameLines[1].position = sf::Vector2f(cf_vSX,
		cf_wSY);
	m_frameLines[2].position = sf::Vector2f(0.0f,
		cf_tBPY);
	m_frameLines[3].position = sf::Vector2f(cf_tBSX,
		cf_tBPY);

	for (int i = 0; i < 4; ++i)
		m_frameLines[i].color = sf::Color::Black;

	Pokemon temp{ 1 };
	m_player.setPokemon(0, temp);
}

void Game::draw(sf::RenderWindow& window)
{
	m_overworld.draw(window);
	m_textBox.draw(window);
	window.draw(m_frameLines);
}
void Game::holdA()
{
	if (!m_player.getLock())
	{
		Direction direction = DIRECTION_LEFT;
		int nextTile = m_overworld.getTile(m_player.getX() - 1, m_player.getY());
		m_player.move(direction, nextTile);
		m_textBox.clear();
		if (m_player.getMoving())
			m_moving = direction;
		else
			m_moving = DIRECTION_NONE;
	}
}
void Game::holdD()
{
	if (!m_player.getLock())
	{
		Direction direction = DIRECTION_RIGHT;
		int nextTile = m_overworld.getTile(m_player.getX() + 1, m_player.getY());
		m_player.move(direction, nextTile);
		m_textBox.clear();
		if (m_player.getMoving())
			m_moving = direction;
		else
			m_moving = DIRECTION_NONE;
	}
}
void Game::holdS()
{
	if (!m_player.getLock())
	{
		Direction direction = DIRECTION_DOWN;
		int nextTile = m_overworld.getTile(m_player.getX(), m_player.getY() + 1);
		m_player.move(direction, nextTile);
		m_textBox.clear();
		if (m_player.getMoving())
			m_moving = direction;
		else
			m_moving = DIRECTION_NONE;
	}
}
void Game::holdW()
{
	if (!m_player.getLock())
	{
		Direction direction = DIRECTION_UP;
		int nextTile = m_overworld.getTile(m_player.getX(), m_player.getY() - 1);
		m_player.move(direction, nextTile);
		m_textBox.clear();
		if (m_player.getMoving())
			m_moving = direction;
		else
			m_moving = DIRECTION_NONE;
	}
}
void Game::pressBackSpace()
{

}
void Game::pressDown()
{

}
void Game::pressLeft()
{

}
void Game::pressReturn()
{

}
void Game::pressRight()
{

}
void Game::pressSpace()
{
	if (m_event.getActive())
		m_event.advance();
	else
		m_overworld.interact();
}
void Game::pressUp()
{

}
/*void Game::pressKeyDown()
{
	if (m_inBattle)
		m_battle.menuDown();
	if (!m_inBattle)
		m_overworld.menuDown();
}
void Game::pressKeyLeft()
{
	if (m_inBattle)
		m_battle.menuLeft();
}
void Game::pressKeyReturn()
{
	if (m_inBattle)
	{
		int move = m_battle.menuReturn();
		if (move != 0)
			m_inBattle = m_battle.useMoves(move);
	}
	if (!m_inBattle)
		m_overworld.menuReturn();
}
void Game::pressKeyRight()
{
	if (m_inBattle)
		m_battle.menuRight();
}
void Game::pressKeySpace()
{
	if (!m_inBattle)
	{
		bool inEvent = false;
		inEvent = m_overworld.interact();
		m_inBattle = m_battle.getInBattle();
		m_lock = inEvent;
	}
}
void Game::pressKeyUp()
{
	if (m_inBattle)
		m_battle.menuUp();
	if (!m_inBattle)
		m_overworld.menuUp();
}*/
/*void Game::readGeneral()
{
	m_read.open("general/strings.dat");

	std::string nextString;
	std::map<int, std::string> general;

	int i = 0;
	general[i] = "";
	while (m_read)
	{
		std::getline(m_read, nextString);
		general[++i] = nextString;
	}

	m_read.close();
	m_generalStringMap = general;
}*/