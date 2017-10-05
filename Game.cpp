#include "Game.h"

Game::Game()
	: //m_battle{ m_player , m_textBox },
	m_overworld{},// m_player, m_battle, m_textBox },
	//m_inBattle{ false },
	//m_intro{ false },
	m_frameLines{ sf::Lines, 4 },
	m_lock{ false }
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

	//Pokemon temp{ 1 };
	//m_player.setPokemon(0, temp);
}

Game::~Game()
{
	//deallocateTileMap();
	//deallocateTriggerMap();
}

void Game::draw(sf::RenderWindow& window)
{
	window.draw(m_frameLines);
}

/*void Game::deallocateTriggerMap()
{
	delete[] m_triggerMap;
	m_triggerMap = nullptr;
}
void Game::deallocateTileMap()
{
	delete[] m_tileMap;
	m_tileMap = nullptr;
}

void Game::draw(sf::RenderWindow& window)
{
	if (m_intro)
	{
	sf::VertexArray janaV;
	sf::Texture janaT;
	janaV.setPrimitiveType(sf::Quads);
	janaV.resize(4);
	janaT.loadFromFile("images/jana.png");

	janaV[0].position = sf::Vector2f(cf_vPX,
	cf_vPY);
	janaV[1].position = sf::Vector2f(cf_vPX + cf_vSX,
	cf_vPY);
	janaV[2].position = sf::Vector2f(cf_vPX + cf_vSX,
	cf_vPY + cf_vSY);
	janaV[3].position = sf::Vector2f(cf_vPX,
	cf_vPY + cf_vSY);

	janaV[0].texCoords = sf::Vector2f(0.0f,
	0.0f);
	janaV[1].texCoords = sf::Vector2f(300.0f,
	0.0f);
	janaV[2].texCoords = sf::Vector2f(300.0f,
	300.0f);
	janaV[3].texCoords = sf::Vector2f(0.0f,
	300.0f);

	window.draw(janaV, &janaT);
	m_overworld.getTextBox().draw(window);
	m_battle.getMenu().draw(window);
	}
	else
	{
	if (m_inBattle)
		m_battle.draw(window);
	if (!m_inBattle)
		m_overworld.draw(window);
	//}
	m_textBox.draw(window);
	window.draw(m_frameLines);
}
void Game::exit()
{
	//m_overworld.deallocateWorld();
}
bool Game::holdKeyA()
{
	if (!m_inBattle)
	{
		int nextTile = m_overworld.getTile(m_player.getX() - 1, m_player.getY());
		bool moving = m_player.move(2, nextTile);
		m_overworld.getTextBox().clear();
		m_lock = moving;
		return moving;
	}
	else
		return false;
}
bool Game::holdKeyD()
{
	if (!m_inBattle)
	{
		int nextTile = m_overworld.getTile(m_player.getX() + 1, m_player.getY());
		bool moving = m_player.move(3, nextTile);
		m_overworld.getTextBox().clear();
		m_lock = moving;
		return moving;
	}
	else
		return false;
}
bool Game::holdKeyS()
{
	if (!m_inBattle)
	{
		int nextTile = m_overworld.getTile(m_player.getX(), m_player.getY() + 1);
		bool moving = m_player.move(0, nextTile);
		m_overworld.getTextBox().clear();
		m_lock = moving;
		return moving;
	}
	else
		return false;
}
bool Game::holdKeyW()
{
	if (!m_inBattle)
	{
		int nextTile = m_overworld.getTile(m_player.getX(), m_player.getY() - 1);
		bool moving = m_player.move(1, nextTile);
		m_overworld.getTextBox().clear();
		m_lock = moving;
		return moving;
	}
	else
		return false;
}
void Game::initialize()
{
	if (m_intro)
	{
	m_overworld.getTextBox().addString("'Sup idiot, which Pokemon u want?");
	}
}
void Game::pressKeyDown()
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
	if (m_intro)
	{
	m_intro = false;
	m_overworld.getTextBox().clear();
	}
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
}
void Game::readGeneral()
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