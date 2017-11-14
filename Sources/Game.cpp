#include "Game.h"

Game::Game()
	: m_battle{ m_menu, m_player , m_textBox },
	m_event{ m_battle, m_player, m_textBox },
	m_menu{ m_player },
	m_overworld{ m_battle, m_event, m_player, m_textBox },
	m_frameLines{ sf::Lines, 4 }
{
	m_frameLines[0].position = sf::Vector2f(c::fVSX,
		0.0f);
	m_frameLines[1].position = sf::Vector2f(c::fVSX,
		c::fWSY);
	m_frameLines[2].position = sf::Vector2f(0.0f,
		c::fTBPY);
	m_frameLines[3].position = sf::Vector2f(c::fTBSX,
		c::fTBPY);

	for (int i = 0; i < 4; ++i)
		m_frameLines[i].color = sf::Color::Black;

	readGeneral();
	m_battle.setStrings(m_generalStrings);

	for (int i = 0; i < 4; ++i)
	{
		Pokemon temp{ i + 1, 5 };
		temp.makePlayers();
		m_player.setPokemon(i, temp);
	}
}

void Game::draw(sf::RenderWindow& window)
{
	if (m_battle.getActive())
		m_battle.draw(window);
	else
		m_overworld.draw(window);
	m_menu.draw(window);
	m_textBox.draw(window);
	window.draw(m_frameLines);
}
void Game::holdA()
{
	if (!m_player.getLock())
	{
		eDirection direction = DIRECTION_LEFT;
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
		eDirection direction = DIRECTION_RIGHT;
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
		eDirection direction = DIRECTION_DOWN;
		int nextTile = m_overworld.getTile(m_player.getX(), m_player.getY() + 1);
		m_player.move(direction, nextTile);
		m_textBox.clear();
		if (m_player.getMoving())
			m_moving = direction;
		else
		{
			m_moving = DIRECTION_NONE;
			int portal = m_overworld.getPortal(m_player.getX(), m_player.getY());
			if (portal != 0)
			{
				std::string portalPath = "Resources/Maps/";
				portalPath.append(m_overworld.getWorld());
				portalPath.append("Portals.dat");
				m_read.open(portalPath);

				int x = 0;
				int y = 0;
				std::string world = "";

				for (int i = 0; i < portal; ++i)
				{
					m_read >> x;
					m_read >> y;
					m_read >> world;
					m_read >> x;
					m_read >> y;
				}

				m_overworld.setWorld(world);
				m_player.setPosition(x, y);
				m_read.close();
			}
		}
	}
}
void Game::holdW()
{
	if (!m_player.getLock())
	{
		eDirection direction = DIRECTION_UP;
		int nextTile = m_overworld.getTile(m_player.getX(), m_player.getY() - 1);
		m_player.move(direction, nextTile);
		m_textBox.clear();
		if (m_player.getMoving())
			m_moving = direction;
		else
		{
			m_moving = DIRECTION_NONE;
			int portal = m_overworld.getPortal(m_player.getX(), m_player.getY());
			if (portal != 0)
			{
				std::string portalPath = "Resources/Maps/";
				portalPath.append(m_overworld.getWorld());
				portalPath.append("Portals.dat");
				m_read.open(portalPath);

				int x = 0;
				int y = 0;
				std::string world = "";

				for (int i = 0; i < portal; ++i)
				{
					m_read >> x;
					m_read >> y;
					m_read >> world;
					m_read >> x;
					m_read >> y;
				}

				m_overworld.setWorld(world);
				m_player.setPosition(x, y);
				m_read.close();
			}
		}
	}
}
void Game::pressBackSpace()
{
	m_menu.back();
}
void Game::pressDown()
{
	m_menu.navigateDown();
}
void Game::pressLeft()
{
	m_menu.navigateLeft();
}
void Game::pressReturn()
{
	m_menu.enter();
	int move = m_menu.getMove();
	int pokemon = m_menu.getPokemon();

	if (move != -1)
	{
		m_textBox.clear();
		m_battle.advance(ACTION_MOVE, move);
		if (!m_battle.getActive())
		{
			m_menu.change(MENU_NONE);
			m_textBox.clear();
			m_event.advance();
		}
	}
	else if (pokemon != -1)
	{
		m_textBox.clear();
		m_battle.advance(ACTION_POKEMON, pokemon);
	}
}
void Game::pressRight()
{
	m_menu.navigateRight();
}
void Game::pressSpace()
{
	if (m_event.getActive())
	{
		if (!m_battle.getActive())
			m_event.advance();
	}
	else
		m_overworld.interact();
}
void Game::pressUp()
{
	m_menu.navigateUp();
}
void Game::readGeneral()
{
	m_read.open("Resources/Strings.dat");

	std::string nextLine;
	std::map<int, std::string> general;

	int i = 0;
	general[i] = "";

	while (m_read.good())
	{
		std::getline(m_read, nextLine);
		general[++i] = nextLine;
	}

	m_read.close();
	m_generalStrings = general;
}